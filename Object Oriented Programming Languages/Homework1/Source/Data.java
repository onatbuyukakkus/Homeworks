import java.awt.Color;
import java.util.*;


public class Data {

    public int width;
    public int height;
    public TokenFairy fairy;
    public List<Token> tokens;
    public List<Course> courses;
    public List<Student> students;
    public List<AnimationEntity> entities;
    public BlackFactory blackFactory;
    public FakeFactory fakeFactory;
    public RegularFactory regularFactory;
    public int maxTokenOnScreen = 25;
    public int left = 3;
    public int top = 20;
    public int lineSize = 20;
    public int x = 0;
    public int y = 0;
    
    public Data(int windowWidth, int windowHeight) {
    	this.width = windowWidth; 
    	this.height = windowHeight;
    	    	
    	this.tokens = new ArrayList<Token>();
    	this.courses = new ArrayList<Course>();
    	this.students = new ArrayList<Student>();
    	this.entities = new ArrayList<AnimationEntity>();
    	this.blackFactory = new BlackFactory();
    	this.fakeFactory = new FakeFactory();
    	this.regularFactory = new RegularFactory();
    	
    	courses.add(new Course("CENG 443", new Color(Color.HSBtoRGB(0.03F, 1.0F, 1.0F)), 80, this));
        courses.add(new Course("CENG 451", new Color(Color.HSBtoRGB(0.155F, 1.0F, 1.0F)), 20, this));
        courses.add(new Course("CENG 462", new Color(Color.HSBtoRGB(0.28F, 1.0F, 1.0F)), 10, this));
        courses.add(new Course("CENG 476", new Color(Color.HSBtoRGB(0.405F, 1.0F, 1.0F)), 10, this));
        courses.add(new Course("CENG 478", new Color(Color.HSBtoRGB(0.53F, 1.0F, 1.0F)), 10, this));
        courses.add(new Course("CENG 495", new Color(Color.HSBtoRGB(0.655F, 1.0F, 1.0F)), 33, this));
        courses.add(new Course("CENG 497", new Color(Color.HSBtoRGB(0.78F, 1.0F, 1.0F)), 10, this));
        courses.add(new Course("CENG 499", new Color(Color.HSBtoRGB(0.905F, 1.0F, 1.0F)), 55, this));
        
        students.add(new BasicStudent("Abdulkadir", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Abdüllatif", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Afşin Buğra", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ahmet Alperen", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ahmet Selim", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Alihan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Alperen", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Andi", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ata", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Aybars Kerem", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Barış", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Barış Çağlar", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Batyr", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Berker", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Buğrahan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Burak", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Cantürk", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Doğuhan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Doğukan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ebru İpek", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Efecan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Enver", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Erbil", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Erinç", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ermek", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ertuğ", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Furkan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Gökhan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Halim Görkem", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Hasan Ali", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Ibrahim Bakarr", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("İlke", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("İzzet Barış", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Kadir Berkay", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Kadir Cenk", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mehmet", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mehmet Ali", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mehmet Can", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mehmet Sait", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Melisa İdil", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mert", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mert", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Mert", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Merve", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Metehan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Muhammet", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Oğuz", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Okan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Onat", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Onur", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Onur Ozan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Özgü", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Pınar", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Recep Fırat", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Recep Gün", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Sait Burak", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Sercan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Sercan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Sinan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Şükrü", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Tolga", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Tolgahan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Tuğçe Alara", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Uğur", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Uğurcan", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Yasin Berk", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        students.add(new BasicStudent("Yiğit", Vector2D.randomVector(0, width, 100, height), new Seek(), this));
        
        fairy = new TokenFairy(this);
        
        entities.addAll(courses);
        entities.addAll(students);
        entities.add(fairy);
        
        for(int i=0; i<maxTokenOnScreen; i++) {
        	Token tempToken = fairy.createToken();
        	tokens.add(tempToken);
        	entities.add(tempToken);
        }
    }
    
    
    public synchronized void stepAll(double deltaTime) {
    	for(AnimationEntity entity: entities) {
    		entity.act(deltaTime);
    	}
    }
}