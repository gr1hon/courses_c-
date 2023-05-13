#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;


int main() {
    time_t t = time(nullptr);
    tm start_time = *localtime(&t);
    cout << "Enter the start_time you want to record (MM:SS):" << endl;
    cin >> get_time(&start_time, "%M:%S");
    int seconds = start_time.tm_sec + start_time.tm_min * 60;
    
//    auto start = std::chrono::steady_clock::now();
//    int k = 0;
//    while(k < seconds){
//        auto curr_time = std::chrono::steady_clock::now();
//        if (curr_time - start >= std::chrono::seconds(1)){
//            start = curr_time;
//            k++;
//            cout << k/60 << ":" << k%60 << endl;
//        }
//    }
//    cout << "DING! DING! DING!" << endl;
//    
//    Как я понял, выводить ответ в консоль раз в секунду одной командой (как в питоне time.sleep(1) вроде бы) нельзя.
//    Поэтому придумал еще одно решение без доп библиотек, но оно какое то некрасивое((

    t = time(nullptr);
    time_t curr_time = t;
    int k; int prev = -1;
    while(curr_time - t < seconds){
        curr_time = time(nullptr);
        k = curr_time - t;
        if (prev != k){
            cout << (seconds-k)/60 << ":" << (seconds-k)%60 << endl;
            prev = k;
        }
    }
    cout << "DING! DING! DING!" << endl;
}
