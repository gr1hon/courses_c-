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
    int* p_linksNumber;

public:

    //конструктор
    shared_ptr_toy(Toy *_obj = nullptr){
        *p_linksNumber = 1;
        obj = _obj;
    }

    shared_ptr_toy(string name){
        obj = new Toy(name);
        *p_linksNumber = 1;
    }

    //    конструктор копий
    shared_ptr_toy(const shared_ptr_toy& oth){
        obj = oth.obj;
        ++(*p_linksNumber);
        cout << "copy " << *p_linksNumber << " " << endl;
    }

    //    оператор присваивания копированием
    shared_ptr_toy& operator=(const shared_ptr_toy& oth){
        obj = oth.obj;
        ++(*p_linksNumber);
        cout << "= " << *p_linksNumber << " " << endl;
        return *this;
    }

    //    деструктор
    ~shared_ptr_toy(){
        if (*p_linksNumber == 0){
            cout << "Delete object" << endl;
            delete obj;
        } else{
            --(*p_linksNumber);
            cout << "Delete copy "  << *p_linksNumber << " " << endl;
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
    Dog a("A", ball, 3);
}
