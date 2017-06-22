import java.awt.Color;

public class Black extends Token {
    
    public Black(double x, double y) {
    	super(x,y);
    	color=Color.BLACK;
    }

	@Override
	public void act(double deltaTime) {
		// TODO Auto-generated method stub
	}

	@Override
	public int getCount() {
		return this.count/2;
	}	
}