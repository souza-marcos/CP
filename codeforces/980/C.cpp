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
    vector<pair<int, int>> arr(n); 
    map<int, int> mp;
    for(auto& [a,b] : arr) cin >> a >> b, mp[a] ++, mp[b] ++;

    map<int, pair<int, int>> relations; 
    int lessels = 0;
    for(auto [k, val]: mp){
        pair<int, int> res = {lessels, 2*n - lessels - val};
        relations[k] = res; 
        lessels += val; 
    }

    vector<tuple<int, int>> newarr(n); 
    for(int i = 0; i < n; i ++){
        auto [a, b] = arr[i];
        auto& [newa, in] = newarr[i];
        auto [lessels, greats] = relations[a];
        newa = lessels - (b < a); 
        auto [lesselso, greatso] = relations[b];
        newa += lesselso - (a < b);

        in = i;
    }

    sort(newarr.begin(), newarr.end());
  
    for(auto [a, i] : newarr){
        // cout << a << endl;
        cout << arr[i].first << " " << arr[i].second << " ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
