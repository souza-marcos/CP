#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;

int main(){ _
    int h, w; cin >> h >> w;
    ll memo[h][w];
    string s;

    for(int i = 0; i < h; i ++){
        cin >> s;
        for(int j = 0; j < w; j ++){
            bool ok = (s[j]=='.');
            memo[i][j] = 0;
            if(!ok) continue;
            if(i > 0) memo[i][j] = memo[i-1][j];
            if(j > 0) {
                memo[i][j] = (memo[i][j] + memo[i][j-1]) % MOD;
                continue;
            }
            if(!i and !j) memo[i][j] = 1;
        }
    }
    cout << memo[h-1][w-1] << endl;
    return 0;
} 
