#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)

int main() {
    int n; cin >> n;
    while(n) {
        string s; cin >> s;
        string t = s + s;
        for(int i = 1; i < n; i ++) {
            bool ng = 0;
            rep(j, i) {
                if(s[j] != s[n - i + j]) ng = 1;
            }
            if(!ng) t = s.substr(0, n) + s.substr(i, n - i);
        }
        cout << t << endl;
        cin >> n;
    }
    return 0;
}
