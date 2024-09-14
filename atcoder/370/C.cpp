#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

int main(){ _
    string s, t; cin >> s >> t;
    vector<int> process;
    for(int i = 0; i < sz(s); i ++) if(s[i] > t[i]) process.push_back(i); 
    for(int i = sz(s)-1; i >= 0; i --) if(s[i] < t[i]) process.push_back(i);

    vector<string> ans;
    for(auto i: process){
        s[i] = t[i], ans.push_back(s);
    }
    cout << sz(ans) << endl;
    for(auto st: ans) cout << st << endl;
    return 0;
} 
