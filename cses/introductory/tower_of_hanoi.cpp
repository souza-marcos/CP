#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

vector<pair<int, int>> res;

void solve(int cur_pile, int from, int to){
    if(cur_pile > 1) solve(cur_pile-1, from, from ^ to ^ 1 ^ 2 ^ 3);
    res.push_back({from, to});
    if(cur_pile > 1) solve(cur_pile-1, from ^ to ^ 1 ^ 2 ^ 3, to);
}

int main(){ _
    int n; cin >> n;
    solve(n, 1, 3);
    cout << sz(res) << endl;
    for(auto [from, to] : res)
        cout << from << " " << to << endl;

    return 0;
} 
