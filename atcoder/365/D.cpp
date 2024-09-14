#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
int n; string s;
const int MAX = 2e5 + 10;
int memo[MAX][26];

int dp(int i, char cur) {
    if(i == n) return 0;
    if(s[i] == 'R' and cur == 'S') return -INF;
    if(s[i] == 'S' and cur == 'P') return -INF;
    if(s[i] == 'P' and cur == 'R') return -INF;

    int &p = memo[i][cur-'A'];
    if(p != -1) return p;

    int maxv = 0;
    int win = 0;
    if(cur == 'S')      maxv = max(maxv, max(dp(i + 1, 'R'), dp(i + 1, 'P'))), win = (s[i] == 'P');
    else if(cur == 'R') maxv = max(maxv, max(dp(i + 1, 'S'), dp(i + 1, 'P'))), win = (s[i] == 'S');
    else                maxv = max(maxv, max(dp(i + 1, 'R'), dp(i + 1, 'S'))), win = (s[i] == 'R');
    return p = maxv + win;
}

int main(){ _
    cin >> n >> s;
    memset(memo, -1, sizeof memo);
    // P R S

    int maxv = max({dp(0, 'R'), dp(0, 'S'), dp(0, 'P')});
    cout << maxv << endl;
    
    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < 26; j ++) cout << memo[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
} 
