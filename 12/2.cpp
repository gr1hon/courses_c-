//Быстрая сортировка

#include <iostream>

using namespace std;

int partition(float numbers[], int l, int r){
    float m = numbers[(l + r) / 2];
    int i = l;
    int j = r;
    while(i <= j){
        while(numbers[i] > m){
            i++;
        }
        while(numbers[j] < m){
            j--;
        }
        if(i >= j){
            break;
        }
        swap(numbers[i++], numbers[j--]);
    }
    return j;
}

void quicksort(float numbers[], int l, int r){
    if(l < r){
        int q = partition(numbers, l, r);
        quicksort(numbers, l, q);
        quicksort(numbers, q + 1, r);
    }
}

int main(){
    float numbers[15];
    for(int i = 0; i < 15; i++){
        cin >> numbers[i];
    }
    cout << "ok\n";
    quicksort(numbers, 0, 14);
    for(int i = 0; i < 15; i++){
        cout << numbers[i] << " ";
    }
}
