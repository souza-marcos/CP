#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(int& el: arr) cin >> el;

    sort(arr.begin(), arr.end());

    ll cnt = 0, cur = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]-cur ==0) {
            cnt ++;
            continue;
        }
        ll val = (arr[i] - cur) * (n - i);
        if(val >= k){
            cnt += k;
            break;
        }
        k -= val;
        cur = arr[i];
        cnt += val + 1;
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
