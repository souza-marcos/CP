#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main() { _

    // The reason is that we get previous init that maximizes my score
    int n; cin >> n;
    vector<int> arr(n); for(int& el : arr) cin >> el;
    map<int, int> mindp;
    mindp[arr[0]] = 1;
    for(int i = 1; i < n; i ++){
        if(mindp.count(arr[i]) == 0) mindp[arr[i]] = INF;        
        mindp[arr[i]] = min(mindp[arr[i-1]] + 1, mindp[arr[i]]);
    }
    cout << mindp[arr[n-1]] << endl;
}