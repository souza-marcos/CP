#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;

int n;
int A[21][21];

int memo[21][1 << 21];

int dp(int last, int used_woman){
    if(used_woman == (1 << n)-1) return 1;
    if(last == n-1) return 0;

    int& p = memo[last][used_woman];
    if(p != -1) return p;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(used_woman & (1 << i)) continue;
        if(A[last + 1][i]) cnt += dp(last + 1, used_woman | (1 << i)), cnt %= MOD;
    }
    return p = cnt;
}

int main(){ _

    cin >> n;
    for(int i =0 ; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> A[i][j];
        }
    }
    memset(memo, -1, sizeof memo);
    int cnt = 0;
    for(int j = 0; j < n; j ++){
        if(A[0][j]) cnt += dp(0, 1 << j), cnt %= MOD;
    }

    cout << cnt << endl;
    return 0;
} 
