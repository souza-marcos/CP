#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

map<ll, ll> memo;
vector<pair<ll, ll>> arr;

bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b){
    if(a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

ll dp(ll cur_arr_sz){

    if(memo.count(cur_arr_sz)) return memo[cur_arr_sz];

    auto& p = memo[cur_arr_sz];

    auto lb = lower_bound(arr.begin(), arr.end(), make_pair(cur_arr_sz, -LINF), comp);
    auto ub = upper_bound(arr.begin(), arr.end(), make_pair(cur_arr_sz, LINF), comp);
    
    ll maxv = 0;
    for(auto it = lb; it != ub; ++it){
        maxv = max(maxv, dp(cur_arr_sz + (*it).second) + (*it).second);
    }
    return p = maxv;
}

void solve(){
    memo.clear(); // Oh my gosh, sempre isso tah doido
    int n; cin >> n;
    arr.resize(n);
    int i = 0;
    for(auto& [tam, val] : arr){
        ll a; cin >> a;
        tam = a + i;
        val = i;
        i ++;
    }

    sort(arr.begin(), arr.end());
    ll maxv = dp(sz(arr));
    cout << maxv + sz(arr) << endl;


    // for(auto [k, val] : memo){
    //     cout << k << "=> " << val << endl;
    // }
    // cout << "===========\n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
