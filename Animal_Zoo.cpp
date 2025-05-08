#include <iostream>                 //Include libraries
#include <string>
#include <vector>
using namespace std;                //Automatically using std::, allowing for simpler more understandable code

class Diet {                        //Create Diet Class
    public:
    string diet;
    Diet () {                       //Creates Diet default value
        diet = "Unknown";
    }
    Diet (const string& diet) {       //Adds availability to enter custom diets, as defined in the Animal class
        this->diet = diet;
    }
};

class Habitat {                     //Create Habitat Class
    public:
    string habitat;
    Habitat() {                         //Habitat default
        habitat = "Unknown";
    }
    Habitat (const string& habitat) {       //Adds availability to enter custom habitat, as defined in the Animal class
        this->habitat = habitat;
    }

};

class Animal {              //Define Animal Class
    public:                 //Everything in the class stays public
    string species;         //Create Animal attributes 
    string name;
    int age;
    Diet diet;
    Habitat habitat;
    Animal(const string name, const string& species, int age, const string& diet, const string& habitat) {      //Animal constructor; also 
        this->species = species;                                                  //providing template for how to enter Animal information
        this->name = name;                          //Assigns entered Animal values from the constructor to actual member variables in Animal class
        this->age = age;
        this->diet = Diet(diet);
        this->habitat = Habitat(habitat);
    }
    virtual void makeSound(){                       //Default Animal 'makeSound' function, virtual to allow polymorphism
        cout << "This Animal Makes a sound.";

    };
    virtual void eat(){                             //Default Animal 'eat' function, virtual to allow polymorphism
        cout << "This Animal Eats.";
    };

    virtual void displayInfo() final {              //'displayInfo()' function to display an Animal object's different attributes
        cout << "Name: " << name << endl;           //Final to avoid confusion, and to provide consistent output formats from
        cout << "Species: " << species << endl;     //Animal type objects
        cout << "Age: " << age << endl;
        cout << "Diet: " << Animal::diet.diet << endl;
        cout << "Habitat: " << Animal::habitat.habitat << endl;
        cout << endl;
    }

};

class Seal : public Animal{         //Create Seal class, inheriting from Animal
    public:
    Seal(const string& name, const string& species, int age, const string& diet, const string& habitat)     //Create Seal constructor, 'inheriting' the same format
        : Animal(name, species, age, diet, habitat){}                                                       //as Animal class objects

    void makeSound() override {                       //Defines and overrides 'makeSound' function in the Animal class, ensuring the seal sound is used
        cout << "Arf! Arf!" << endl;
    }
    void eat() override {                             //Defines and overrides 'eat' function in the Animal class, ensuring the Seal eating is used
        cout << name << " Eats: " << Seal::diet.diet << endl;
    }
};

class Bird : public Animal{          //Create Quaker class, inheriting from Animal
    public:
    Bird(const string& name, const string& species, int age, const string& diet, const string& habitat)   //Create Quaker constructor, 'inheriting' the same format
        : Animal(name, species, age, diet, habitat){}                                                       //as Animal class objects

    void makeSound() override {         //Defines and overrides 'makeSound' function in the Animal class, ensuring the Quaker sound is made
        cout << "Tweet! Tweet!" << endl;
    }
    
    void eat() override {               //Defines and overrides 'eat' function in the Animal class, ensuring the Quaker eating effect is used
        cout << name << " Eats seeds." << endl;
    }
};

vector<Animal*> animalList;         //Create the vector containing the Animals in the Zoo

void makeAllAnimalSound(){          //Function for making all of the animals sound individually
    for (Animal* animal : animalList){
        animal->makeSound();
    }
}

int main() {
    Seal mySeal("Sammy", "Harbor Seal", 2, "Fish, Crustaceans, Mollusks, and Squid", "North Atlantic & Pacific Oceans");   //Creates two of each animal type
    Bird Quaker("Sunny", "Albino Quaker", 5, "Fruits, nuts, and Seeds", "Open Savabnnas, Palm Groves, Scrub Forests");
    Seal greySeal("Sally", "Grey Seal", 3, "Fish, Sand Eels, Cod", "North Atlantic Ocean");
    Bird Macaw("Simon", "Hyacinth Macaw", 1, "Palm Nuts, Fruits, Nectar, Other Vegetables", "Palm Swamps and Flooded Grasslands");
    animalList.push_back(&mySeal);                          //Adds animals to the Zoo (animalList vector)
    animalList.push_back(&Quaker);
    animalList.push_back(&greySeal);
    animalList.push_back(&Macaw);
    Macaw.displayInfo();                                //Displays information for each animal when called
    mySeal.displayInfo();
    greySeal.displayInfo();
    Quaker.displayInfo();
    makeAllAnimalSound();                               //Sounds all of the animals individually as they appear int animalList vector
}