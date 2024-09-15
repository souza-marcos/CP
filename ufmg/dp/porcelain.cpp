// https://codeforces.com/contest/148/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

int n, m;
vector<vector<int>> prat;

int memo[101][10010];
vector<vector<int>> maxprat;

int dp(int i, int j){
    if(i == n) return 0;
    if(j < 0) return -INF;
    int &p = memo[i][j];
    if(p != -1) return p;

    int maxval = 0;
    for(int k = 0; k <= min(sz(maxprat[i])-1, j); k ++){
        maxval = max(dp(i + 1, j - k) + maxprat[i][k], maxval);
    }
    return p = maxval;
}

int main(){ _
    
    cin >> n >> m;
    prat.resize(n);

    int t;
    vector<vector<int>> pref;
    pref.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> t;
        prat[i].resize(t);
        pref[i].resize(t + 1);
        pref[i][0] = 0;
        for(int j = 0; j < t; j ++) {
            cin >> prat[i][j];
            pref[i][j + 1] = pref[i][j] + prat[i][j];
        }
    }

    maxprat.resize(n);
    for(int i = 0; i < n; i ++){

        maxprat[i].resize(sz(prat[i]) + 1);
        maxprat[i][0] = 0;
        for(int j = 1; j <= sz(prat[i]); j++){
            int maxval = 0, sum = 0;
            for(int k = 0; k <= j; k ++){
                sum = pref[i][j - k] + (pref[i][sz(prat[i])] - pref[i][sz(prat[i]) - k]);
                if(maxval < sum) maxval = sum;
            }
            maxprat[i][j] = maxval;
        }
    }
    // for(auto row: maxprat) {
    //     for(auto el : row ) cout << el << " ";
    //     cout << endl;
    // }
    // cout << endl;

    // DP to calculate how best I can do in 0..i when i break j porcelain.
    memset(memo, -1, sizeof memo);
    cout << dp(0, m) << endl;
    return 0;
}


