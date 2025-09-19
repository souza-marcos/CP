#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    ll n, x; cin >> n >> x;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;
    int i = 0, j = 0; // i => the left inside, j => the next on the right  

    int cnt = 0;
    ll sum = 0;
    while(j < n){
        sum += arr[j], j ++;
        while(sum > x) sum -= arr[i], i ++;
        if(sum == x) cnt ++;
    }
    cout << cnt << endl;
    return 0;       
}
