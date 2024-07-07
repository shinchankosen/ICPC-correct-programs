#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void solve(vector<int> v) {
    int n = v.size();
    vector dp(n + 1, vector(71, bitset<22000> (0)));
    dp[0][35][11000] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= 70; j ++) {
            if(v[i - 1] < 0) {
                if(j != 70) dp[i][j + 1] |= dp[i - 1][j] >> abs(v[i - 1]);
                if(j) dp[i][j - 1] |= dp[i - 1][j] << abs(v[i - 1]);
                continue;
            }
            if(j != 70) dp[i][j + 1] |= (dp[i - 1][j] << v[i - 1]);
            if(j) dp[i][j - 1] |= (dp[i - 1][j] >> v[i - 1]);
        }
    }
    
    if(!dp[n][35][11000]) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    vector<int> a(n), b(n);
    vector<int> plus, minus;
    int sum = 11000, cnt = 35;
    
    for(int i = n - 1; i >= 0; i --) {
        if(cnt - 1 >= 0 and sum - v[i] >= 0 and dp[i][cnt - 1][sum - v[i]]) {
            cnt --;
            sum -= v[i];
            plus.pb(i);
        } else if(cnt + 1 <= 70 and sum + v[i] < 22000 and dp[i][cnt + 1][sum + v[i]]) {
            cnt ++;
            sum += v[i];
            minus.pb(i);
        }
    }
    vector<int> ord;
    rep(i, n / 2) {
        ord.pb(plus[i]);
        ord.pb(minus[i]);
    }
    int x = 0;
    a[ord[0]] = x;
    rep(i, n) {
        if(i) {
            a[ord[i]] = b[ord[i - 1]];
        }
        b[ord[i]] = v[ord[i]] - a[ord[i]];
    }
    foa(e, a) cout << e << " ";
    cout << endl;
    foa(e, b) cout << e << " ";
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n) {
        vector<int> v(n);
        rep(i, n) cin >> v[i];
        {
            int sum = 0;
            foa(e, v) sum += e;
            if(sum & 1) {
                cout << "No" << endl;
                cin >> n;
                continue;
            }
            int flag = 0;
            foa(e, v) if(e % 2 == 0) flag = 1;
            if(!flag) {
                solve(v);
                cin >> n;
                continue; 
            }
            cout << "Yes" << endl;
        }
        int id = -1;
        vector<int> a(n), b(n);
        rep(i, n) if(v[i] % 2 == 0) id = i;
        rep(i, n) if(v[i] % 2 == 0) {
            if(i != id) {
                a[i] = v[i] / 2;
                b[i] = v[i] / 2;
            }
        }
        vector<int> ord;
        rep(i, n) if(v[i] & 1) {
            ord.pb(i);
        }
        sort(all(ord), [&] (int i, int j) {
            return v[i] < v[j];
        });
        reverse(all(ord));
        int sum = 0, m = ord.size();
        rep(i, m) {
            if(i & 1) sum -= v[ord[i]];
            else sum += v[ord[i]];
        }
        sum += v[id];
        int x = sum / 2;
        b[id] = x;
        a[id] = v[id] - x;

        rep(i, m) {
            if(i == 0) {
                a[ord[i]] = x;
            } else {
                a[ord[i]] = b[ord[i - 1]];
            }
            b[ord[i]] = v[ord[i]] - a[ord[i]];
        }
        rep(i, n) cout << a[i] << " ";
        cout<< endl;
        rep(i, n) cout<< b[i] << " ";
        cout << endl;
        cin >> n;
    }
    return 0;
}
