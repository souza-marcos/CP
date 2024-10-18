#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int n; 
struct Person { int power, team; }; 
vector<Person> v;
const int MAXN = 101;
const int MAXV = 510;
int memo[MAXN][MAXV][MAXV];

vector<int> pref;


int dp(int i, int ca, int cb){
    int lim = ceil(pref[n]/(double)3);
    if(ca > lim or cb > lim) return INF;
    if(i == n){
        int cc = pref[n] - ca - cb;
        if(ca == cb and ca == cc) return 0;
        else return INF;
    }

    int& p = memo[i][ca][cb];
    if(p != -1) return p;

    return p = min(
        dp(i + 1, ca + v[i].power, cb) + (v[i].team != 1),
        min(dp(i + 1, ca, cb + v[i].power) + (v[i].team != 2),
        dp(i + 1, ca, cb) + (v[i].team != 3))
    );
}

int main(){ _
    cin >> n;
    v.resize(n), pref.resize(n+1);
    pref[0] = 0;
    for(int i = 0; i < n; i ++){
        cin >> v[i].team >> v[i].power;
        pref[i + 1] = pref[i] + v[i].power;
    }

    memset(memo, -1, sizeof memo);
    int val = dp(0, 0, 0);
    if(val == INF) cout << -1 << endl;
    else cout << val << endl;

    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < ceil(pref[n]/3); j ++){
    //         for(int k = 0; k < ceil(pref[n]/3); k ++){
    //             cout << i << " " << j << " " << k << " " << memo[i][j][k] << endl;;
    //         }    
    //     }
    // }

    return 0;
} 
