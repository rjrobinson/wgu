package com.example.rrapplicationmain;

import animal.Animal;
import animal.Dog;
import animal.Cat;

public class RRApplicationMain {

    //    @ param args the command line arguments
    public static void main(String[] args) {
        // Call static members

        Animal.setSeller("Petco");

        System.out.println(Animal.getSeller());

        Dog dog = new Dog(null, null, 0.0,0);
        Cat cat = new Cat(null, null, 0.0,0);

        System.out.println(dog.getSeller());
        System.out.println(cat.getSeller());
    }
}