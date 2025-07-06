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
    int n; cin >> n;
    while(n) {
        vector<vector<pair<int, int>>> v(n);
        for(int i = 1; i < n; i ++) {
            int x, y; cin >> x >> y;
            x --;
            v[x].push_back({i, y});
            v[i].push_back({x, y});
        }
        vector<int> val(n, 0), deg(n, 0);
        auto dfs = [&](auto dfs, int now, int p) -> void {
            for(auto [x, y] : v[now]) {
                if(x == p) continue;
                val[x] = y + 1;
                dfs(dfs, x, now);
                deg[now] ++;
            }
        };
        dfs(dfs, 0, -1);
        vector<int> seen(n, 0);
        priority_queue<pair<int, int>> pq;
        rep(i, n) if(deg[i] == 0) pq.push({val[i], i});
        bool ng = 0;
        vector<int> vec;
        for(int i = n - 1; i >= 0; i --) {
            auto [x, y] = pq.top();
            pq.pop();
            if(x < i) {
                ng = 1;
                break;
            }
            if(i) vec.pb(y);
            for(auto [to, co] : v[y]) {
                if(!seen[to]) {
                    deg[to] --;
                    if(deg[to] == 0) {
                        pq.push({val[to], to});
                        seen[to] = 1;
                    }
                }
            }
        }
        reverse(all(vec));
        if(ng) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
            foa(e, vec) cout << e + 1 << " ";
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}
