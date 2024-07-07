#include <bits/stdc++.h>

using namespace std;
#define SZ(x) (int) (x).size()
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(auto i = (a); i < (b); i++)
#define For(i, a, b, c) \
	for(auto i = (a); i != (b); i += (c))
#define REPR(i, n) for(auto i = (n) - 1; i >= 0; i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase(unique(ALL(v)), (v).end())
#define eb emplace_back

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
const double EPS = 1e-6;
const int MOD = 1e9 + 7;
const int INF = (1 << 30);
const ll LINF = 1e18 + 100;
const double math_PI = acos(-1);

template<typename T>
vector<T> make_v(size_t a) {
	return vector<T>(a);
}

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(
		a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(
	T& t, const V& v) {
	t = v;
}

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(
	T& t, const V& v) {
	for(auto& e: t) fill_v(e, v);
}

template<class T>
bool chmax(T& a, const T& b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
bool chmin(T& a, const T& b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename S, typename T>
istream& operator>>(istream& is, pair<S, T>& p) {
	cin >> p.first >> p.second;
	return is;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
	for(T& x: vec) is >> x;
	return is;
}

template<typename T>
string join(vector<T>& vec, string splitter) {
	stringstream ss;
	REP(i, SZ(vec)) {
		if(i != 0) ss << splitter;
		ss << vec[i];
	}
	return ss.str();
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
	os << join(vec, " ");
	return os;
}

int main(){
    int A,B,X,Y,N;
    cin >> A >> B >> X >> Y >> N;
    using T = tuple<int,int,int>;
    while(A != 0){
        cerr << "=========" << endl;
        int PX = X;
        int PY = Y;
        vector<vector<T>> P(A + B + 100),M(2 * max(A , B) + 100);
        int zero = max(A , B) + 50;
    
        for(int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            P[x + y].emplace_back(x,y,i + 1);
            M[x - y + zero].emplace_back(x, y, i + 1);
        }
        for(int i = 0; i < A + B + 100; i++){
            so(P[i]);
        }
        for(int i = 0; i < 2 * max(A,B) + 100; i++){
            so(M[i]);
        }
        vi ans;
        REP(ini_dir, 4){
            //cerr << "hoge" << endl;
            set<PI> S;
            set<int> s;
            int dir = ini_dir;
            // cerr << "! " << dir << endl;
            int f = -1;
            while(true){
                //cerr << X << " " << Y << " " << dir << endl;
                if(dir == 0){
                    //right up
                    auto it = lower_bound(ALL(M[zero + X - Y]), T{X, Y, -1});
                    if(it != M[zero + X - Y].end()){
                        auto [x, y, id] = *it;
                        if(next(it) != M[zero + X - Y].end())break;
                        if(f != -1 && f != id)break;
                        f = id;
                    }
                    int step = min(A - X, B - Y);
                    X += step;
                    Y += step;
                    if(S.find({X,Y}) != S.end()) break;
                    if(X == A && Y == B)break;
                    else if(X == A)dir = 2;
                    else if(Y == B)dir = 1;
                    S.insert({X,Y});
                }else if(dir == 1){
                    // right down
                    //cerr << "p " << X << " " << Y << endl;
                    auto it = lower_bound(ALL(P[X + Y]), T{X, Y, -1});
                    if(it != P[X + Y].end()){
                        auto [x, y, id] = *it;
                        if(next(it) != P[X + Y].end())break;
                        if(f != -1 && f != id)break;
                        f = id;
                    }
                    int step = min(A - X, Y);
                    //cerr << "s " << step << endl;
                    X += step;
                    Y -= step;
                    if(S.find({X,Y}) != S.end()) break;
                    if(X == A && Y == 0) break;
                    else if(X == A) dir = 3;
                    else if(Y == 0) dir = 0;
                    S.insert({X,Y});
                }else if(dir == 2){
                    // left up
                    auto it = upper_bound(ALL(P[X + Y]), T{X, Y, -1});
                    if(it != P[X + Y].begin()){
                        auto [x, y, id] = *prev(it);
                        if(prev(it) != P[X + Y].begin())break;
                        if(f != -1 && f != id)break;
                        f = id;
                    }
                    int step = min(X, B - Y);
                    X -= step;
                    Y += step;
                    if(S.find({X,Y}) != S.end()) break;
                    if(X == 0 && Y == B) break;
                    else if(X == 0) dir = 0;
                    else if(Y == B) dir = 3;
                    S.insert({X,Y});
                }else if(dir == 3){
                    // left down
                    auto it = upper_bound(ALL(M[zero + X - Y]), T{X, Y, -1});
                    if(it != M[zero + X - Y].begin()){
                        auto [x, y, id] = *prev(it);
                        if(f != -1 && f != id)break;
                        ans.push_back(id);
                        if(prev(it) != M[zero + X - Y].begin())break;
                        f = id;
                    }
                    int step = min(X, Y);
                    X -= step;
                    Y -= step;
                    if(S.find({X,Y}) != S.end()) break;
                    if(X == A && Y == B)break;
                    else if(X == 0)dir = 1;
                    else if(Y == 0)dir = 2;
                    S.insert({X,Y});
                }            
                //cerr << X << " " << Y << " " << dir << endl;
            }
            X = PX;
            Y = PY;
        }
        so(ans);
        uni(ans);
        if(ans.empty())cout << "No" << endl;
        else cout << ans << endl;
        cin >> A >> B >> X >> Y >> N;
    }
}
