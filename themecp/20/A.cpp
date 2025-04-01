#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, x; cin >> n>> x;
    vector<ll> arr(n); for(auto& el: arr) cin >> el;

    sort(arr.begin(), arr.end());
    map<ll, queue<ll>> mp;
    for(auto el : arr){
        mp[el%x].push(el);
    }
    
    int cur = 0;
    while(true){

        if(mp[cur%x].empty()) break;
        ll el = mp[cur%x].front();

        if(el > cur) break;
        else mp[cur%x].pop(), cur ++;
    }
    cout << cur << endl;
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
