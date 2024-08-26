#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n; vector<ll> v(n);

const int MAX = 1e3 + 10;
ll memo[MAX][MAX];

ll dp(int i, int j){
    if(i > n) return 0;
    ll& p= memo[i][j];
    if(p != -1) return p;

    // cout << i << " " << j << "=> " << v[i] << ", " << v[i + 1] << ", o: " << v[j] << " ==> " << 
    // abs(v[i] - v[i + 1]) << " " << abs(v[j] - v[i + 1]) << endl;
    ll val = min(dp(i + 1, j) + abs(v[i] - v[i + 1]), 
                 dp(i + 1, i) + abs(v[j] - v[i + 1]));
    

    return p = val;
}

int main(){ _
    cin >> n;
    v.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    v.push_back(v.back());

    if(n == 1) {
        cout << v[1] << endl;
        return 0;
    }

    memset(memo, -1, sizeof memo);
    cout << dp(0,0) << endl;
    // for(int i = 0; i <= n+1; i++){
    //     for(int j = 0; j <= n+1; j ++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }
    
    return 0;
} 
