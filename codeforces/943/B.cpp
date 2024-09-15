#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    string s, t; cin >>  s >> t;
    // cout << s << " , " << t << endl;
    int i = 0;
    for(int j = 0; j < m; j++){
        if(s[i] == t[j]) i ++;           
    }
    cout << i << endl;
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
