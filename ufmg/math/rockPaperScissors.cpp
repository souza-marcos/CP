#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < sz(a) + sz(b)) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int main(){ _
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    string mp = "SRP";
    string mp2 = "RPS";
    
    reverse(t.begin(), t.end());

    vector<int> res;
    vector<int> a(n), b(m);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j ++)
            a[j] = (mp[i]==s[j]);
        for(int j = 0; j < m; j ++)
            b[j] = (mp2[i]==t[j]);

        auto c = multiply(a, b);
        res.resize(sz(c));
        for(int j = 0; j < sz(c); j ++)
            res[j] += c[j];
    }

    ll maxv = 0;
    for(int i=m-1; i<sz(res); i++) if(res[i] > maxv) maxv = res[i];
    cout << maxv << endl;
    return 0;
} 
