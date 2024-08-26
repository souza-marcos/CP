#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;

    vector<int> v; 
    map<int, vector<int>> bags;
    for(int i = 0 ; i < n; i++) {
        int el; cin >> el;
        bags[el%k].push_back(el);
    }
    if(n == 1) { cout << 0 << endl; return;}

    ll cnt= 0;
    bool used = false;
    
    for(auto& [key, vec]: bags){
        if(sz(vec)%2){
            if(used) { cout << -1 << endl; return; }
            used = true;
        }
        sort(vec.begin(), vec.end());
        
        if(sz(vec) % 2){
            vector<ll> pre(sz(vec)/2 + 4), suf(sz(vec)/2 + 4);
            for(int i = 0; i + 1 < sz(vec); i+=2){
                pre[i/2 + 1] = pre[i/2] + (vec[i + 1] - vec[i]) /k;
            }

            for(int i = sz(vec)-1; i -1 > 0; i-=2){
                suf[ceil(i/2.0)] = suf[ceil(i/2.0) + 1] + (vec[i] - vec[i-1])/k;
            }

            ll minval = INF;
            for(int i = 0; i < sz(vec); i++){
                ll val =  pre[i/2] + suf[(i + 1)/2 + 1] + (i%2 == 1? (vec[i + 1] - vec[i-1])/k : 0);
                minval = min(minval, val);
            }
            cnt += minval;
        }else{
            for(int i = 0; i + 1 < sz(vec); i+=2){
                cnt += (vec[i + 1] - vec[i]) /k;
            }
        }
    }
    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
