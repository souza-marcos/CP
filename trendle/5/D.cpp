#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 

    ll n; cin >> n; string s; cin >> s;
    map<char, ll> cnt;

    for(auto el : s) cnt[el] ++;

    ll tot = (n + 1) * n /2;
    for(auto [el, val] : cnt) {
        tot -= (val-1) * val /2;
    }
    cout << tot << endl;
} 
