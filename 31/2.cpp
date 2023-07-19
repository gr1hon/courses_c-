#include <iostream>
#include <memory>

using namespace std;

class Toy {
public:
    Toy(const string& name) {
        name_ = name;
    }
    std::string getName() {
        return name_;
    }
    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }
private:
    std::string name_;
};

class shared_ptr_toy{
private:
    Toy* obj;
    int linksNumber = 0;
    int* p_linksNumber = &linksNumber;

public:

    //конструктор
    shared_ptr_toy(Toy *_obj = nullptr){
        ++(*p_linksNumber);
        obj = _obj;
    }

    shared_ptr_toy(string name){
        obj = new Toy(name);
        ++(*p_linksNumber);
    }

    //    конструктор копий
    shared_ptr_toy(const shared_ptr_toy& oth){
        obj = oth.obj;
        ++(*oth.p_linksNumber);
        ++(*p_linksNumber);
//        cout << "copy " << linksNumber << " "  << obj->getName() << endl;
    }

    //    оператор присваивания копированием
    shared_ptr_toy& operator=(const shared_ptr_toy& oth){
//        ++(*oth.p_linksNumber);
        obj = oth.obj;
        ++(*p_linksNumber);
        return *this;
    }

    //    деструктор
    ~shared_ptr_toy(){
        --(*p_linksNumber);
        if (*p_linksNumber == 0){
            cout << "Delete object" << endl;
            delete obj;
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
private:
    int age;
    string name;
    shared_ptr_toy lovelyToy;
public:
    Dog(string _name, const shared_ptr_toy toy, int _age) : name(_name), lovelyToy(toy){
        if (_age >=0 && _age <= 30)
            age = _age;
    }
    Dog() : Dog("Snow", make_shared_toy("SomeToy"), 0) {};
    Dog(string _name) : Dog(_name, make_shared_toy("SomeToy"), 0) {};
    Dog(int _age) : Dog("Snow", make_shared_toy("SomeToy"), _age) {};

};

int main() {
    shared_ptr_toy ball = make_shared_toy("Ball");
    shared_ptr_toy bone = make_shared_toy("Bone");
//    shared_ptr_toy ball_copy = make_shared_toy(ball);
    Dog* a = new Dog("A", ball, 3);
    delete a;
}
