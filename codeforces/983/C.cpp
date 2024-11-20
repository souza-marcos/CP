#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(ll& el: arr) cin >> el;
    sort(arr.begin(), arr.end());

    // Se eu transformar i menores em algum maior quantos maiores preciso transformar
    ll minv = INF;
    for(int i = 0; i <= n-2; i ++){

        minv = min(minv, 
            1LL* i + (arr.end() - lower_bound(arr.begin(), arr.end(), arr[i] + arr[i + 1]))
        );

    } 
    cout << minv << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
