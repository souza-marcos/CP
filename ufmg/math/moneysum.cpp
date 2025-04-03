#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
const int MAX = 100 * 1000;
bool can[100][MAX + 10];

int main(){ _
    int n; cin >> n;
    vector<ll> arr(n);
    ll maxv = 0;
    for(auto & el: arr) cin >> el, maxv = max(maxv, el);


    can[0][0]=can[0][arr[0]]=true;
    for(int i = 0; i < n-1; i ++){
        for(int j = 0; j <= MAX; j ++) if(can[i][j]) can[i+1][j] = can[i+1][j+arr[i+1]] = true; 
    }

    vector<int> ans;
    for(int i = 1; i <= MAX; i ++) 
        if(can[n-1][i]) ans.push_back(i);

    cout << sz(ans) << endl;
    for(auto el : ans) cout << el << " ";
    cout << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j <= ans.back(); j ++){
    //         cout << can[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
} 
