#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    map<string, string> mp;
    mp["N"] = "S";
    mp["S"] = "N";
    mp["E"] = "W";
    mp["W"] = "E";
    mp["NE"] = "SW";
    mp["SW"] = "NE";
    mp["NW"] = "SE";
    mp["SE"] = "NW";
    
    string in; cin >> in;
    cout << mp[in] << endl;

    return 0;
} 
