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
    int q; cin >> q;

    ll cnt = 0;
    for(int i = 0; i < sz(s); i ++){
        if(s.substr(i, 4) == "1100") cnt ++;
    }
    
    while( q--){
        int idx; char v; cin >> idx >> v; idx --;

        // before
        int bef= 0;
        for(int i = max(0, idx-3); i <= min(sz(s)-4, idx); i ++){
            if(i + 3 >= sz(s)) break;
            if(s.substr(i, 4) == "1100") bef ++;
        }

        cnt -= bef;
        // cout << s << " ";
        s[idx] = v;
        bef= 0;


        for(int i = max(0, idx-3); i <= min(sz(s)-4, idx); i ++){
            if(i + 3 >= sz(s)) break;
            if(s.substr(i, 4) == "1100") bef ++;
        }
        cnt += bef;
    
        // cout << s << " ";
        if(cnt > 0){
            cout << "YES\n";
        }else cout << "NO\n";
    }


}

int main(){ _

    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
