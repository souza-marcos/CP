#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for(auto& row : v) cin >> row[0] >> row[1] >> row[2]; 
    int memo[n][3];

    int i = 0; while(i < 3) memo[0][i] = v[0][i], i ++;
    for(int i=0; i < n-1; i ++){
        for(int j = 0; j < 3; j ++) memo[i+1][j] = -INF;
        for(int j = 0; j < 3; j ++){
            auto& n1 = memo[i+1][(j+1)%3], &n2 = memo[i+1][(j+2)%3]; 
            n1 = max(n1, memo[i][j] + v[i+1][(j+1)%3]);
            n2 = max(n2, memo[i][j] + v[i+1][(j+2)%3]);
        }
    }
    cout << max(memo[n-1][0], max(memo[n-1][1], memo[n-1][2])) << endl;

    return 0;
} 
