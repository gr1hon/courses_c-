    #include <iostream>
    #include <memory>
    //#include <memory>

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
        Toy *obj;
        int linksNumber = 1;
        int* p_linksNumber = &linksNumber;

    public:

        //конструктор
        shared_ptr_toy(Toy *_obj = nullptr){
            cout << "constr1 " << *this->p_linksNumber << " " << linksNumber << endl;
            obj = _obj;
        }

        shared_ptr_toy(string name){
            cout << "constr2 " << *this->p_linksNumber << " " << linksNumber << endl;
            obj = new Toy(name);

        }

    //    конструктор копий
        shared_ptr_toy(const shared_ptr_toy& oth){
            obj = oth.obj;
    //        cout << "copy " << *p_linksNumber << " " << linksNumber << endl;
            ++(*this->p_linksNumber);
            cout << "copy " << *this->p_linksNumber << " " << linksNumber << endl;
        }
    //    оператор присваивания копированием
        shared_ptr_toy& operator=(const shared_ptr_toy& oth){
            obj = oth.obj;
            ++(*this->p_linksNumber);
            cout << "= " << *this->p_linksNumber << " " << linksNumber << endl;
            return *this;
        }
    //    деструктор
        ~shared_ptr_toy(){
            if ((*this->p_linksNumber) == 0){
                cout << "Delete object" << endl;
                delete obj;
            } else{
                --(*this->p_linksNumber);
                cout << "Delete copy "  << *this->p_linksNumber << " " << linksNumber << endl;
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
        Dog(string _name, const shared_ptr_toy& toy, int _age) : name(_name), lovelyToy(toy){
            if (_age >=0 && _age <= 30)
                age = _age;
        }
        Dog() : Dog("Snow", make_shared_toy("SomeToy"), 0) {};
        Dog(string _name) : Dog(_name, make_shared_toy("SomeToy"), 0) {};
        Dog(int _age) : Dog("Snow", make_shared_toy("SomeToy"), _age) {};
    };

    int main() {
    //    Test* test  = new Test();
    //    test->set_count(4);
    //    test->print();
    //    delete test;
        cout << "start" << endl;
    //    shared_ptr_toy bone1 = make_shared_toy("Bone");
        shared_ptr_toy ball = make_shared_toy("Ball");
    //    shared_ptr_toy bone = make_shared_toy(ball);
        Dog a("A", ball, 3);
    //    Dog c("C", ball, 5);
        cout << "end" << endl;
        std::shared_ptr<Toy> lovelyToy;
    }
