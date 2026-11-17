import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class CrabWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class CrabWorld extends World
{
    public static int getRandomNumber(int start, int end){
        int normal = Greenfoot.getRandomNumber(end-start+1);
        return normal+start;
    }
    
    public static int mToMs(int minutes, int seconds){
        int mili = minutes*6000 + seconds*100;
        return mili;
    }
    
    public static void addTime(int secs){
        time+=secs*100;
    }
    
    static int numWorms = getRandomNumber(5,15);
    static int specWorms = getRandomNumber(1,5);
    static int time = mToMs(0,2);
    

    /**
     * Constructor for objects of class CrabWorld.
     * 
     */
    public CrabWorld()
    {    
        super(560, 560, 1);
        
        for(int i = 0; i<numWorms-specWorms; i++){
            addObject(new Worm(), getRandomNumber(60,500), getRandomNumber(60,500));
        }
        for(int i = 0; i<specWorms; i++){
            addObject(new SpecialWorm(), getRandomNumber(60,500), getRandomNumber(60,500));
        }
        addObject(new Crab(), 560/2, 560/2);
    }
    
    public void act(){
        
        time--;
        if(time%6000/100 < 10){
            showText(time/6000+":0"+time%6000/100, 30, 15);
        }else{
            showText(time/6000+":"+time%6000/100, 30, 15);
        }
        if(time == 0){
            showText("¡Se ha agotado el tiempo!", 560/2, 560/2);
            Greenfoot.stop();
        }
    }
}
