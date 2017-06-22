import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;

public class Taken1 extends StudentDecorator {

    public Taken1(Student decoratedStudent) {
    	super(decoratedStudent);
    }

	@Override
	public void draw(Graphics2D g2d) {
		
		decoratedStudent.draw(g2d);
        AffineTransform transform = g2d.getTransform();
        g2d.translate(decoratedStudent.position.x, decoratedStudent.position.y);
        g2d.setColor(decoratedStudent.data.courses.get(decoratedStudent.takenCourses.get(0)).color);
        g2d.fillRect(6, 14, 10, 15);
        g2d.setTransform(transform);
	}

	@Override
	public void act(double deltaTime) {
		
        this.decoratedStudent.state.act(decoratedStudent, deltaTime, decoratedStudent.data);
	}
}