
//hint
#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = V<VV<T>>;
template<class T> using VVVV = VV<VV<T>>;
#define rep(i,n) for(ll i=0ll;i<n;i++)
#define REP(i,a,n) for(ll i=a;i<n;i++)
const long long INF = (1LL << 60);
const long long mod99 = 998244353;
const long long mod107 = 1000000007;
const long long mod = mod99;
#define eb emplace_back
#define be(v) (v).begin(),(v).end()
#define all(i,v) for(auto& i : v)
#define UQ(v) sort(be(v)), v.erase(unique(be(v)), v.end())
#define LB(x,v) (lower_bound(be(v),(x))-(v).begin())
#define UB(x,v) (upper_bound(be(v),(x))-(v).begin())
#define dout()  cout << fixed << setprecision(20)
#define randinit() srand((unsigned)time(NULL))

template<class T, class U> bool chmin(T& t, const U& u) { if (t > u){ t = u; return 1;} return 0; }
template<class T, class U> bool chmax(T& t, const U& u) { if (t < u){ t = u; return 1;} return 0; }


VV<ll> rot(VV<ll> v){
    ll n=v.size();
    VV<ll> ret = v;
    rep(i,n) rep(j,n) if(v[i][j]){
        assert(ret[n-j-1][i]==0 || v[i][j]==ret[n-j-1][i]);
        ret[n-j-1][i] = v[i][j];
    }
    return ret;
}

bool solve(){
    ll n;
    cin >> n;
    if(n==0) return 0;
    V<ll> v(n);
    rep(i,n) cin >> v[i];

    if(v[0]==v[n-1]){
        VV<ll> ans(n, V<ll>(n, 0));
        rep(i,n) ans[i][0] = v[i];
        rep(i,n) ans[n-1][i] = v[i];
        rep(i,n) ans[n-i-1][n-1] = v[i];
        rep(i,n) ans[0][n-i-1] = v[i];
        cout << "Yes" << endl;
        rep(i,n){
            rep(j,n) cout << ans[i][j] << " ";
            cout << endl;
        }
    }else{
        ll l=-1, r=-1;
        rep(i,n-1) if(v[i]==v[n-1]){
            l = i;
            break;
        }
        REP(i,1,n) if(v[i]==v[0]) r=i;
        if(l==-1||r==-1) cout << "No" << endl;
        else{
            VV<ll> ans(n, V<ll>(n, 0));
            rep(i, l) ans[r][i] = v[i];
            REP(i,r+1,n) ans[i][l] = v[i];
            REP(i,l,r+1) ans[n-1][i] = v[i];
            ans = rot(ans);
            ans = rot(ans);
            ans = rot(ans);
            cout << "Yes" << endl;
            rep(i,n){
                rep(j,n) cout << ans[i][j] << " ";
                cout << endl;
            }
        }
    }

    return 1;
}





int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t=1;
    // cin >> t;
    while(solve());
}