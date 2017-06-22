public abstract class State {

    public State() {
    }

    public abstract void act(Student student, double deltaTime, Data data);
}