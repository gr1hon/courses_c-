#include <iostream>

using namespace std;

int jumps(int n, int k = 3){
    if (k==3){
        switch (n) {
            case 0: return 1;
            case 1: return 1;
            case 2: return 2;
            case 3: return 4;
            default: return jumps(n-1) + jumps(n-2) + jumps(n-3);
        }
    }
    else{
        if (n > 0 && k == 0){
            return 0;
        } else if (n == 0 && k >= 0){
            return 1;
        } else if (n < k){
            int ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans += jumps(n-i, n);
            }
            return ans;
        } else {
            int ans = 0;
            for (int i = 1; i <= k; ++i) {
                ans += jumps(n-i, k);
            }
            return ans;
        }
    }
}

int main() {
    int n; int k = -1;
    cout << "Enter step number and max length of jump(enter -1 to use the default jump value):\n";
    cin >> n >> k;
    if(n < 0){
        cerr << "Step number must be >= 0!";
        return 0;
    }
    if (k != -1 && k < 0){
        cerr << "Max length must be >=0";
        return 0;
    }
    if (k == -1){
        cout << jumps(n);
    } else cout << jumps(n,k);
}
