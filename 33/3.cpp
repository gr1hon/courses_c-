#include <iostream>
#include <vector>

using namespace std;


template<typename T1, typename T2>
class MyMap{
private:
    vector<pair<T1,T2>> vec;
public:
    void add(T1 new_key, T2 new_value){
        vec.emplace_back(new_key,new_value);
    }

    void remove(T1 key){
        for(auto it = vec.begin(); it != vec.end(); ++it){
            if (it->first == key){
                vec.erase(it);
                it = vec.begin();
            }
        }
    }

    void print(){
        for(auto& elem: vec){
            cout << elem.first << " : " << elem.second << endl;
        }
    }

    void find(T1 key){
        for(auto& elem: vec){
            if (elem.first == key){
                cout << elem.second << endl;
            }
        }
    }
};


int main(){
    MyMap<string, int> map;
    map.add("apple", 6);
    map.add("banana", 3);
    map.add("orange", 11);
    map.add("apple", 30);
    map.print();
    map.find("apple");
    map.remove("orange");
    map.print();
}
