#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, m; cin >> n >> m;
    int arr[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> arr[i][j];
        }
    }

    vector<int> has(n*m + 1); // has the value - is fully strange

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            has[arr[i][j]]= max(has[arr[i][j]], 1ll);
            for(int vnew : {-1, 1}){
                
                int ni = vnew + i;
                int nj = vnew + j;

                if(ni >= 0 and ni < n and arr[i][j] == arr[ni][j]) has[arr[i][j]] = 2;
                if(nj >= 0 and nj < m and arr[i][j] == arr[i][nj]) has[arr[i][j]] = 2;
            }
        }
    }
    vector<int> vals;
    for(int el : has) if(el > 0) vals.push_back(el);
    sort(vals.rbegin(), vals.rend());

    int ans = 0;
    for(int i = 1; i < sz(vals); i ++) ans += vals[i];
    cout << ans << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
