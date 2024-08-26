#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N1, N2, K1, K2, MOD = 1e8;

map<tuple<int, int, int, int, int>, int> memo;

int dp(int i, int res1, int res2, int seg1, int seg2){
    if(seg1 > K1 or seg2 > K2) return 0;
    if(i == N1 + N2) return 1;
    if(res1 == 0 and res2 == 0) return 0;

    if (memo.count({i, res1, res2, seg1, seg2}) > 0) return memo[{i, res1, res2, seg1, seg2}];

    int& p = memo[{i, res1, res2, seg1, seg2}] = 0;

    if(res1 == 0) return p = dp(i + 1, res1, res2 - 1, 0, seg2 + 1);
    else if(res2 == 0) return p = dp(i + 1, res1 -1, res2, seg1+ 1, 0);
    else{
        return p = (dp(i + 1, res1 - 1, res2, seg1 + 1, 0) + dp(i + 1, res1, res2 - 1, 0, seg2 + 1))%MOD;
    }
}

int main(){ _
    cin >> N1 >> N2 >> K1 >> K2;

    cout << dp(0, N1, N2, 0, 0)%MOD << endl; // choose soldier 0 -- n-1, Com N1 e N2 restantes, rest1 seguidos, rest2 seguidos.

    return 0;
} 
