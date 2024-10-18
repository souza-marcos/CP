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
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    sort(arr.begin(), arr.end());
    ll last=arr[0];
    for(int i = 1; i < n; i ++){
        last= (last + arr[i])/2;
    }

    cout << last << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();    

    return 0;
} 
