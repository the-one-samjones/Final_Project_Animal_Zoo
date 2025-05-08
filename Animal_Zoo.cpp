/*
Create classes representing a zoo management system.
    Create a class "Animal" with these attributes:
        name (String)
        age (int)
        species (a const string initialized via constructor, representing a final field)
        a Diet object 
        a Habitat object
    Include these functions of an animal
        makeSound();
        eat();
    Provide a construct in "Animal class that initializes name, age, species, diet and habitat with "this" pointer
    Create two subclasses of Animal (Lion, Elephant, Dog)
    Instantiate at least two of each animal type (Two lions, two dogs)

Create a Zoo Collection using vector<Animal*> to store animals
Add each animal to the collection
Create a function "makeAllAnimalsSound()" to iterate through the zoo and call makeSound() for each animal
In the Animal class, declare a final method "displayInfo()" that prints out all of the animals attributes

Create a Diet class with an attribute and an appropriate getter
Same for Habitat

Resulting Final Code Should
    Define the class Animal with required attributes, constructor, and virtual methods
    Create Diet and Habitat classes included as member variables in Animal Class
    Implement the Lion and Elephant classes, ensuring the implement the virtual functions
    use vector<Animal*> to manage the zoo
    In the main() function:
        Instantiate animals of different types
        Add them to the zoo collection
        call "makeAllAnimalsSound()" to demonstrate polymorphism
        Call displayInfo() on each animal to demonstrate use of the final method and display the has-a data
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Diet {
    public:
    string diet;
    Diet () {
        diet = "Unknown";
    }
    Diet (const string& diet) {
        this->diet = diet;
    }
};

class Habitat {
    public:
    string habitat;
    Habitat() {
        habitat = "Unknown";
    }
    Habitat (const string& habitat) {
        this->habitat = habitat;
    }

};

class Animal {
    public:
    string species;
    string name;
    int age;
    Diet diet;
    Habitat habitat;
    Animal(const string name, const string& species, int age, const string& diet, const string& habitat) {
        this->species = species;
        this->name = name;
        this->age = age;
        this->diet = Diet(diet);
        this->habitat = Habitat(habitat);
    }
    virtual void makeSound(){
        cout << "This Animal Makes a sound.";

    };
    virtual void eat(){
        cout << "This Animal Eats.";
    };

    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Age: " << age << endl;
        cout << "Diet: " << Animal::diet.diet << endl;
        cout << "Habitat: " << Animal::habitat.habitat << endl;
        cout << endl;
    }

};

class Seal : public Animal{
    public:
    Seal(const string& name, const string& species, int age, const string& diet, const string& habitat) 
        : Animal(name, species, age, diet, habitat){}
    
    void makeSound() override {
        cout << "Arf! Arf!" << endl;
    }
    void eat() override {
        cout << name << " Eats: " << Seal::diet.diet << endl;
    }
};

class Quaker : public Animal{
    public:
    Quaker(const string& name, const string& species, int age, const string& diet, const string& habitat)
        : Animal(name, species, age, diet, habitat){}

    void makeSound() override {
        cout << "Tweet! Tweet!" << endl;
    }
    
    void eat() override {
        cout << name << " Eats seeds." << endl;
    }
};

vector<Animal*> animalList;

void makeAllAnimalSound(){
    for (Animal* animal : animalList){
        animal->makeSound();
    }
}

int main() {
    Seal mySeal("Sammy", "Seal", 2, "Mainly fish, but Sammy enjoys oranges as well.", "Ocean");
    Quaker myQuaker("Sunny", "Bird", 5, "Seeds", "Jungle");
    animalList.push_back(&mySeal);
    animalList.push_back(&myQuaker);
    mySeal.displayInfo();
    myQuaker.displayInfo();
    makeAllAnimalSound();
}











    /*cout << myAnimal.species << endl;
    cout << myAnimal.name << endl;
    cout << myAnimal.diet.diet << endl;
    cout << myAnimal.age << endl;
    cout << myAnimal.habitat.habitat << endl;*/




