#include<iostream>
#include<cmath>

using namespace std;

struct vector{
    double x;
    double y;
};

vector add(vector v1, vector v2){
    vector res{};
    res.x = v1.x + v2.x;
    res.y = v1.y + v2.y;
    return res;
}

vector subtract(vector v1, vector v2){
    vector res{};
    res.x = v1.x - v2.x;
    res.y = v1.y - v2.y;
    return res;
}

void scale(vector& v, float k){
    v.x *= k;
    v.y *= k;
}

double length(vector v){
    return sqrt(pow(v.x, 2) + pow(v.x, 2));
}

void normalize(vector& v){
    double len = 1 / length(v);
    v.x *= len;
    v.y *= len;
}

int main(){
    string operation;
    cout << "Enter operation (add, subtract, scale, length, normalize):" << endl;
    cin >> operation;
    if (operation == "add"){
        vector v1; vector v2;
        cout << "Enter the coordinates of the first vector:" << endl;
        cin >> v1.x >> v1.y;
        cout << "Enter the coordinates of the second vector:" << endl;
        cin >> v2.x >> v2.y;
        vector res = add(v1, v2);
        cout << "Result: (" << res.x << ";" << res.y << ")." << endl;
    } else if (operation == "subtract"){
        vector v1; vector v2;
        cout << "Enter the coordinates of the first vector:" << endl;
        cin >> v1.x >> v1.y;
        cout << "Enter the coordinates of the second vector:" << endl;
        cin >> v2.x >> v2.y;
        vector res = subtract(v1, v2);
        cout << "Result: (" << res.x << ";" << res.y << ")." << endl;
    } else if (operation == "scale"){
        vector v;
        double k;
        cout << "Enter the coordinates of the vector:" << endl;
        cin >> v.x >> v.y;
        cout << "Enter the number:" << endl;
        cin >> k;
        scale(v, k);
        cout << "Result: (" << v.x << ";" << v.y << ")." << endl;
    }else if (operation == "length") {
        vector v;
        cout << "Enter the coordinates of the vector:" << endl;
        cin >> v.x >> v.y;
        cout << "Result: " << length(v) << endl;
    } else if (operation == "normalize") {
        vector v;
        cout << "Enter the coordinates of the vector:" << endl;
        cin >> v.x >> v.y;
        normalize(v);
        cout << "Result: (" << v.x << ";" << v.y << ")." << endl;
    } else{
        cerr << "Unknown operation!" << endl;
    }
}
