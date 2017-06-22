import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

public class Display extends JPanel {

	private Data data;

	public Display(Data data) {
    	this.data=data;
    	setBackground(Color.WHITE);
    }

    public Dimension getPreferredSize() {
    	return new Dimension(super.getSize().width, super.getSize().height);
    }

    @Override
    public void paintComponent(Graphics g) {

    	super.paintComponent(g);
    	Graphics2D g2d=(Graphics2D)g;
    	
    	this.data.width = getPreferredSize().width;
    	this.data.height = getPreferredSize().height;
    	
    	//turn data information to original in each paint iteration
    	this.data.left = 3;
    	this.data.top = 20;
    	this.data.lineSize = 20;
    	this.data.x = 0;
    	this.data.y = 0;
    	///////////////////////////////////

        //synchronized (this.data){
        	for(AnimationEntity entity: this.data.entities) {
        		entity.draw(g2d);
        	}       	
        //} 
    }
}