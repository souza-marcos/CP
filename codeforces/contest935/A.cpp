#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int intro, extro, univ; cin >> intro >> extro >> univ;
    if(extro%3 != 0 and (extro%3 + univ) < 3){
        cout << -1 << endl;
        return;
    }
    int ans = intro + extro/3 + ceil((univ + extro%3)/3.0);
    cout << ans << endl;
}


int main(){ _

    int t; cin >> t; 
    while(t --) solve();

    return 0;
} 
