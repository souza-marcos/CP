// https://codeforces.com/contest/977/problem/F
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    map<int, int> last; // last index 
    vector<pair<int, int>> dp(n); // szo - point index the previous 
    int maxv = -INF, maxidx = -1;
    for(int i = 0; i < n; i ++){
        if(last.count(arr[i]-1) == 0) dp[i] = {1, -1};
        else {
            int prev = last[arr[i]-1];
            dp[i] = {dp[prev].first + 1, prev};
        }

        if(dp[i].first > maxv) maxv = dp[i].first, maxidx = i;
        last[arr[i]] = i;
    }
    cout << maxv << endl;
    vector<int> res;
    while(maxidx != -1){
        res.push_back(maxidx + 1); 
        maxidx = dp[maxidx].second;
    }

    for(auto it = res.rbegin(); it != res.rend(); it ++){
        cout << *it << " ";
    }

    cout << endl;

} 
