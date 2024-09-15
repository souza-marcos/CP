#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);

#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<ll> pre(n + 1);
    pre[0] = 0;
    for(int i = 1; i<=n; i++){
        int a; cin >> a;
        pre[i] = pre[i-1] + a;
        // cout << pre[i] << " ";
    }
    // cout << endl;
    string label; cin >> label; 
    int i = 0, j = n-1;
    ll ans = 0;
    while(i < j){
        while(i <= n-1 and label[i] != 'L') i++;
        while(j >= 0 and label[j] != 'R') j--;
        if(j < 0 or i >= n ) break;

        if(i > j) break;
        ans += pre[j + 1]-pre[i];   
        i ++, j--;
    }
    cout << ans << endl;

}

int main(){_
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
