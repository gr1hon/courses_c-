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
class Dog{
private:
    int age;
    string name;
    shared_ptr<Toy> lovelyToy;
public:
    Dog(string _name, const shared_ptr<Toy>& toy, int _age) : name(_name), lovelyToy(toy){
        if (_age >=0 && _age <= 30)
            age = _age;
    }
    Dog() : Dog("Snow", make_shared<Toy>("SomeToy"), 0) {};
    Dog(string _name) : Dog(_name, make_shared<Toy>("SomeToy"), 0) {};
    Dog(int _age) : Dog("Snow", make_shared<Toy>("SomeToy"), _age) {};

    void getToy(shared_ptr<Toy> newToy){
//        cout << newToy.use_count() << endl;
        if (newToy == lovelyToy)
            cout << "I already have this toy." << endl;
        else if (newToy.use_count() != 2)
            cout << "Another dog is playing with this toy." << endl;
        else{
            lovelyToy = newToy;
            cout << "Now I have new toy." << endl;
        }

    }
    void dropToy(){
        if (lovelyToy.use_count() == 2){
            cout << "I drop my toy." << endl;
//            cout << lovelyToy.use_count() << endl;
            lovelyToy.reset();
//            cout << lovelyToy.use_count() << endl;
        } else{
            cout << "Nothing to drop." << endl;
        }
    }

};

int main() {
    shared_ptr<Toy> ball = make_shared<Toy>("Ball");
    shared_ptr<Toy> bone = make_shared<Toy>("Bone");
//    cout << ball.use_count() << " " << bone.use_count() << endl;
    Dog a("A", ball, 3);
    Dog b("B", bone, 2);
    a.getToy(ball);
    a.getToy(bone);
    b.dropToy();
    b.dropToy();
}
