#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl "\n"
#define sz(x) (int)x.size()

int main(){ _
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& el: a) {cin >> el; el --;}

    ll memo[n];
    for(int i = 0; i < n; i++){
        ll res = 0;
        int l = min(i, k);
        int r = min(k + i, n-1);
        memo[i] = l + r + 1;
        if(a[i] != -1){
            int inte = min(a[i] + k, n-1) - (i - l) + 1;
            memo[i] = memo[i] - (inte >= 0 ? inte: 0);
        }
        cout << memo[i] << " ";
    }cout << endl;

    return 0;
} 
