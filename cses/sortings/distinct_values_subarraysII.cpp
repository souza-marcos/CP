#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    vector<int> arr(n);
    for(int& el : arr) cin >> el;

    ll res = 0;
    for(int i = 0, j = 0; i < n; i ++){
        cnt[arr[i]] ++;
        while(sz(cnt) > k){
            auto it = cnt.find(arr[j]);
            if(it->second == 1){
                cnt.erase(it);
            } else cnt[arr[j]]--;
            j ++;
        }
        res += i-j+1;
    }
    cout << res << endl;
    return 0;       
}
