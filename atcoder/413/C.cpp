#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
   
int main(){ _

    vector<pair<ll, ll>> arr; // element - quantity
    int cur_element = 0;
    
    int q; cin >> q;
    while(q --){
        int t; cin >> t;
        if(t == 1){
            ll c, x; cin >> c >> x;
            arr.push_back({x, c});
        }else {
            ll k; cin >> k;
            ll res = 0;
            while(cur_element < sz(arr) and arr[cur_element].second <= k){
                k -= arr[cur_element].second;
                res += arr[cur_element].first * arr[cur_element].second;
                cur_element ++;
            }
            if(k > 0){
                res += arr[cur_element].first * k;
                arr[cur_element].second -= k;
            }
            cout << res << endl;
        }   

    }
    return 0;
} 
