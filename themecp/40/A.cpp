// https://codeforces.com/problemset/problem/1934/B
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

/*
0 + 1 => 1
1 + 2 => 3
3 + 3 => 6
6 + 4 => 10
10 + 5 => 15
*/

int32_t main(){ _ 

    vector<int> dp(16, INF);
    dp[0] = 0;
    vector mvs = {1, 3, 6, 10, 15};
    for(int i : mvs) dp[i] = 1;
    for(int i = 2; i < 16; i ++){
        for(int j : mvs) if(i - j >= 0) dp[i] = min(dp[i], dp[i-j] + 1);
        // cout << dp[i] << " ";
    }
    // cout << endl;


    int q; cin >> q;
    while(q--){
        int el; cin >> el;

        int cnt = 0;
        if(el > 15){
            cnt = el/15 - 1;
            el = el - cnt*15;


            int minel = LINF;
            for(int i = 1; i <= 15; i ++){
                if(el - i <= 15) minel = min(minel, cnt + dp[i] + dp[el-i]);
            }
            cnt = minel;
        }
        else cnt = dp[el];

        cout << cnt << endl;
    }



} 
