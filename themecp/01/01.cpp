#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n ; cin >> n ;
    int last = INF; 
    bool ok = true;
    while(n --){
        int a, b; cin >> a >> b;
        int mi = min(a, b), ma = max(a, b);
        if(ma <= last) last = ma;
        else if(mi <= last) last = mi;
        else {
            ok = false;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
} 
