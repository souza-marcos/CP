#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

void solve(){

    int n; cin >> n;
    int arr[n];
    ll suff[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    suff[n - 1] = arr[n - 1];
    for(int i = n-2; i >= 0; i --) suff[i] = arr[i] + suff[i + 1];

    ll ans = arr[0], cont = 1;
    for(int i = 1; i < n; i ++){
        if(suff[i] > 0){ // break the subarray
            cont ++;
        }
        ans += arr[i] * cont;
    }
    cout << ans << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
