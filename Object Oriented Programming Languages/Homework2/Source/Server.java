//***************************************************************************************************************************************************

// TODO: Imports
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Timer;
import java.util.TimerTask;

//***************************************************************************************************************************************************




//***************************************************************************************************************************************************

public class Server extends Thread
{
  //=================================================================================================================================================

  private boolean                                isRunning    ;
  private final Map  < String , List< String > > content      ;
  private final Queue< Request                 > requestQueue ;

  //=================================================================================================================================================

  // TODO: Optional extra fields
  public List <String> keys;
  private int numberOfReqs = 0;
  private int numberOfReps = 0;

  //=================================================================================================================================================

  public Server ( String name )
  {
    super( name ) ;

    isRunning    = true               ;
    content      = new HashMap   <>() ;  generateContent() ;
    requestQueue = new LinkedList<>() ;

    keys = new ArrayList <String>();
	for (Map.Entry<String, List <String> > entry : content.entrySet()) {
	    keys.add(entry.getKey());
	}
    
    Timer     timer     = new Timer    () ;
	TimerTask timerTask = new TimerTask()
                          {
                              @Override public void run()
                              {
                                  Runner.logf( "Timer    : Server shutting down...%n" ) ;

                                  isRunning = false ;

                                  // TODO: Optional extra statements here
                                  synchronized (requestQueue) {
                                      requestQueue.notify();
                                  }

                                  timer.cancel() ;
                              }
                          } ;

    timer.schedule( timerTask , 10 * 1000 ) ;

    start() ;
  }

  //=================================================================================================================================================

  public boolean acceptRequest ( Request request )
  {
      // TODO
      Method method = null;
      try {
          method = request.getClass().getDeclaredMethod("isValid");
      } catch (NoSuchMethodException e) {
          e.printStackTrace();
      }
      method.setAccessible(true);
      Object isVal = null;
      try {
          isVal = method.invoke(request);
      } catch (IllegalAccessException e) {
          e.printStackTrace();
      } catch (InvocationTargetException e) {
          e.printStackTrace();
      }
      return (boolean) isVal;
  }

  //=================================================================================================================================================

  @Override public void run ()
  {
    // TODO
	  while(isRunning) {
		synchronized (requestQueue) {
			try {
				if(requestQueue.isEmpty() == true) {
					Runner.logf("Server   : Request queue is empty, waiting...%n");
					requestQueue.wait();
                    Runner.logf("Server   : Has just been notified, getting back to work...%n");
				}
			}
			catch(Exception e) {
				e.printStackTrace();
			}
		}

		if(!isRunning) break;

		Request currentReq = requestQueue.poll();
		numberOfReqs++;
        Client currentCli = (Client) reflectionForFields(currentReq, "client");
		synchronized (currentCli) {
			if(acceptRequest(currentReq)) {
				Runner.logf("Server   : Request " + currentReq + " is VALID, handling...%n");
                String currentMethod = (String) reflectionForFields(currentReq, "method");
                String currentUri = (String) reflectionForFields(currentReq, "uri");
				if(currentMethod.equals("Get")) {
					if(currentUri.equals("Index")) {
						Reply reply = new Reply("Index", keys);
						try {
							currentCli.acceptReply(reply);
						} catch (Exception e) {
							e.printStackTrace();
						}
						numberOfReps++;
						currentCli.notify();
					}
					else if(currentUri.equals("Z")) {
						List <String> naKeys = new ArrayList <String>();
						naKeys.add("NA");
						Reply reply = new Reply("404", naKeys);
						try {
							currentCli.acceptReply(reply);
						} catch (Exception e) {
							e.printStackTrace();
						}
						numberOfReps++;
						currentCli.notify();
					}
					else {
						Reply reply = new Reply("Document", content.get(currentUri));
						try {
							currentCli.acceptReply(reply);
						} catch (Exception e) {
							e.printStackTrace();
						}
						numberOfReps++;
						currentCli.notify();
					}
				}
				else if(currentMethod.equals("Post")) {
				    String currentParam = (String) reflectionForFields(currentReq, "parameter");
                    if(currentUri.equals("Z")) {
                        Runner.logf("Server   : Post data " + currentParam + " on Z has invalid target uri, ignored!%n");
                        currentCli.notify();
                    }
                    else {
                        /*List <String> newValues = new ArrayList <String>();
                        for(String oldValue : content.get(currentReq.uri)) {
                            newValues.add(oldValue);
                        }
                        newValues.add(currentReq.parameter);
                        content.put(currentReq.uri, newValues);*/
                        Runner.logf("Server   : Post data " + currentParam + " on " + currentUri + " handled successfully.%n");
                        currentCli.notify();
                    }
                }
			}
			else {
				Runner.logf("Server   : Request " + currentReq + " is INVALID, dropped...%n");
				currentCli.notify();
			}
		}
	  }
	  Runner.logf("Server   : Reporting...%n");
      Runner.logf("           - Number of requests received = " + numberOfReqs + "%n");
      Runner.logf("           - Number of replies sent      = " + numberOfReps + "%n");
  }

  //=================================================================================================================================================

  private void generateContent ()
  {
    String         key   ;
    List< String > value ;

    key = "A" ;  value = new ArrayList<>() ;  value.add( "A1" ) ;  value.add( "A2" ) ;  content.put( key , value ) ;
    key = "B" ;  value = new ArrayList<>() ;  value.add( "B1" ) ;  value.add( "B2" ) ;  content.put( key , value ) ;
    key = "C" ;  value = new ArrayList<>() ;  value.add( "C1" ) ;  value.add( "C2" ) ;  content.put( key , value ) ;
    key = "D" ;  value = new ArrayList<>() ;  value.add( "D1" ) ;  value.add( "D2" ) ;  content.put( key , value ) ;
  }

  //=================================================================================================================================================

  // TODO: Optional extra helper methods
  public Object reflectionForFields(Object object, String fieldName) {
      Field field = null;
      try {
          field = object.getClass().getDeclaredField(fieldName);
      } catch (NoSuchFieldException e) {
          e.printStackTrace();
      }
      field.setAccessible(true);
      Object value = null;
      try {
          value = field.get(object);
      } catch (IllegalAccessException e) {
          e.printStackTrace();
      }
      return value;
  }

  //=================================================================================================================================================
}

//***************************************************************************************************************************************************

