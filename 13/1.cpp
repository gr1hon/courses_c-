#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    vector<int> vec;
    cout << "Input vector size: ";
    cin >> size;
    if(size < 0){
        cout << "Invalid size!";
        return 0;
    }    
    cout << "Input numbers: ";
    int x;
  
    for (int i = 0; i < size; ++i) {
        cin >> x;
        vec.push_back(x);
    }
  
    cout << "Input number to delete: ";
    cin >> x;
  
    for (int i = size - 1; i >= 0; --i) {
        if (vec[i] == x){
            for (int j = i; j < vec.size()-1; ++j) {
                swap(vec[j], vec[j+1]);
            }
            vec.pop_back();
        }
    }
  
    cout << "Result: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
  
}
