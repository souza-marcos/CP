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
    vector<int> arr(n); for(int& el : arr) cin >> el;
    map<ll, int> has;
    ll pref = 0; 
    int last = -2, cnt = 0;
    has[0] = -1;
    for(int i = 0; i < n; i ++){
        pref += arr[i];
        
        if(has.count(pref) and has[pref] >= last){
            last = i;
            // cout << "I: " << i << "\n";
            cnt++;
        }
        // cout << "PREF: " << pref << endl;;
        has[pref] = i;
    }

    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
