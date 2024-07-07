
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




bool solve(){
    ll n;
    cin >> n;
    if(n==0) return 0;

    ll a,b,d;
    cin >> a >> b >> d;
    VV<ll> ok(110, V<ll>(110, 1));
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        ok[x][y] = 0;
    }
    VVV<ll> dat(101, VV<ll>(101, V<ll>(4, -1)));
    V<ll> dx={1, 0, -1, 0};
    V<ll> dy={0,1,0,-1};
    ll di = 0;
    while(d>0&&a>=0&&b>=0&&a<101&&b<101){
        ll na = a + dx[di];
        ll nb = b + dy[di];
        while(na>=0&&nb>=0&&na<101&&nb<101&&!ok[na][nb]){
            (di +=1) %=4;
            na = a + dx[di];
            nb = b + dy[di];
        }
        if(na<0||nb<0||na>100||nb>100){
            a = na;
            b = nb;
            d--;
            break;
        }
        if(dat[na][nb][di]!=-1){
            ll nd = dat[na][nb][di] - d;
            if(nd) d %= nd;
        }
        dat[na][nb][di] = d;
        d--;
        a = na;
        b = nb;
    }
    cout << a+dx[di]*d << " " << b+dy[di]*d << endl;


    return 1;
  
}





int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t=1;
    // cin >> t;
    while(solve());
}