#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    ll n, m; cin >> n >> m;

    ll cur = 1, res = 0;
    for(int i = 0; i <= m; i ++){
        res += cur;
        cur *= n;
        if(res > 1e9){
            cout << "inf\n";
            return 0;
        }
    }

    cout << res << endl;

    return 0;
} 
