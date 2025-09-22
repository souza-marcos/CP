#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ 

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<int> res(2*n + 1);
        int cur = 1; 
        for(int x = n; x >= 1; x --){
            for(int i = x; cur+i <= 2*n; i += x){
                if(res[cur+i] == 0){
                    res[cur] = res[cur+i] = x;
                    break;
                }
            }
            while(cur <= 2*n and res[cur] != 0) cur ++;
        }

        for(int i = 1; i <= 2*n; i ++) cout << res[i] << " ";
        cout << endl;
    }
}
