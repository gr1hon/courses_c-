//Как я понял из условия, список рыб в реке не изменяется, 
//т.е мы не удаляем оттуда рыб, которых поймали(хотя так было бы логичнее, на мой взгляд)

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream river;
    ofstream basket;
    string fish_type;
    cout << "Enter the type of fish you want to catch:" << endl;
    cin >> fish_type;
    river.open("..\\river.txt");
    if (river.is_open()){
        basket.open("..\\basket.txt", ios::app);
        if (basket.is_open()){
            string fish;
            int count = 0;
            while(getline(river, fish)){
                if (fish == fish_type){
                    count++;
                    basket << fish_type << endl;
                }
            }
            cout << "You caught " << count << " " << fish_type << "!" << endl;
        } else
            cerr << "Output file open error!" << endl;
    } else
        cerr << "Input file open error!" << endl;
    river.close();
    basket.close();
}
