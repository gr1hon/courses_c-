#include <iostream>
#include <string>

using namespace std;

int main(){
    string flat[10];
    for(int i = 0; i < 10; i++){
        cin >> flat[i];
    }
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        if(n > 0 && n < 11){
            cout << flat[n-1] << endl;
        } else{
            cout <<"Invalid number!" << endl;
            i--;
        }
    }
}
