package animal;

public abstract class Animal {

    private static String seller;

    public static String getSeller() {
        return seller;
    }

    public static void setSeller(String seller) {
        Animal.seller = seller;
    }

    private String behavior, breed;
    private double price;
    private int lifespan;

    public Animal(String behavior, String breed, double price, int lifespan) {
        this.behavior = behavior;
        this.breed = breed;
        this.price = price;
        this.lifespan = lifespan;
    }

    public String getBehavior() {
        return behavior;
    }

    public void setBehavior(String behavior) {
        this.behavior = behavior;
    }

    public String getBreed() {
        return breed;
    }

    public void setBreed(String breed) {
        this.breed = breed;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getLifespan() {
        return lifespan;
    }

    public void setLifespan(int lifespan) {
        this.lifespan = lifespan;
    }
}
