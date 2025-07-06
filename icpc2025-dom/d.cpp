#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(a) push_back(a)
#define rep(i, n) for(int i=0;i<(n);i++)
#define foa(e, v) for(auto& e : v)
using ll = long long;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL << 60);
#define dout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<int> ru(string s) {
    vector<pair<char, int>> v;
    foa(e, s) {
        if(v.empty()) {
            v.push_back({e, 1});
        } else {
            if(v.back().first == e) {
                v.back().second ++;
            } else {
                v.push_back({e, 1});
            }
        }
    }
    vector<int> ret;
    for(auto [x, y] : v) {
        ret.pb(y);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    while(n) {
        vector<string> s(n);
        rep(i, n) {
            cin >> s[i];
        }
        bool ng = 0;
        int ans = -1;
        rep(i, n) {
            char c = s[i][0];
            int cnt = -1;
            for(int j = 1; j < m; j ++) {
                if(c == s[i][j]) {
                    if(cnt == -1) continue;
                    cnt ++;
                } else {
                    if(cnt == -1) {
                        ;
                    } else {
                        if(ans == -1) {
                            ans = cnt;
                        } else if(ans != cnt) {
                            ng = 1;
                            break;
                        }
                    }
                    cnt = 1;
                    c = s[i][j];
                }
            }
            if(ng) break;

        }
        rep(i, m) {
            char c = s[0][i];
            int cnt = -1;
            for(int j = 1; j < n; j ++) {
                if(c == s[j][i]) {
                    if(cnt == -1) continue;
                    cnt ++;
                } else {
                    if(cnt == -1) {
                        ;
                    } else {
                        if(ans == -1) {
                            ans = cnt;
                        } else if(ans != cnt) {
                            ng = 1;
                            break;
                        }
                    }
                    cnt = 1;
                    c = s[j][i];
                }
            }
            if(ng) break;
        }
        rep(i, n - 1) {
            int cnt = 0;
            rep(j, m) if(s[i][j] != s[i + 1][j]) cnt ++;
            if(cnt == 0 or cnt == m) continue;
            ng = 1;
        }
        rep(i, m - 1) {
            int cnt = 0;
            rep(j, n) if(s[j][i] != s[j][i + 1]) cnt ++;
            if(cnt == 0 or cnt == n) continue;
            ng = 1;
        }
        if(ng) {
            cout << -1 << endl;
        } else if(ans == -1) {
            cout << 0 << endl;
        } else {
            rep(i, n) {
                string t = s[i];
                auto vec = ru(t);
                if(vec.back() > ans) {
                    ng = 1;
                    break;
                }
                vec.pop_back();
                if(vec.empty()) continue;
                if(vec[0] > ans) {
                    ng = 1;
                    break;
                }
                vec.erase(vec.begin());
                foa(e, vec) {
                    if(e != ans) ng = 1;
                }
            }
            rep(i, m) {
                string t = "";
                rep(j, n) t += s[j][i];
                auto vec = ru(t);
                if(vec.back() > ans) {
                    ng = 1;
                    break;
                }
                vec.pop_back();
                if(vec.empty()) continue;
                if(vec[0] > ans) {
                    ng = 1;
                    break;
                }
                vec.erase(vec.begin());
                foa(e, vec) {
                    if(e != ans) ng = 1;
                }
            }
            if(ng) cout << -1 << endl;
            else cout << ans << endl;
        }
        cin >> n >> m;
    }
    return 0;
}
