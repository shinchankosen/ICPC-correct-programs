#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<(n);i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

template <class T> struct BIT {
    int n;
    vector<T> a;
    BIT(int m) : n(m), a(m + 1, 0) {}
    void add(int x, T y) {
        x ++;
        while(x <= n) {
            a[x] += y;
            x += x & -x;
        }
    }
    T sum(int x) {
        T r = 0;
        while(x > 0) {
            r += a[x];
            x -= x & -x;
        }
        return r;
    }
    T sum(int x, int y) {
        return sum(y) - sum(x);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    while(n) {
        n *= 2;
        BIT<ll> bit(n);
        vector<int> taiou(n);
        vector<vector<int>> v(n);
        vector<int> a(n);
        rep(i, n) {
            cin >> a[i];
            a[i] --;
            v[a[i]].pb(i);
        }
        rep(i, n) {
            int m = (int)v[i].size() / 2;
            rep(j, m) {
                taiou[v[i][j]] = v[i][j + m];
                taiou[v[i][j + m]] = v[i][j];
            }
        }
        ll ans = 0;
        vector<ll> val(n, -1);
        rep(i, n) {
            if(taiou[i] > i) {
                ll num = bit.sum(i, taiou[i]);
                val[i] = num;
                bit.add(taiou[i], 1);
            }
            else bit.add(i, -1);
        }
        for(int i = n - 1; i >= 0; i --) {
            if(taiou[i] < i) {
                ll num = bit.sum(taiou[i], i);
                val[taiou[i]] += num;
                ans += (n - 2) / 2 - val[taiou[i]];
                bit.add(taiou[i], 1);
            } else {
                bit.add(i, -1);
            }
        }
        cout << ans / 2 << endl;
        cin >> n;
    }
    return 0;
}
