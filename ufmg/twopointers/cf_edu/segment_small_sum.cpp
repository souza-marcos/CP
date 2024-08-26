#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    ll n, s; cin >> n >> s;
    vector<ll> v(n), pre(n+1);
    for(int i = 0; i< n; i++) {
        cin >> v[i], pre[i + 1] = pre[i] + v[i];
    }

    int i = 0, j = 0;
    int maxinterval = 0;
    while (i <= n){
        while (pre[i] - pre[j] > s) j++;
        maxinterval = max(maxinterval, i - j);
        i++;
    }
    cout << maxinterval << endl;
    return 0;
} 
