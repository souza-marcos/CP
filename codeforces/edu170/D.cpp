#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    vector<int> cnti(m + 1), cnts(m + 1);

    vector<int> a(n); 
    for(int& el: a){
        cin >> el;
        if(el > 0) cnti[el] ++;
        else if(el < 0) cnts[-el] ++;
    }

    vector<int> dp(m+1); 
    // dp(j) = max pontos que consigo usando 
    // j pontos de inteligencia nos i primeiros elementos;
    // Take Away => Se a atualização de uma dp demora (O(n)) 
    // mas ela eh executada um numero limitado de vezes

    int points = 0;
    for(int i = 0; i < n; i ++){
        if(a[i] > 0) cnti[a[i]] --;
        else if(a[i] < 0) cnts[-a[i]] --;
        else { // el == 0 => Gain a atribute point
            points++;
            // cout << i << ": ";
            for(int j = points; j >= 0; j --){
                dp[j] = max(dp[j] + cnts[points-j], 
                        (j == 0?0:dp[j-1]) + cnti[j]);
                // cout << dp[j] << " ";
            }
            // cout << endl;
        }
    }
    int maxv = 0;
    for(int i = 0; i <= m; i ++){
        maxv = max(maxv, dp[i]);
    }
    cout << maxv << endl;

    return 0;
} 
