import java.util.*;

public class Deposit extends State {
	
    public Deposit() {
    }
    
    @Override
    public void act(Student student, double deltaTime, Data data){
    	Random restRand = new Random();
    	int restRandom = restRand.nextInt(500000);
    	if(restRandom == 79) {
    		student.state = new Rest();
    	}
    	
    	if(student.depositFlag == 1) {
    		Random rand = new Random();
        	student.whichCourse = rand.nextInt(data.courses.size());
        	if(student.takenCourses.contains((Integer) student.whichCourse) == true) {
        		if(student.whichCourse == 7) {
        			student.whichCourse = 6;
        		}
        		else if(student.whichCourse == 0) {
        			student.whichCourse = 1;
        		}
        		else {
        			student.whichCourse += 1;
        		}
        	}
        	student.depositFlag = 0;
    	}
    	
    	Vector2D position = new Vector2D(data.width/(data.courses.size()*2) + student.whichCourse*data.width/data.courses.size(), 100); 
    	Vector2D distVector = new Vector2D(position.x - student.position.x, position.y - student.position.y);
    	distVector.unitise();
    	Vector2D pixelSpeed = student.speed.multiply(new Vector2D(0.0001,0.0001));
    	Vector2D directionVector = distVector.multiply(pixelSpeed);
    	student.position.add(directionVector);
    	
    	if(student.position.distanceTo(position) <= 5) {
    		int temp;
    		temp = student.courseTokens.get(student.whichCourse);
    		student.courseTokens.set(student.whichCourse, (temp+student.tokenCount));
    		if(student.courseTokens.get(student.whichCourse) >= data.courses.get(student.whichCourse).minTokens) {
    			student.takenCourses.add(student.whichCourse);
    			data.courses.get(student.whichCourse).studentCounter();
    			if(student.takenCourses.size() == 1) {
    				//taken1
    				student.previousState = 0;
    				student.state = new Seek();
    				Student taken1Student = new Taken1(student);
    				data.entities.remove(student);
    				data.entities.add(taken1Student);
    				data.students.remove(student);
    				data.students.add(taken1Student);
    			}
    			else {
    				//taken2
    				student.previousState = 2;
    				student.state = new Leave();
    				Student taken2Student = new Taken2(student);
    				data.entities.remove(student);
    				data.entities.add(taken2Student);
    				data.students.remove(student);
    				data.students.add(taken2Student);
    			}
    		}
    		else {
				student.previousState = 0;
    			student.state = new Seek();
    		}
    		student.tokenCount = 0;
    	}

    }
}