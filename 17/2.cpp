#include <iostream>

using namespace std;

void reverse(int* x){
    for (int i = 0; i < 5; ++i) {
        swap(*(x + i), *(x + 9 - i));
    }
}

int main() {
    //Как я понял, указатель на тип int, по которому размещены 10 переменных типа int - это первый элемент массива длины 10
    int arr[] {1,2,3,4,5,6,7,8,9,10};
    reverse(&arr[0]);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
}
