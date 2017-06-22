import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.*;
import javax.imageio.ImageIO;

public class TokenFairy implements AnimationEntity {

	public Data data;
	private double actionTime;
	private int logoChoice;
	public Random rand;
	public String fairyLeftImage = "salt_bae_left.png";
    public String fairyRightImage = "salt_bae_right.png"; 
    public Vector2D position;
    public BufferedImage fairyLogo;
    
    public TokenFairy(Data data) {
    	
    	this.data = data;
    	this.rand = new Random();
    	actionTime = 0;
    	logoChoice = 0;
    	position = Vector2D.randomVector(0, data.width, 100, data.height);
    }
     
    public Token createToken() {
    	
    	Random rand = new Random();
    	int temp = rand.nextInt(3);
    	if(temp == 0) {
    		return this.data.blackFactory.createToken(0, this.data.width, 100, this.data.height);
    	}
    	else if(temp == 1) {
    		return this.data.fakeFactory.createToken(0, this.data.width, 100, this.data.height);
    	}
    	else {
    		return this.data.regularFactory.createToken(0, this.data.width, 100, this.data.height);
    	}
    }

    public void draw(Graphics2D g2d) {
    	
    	try {
    		if(this.logoChoice == 1) {
        		this.fairyLogo = ImageIO.read(new File(fairyLeftImage));
        	}
        	else {
        		this.fairyLogo = ImageIO.read(new File(fairyRightImage));
        	}
    	}
    	catch(Exception e) {
    		e.printStackTrace();
    	}
    	
    	g2d.drawImage(this.fairyLogo, this.position.getIntX(), this.position.getIntY(), fairyLogo.getWidth(), fairyLogo.getHeight(), null);
    }

    public void act(double deltaTime) {
        if(this.actionTime >= deltaTime) {
        	
        	position.x = rand.nextInt(this.data.width);
        	position.y = rand.nextInt(this.data.height - 100) + 100; //en altta cikmasini engelle
        	actionTime = 0;
        	logoChoice = rand.nextInt(2);
        	
        }
        else {
        	this.actionTime+=0.000001;
        	if(this.data.tokens.size() < this.data.maxTokenOnScreen) {
        		for(int i=0; i<this.data.maxTokenOnScreen - this.data.tokens.size(); i++) {
        			Token tempToken = createToken();
        			this.data.tokens.add(tempToken);
        			this.data.entities.add(tempToken);
        		}
        	}
        }
    }
}
