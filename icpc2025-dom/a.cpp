#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n) {
        int sum = 0;
        for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) sum += i * j;
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}
