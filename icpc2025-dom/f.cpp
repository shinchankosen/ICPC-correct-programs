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
    int n; cin >> n;
    while(n) {
        string s, t; cin >> s >> t;
        if(count(all(s), 'a') != count(all(t), 'a')) {
            cout << "no" << '\n';
            cin >> n;
            continue;
        }
        string ans = "";
        int X = char('a') ^ char('b');
        auto process = [&](char c, bool flag) -> bool {
            string u = s;
            int cnt = 0;
            rep(i, n) {
                if(s[i] == c) {
                    c = char(c ^ X);
                    u[i] = c;
                    cnt ++;
                } 
                if(cnt == 2) break;
            }
            if(cnt == 2) {
                if(flag) {
                    s = u;
                    int num = c - 'a';
                    ans += char('A' + num);
                }
                return true;
            }
            return false;
        };
        while(process('b', 1));
        for(int i = n - 1; i >= 0; i --) {
            while(s[i] != t[i]) {
                process(t[i], 1);
            }
        }
        cout << "yes" << '\n';
        cout << ans << '\n';
        cin >> n;
    }
    return 0;
}
