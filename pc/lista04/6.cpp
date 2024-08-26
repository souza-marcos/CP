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
const long double PI = acos(-1);
#define sz(x) (int)x.size()

void fft(vector<complex<double>>& a, bool invert){
    int n = sz(a);

    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if(i < j) swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        double ang = 2 * PI / len * (invert ? -1: 1);
        complex<double> wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            complex<double> w(1);
            for(int j = 0; j < len /2; j++){
                complex<double> u = a[i + j], v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert) for(complex<double> &x: a) x /= n;
}

vector<int> mult_polys(vector<int> const& a, vector<int> const& b){
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1;
    while(n < sz(a) + sz(b)) n <<= 1;

    fa.resize(n), fb.resize(n);
    fft(fa, false), fft(fb, false);

    for(int i = 0; i < n; i++) fa[i] *= fb[i];

    fft(fa, true);
    vector<int> res(n);
    for(int i = 0; i < n; i++) res[i] = round(fa[i].real());
    return res;
}

int main(){ _
    
    string s; cin >> s; 
    
    vector<int> v(sz(s));
    v[0] = s[0] - 'a' + 1;
    for(int i = 1; i < sz(s); i++){
        v[i] = v[i-1] + (s[i] - 'a' + 1);
        // cout << v[i] << " ";
    } // cout << endl;

    vector<int> p(v.back() + 1), q(v.back() + 1);

    for(auto peso : v)
        p[peso] = 1; 

    for(int i = 0; i < sz(s) -1; i++)     
        q[v.back() - v[i]] = 1;
    
    q[v.back()] = 1;

    auto res = mult_polys(p, q);

    int cnt = 0;
    for(int submass = v.back() + 1; submass <= 2 * v.back(); submass ++)
        if(res[submass]) cnt ++;
    
    cout << cnt << endl;

    return 0;
} 
