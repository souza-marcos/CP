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


using cd = complex<double>;
const double PI = acos(-1);


// Recursivo
void fft(vector<cd> &a, bool invert){
    int n = sz(a);
    if(n == 1) return;

    vector<cd> a0(n/2), a1(n/2);
    for(int i =0; 2 * i < n; i ++){
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang)); // w_n = e^(i * 2pi/n)
    for(int i = 0; 2 * i < n; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if(invert) a[i] /= 2, a[i + n/2] /= 2;
        w *= wn;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < sz(a) + sz(b)) n <<= 1;

    fa.resize(n), fb.resize(n); // Completando com zeros

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; i++){
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector<int> result(n);
    for(int i = 0; i < n; i++){
        result[i] = round(fa[i].real());
    }
    return result;
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
