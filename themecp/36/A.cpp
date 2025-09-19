#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int t; cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        x --, y --;
        vector<int> res(n, 1);
        bool ok = 1;
        for(int i = y-1; i >= 0; i --){
            if(ok) res[i] = -1;
            else res[i] = 1;
            ok ^= 1;
        }
        ok = 1;
        for(int i = x+1; i < n; i ++){
            if(ok) res[i] = -1;
            else res[i] = 1;
            ok ^= 1;
        }
        for(int el : res) cout << el << " ";
        cout << endl;
    }

} 
