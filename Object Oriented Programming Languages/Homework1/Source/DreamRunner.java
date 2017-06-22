import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class DreamRunner {
	
	public static JFrame window;
	public Display display;
	public Data data;
	public static boolean paused = false ;
	  
    public DreamRunner(int width, int height) {
    	
    	window = new JFrame();
	    window.setTitle("CENG 443 Token Dreams Salt Bae Edition by Onat Buyukakkus");
	    //window.setLocationByPlatform(true);
	    window.setSize(width, height);
	    //window.setDefaultCloseOperation(3);
	    
	    data = new Data(width,height);
	    display = new Display(data);
	    window.add(display);
	    SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                window.setVisible(true);
            }
        });
    }

    public static void main(String[] args) {
    	
    	if (args.length < 2) {
    	      args = new String[] { "800", "600"};
	    }
	    int width = Integer.parseInt(args[0]);
	    int height = Integer.parseInt(args[1]);

	    DreamRunner dreamRunner = new DreamRunner(width, height);
	    
	    java.awt.KeyboardFocusManager.getCurrentKeyboardFocusManager().addKeyEventDispatcher
	    (
	      new java.awt.KeyEventDispatcher() {
	    	  
	        @Override public boolean dispatchKeyEvent ( java.awt.event.KeyEvent event ) {
	          String key = javax.swing.KeyStroke.getKeyStrokeForEvent(event).toString();

	          if(key.equals("pressed P")) {
	        	  paused =! paused;
	        	  return true;
	          }
	          if(key.equals("pressed Q")) {
	        	  System.exit(0);
	        	  return true;
	          }
	          if(key.equals("pressed D")) {
	        	  window.setSize(width, height);
	        	  return true;
	          }
	          return false ;
	        }
	      }
	    );
	    
	    System.out.println("Press D for original size");
	    System.out.println("Press P to play/pause");
	    System.out.println("Press Q to quit");
	    System.out.println();
	    
 	    try {
    	    while(true) {
    	    	if(!paused) {
    	    		dreamRunner.display.repaint();
        	    	try {
            	    	dreamRunner.data.stepAll(1);
        	    	}
        	    	catch(Exception e) {
        	    	}
    	    	}
    	    	Thread.sleep((long) 0.001);
    	    }
	    }
 	    catch(Exception e) {
	    }
    }
}