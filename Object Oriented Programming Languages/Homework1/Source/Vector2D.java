import java.util.*;

public class Vector2D {
	
	public double x;
    public double y;
 
    public Vector2D(double x, double y) {
    	this.x = x;
    	this.y = y;
    }

    public int getIntX() {
        return (int) this.x;
    }

    public int getIntY() {
    	return (int) this.y;
    }
    
    public void add(Vector2D vect) {
        this.x += vect.x;
        this.y += vect.y;
    }
    
    public Vector2D multiply(Vector2D vect) {
    	return new Vector2D(vect.x * this.x, vect.y * this.y);
    }

    public double distanceTo(Vector2D vect) {
        return Math.sqrt(Math.pow(this.x - vect.x,2)+Math.pow(this.y - vect.y,2));
    }
    
    public double norm() {
        return Math.sqrt(Math.pow(this.x,2)+Math.pow(this.y,2));
    }
    
    public void unitise() {
    	double len = norm();
    	this.x /= len;
    	this.y /= len;
    }
    
    public static Vector2D randomVector(int xBelow, int xUpper, int yBelow, int yUpper){
    	Random rand = new Random();
    	Random rand2 = new Random();
    	double x = rand.nextInt(xUpper - xBelow) + xBelow;
    	double y = rand2.nextInt(yUpper - yBelow) + yBelow;
    	return new Vector2D(x,y);
    }
}