#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, cur = 0;    
    for(auto c : s) cnt += (c-'0'==cur? 0: 1), cur = c-'0';
    if(cnt > 2) cnt -= 2;
    else if(cnt == 2) cnt = 1;
    cout << n + cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
