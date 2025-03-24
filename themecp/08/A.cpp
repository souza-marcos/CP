#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int x, y; cin >> x >> y;

    int cnt = 0;
    for(int i = 0; i < 32; i ++){
        int k = (x >> i) & 1,
            l = (y >> i) & 1;

        if(k != l) break;
        cnt ++;
    }
    cout << (1LL << cnt) << endl;


}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
