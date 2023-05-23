#include <iostream>

using namespace std;

class Animal{

public:
    string name;
};

class Talent{

public:
    virtual void swimming() = 0;

    virtual void dancing() = 0;

    virtual void counting() = 0;
};

class Swim: virtual public Talent{

public:
    virtual void swimming(){
        cout << "Swim!" << endl;
    }
    bool canSwimming = false;
};

class Dance: virtual public Talent{

public:
    virtual void dancing(){
        cout << "Dance!" << endl;
    }
    bool canDancing = false;
};

class Count: virtual public Talent{

public:
    virtual void counting(){
        cout << "Count!" << endl;
    }
    bool canCounting = false;
};

class Dog: public Animal,
            virtual public Count,
            virtual public Dance,
            virtual public Swim{

public:

    Dog(string _name){
        name = _name;
    }

    void addTalentDance(){
        if (!this->canDancing){
            this->Dance::dancing();
            this->canDancing = true;
        } else
            cout << this->name << " can already dance!" << endl;
    }

    void addTalentSwim(){
        if (!this->canSwimming){
            this->Swim::swimming();
            this->canSwimming = true;
        } else
            cout << this->name << " can already swim!" << endl;
    }

    void addTalentCount(){
        if (!this->canCounting){
            this->Count::counting();
            this->canCounting = true;
        } else
            cout << this->name << " can already count!" << endl;
    }

    void show_talent(){
        cout << "This is " << this->name << " and it has some talents:" << endl;
        if (this->canCounting)
            cout << "It can count" << endl;
        if (this->canSwimming)
            cout << "It can swim" << endl;
        if (this->canDancing)
            cout << "It can dance" << endl;
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
    dog->show_talent();
}
