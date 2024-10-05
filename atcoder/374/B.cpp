#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _
    string s, t; cin >> s >> t;
    s.push_back('$'), t.push_back('$');
    for(int i = 0; i < min(sz(s), sz(t)); i ++){
        if(s[i] != t[i]) {
            cout << i + 1 << endl; 
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
} 
