#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n; cin >> n;
    vector<int> v(n); for(auto& el: v) cin >> el;
    int memo[n + 1][3];
    
    memo[n][0] = memo[n][1] = memo[n][2] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 3; j ++){
            if(j == 0 and (v[i] == 0 or v[i] == 1)) memo[i][j] = -INF;
            else if(j == 1 and (v[i] == 0 or v[i] == 2)) memo[i][j] = -INF;
            else if(j == 2) memo[i][j] = max(memo[i + 1][0], max(memo[i + 1][1], memo[i + 1][2]));
            else memo[i][j] = max(memo[i + 1][(j+1)%3], memo[i + 1][(j+2)%3]) + 1;
        }
    }

    cout << n - max(memo[0][0], max(memo[0][1], memo[0][2])) << endl;
    return 0;
}