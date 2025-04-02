#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        arr[i] = a * (i&1? 1: -1);
    }


    set<ll> pre = {0};
    ll sum = 0;
    for(auto el : arr){
        sum += el;
        if(pre.count(sum)){
            cout << "YES\n";
            return;
        }
        pre.insert(sum);
    }

    cout << "NO\n";
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
