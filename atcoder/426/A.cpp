#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _
    map<string, int> mp;
    mp["Ocelot"] = 1, mp["Serval"] = 2, mp["Lynx"] = 3;
    string s, t; cin >> s >> t;
    cout << (mp[s] >= mp[t] ? "Yes\n" : "No\n");

    return 0;
} 
