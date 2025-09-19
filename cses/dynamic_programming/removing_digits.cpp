#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n; cin >> n;
    vector<int> dp(n + 1, INF); dp[n]=0;
    
    for(int i = n; i > 0; i--){
        if(dp[i]==INF) continue;
        int el = i;
        while(el > 0){
            int d=i-(el%10);
            dp[d] = min(dp[d], dp[i]+1);
            el/=10; 
        }
    }
    cout << dp[0] << endl;
    return 0;       
}
