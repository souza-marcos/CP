#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _  
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> x;
    for(auto& [f, s] : v) cin >> f;
    for(auto& [f, s] : v) cin >> s;
    
    vector<ll> pref(n + 1); pref[0] = 0;
    int i = 0;
    for(auto [f, s] : v) x.push_back(f), pref[i + 1] = pref[i] + s, i ++;

    int q; cin >> q;
    while(q --){
        int l, r; cin >> l >> r;
        auto itr = lower_bound(x.begin(), x.end(), r);
        auto itl = lower_bound(x.begin(), x.end(), l);
        
        int itr_n = itr - x.begin() + (itr != x.end() and *itr == r);
        int itl_n = itl - x.begin();
        cout << pref[itr_n] - pref[itl_n] << endl;
    }
    return 0;
} 
