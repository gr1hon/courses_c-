#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<float> prices {2.5, 4.25, 3.0, 10.0};
    vector<int> items {1, 1, 0, 5};
    float sum = 0;
    for (int i = 0; i < items.size(); ++i) {
        if (items[i] >= prices.size()){
            cout << "Ошибка ввода!";
            return 0;
        }
        sum += prices[items[i]];
    }
    cout << "Суммарная стоимость - " << sum;
}
