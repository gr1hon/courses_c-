#include <iostream>
#include <cassert>
using namespace std;

float travelTime(float distance, float speed){
    assert(speed > 0);
    return distance / speed;
}

int main(){
    cout << travelTime(10, -2);
}
