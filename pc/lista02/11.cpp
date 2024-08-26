#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

const int MAX = 5e3 + 1;
int memo[MAX][MAX];

int main(){_

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    for(int i = 0; i <= n; i++) memo[i][m] = 0;
    for(int i = 0; i <= m; i++) memo[n][i] = 0;
    

    for(int i = s.size() -1; i >= 0; i --){
        for(int j = t.size() -1; j >= 0; j--){
            if(s[i] == t[j]) memo[i][j] = 1 + memo[i + 1][j + 1];
            else memo[i][j] = max(memo[i + 1][j], memo[i][j + 1]); 
        }
    }

    cout << memo[0][0] << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < m; j++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}