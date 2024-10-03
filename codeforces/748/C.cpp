#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int n, k;
vector<ll> mice, pref;

bool valid(int guess){
    int pos_cat = n;
    for(int i = guess-1; i >= 0; i--){
        if(pos_cat <= mice[i]) return false;
        pos_cat -= mice[i];
    }
    return true;
}

void solve(){
    cin >> n >> k;
    mice.resize(k); for(auto& el: mice) cin >> el, el = n - el;
    sort(mice.begin(), mice.end());
    // pref.resize(k + 1); pref[0] = 0;
    // for(int i = 0; i < k; i ++){
    //     pref[i + 1] = pref[i] + mice[i];
    // }

    int l = 0, r = k + 1;
    while(l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
