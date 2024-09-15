#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
// Using Hashing or z-function

vector<int> zfunction(string& s){
    vector<int> z(sz(s));
    int l = 0, r = 0;
    for(int i = 1; i < sz(s); i ++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < sz(s) and s[z[i]] == s[i + z[i]]) 
            z[i] ++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

struct str_hash{
    int p = 98'765'432, m = 1e9 + 7;
    vector<ll> pref, ppi; // p pow inverse
    str_hash(string& s) : pref(sz(s)), ppi(sz(s)){
        ppi[0] = 1, pref[0] = s[0];
        for(int i = 1; i < sz(s); i++){
            ppi[i] = ppi[i-1] * p % m;
            pref[i] = pref[i] = (pref[i - 1] * p + s[i]) % m;
        }
    }

    int substr(int l, int size){
        // cout << l << " " << size << endl;
        assert(size + l <= sz(pref));
        ll val = pref[l + size - 1] - (l ? pref[l - 1] * ppi[size] % m : 0);
        return (val + m) % m;
    }
};

// int main(){ _
//     string s; cin >> s;
//     auto z = zfunction(s);
//     for(int i = 1; i < ceil(sz(s)/2.0); i ++){
//         if(z[i] == (sz(s) - i)){
//             cout << "YES\n" << s.substr(i, z[i]) << endl;
//             return 0;
//         }
//     }
//     cout << "NO\n";
//     return 0;
// } 

int main(){ _ 
    string s; cin >> s;
    str_hash hval(s);
    for(int i = 1; i < ceil(sz(s)/2.0); i ++){
        if(hval.substr(0, sz(s)- i) == hval.substr(i, sz(s) - i)){
            cout << "YES\n" << s.substr(0, sz(s) - i) << endl;
            return 0;
        }
    }
    cout << "NO\n";

}
