#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    // reduzir para a mediana  
    int n; cin >> n;
    vector<ll> arr(n); for(ll& el : arr) cin >> el;
    
    sort(arr.begin(), arr.end());
    ll end = arr[n/2];
    ll res = 0;
    for(ll& el : arr) res += abs(end - el);
    cout << res << endl;
    return 0;   
} 
