import java.awt.Graphics2D;

public interface AnimationEntity {
	
    public void draw(Graphics2D g2d);
    public void act(double deltaTime);
}