#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n, x; cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int& el : price) cin >> el;
    for(int& el : pages) cin >> el;

    vector<int> dp(x + 1); // maximum pages to get with i first books and j budget 
    for(int i = 0; i < n; i++){
        for(int j = x-price[i]; j >= 0; j--){
            dp[j+price[i]] = max(dp[j+price[i]], dp[j] + pages[i]);
        }
    }
    cout << dp[x] << endl;
    return 0;       
}
