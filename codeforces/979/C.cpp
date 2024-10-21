#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(s[0] == '1' or s[n-1] == '1'){
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n-1; i ++){
        if(s[i]=='1' and s[i+1]=='1'){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
