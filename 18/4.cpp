#include <iostream>

using namespace std;

void evendigits(long long n, int& ans){
    if(n >= 10){
        if (n%2 == 0){
            ans += 1;
            evendigits(n/10, ans);
        } else{
            evendigits(n/10, ans);
        }
    } else {
        if (n%2 == 0){
            ans += 1;
        }
    }
}
int main() {
   int ans = 0;
   long long n;
   cout << "Enter number:" << endl;
   cin >> n;
   evendigits(n, ans);
   cout << "Number of even digits - " << ans;
}
