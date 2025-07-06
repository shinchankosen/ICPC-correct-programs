#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<(n);i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll arcin() {
    string s; cin >> s;
    ll sum = 0;
    int id = -1;
    rep(i, 4) {
        if(s[i] == '.') {
            id = i + 1;
            break;
        }
        sum *= 10;
        sum += (s[i] - '0');
    }
    for(int i = id; i <= id + 8; i ++) {
        sum *= 10;
        sum += (s[i] - '0');
    }
    return sum;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    while(n) {
        ll m;
        vector<ll> a(n);
        rep(i, n) a[i] = arcin();
        cin >> m;
        vector<ll> b(m);
        rep(i, m) b[i] = arcin();
        ll base = 180000000000LL;
        set<ll> st;
        st.insert(n + m + 2);
        rep(i, n) rep(j, m) {
            ll cnt = n + m + 1;
            ll sum1 = base - a[i], sum2 = base - b[j];
            ll x = (i + 1) % n; ll y = (j + 1) % m;
            while(x != i and y != j) {
                if(sum1 == sum2) {
                    cnt --;
                    sum1 += base - a[x];
                    sum2 += base - b[y];
                    x ++; y ++;
                    if(x >= n) x = 0;
                    if(y >= m) y = 0;
                } else if(sum1 < sum2) {
                    sum1 += base - a[x];
                    x ++;
                    if(x >= n) x = 0;
                } else {
                    sum2 += base - b[y];
                    y ++;
                    if(y >= m) y = 0;
                }
            }
           
            st.insert(cnt);
        }
        foa(e, st) cout << e << " ";
        cout << endl;
        cin >> n;
    }
    return 0;
}
