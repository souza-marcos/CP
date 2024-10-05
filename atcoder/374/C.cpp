#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _

    int n; cin >> n;
    ll sum = 0;
    vector<int> arr(n); for(int& el: arr) cin >> el, sum += el;

    ll minv = LINF;
    for(int i = 0; i < (1 << n); i++){
        ll cur = 0;
        for(int j = 0; j < n; j ++){
            if(i & (1 << j)) cur += arr[j]; 
        }
        minv = min(minv, max(cur, (sum - cur)));
    }

    cout << minv << endl;

    return 0;
} 
