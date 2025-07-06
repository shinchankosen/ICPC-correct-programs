#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<(n);i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    while(n) {
        string s; cin >> s;
        vector<int> exle(n, 0), exri(n, 0);
        ll ans = 0;
        for(int i = 1; i < n; i ++) {
            if(s[i] == s[i - 1]) {
                int j = i - 2;
                if(s[i] == '(') {
                    exle[i] = exle[i - 1] = 1;
                    while(j >= 0 and !exle[j]) {
                        if(s[j] == s[j + 1]) break;
                        exle[j] = 1;
                        j --;
                    }
                } else {
                    exri[i] = exri[i - 1] = 1;
                    while(j >= 0 and !exri[j]) {
                        if(s[j] == s[j + 1]) break;
                        exri[j] = 1;
                        j --;
                    }
                }
                j = i + 1;
                if(s[i] == '(') {
                    while(j < n and !exle[j]) {
                        if(s[j] == s[j - 1]) break;
                        exle[j] = 1;
                        j ++;
                    }
                } else {
                    while(j < n and !exri[j]) {
                        if(s[j] == s[j - 1]) break;
                        exri[j] = 1;
                        j ++;
                    }
                }
            }
        }
        ll cnt[2][2] = {0};
        rep(i, n) {
            if(s[i] == '(' and exle[i]) cnt[0][i & 1] ++;
            else if(s[i] == ')' and exri[i]) cnt[1][i & 1] ++;
        }
        ans += cnt[0][1] * cnt[1][0] + cnt[0][0] * cnt[1][1];
        ll lev = 1;
        char c = s[0];
        for(int i = 1; i < n; i ++) {
            if(c != s[i]) {
                lev ++;
            } else {
                ll num = lev / 2;
                if(!exle[i - 1] or !exri[i - 1]) {
                    ans += num * (num + (lev & 1));
                }
                lev = 1;
            }
            c = s[i];
        }
        ll num = lev / 2;
        if(!exle[n - 1] or !exri[n - 1]) {
            ans += num * (num + (lev & 1));
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
