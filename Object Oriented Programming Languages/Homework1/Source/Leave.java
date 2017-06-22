import java.util.Random;

public class Leave extends State {

    public Leave() {
    }
    
    @Override
    public void act(Student student, double deltaTime, Data data){    	
    	Random restRand = new Random();
    	int restRandom = restRand.nextInt(500000);
    	if(restRandom == 79) {
    		student.state = new Rest();
    	}
    	
    	Vector2D position = new Vector2D(student.position.x, data.height+200); 
    	Vector2D distVector = new Vector2D(position.x - student.position.x, position.y - student.position.y);
    	distVector.unitise();
    	Vector2D pixelSpeed = student.speed.multiply(new Vector2D(0.0001,0.0001));
    	Vector2D directionVector = distVector.multiply(pixelSpeed);
    	student.position.add(directionVector);
    	if(student.position.y >= data.height+200) {
    		data.entities.remove(student);
    		data.students.remove(student);
    	}
    }
}