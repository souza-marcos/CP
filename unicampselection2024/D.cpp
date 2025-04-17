#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, k; cin >> n >> k;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    ll sum=0, sq = 0;
    for(int i=0; i < k; i ++) sum += arr[i], sq += arr[i] * arr[i];

    int l = 0, r = k-1;
    ll mindp = (k*sq - 2*sum*sum + sum*sum);
    cout << fixed << setprecision(10);
    for(int i = k; i < n; i ++){
        // tira i-k, add i
        sum -= arr[i-k], sum += arr[i];
        sq -= arr[i-k]*arr[i-k], sq += arr[i] * arr[i];

        ll val =  (k*sq - 2*sum*sum + sum*sum);
        if(val < mindp) l = i-k+1, r = i, mindp = val;
    }
    cout << l + 1 << " " << r + 1 << endl;
    cout << sqrt(mindp)/k << endl;

} 
