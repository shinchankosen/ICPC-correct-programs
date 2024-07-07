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
    int N;
    cin >> N;
    while(N != 0){
    int cur = 0;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        if(cur + A <= 300){
            cur += A;
        }
    }
    cout << cur << endl;
    cin >> N;
    }
}
