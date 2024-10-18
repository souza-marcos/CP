#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int n, k; 
vector<int> arr;

bool valid(ll guess){
    ll slots = guess * k;
    for(int i = 0; i < n; i ++){
        if(arr[i] > guess) return false;
        slots -= arr[i];
        if(slots < 0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    arr.resize(n); for(int& el: arr) cin >> el;
    sort(arr.rbegin(), arr.rend());

    ll l = arr[0]-1, r = 1e16;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
