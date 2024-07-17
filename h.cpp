#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<n;i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void chmax(int &a, int b) { a = max(a, b); }

set<pair<int, int>> st1, st2;
vector<vector<ll>> dijkstra(vector<vector<ll>> &a, vector<vector<int>> &fin, vector<pair<int, int>> &edge, int h, int w, int May, int Max, vector<vector<int>> &type) {
    using T = tuple<ll, int, int, int>;
    vector dis(h + 2, vector(w + 2, INF));
    priority_queue<T, vector<T>, greater<T>> Q;
    for(int i = 1; i <= h + 1; i ++) {
        dis[i][0] = 0;
        Q.push({0, i, 0, 1});
    }
    for(int i = 1; i <= w; i ++) {
        dis[h + 1][i] = 0;
        Q.push({0, h + 1, i, 1});
    }
    while(!Q.empty()) {
        auto [d, i, j, flag] = Q.top();
        Q.pop();
        if(fin[i][j]) break;
        if(dis[i][j] < d) continue;
        for(auto [dy, dx] : edge) {
            int y = i + dy;
            int x = j + dx;
            if(y < 0 or x < 0 or y >= h + 2 or x >= w + 2) continue;
            ll nxd = d + a[y][x];
            if(dis[y][x] > nxd) {
                if(flag) {
                    if(fin[y][x]) continue;

                    if(j == 0 and type[y][x] == 2) continue;
                    if(i == h + 1) {
                        int Y = y + May - h;
                        int X = x + Max - w;
                        if(Y >= 0 and X >= 0 and type[Y][X] == 2) continue;
                    }
                } 
                if(fin[y][x]) {
                    if(x == w + 1) {
                        int Y = i + May - h;
                        int X = j + Max - w;
                        if(Y >= 0 and X >= 0 and type[Y][X] == 1) continue;
                    }
                    if(y == 0 and type[i][j] == 1) continue;
                }
                if((type[i][j] ^ type[y][x]) == 3) {
                    if(!st2.count({dy, dx})) continue;
                }
                if(i - h + May >= 0 and j - w + Max >= 0 and y - h + May >= 0 and x - w + Max and (type[i - h + May][j - w + Max] ^ type[y - h + May][x - w + Max]) == 3) {
                    if(!st1.count({dy, dx})) continue;
                }
                dis[y][x] = nxd;
                Q.push({nxd, y, x, 0});
            }
        }
    }
    return dis;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    while(h) {
        st1.clear();
        st2.clear();
        vector a(h + 2, vector(w + 2, 0LL));
        rep(i, h) rep(j, w) cin >> a[i + 1][j + 1];

        vector fin(h + 2, vector(w + 2, 0));
        vector<pair<int, int>> tile, tile1, tile2;
        int Max = 0, May = 0;
        {
            a[0][0] = a[h + 1][w + 1] = INF;
            for(int i = 1; i <= w + 1; i ++) fin[0][i] = 1;
            for(int i = 1; i <= h; i ++) fin[i][w + 1] = 1;
            
            for(int i = 1; i <= h; i ++) {
                for(int j = 1; j <= w; j ++) {
                    if(a[i][j] == -1) {
                        tile.push_back({i, j});
                        chmax(May, i);
                        chmax(Max, j);
                    }
                }
            }

            {
                int idy = 0, idx = 0;
                for(int i = 1; i <= h; i ++) {
                    if(a[i][Max] == -1) {
                        idy = i;
                        break;
                    }
                }
                for(int i = 1; i <= w; i ++) {
                    if(a[May][i] == -1) {
                        idx = i;
                        break;
                    }
                }
                for(int i = idy; i <= May; i ++) {
                    for(int j = idx; j <= Max; j ++) {
                        if(a[i][j] == -1) {
                            tile1.push_back({i, j});
                        }
                    }
                }
            }

            {
                int idy = 0, idx = 0;
                for(int i = 1; i <= h; i ++) {
                    if(a[i][1] == -1) {
                        idy = i;
                    }
                }
                for(int i = 1; i <= w; i ++) {
                    if(a[1][i] == -1) {
                        idx = i;
                    }
                }
                for(int i = 1; i <= idy; i ++) {
                    for(int j = 1; j <= idx; j ++) {
                        if(a[i][j] == -1) {
                            tile2.push_back({i, j});
                        }
                    }
                }
            }

            for(int i = May; i >= 1; i --) {
                bool f = 0;
                for(int j = Max; j >= 1; j --) {
                    if(j == Max and a[i][j] == -1) f = 1;
                    if(a[i][j] == -1) break;
                    a[h - May + i][w - Max + j] = INF;
                }
                if(f) break;
            }
            for(int i = 1; i <= h; i ++) {
                bool f = 0;
                for(int j = 1; j <= w; j ++) {
                    if(j == 1 and a[i][j] == -1) f = 1;
                    if(a[i][j] == -1) break;
                    a[i][j] = INF;
                }
                if(f) break;
            }

            for(int i = 1; i <= h; i ++) {
                for(int j = 1; j <= w; j ++) {
                    if(a[i][j] == -1) a[i][j] = INF;
                }
            }
        }

        vector<pair<int, int>> edges;
        {
            set<pair<int, int>> st;
            for(auto [y1, x1] : tile) {
                for(auto [y2, x2] : tile) {
                    for(int dy = -1; dy <= 1; dy ++) {
                        for(int dx = -1; dx <= 1; dx ++) {
                            int y = y1 - y2 + dy;
                            int x = x1 - x2 + dx;
                            if(st.count({y, x})) continue;
                            st.insert({y, x});
                        }
                    }
                }
            }
            for(auto [y, x] : st) edges.push_back({y, x});
        }{
            for(auto [y1, x1] : tile2) {
                for(auto [y2, x2] : tile2) {
                    for(int dy = -1; dy <= 1; dy ++) {
                        for(int dx = -1; dx <= 1; dx ++) {
                            int y = y1 - y2 + dy;
                            int x = x1 - x2 + dx;
                            if(st2.count({y, x})) continue;
                            st2.insert({y, x});
                        }
                    }
                }
            }
            for(auto [y1, x1] : tile1) {
                for(auto [y2, x2] : tile1) {
                    for(int dy = -1; dy <= 1; dy ++) {
                        for(int dx = -1; dx <= 1; dx ++) {
                            int y = y1 - y2 + dy;
                            int x = x1 - x2 + dx;
                            if(st1.count({y, x})) continue;
                            st1.insert({y, x});
                        }
                    }
                }
            }
        }
        vector type(h + 2, vector(w + 2, 0));
        {
            vector seen(h + 2, vector(w + 2, 0));
            queue<tuple<int, int, int>> que;
            if(a[May][1] != INF) {
                seen[May][1] = 1;
                type[May][1] = 1;
                que.push({May, 1, 1});
            }
            if(a[1][Max] != INF) {
                seen[1][Max] = 1;
                type[1][Max] = 2;
                que.push({1, Max, 2});
            }
            int dy[4] = {-1, 0, 0, 1};
            int dx[4] = {0, -1, 1, 0};
            while(!que.empty()) {
                auto [i, j, id] = que.front();
                que.pop();
                rep(k, 4) {
                    int y = dy[k] + i;
                    int x = dx[k] + j;
                    if(y < 1 or y > May or x < 1 or x > Max) continue;
                    if(a[y][x] == INF) continue;
                    if(seen[y][x]) continue;
                    seen[y][x] = 1;
                    type[y][x] = id;
                    que.push({y, x, id});
                }
            }
        }
        ll ans = INF;
        for(auto [y, x] : tile) {
            if(a[h - May + y][w - Max + x] < ans) ans = a[h - May + y][w - Max + x];
            a[h - May + y][w - Max + x] = INF;
        } 
        auto ret = dijkstra(a, fin, edges, h, w, May, Max, type); 
        
        rep(i, h + 2) rep(j, w + 2) if(fin[i][j] and ans > ret[i][j]) ans = ret[i][j];
        cout << ans << endl;
        cin >> h >> w;
    }
    return 0;
}
