import java.awt.Color;

public class Fake extends Token {
    
    public Fake(double x, double y) {
    	super(x,y);
    	color=Color.BLUE;
    }
	
	@Override
	public void act(double deltaTime) {
		// TODO Auto-generated method stub
	}

	@Override
	public int getCount() {
		return 1;
	}	
}