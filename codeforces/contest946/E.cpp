#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

vector<vector<ll>> memo;

void solve(){
    int m;
    ll salary; cin >> m >> salary;
    vector<int> c(m), h(m);
    int sum = 0;
    for(int i = 0; i < m; i++){
        cin >> c[i] >> h[i];
        sum += h[i];
    }
    memo.assign(sum + 1, vector<ll>(m+1, -1));

    memo[0][0] = 0;
    for(int i = 0; i < m; i++){
        for(int hi = 0; hi <= sum; hi ++){
            if(memo[hi][i] == -1) continue;
            if(memo[hi][i] >= c[i]) memo[hi+h[i]][i+1] = max(memo[hi+h[i]][i+1], memo[hi][i] + salary - c[i]);
            memo[hi][i + 1] = max(memo[hi][i + 1], memo[hi][i] + salary);
        }
    }

    for(int j = 0; j <= sum; j++){
        for(int i = 0; i < m; i ++){
            if(memo[j][i] == INF) cout << "INF\t";
            else cout << memo[j][i]<< "\t";
        } cout << endl;
    }
    cout << endl;

    for(int i = sum-1; i >= 0; i--){
        if(memo[i][m-1] >=0){
            cout << i << endl;
            return;
        }
    }
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
