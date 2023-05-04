#include <iostream>

using namespace std;

int jumps(int n){
    switch (n) {
        case 0: return 1;
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
        default: return jumps(n-1) + jumps(n-2) + jumps(n-3);
    }
}

int main() {
    int n;
    cout << "Enter step number:\n";
    cin >> n;
    if(n < 0){
        cerr << "Step number must be >= 0!";
    } else if (n >= 37){
        cerr << "Too big number!(number must be <37)";
    }
    cout << jumps(n);
}
