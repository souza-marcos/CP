#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;

    int res = 0;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        res ^= a;
    }

    int ball = 0;
    for(int i = 0; i < m; i ++){
        int a; cin >> a;
        ball |= a;
    }

    int maxv = res, minv = res;
    if(n&1){
        maxv = res | ball;
    }else{
        minv = res & (~ball);
        // cout << "DEBUG: " << res << " " << ball << endl;
    }

    cout << minv << " " << maxv << endl;

}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
