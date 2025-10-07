#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _ 

    int n, q; cin >> n >> q;

    set<pair<int, int>> id;
    for(int i = 0; i < n; i ++) id.insert({i, 1});
    
    while(q --){
        int init, to; cin >> init >> to;
        init --, to --;
        int sum = 0;
        while(sz(id) > 0 and id.begin()->first <= init){
            sum += id.begin()->second;
            id.erase(id.begin());
        }
        auto it = id.lower_bound(make_pair(to, 0));
        cout << sum << endl;
        if(it != id.end() and it->first == to){
            sum += it->second;
            id.erase(it);
        }
        id.insert({to, sum});
    }
    return 0;
} 
