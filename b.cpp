#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n) {
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        int sum = 0;
        int f = 0;
        int ans = 0;
        rep(i, n) {
            int nx = sum + a[i] - b[i];
            if(!f) {
                if(nx > 0) {
                    f = 1;
                    sum = nx;
                } else if(nx < 0) {
                    f = -1;
                    sum = nx;
                } else {
                    continue;
                }
                continue;
            } else if(f == 1) {
                if(nx < 0) {
                    f = -1;
                    ans ++;
                } 
            } else {
                if(nx > 0) {
                    f = 1;
                    ans ++;
                }
            }
            sum = nx;
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
