public class Rest extends State {

	double actionTime = 0;
    
	public Rest() {
    }
    
    @Override
    public void act(Student student, double deltaTime, Data data){
    	if(this.actionTime >= deltaTime) {
        	
        	if(student.previousState == 0) {
        			student.state = new Seek();
        	}
        	else if(student.previousState == 1) {
    			student.state = new Deposit();
        	}
        	else if(student.previousState == 2) {
    			student.state = new Leave();
        	}
        	actionTime = 0;
        }
        else this.actionTime+=0.00001;
    }
}