//***************************************************************************************************************************************************

// TODO: Imports
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Random;

//***************************************************************************************************************************************************




//***************************************************************************************************************************************************

public class Client extends Thread
{
  //=================================================================================================================================================

  private final Server   server              ;
  private final int      periodOfRequests    ;
  private final Random   random              ;

  //=================================================================================================================================================

  // TODO: Optional extra fields
  private Reply reply;
  private int firstReq = 0;
  private List<String> keys;
  private int numberOfReqs = 0;
  private int numberofReps = 0;

  //=================================================================================================================================================

  public Client ( String name , double frequencyOfRequests , Server server )
  {
    super( name ) ;

    this.server           = server                                 ;
    this.periodOfRequests = (int) ( 1000.0 / frequencyOfRequests ) ;
    this.random           = new Random()                           ;

    start() ;
  }

  //=================================================================================================================================================

  public void acceptReply ( Reply reply ) throws Exception
  {
    // TODO
      this.numberofReps++;
      this.reply = reply;
      String desc = (String) reflectionForFields(reply, "description");
      if(desc.equals("Index")) {
          firstReq = 1;
          this.keys = new ArrayList<String>();
          List<String> cont = (List<String>) reflectionForFields(reply, "content");
          for(String newKey : cont) {
              this.keys.add(newKey);
          }
          keys.add("Z");
      }
      Runner.logf(this.getName() + " : Got reply " + reply + "%n");

  }

  //=================================================================================================================================================

  @Override public void run ()
  {
    // TODO
    while((boolean) reflectionForFields(server, "isRunning")) {
        try {
            Thread.sleep(periodOfRequests);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if(!((boolean) reflectionForFields(server, "isRunning"))) break;
        Request req = generateRequest();
        Queue<Request> currentReqQue = (Queue<Request>) reflectionForFields(server, "requestQueue");
        synchronized (currentReqQue) {
            Runner.logf(this.getName() + " : Sent request " + req + "%n");
            currentReqQue.add(req);
            this.numberOfReqs++;
            currentReqQue.notify();
        }

        synchronized (this) {
            try {
                this.wait();
            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
    Runner.logf(this.getName() + " : Reporting...%n");
    Runner.logf("           - Number of requests sent    = " + numberOfReqs + "%n");
    Runner.logf("           - Number of replies received = " + numberofReps + "%n");
  }

  //=================================================================================================================================================

  private Request generateRequest ()
  {
    // TODO
      if(firstReq == 0) {
          return new Request(this, "Get", "Index", null);
      }
      else {
          int methodRand = random.nextInt(2);
          int uriRand = random.nextInt(this.keys.size());
          if(methodRand == 0) { //GET
              return new Request(this, "Get", this.keys.get(uriRand), "NA");
          }
          else { //POST
              int dataRand = random.nextInt(1000);
              return new Request(this, "Post", this.keys.get(uriRand), ("Data" + dataRand));
          }
      }
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

