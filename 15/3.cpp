#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    int number = 0;
    while(number != -2){
        cin >> number;
        if (number != -1){
            vec.push_back(number);
        } else if (vec.size() < 5){
            cout << "Count of vec less than 5!\n";
        } else{
            sort(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); ++i) {
                cout << vec[i] << " ";
            }
            cout << "\n" << vec[4] << "\n";
        }
    }
    cout << "End";

//int partition(vector<int> numbers, int l, int r){
//    int m = numbers[(l + r) / 2];
//    int i = l;
//    int j = r;
//    while(i <= j){
//        while(numbers[i] < m){
//            i++;
//        }
//        while(numbers[j] > m){
//            j--;
//        }
//        if(i >= j){
//            break;
//        }
//        int tmp;
//        tmp = numbers[i];
//        numbers[i++] = numbers[j];
//        numbers[j--] = tmp;
//    }
//    return j;
//}
//
//void quicksort(vector<int> numbers, int l, int r){
//    if(l < r){
//        int q = partition(numbers, l, r);
//        quicksort(numbers, l, q);
//        quicksort(numbers, q + 1, r);
//    }
//}

int main(){
    cout << "123";
}



//int main(){
//    vector<int> vec;
//    int number = 0;
//    while(number != -2){
//        cin >> number;
//        if (number != -1){
//            vec.push_back(number);
//        } else if (vec.size() < 5){
//            cout << "Count of vec less than 5!\n";
//        } else{
//            quicksort(vec, 0, vec.size()-1);
//            for (int i = 0; i < vec.size(); ++i) {
//                cout << vec[i] << " ";
//            }
//            cout << "\n" << vec[4] << "\n";
//        }
//    }
//    cout << "End";
//}
