#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl "\n"

int main(){ _

    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> last, first;
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        arr[i] = a;
        last[a] = i;
        if(first.count(a)==0) first[a] = i;
    }

    vector<int> dp(n, 0);
    for(int i = 0; i < n; i ++){
        if(i > 0) dp[i] = dp[i-1];
        if(last[arr[i]] != i) continue;

        int minv = first[arr[i]];
        int res = 0;
        set<int> cnt;
        bool ok = true;
        for(int j = i; j >= minv; j --){
            if(cnt.count(arr[j]) == 0) {
                if (last[arr[j]] > i) {
                    ok = false;
                    break;
                }
                minv = min(first[arr[j]], minv), res ^= arr[j];
                cnt.insert(arr[j]);
            }
        }
        
        if(ok) dp[i] = max(dp[i], res + (minv == 0? 0 : dp[minv-1]));
    }

    cout << dp[n-1] << endl;

    return 0;
} 
