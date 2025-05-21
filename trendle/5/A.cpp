#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int res = 0;
    for(int i = 0; i < n; i ++){
        int in = s[i]-'0', out = t[i]-'0';
        if(out < in) swap(out, in);
        res += min(in + 10 - out, out - in);
    }
    cout << res << endl;
} 
