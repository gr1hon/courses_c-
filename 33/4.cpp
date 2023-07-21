#include <iostream>

using namespace std;

template<typename T>
T avg(T array[8]){
    T sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    return sum / 8;
}

template<typename T>
void input(T array[8]){
    cout << "Fill the array (8):" << endl;
    T x;
    for (int i = 0; i < 8; ++i){
        cin >> x;
        array[i] = x;
    }
    cout << "Average value is " << avg(array) << endl;
}



int main(){
    double array[8];
    input<double>(array);
}
