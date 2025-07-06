#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

using ld = long double;
void chmin(ld &a, ld b) { a = min(a, b); }
void chmax(ld &a, ld b) { a = max(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n) {
        vector<int> flag;
        vector<ld> p(n);
        rep(i, n) {
            string s;
            cin >> s;
            flag.pb(s == "Ally");
            cin >> p[i];
        }
        reverse(all(p));
        reverse(all(flag));
        vector<ld> dp(n + 1, ld(1));
        ld one = (ld)1;
        rep(i, n) {
            vector<ld> nx(n + 1, ld(0));
            if(flag[i]) {
                for(int j = 0; j <= n; j ++) {
                    if(j != 0) nx[j - 1] += dp[j] * p[i];
                    nx[j] += dp[j] * (one - p[i]);
                }
            } else {
                for(int j = 0; j <= n; j ++) {
                    if(j != 0) chmax(nx[j], dp[j - 1]);
                    chmax(nx[j], dp[j] * (one - p[i]));
                }
            }
            swap(nx, dp);
        }
        dout(dp[0]);
        cin >> n;
    }
    return 0;
}
