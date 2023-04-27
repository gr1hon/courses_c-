#include <iostream>

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int sum = 0;
    int min = INT_MAX;
    for (int i = 0; i < 15; ++i) {
        sum += numbers[i];
        if( numbers[i] < min){
            min = numbers[i];
        }
    }
    std::cout << sum - 14 * min - 13 * 7 << std::endl;
    return 0;
}
