#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, a, b; cin >> n >> a >> b;
    vector<ll> arr(n+1);
    for(int i = 1; i < n + 1; i ++) 
        cin >> arr[i];

    if(n == 1){
        cout << b * arr[0] << endl;
        return;
    }

    vector<ll> pre(n + 1); // conquistando e movendo
    for(int i = 1; i < n + 1; i ++){
        pre[i] = pre[i-1] + (arr[i] - arr[i-1]) * b;
    }


    // Quero calcular até onde quero mudar a capital
    // [-1, n-2]
    ll changeCost = 0;
    for(int i = n-1; i >= 0; i --){
        changeCost = arr[i] * a;

    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
