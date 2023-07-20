#include <iostream>
#include <exception>
#include <map>

using namespace std;


int adding_product(int basket_count, int store_count){
    if (basket_count > store_count){
        throw invalid_argument("count");
    }
    return store_count - basket_count;
}

void finding_product(const string& product, map<string, int>& shop){
    if (shop.find(product) == shop.end()){
        throw invalid_argument("product");
    }
}

class Basket{
private:
    map<string, int> products;
public:
    map<string, int> get_products(){
        return products;
    }
    void add(const string& product, int count, map<string, int>& shop){
        try{
            finding_product(product, shop);
            int store_count = shop.find(product)->second;
            try{
                shop.find(product)->second = adding_product(count, store_count);
                pair<string, int> new_product;
                new_product.first = product;
                new_product.second = count;
                if (products.find(product) != products.end()){
                    products.find(product)->second += count;
                } else
                    products.insert(new_product);
            }
            catch(const invalid_argument& x) {
                cerr << "Invalid argument supplied: " << x.what() << endl;
            }
        }
        catch (const invalid_argument& x){
            cerr << "Invalid argument supplied: " << x.what() << endl;
        }
    }

    void remove(const string& product, int count){
        try{
            int basket_count = products.find(product)->second;
            try{
                products.find(product)->second = adding_product(count, basket_count);
                if (products.find(product)->second == 0){
                    products.erase(products.find(product));
                }
            }
            catch(const invalid_argument& x) {
                cerr << "Invalid argument supplied: " << x.what() << endl;
            }
        }
        catch (const invalid_argument& x) {
            cerr << "Invalid argument supplied: " << x.what() << endl;
        }
    }
};

void initializing(map<string, int>& shop){
    string product;
    int count;
    cout << "The filling of the store begins" << endl;
    while(product != "exit"){
        cout << "Enter the product name(or 'exit')" << endl;
        cin >> product;
        if (product != "exit"){
            cout << "Enter the count of " << product << endl;
            cin >> count;
            if (count >= 0){
                pair<string, int> new_product;
                new_product.first = product;
                new_product.second = count;
                shop.insert(new_product);
            } else
                cerr << "Invalid argument!" << endl;
        }
    }
    cout << "The filling of the store is over" << endl;
}

int main(){
    map<string, int> shop;
    initializing(shop);
    string input;
    auto* basket = new Basket();
    while (input != "exit"){
        cout << "Enter the type of the operation(add, remove or exit): " << endl;
        cin >> input;
        if (input != "exit"){
            string product;
            int count;
            if (input == "add"){
                cout << "Enter the product: " << endl;
                cin >> product;
                cout << "Enter the count of " << product << ": " << endl;
                cin >> count;
                basket->add(product, count, shop);
            } else if(input == "remove"){
                cout << "Enter the product: " << endl;
                cin >> product;
                cout << "Enter the count of " << product << ": " << endl;
                cin >> count;
                basket->remove(product, count);
            } else
                cerr << "Unknown operation!" << endl;
        }
    }

    if (basket->get_products().empty()){
        cout << "Your basket is empty";
    } else{
        cout << "Your basket: " << endl;
        for (const auto& item : basket->get_products()) {
            cout << item.first << ": " << item.second << endl;
        }
    }
}
