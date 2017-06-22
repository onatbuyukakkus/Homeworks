import java.awt.Graphics2D;

public abstract class StudentDecorator extends Student {

	public Student decoratedStudent;
	
	public StudentDecorator(Student decoratedStudent) {
    	super();
    	this.decoratedStudent = decoratedStudent;
    }

    public abstract void draw(Graphics2D g2d);
}