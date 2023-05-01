#include <iostream>

using namespace std;

int main() {
    float speed = 0;
    float dif;
    do{
        char output[10];
        cout << "Input speed difference:\n";
        cin >> dif;
        if (speed + dif > 150){
            speed = 150;
        } else if (speed + dif < 0){
            speed = 0;
        } else{
            speed += dif;
        }
        std::sprintf(output, "%.1f", speed);
        cout << output << " km/h\n";
    } while(speed > 0.01);
}
