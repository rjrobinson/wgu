package animal;

public class Dog extends Animal {

    private String sound;

    public Dog(String behavior, String breed, double price, int lifespan) {
        super(behavior, breed, price, lifespan);
    }

    public void setSound(String sound) {
        this.sound = sound;
    }

    public String getSound() {
        return "Woof!";
    }
}

