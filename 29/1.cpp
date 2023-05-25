#include <iostream>
#include <vector>
using namespace std;

class Animal{

public:
    string name;
};

class Talent{

public:
    virtual void invoke() = 0;
};

class Swim: virtual public Talent{

public:
    void invoke() override{
        cout << "It can swim!" << endl;
    }
};

class Dance: virtual public Talent{

public:
    void invoke() override{
        cout << "It can dance!" << endl;
    }
};

class Count: virtual public Talent{

public:
    void invoke() override{
        cout << "It can count!" << endl;
    }
};

class Dog: public Animal{
private:
    vector<Talent*> talents;
public:
    
    Dog(string _name){
        name = _name;
    }

    void addTalentDance(){
        auto* dance = new Dance();
        talents.push_back(dance);
    }

    void addTalentSwim(){
        auto* swim = new Swim();
        talents.push_back(swim);
    }

    void addTalentCount(){
        auto* count = new Count();
        talents.push_back(count);
    }

    void show_talents(){
        cout << "This is " << this->name << " and it has some talents:" << endl;
        for (auto & talent : talents) {
            talent->invoke();
        }
    }

};

int main() {
    string name;
    cout << "Enter the name of the dog:" << endl;
    cin >> name;
    Dog* dog = new Dog(name);
    cout << "Enter the talent of " << dog->name << " (or 'exit')" << endl;
    string talent;
    cin >> talent;
    while(talent != "exit"){
        if (talent == "dance")
            dog->addTalentDance();
        else if (talent == "swim")
            dog->addTalentSwim();
        else if (talent == "count")
            dog->addTalentCount();
        else
            cerr << "Unknown command!" << endl;
        cout << "Enter the talent of " << dog->name <<  " (or 'exit')" << endl;
        cin >> talent;
    }
    dog->show_talents();
}
