#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    ll mat[n][m];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> mat[i][j];
        }
    }
    map<pair<int, int>, vector<ll>> conjs; // {i, j} => {# els, sum}
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            auto& el = conjs[{min(i + 1, n-i), min(j + 1, m-j)}];
            el.push_back(mat[i][j]);
        }
    }

    ll cumu = 0;

    auto calc = [&](vector<ll>& arr, ll goal) -> ll {
        ll diff = 0;
        for(auto el : arr){
            diff += abs(el - goal);
        };
        return diff;
    };


    for(auto& [k, arr]: conjs){
        if(sz(arr) <= 1) continue; 
        sort(arr.begin(), arr.end()); // The answer is the median (Why?) but i will test all
        ll val = LINF;
        for(auto el : arr) val = min(val, calc(arr, el));
        cumu += val;
    }
    cout << cumu << endl;

}


int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
