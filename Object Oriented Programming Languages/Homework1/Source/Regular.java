import java.awt.Color;

public class Regular extends Token {
    
    public Regular(double x, double y) {
    	super(x,y);
    	color=Color.GREEN;
    }
	
	@Override
	public void act(double deltaTime) {
		// TODO Auto-generated method stub
	}

	@Override
	public int getCount() {
		return this.count;
	}
}