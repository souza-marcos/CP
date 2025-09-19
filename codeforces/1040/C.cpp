#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
// #define int ll

void solve(){

    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for(auto &[fr, sn] : arr) cin >> fr >> sn;

    vector<int> id(2*n + 1), szo(2*n + 1, 1);
    iota(id.begin(), id.end(), 0);


    auto find = [&](auto&& self, int a) -> int {
        return id[a] = (id[a] == a? a : self(self, id[a]));
    };

    auto uni = [&](int a, int b) -> void {
        a = find(find, a), b = find(find, b);
        if(a == b) return;
        if(szo[a] < szo[b]) swap(a, b);
        id[b] = a;
        szo[a] += szo[b];
    };

    vector<int> res;
    int i = 1;
    for(auto [fr, sn] : arr){
        if(find(find, fr) != find(find, sn))
            res.push_back(i), uni(fr, sn);
        i ++;
    }
    cout << sz(res) << endl;
    for(auto el : res) cout << el << " ";
    cout << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
} 
