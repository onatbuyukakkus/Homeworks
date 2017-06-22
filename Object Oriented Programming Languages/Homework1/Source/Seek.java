import java.util.Random;

public class Seek extends State {
	
    public Seek() {
    }
    
    @Override
    public void act(Student student, double deltaTime, Data data) {
    	Random restRand = new Random();
    	int restRandom = restRand.nextInt(500000);
    	if(restRandom == 79) {
    		student.state = new Rest();
    	}
    	
		double minDist = Double.MAX_VALUE;
		int minIndex = 0;
    	for(Token token : data.tokens) {
    		double tempDist = student.position.distanceTo(token.position);
    		if(tempDist < minDist) {
    			minDist = tempDist;
    			minIndex = data.tokens.indexOf(token);
    		}
    	}
    	
    	Vector2D distVector = new Vector2D(data.tokens.get(minIndex).position.x - student.position.x, data.tokens.get(minIndex).position.y - student.position.y);
    	distVector.unitise();
    	Vector2D pixelSpeed = student.speed.multiply(new Vector2D(0.0001,0.0001));
    	Vector2D directionVector = distVector.multiply(pixelSpeed);
    	student.position.add(directionVector);
    	if(student.position.distanceTo(data.tokens.get(minIndex).position) <= 15) {
    		
    		student.tokenCount = data.tokens.get(minIndex).getCount();
    		data.entities.remove(data.tokens.get(minIndex));
    		data.tokens.remove(data.tokens.get(minIndex));
    		student.depositFlag = 1;
    		student.previousState = 1;
    		student.state = new Deposit();
    	}
    }
}