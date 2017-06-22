import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.util.*;


public abstract class Token implements AnimationEntity {

	protected int count;
    public Vector2D position;
    public double radius = 20;
    public Color color;	
  
    public Token(double x, double y) {
    	
    	this.position = new Vector2D((int)x, (int)y);
    	Random rand = new Random();
    	this.count = rand.nextInt(15)+5; 
    }
    
    public void draw(Graphics2D g2d) {
    	
    	String temp = "" + this.count;
        AffineTransform transform = g2d.getTransform();

        g2d.setColor(this.color);

        g2d.translate(this.position.x, this.position.y);
        
        g2d.setStroke(new BasicStroke(3.0f));
        g2d.drawOval(0, 0, (int) radius, (int) radius);
        
        g2d.drawString(temp, (int) (6), (int) -6);
        g2d.setTransform(transform);
    }
   
    public abstract int getCount();
    public abstract void act(double deltaTime);
}