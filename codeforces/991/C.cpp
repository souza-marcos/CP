#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string s; cin >> s;
    ll sum = 0;
    int cnt2 = 0, cnt3 = 0;
    for(auto c : s){
        if(c == '2') cnt2 ++;
        if(c == '3') cnt3 ++;
        sum += (c - '0');
    }

    for(int i = 0; i <= cnt3; i ++){

        int aux = sum + i * 6;
        int res = aux % 9;
        res = (9 - res) % 9;
        if(res%2 == 1) res += 9;
        res /= 2;
        if(res <= cnt2){ cout << "Yes\n"; return; }
    }
    cout << "No\n";
}

int main(){ _
    int t; cin >> t;
    while( t--) solve();
    return 0;
} 
