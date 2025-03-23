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
    int ans = 0;


    if(n % 2 == 1) { 
        n-=k;
        ans ++;
    }

    ans += ceil(n / (double)(k-1)); 
    cout << ans << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
