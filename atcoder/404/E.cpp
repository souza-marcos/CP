#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()



int main(){ //_
    // Quero pegar o mais a direita que eh maior que 0 

    int n; cin >> n;

    vector<int> a(n); for(int i = 1; i < n; i ++) cin >> a[i];
    vector<int> c(n); for(int i = 1; i < n; i ++) cin >> c[i];

    a[0] = c[0] = 0;
    vector<int> dp(n, INF), par(n, -1);
    dp[0]=0;
    for(int i = 1; i < n; i ++){
        int choose = i-1;
        for(int j = i-1; j >= max(0, i-a[i]); j --){
            if(j == 0 or c[j]>=1) {
                dp[i] = 0;
                choose = j;
                break;
            }
            if(dp[j]+1 < dp[i]){
                choose = j;
                dp[i] = dp[j] + 1;
            }
        }
        par[i] = choose;
    }

    for(auto el : par) cout << el << " ";
    cout << endl;

    int cnt =0;
    for(int i = n-1; i > 0; i --){
        if(a[i] > 0) cnt ++, cout << par[i] << " ", a[par[i]] ++;
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
} 
