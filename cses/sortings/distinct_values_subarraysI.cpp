#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n; cin >> n;
    vector<int> arr(n); for(int& el: arr) cin >> el;

    set<int> cnt;
    int i = 0, j = 0;
    ll res = 0;
    while(j < n){
        while(cnt.count(arr[j])){
            cnt.erase(arr[i]);
            i++;
        }
        cnt.insert(arr[j]);
        res += j-i+1;
        j ++;
    }
    cout << res << endl;
    return 0;       
}
