import java.awt.Color;
import java.awt.Graphics2D;

public class Course implements AnimationEntity {

	public String name;
    public Color color;
    public int minTokens;
    public int studentCount;
    private Data data;
    
	public Course(String name, Color color, int minTokens, Data data) {
    	this.name = name;
    	this.color = color;
    	this.minTokens = minTokens;
    	this.data = data;
    	this.studentCount = 0;
    }

	@Override
	public void draw(Graphics2D g2d) {
		    	
		g2d.setColor(this.color);
        g2d.fillRect(this.data.x, this.data.y, this.data.width/this.data.courses.size(), 100);
        
        g2d.setPaint(Color.BLACK);
        g2d.drawRect(this.data.x, this.data.y, this.data.width/this.data.courses.size(), 100);
        
        this.data.x += this.data.width / this.data.courses.size();
        
        g2d.drawString(this.name, this.data.left, this.data.top);
        
        this.data.top += this.data.lineSize;
        g2d.drawString("Min Tokens: " + this.minTokens, this.data.left, this.data.top);
        
        this.data.top += this.data.lineSize;
        g2d.drawString("Students: " + this.studentCount, this.data.left, this.data.top);

        this.data.top = 20;
        this.data.left += this.data.width/this.data.courses.size();
	}
	
	@Override
	public void act(double deltaTime) {
	}
	
	public void studentCounter() {
		this.studentCount ++;
	}
}