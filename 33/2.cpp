#include <iostream>
#include <exception>
#include <ctime>
#include <vector>

using namespace std;

class FishIsFoundException: public exception{
    const char* what() const noexcept override{
        return "Congratulations! You caught a fish!";
    }
};

class BootIsFoundException: public exception{
    const char* what() const noexcept override{
        return "Alas, you caught the boot";
    }
};

struct sector{
    bool fish = false;
    bool boot = false;
};

void throwing(sector& s){
    if (s.boot)
        throw BootIsFoundException();
    else if (s.fish)
        throw FishIsFoundException();
    else
        cout << "You didn't catch anything!" << endl;
}
int main(){
    srand(time(nullptr));
    vector<sector> field(9);
    field[std::rand() % 9].fish = true;
    int count = 0;
    while(count < 3){
        int k = std::rand() % 9;
        if (!field[k].fish && !field[k].boot){
            field[k].boot = true;
            count++;
        }
    }
    int attempts = 0;
    while(true){
        int s;
        cout << "Enter the number of sector(from 0 to 8): " << endl;
        cin >> s;
        attempts++;
        try {
            throwing(field[s]);
        }
        catch (const exception& x){
            cerr << x.what() << endl;
        }
        if (field[s].fish){
            cout << "You have spent " << attempts << " attempts" << endl;
            break;
        } else if (field[s].boot){
            cout << "The game is over!" << endl;
            break;
        }
    }
}
