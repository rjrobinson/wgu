package animal;

public class Cat extends Animal{

    private String sound;

    public Cat(String behavior, String breed, double price, int lifespan) {
        super(behavior, breed, price, lifespan);
    }

    public String getSound() {
        return "Meow!";
    }

    public void setSound(String sound) {
        this.sound = sound;
    }

    public void setSound(String sound, String otherSound) {
        this.sound = sound;
    }

}
