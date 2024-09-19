#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MAX = 1e5 + 10; 
ll memo[101][MAX];

int main(){ _
    int n, w; cin >> n >> w;
    struct El{int w, v;};
    vector<El> arr(n); for(auto& [w, v] : arr) cin >> w >> v;

    memset(memo, -1, sizeof memo);
    memo[0][w] = 0, memo[0][w-arr[0].w] = arr[0].v;
    for(int i = 0; i < n; i ++){
        for(int j = w; j >= 0; j --){
            if(memo[i][j] == -1) continue;
            
            memo[i+1][j] = max(memo[i+1][j], memo[i][j]);
            if(j >= arr[i+1].w) memo[i+1][j-arr[i+1].w] = max(memo[i+1][j-arr[i+1].w], memo[i][j] + arr[i+1].v);
        }
    }

    ll maxv = 0;
    for(int i=0; i<=w; i ++){
        if(maxv < memo[n-1][i]) maxv = memo[n-1][i];
    }
    cout << maxv << endl;
    return 0;
} 
