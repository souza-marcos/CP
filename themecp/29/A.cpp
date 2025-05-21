#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    string s[2]; cin >> s[0] >> s[1];

    bool ok = false;
    int g = -1;
    for(int i = 0; i < sz(s[0]); i ++){
        if(ok){
            char ma = max(s[0][i], s[1][i]),
                 mi = min(s[0][i], s[1][i]);


            s[g][i]=mi, s[!g][i]=ma; 
        } else {
            if(s[0][i] == s[1][i]) continue;
            
            ok = true;
            if(s[0][i] > s[1][i]) g = 0;
            else g = 1;
        }
    }

    cout << s[0] << endl << s[1] << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
