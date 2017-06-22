import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;

public class BasicStudent extends Student {

    public BasicStudent(String name, Vector2D position, State state, Data data) {
    	super(name, position, state, data);
    }

	@Override
	public void draw(Graphics2D g2d) {
		
		String nameAndSpeed = "" + this.name + " (" + this.speed.getIntX() + ")";
		String tokenCount;
		String courseCount = "" + this.takenCourses.size();
		
		if(this.tokenCount == 0) {
			tokenCount = "None"; 
		}
		else {
			tokenCount = "" + this.tokenCount;
		}
        
        AffineTransform transform = g2d.getTransform();

        g2d.setColor(Color.GRAY);

        g2d.translate(this.position.x, this.position.y);
        
        g2d.setStroke(new BasicStroke(1.0f));
        g2d.drawOval(0, 0, (int) radius, (int) radius);
        
        if(this.state.getClass().getName().equals("Seek")) {
        	g2d.drawString("Seek", (int) 5, (int) 12);
        	
        }
        else if(this.state.getClass().getName().equals("Rest")) {
        	g2d.drawString("Rest", (int) 5, (int) 12);
        	
        }
        else if(this.state.getClass().getName().equals("Leave")) {
        	g2d.drawString("Leave", (int) 5, (int) 12);
        	
        }
        else {
        	g2d.setColor(this.data.courses.get(this.whichCourse).color);
        	g2d.drawString("Deposit", (int) 5, (int) 12);
        }
        
        g2d.setColor(Color.BLACK); 
        g2d.drawString(nameAndSpeed, (int) 0, (int) -6);
        
        g2d.setColor(Color.MAGENTA);
        g2d.drawString(courseCount, (int) 16, (int) 30);
        
        g2d.setColor(Color.GREEN);
        if(tokenCount.equals("None")) {
        	g2d.drawString(tokenCount, (int) 0, (int) 52);
        }
        else {
        	g2d.drawString(tokenCount, (int) 18, (int) 52);
        }
       
        g2d.setTransform(transform);
	}

	@Override
	public void act(double deltaTime) {
        this.state.act(this, deltaTime, this.data);
	}
}