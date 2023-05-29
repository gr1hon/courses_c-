#include <iostream>

using namespace std;

class Toy{
public:
    Toy(string _name) : name(_name) {};
    Toy() : name("SomeToy"){};
private:
    string name;
};

class shared_ptr_toy{
private:
    Toy* obj;
    int linksNumber;

public:

    //конструктор
    shared_ptr_toy(Toy* _obj = nullptr){
        linksNumber = 0;
        obj = _obj;
    }

    shared_ptr_toy(string name){
        obj = new Toy(name);
        linksNumber = 0;
    }

//    конструктор копий
    shared_ptr_toy(const shared_ptr_toy& oth){
        obj = oth.obj;
        linksNumber++;
    }
//    оператор присваивания копированием
    shared_ptr_toy& operator=(const shared_ptr_toy& oth){
        obj = oth.obj;
        linksNumber++;
        return *this;
    }
    //деструктор
    ~shared_ptr_toy(){
        if ((obj != nullptr) && (linksNumber == 0)){
            cout << "Delete object" << endl;
            delete[] obj;
        } else{
            cout << "Delete copy" << endl;
            linksNumber--;
        }
    }
};

shared_ptr_toy make_shared_toy(string _name){
    auto* toy = new shared_ptr_toy(_name);
    return *toy;
}

shared_ptr_toy make_shared_toy(const shared_ptr_toy& otherToy){
    auto* toy = new shared_ptr_toy(otherToy);
    return *toy;
}

class Dog{
public:
    Dog(string _name, shared_ptr_toy toy, int _age) : name(_name), lovelyToy(toy){
        if (_age >=0 && _age <= 30)
            age = _age;
    }
    Dog() : Dog("Snow", make_shared_toy("SomeToy"), 0) {};
    Dog(string _name) : Dog(_name, make_shared_toy("SomeToy"), 0) {};
    Dog(int _age) : Dog("Snow", make_shared_toy("SomeToy"), _age) {};

private:
    int age;
    string name;
    shared_ptr_toy lovelyToy;
};


int main() {

    shared_ptr_toy bone1 = make_shared_toy("Bone");
    shared_ptr_toy bone2 = make_shared_toy(bone1);
    shared_ptr_toy ball = make_shared_toy("Ball");
    Dog a("A", ball, 3);
    Dog c("C", ball, 5);
}
