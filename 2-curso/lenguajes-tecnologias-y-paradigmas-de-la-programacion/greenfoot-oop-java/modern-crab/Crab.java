import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Crab extends Actor
{
    int numOfWorms = 0;
    /**
     * Act - do whatever the Crab wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act() 
    {
        getWorld().showText(null, getX(), getY()); //Limpiamos el texto
        move(4);
        if(Greenfoot.isKeyDown("left")) turn(-3);
        if(Greenfoot.isKeyDown("right")) turn(3);
        
        Worm worm = (Worm)getOneObjectAtOffset(0,0,Worm.class);
        if(worm != null) {
            numOfWorms++;
            getWorld().removeObject(worm);
            Greenfoot.playSound("eating.wav");
        }
        
        SpecialWorm specWorm = (SpecialWorm)getOneObjectAtOffset(0,0,SpecialWorm.class);
        if(specWorm != null) {
            numOfWorms++;
            getWorld().removeObject(specWorm);
            Greenfoot.playSound("eating.wav");
            CrabWorld.addTime(10);
        }
        
        getWorld().showText("" + numOfWorms, getX(), getY());
    }
}
