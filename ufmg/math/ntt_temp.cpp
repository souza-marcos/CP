#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

// Aritmetica Modular
//
// O mod tem q ser primo

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

const int MOD = 998244353;
typedef mod_int<MOD> mint;

void ntt(vector<mint>& a, bool rev){
    int n = sz(a);
    auto b = a;
    assert(!(n & (n-1)));
    mint g = 1;
    while((g^(MOD / 2)) == 1) g+= 1;
    if(rev) g = 1/g;

    for(int step = n/2; step; step /= 2){
        mint w = g^(MOD / (n / step)), wn = 1;

        for(int i = 0; i < n/2; i+= step){
            for(int j = 0; j < step; j++){
                auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
                b[i + j] = u + v;
                b[i + n/2 + j] = u - v;
            }
            wn = wn * w;
        }
        swap(a, b);
    }
    if(rev) {
        auto n1 = mint(1) / n;
        for(auto& x : a) x *= n1;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b){
    vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    int N = sz(a) + sz(b) -1, n = 1;
    while(n <= N) n <<= 1;

    fa.resize(n), fb.resize(n); // Completando com zeros

    ntt(fa, false);
    ntt(fb, false);

    for(int i = 0; i < n; i++){
        fa[i] *= fb[i];
    }
    ntt(fa, true);
    fa.resize(N);
    vector<int> res(N);
    for(int i = 0; i < N; i++){
        res[i] = fa[i].v;
    }
    return res;
}


int main(){ _
    
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto& el : a) cin >> el;
    for(auto& el : b) cin >> el;

    vector<int> res = multiply(a, b);

    for(auto el: res) cout << el << " ";
    cout << endl;

    return 0;
} 
