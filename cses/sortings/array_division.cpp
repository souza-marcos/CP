#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, k; cin >> n >> k;
    vector<ll> arr(n); 
    ll minv = -INF;
    for(ll& el : arr) cin >> el, minv = max(minv, el);


    auto check = [&](ll guess) -> bool {
        int cnt = 1;
        ll acc = 0;
        for(int i = 0; i < n; i ++){
            if(arr[i] + acc > guess){
                cnt ++;
                acc = arr[i];
            } else acc += arr[i];
        }
        return cnt <= k;
    };

    ll l = minv-1, r = 1e16;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(check(m)) r=m;
        else l=m;
    }
    cout << r << endl;
    return 0;       
}
