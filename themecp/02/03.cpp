#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    string s; cin >> s;
    set<pair<pair<int, int>, pair<int, int>>> vis;
    
    pair<int, int> last = {0, 0};
    map<char, pair<int, int>> mvs = {
        {'N', {0, -1}},
        {'S', {0, 1}},
        {'W', {-1, 0}},
        {'E', {1, 0}}
    };

    int cnt = 0;

    for(auto c : s){
        auto [newi, newj] = mvs[c];
        newi += last.first, newj += last.second;
        if(vis.count({{newi, newj},last})) cnt += 1;
        else cnt += 5, vis.insert({{newi, newj},last}), vis.insert({last, {newi, newj}});

        last = {newi, newj};
    }

    cout << cnt << endl;
}

int main(){ _
    int t; cin >> t;
    while (t --) solve();
    return 0;
} 
