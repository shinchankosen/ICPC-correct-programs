#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    while(n) {
        vector<ll> a(n);
        rep(i, n) {
            cin >> a[i];
        }
        ll sum = m / 7;
        sum *= 5;
        sum += min(m % 7, 5LL);
        set<ll> st;
        foa(e, a) {
            if(e % 7 == 6LL or e % 7 == 0) continue;
            if(e > m) continue;
            st.insert(e);
        }
        sum -= st.size();
        cout << sum << endl;
        cin >> n >> m;
    }
    return 0;
}
