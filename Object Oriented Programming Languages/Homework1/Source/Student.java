import java.awt.Graphics2D;
import java.util.*;

public abstract class Student implements AnimationEntity {

	public String name;
    public Vector2D position;
    public Vector2D speed;
    public State state;
    public Data data;
    public double radius = 40;
    public int tokenCount = 0;
    public int previousState = 0; //0 - seek
    							  //1 - deposit
    							  //2 - leave
    public int depositFlag = 0;
    public int whichCourse;
    public List<Integer> courseTokens = new ArrayList<Integer> ();
    public List<Integer> takenCourses = new ArrayList<Integer> ();
    
    public Student() {
    	
    }
    
    public Student(String name, Vector2D position, State state, Data data) {
    	this.name = name;
    	this.position = position;
    	this.state = state;
    	this.data = data;
    	this.speed = Vector2D.randomVector(4, 9, 4, 9);
    	this.speed.y = this.speed.x;
    	
    	for (int i=0; i < this.data.courses.size(); i++) {
    	    this.courseTokens.add(0);
    	}
    }

    public abstract void draw(Graphics2D g2d);
    public abstract void act(double deltaTime);
}