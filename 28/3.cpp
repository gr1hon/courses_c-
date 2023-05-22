#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

using namespace std;

mutex cooking;
mutex dishes_access;
int delivery = 0;
vector<string> dishes;

string getOrder(){
    string dish;
    cout << "Enter the dish you want to order(pizza, soup, steak, salad or sushi): " << endl;
    do {
        cin >> dish;
        if (dish != "pizza" &&
            dish != "soup" &&
            dish != "steak" &&
            dish != "salad" &&
            dish != "sushi")
            cout << "Incorrect dish, please, try again!" << endl;
        else return dish;
    } while(dish != "pizza" &&
            dish != "soup" &&
            dish != "steak" &&
            dish != "salad" &&
            dish != "sushi");
}

void cookingDish(string dish){
    cooking.lock();
    cout << "The " << dish << " is cooking" << endl;
    int k = rand() % 11 + 5;
    this_thread::sleep_for(chrono::seconds(k));
    cout << "The " << dish << " is ready" << endl;
    dishes_access.lock();
    dishes.push_back(dish);
    dishes_access.unlock();
    cooking.unlock();
}

void deliveryOrders(){
    this_thread::sleep_for(chrono::seconds(15));
    while (delivery < 5){
        int k = (int) dishes.size();
        if (k > 0){
            cout << "The courier took " << k << " ready orders" << endl;
            dishes_access.lock();
            dishes.clear();
            dishes_access.unlock();
            this_thread::sleep_for(chrono::seconds(15));
            cout << "The courier delivered " << k << " orders" << endl;
            delivery += k;
            cout << "Total orders delivered: " << delivery << endl;
        }
    }
}

int main() {
    srand(time(nullptr));
    thread courier(deliveryOrders);
    while(delivery < 5){
        string dish = getOrder();
        thread newOrder(cookingDish, dish);
        newOrder.detach();
        if (delivery >= 5){
            courier.join();
            cout << "Total orders delivered: " << delivery << ". End" << endl;
            return 0;
        }
        int n = ::rand() % 6 + 5;
        this_thread::sleep_for(chrono::seconds(n));
        if (newOrder.joinable()) newOrder.join();
    }
    courier.join();
    cout << "Total orders delivered: " << delivery << ". End" << endl;
}
