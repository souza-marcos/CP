#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n; cin >> n; string s; cin >> s;

    bool d = false;
    int last = -INF;
    for(int i = 0; i < n; i++){
        if(isdigit(s[i]) and d) {cout << "NO\n"; return;}
        if(!isdigit(s[i]) and !d) d = true, last = -INF;

        if(s[i] < last) { cout << "NO\n"; return;}
        last = s[i];
    }
    cout << "YES\n";
}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
