#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl "\n"
#define sz(x) (int)x.size()

void solve(){
    int j; cin >> j;
    string s; cin >> s;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
    }
    
    int c = m - (n-1);

    int val = s[c % j] - '1';
    if(!val) cout << 2 << endl;
    else cout << 1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
