#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;

vector<set<int>> g(MAX);
int n, q; 
vector<int> order;
vector<int> limit;
map<int, int> start;

int dfs(int node){
    order.push_back(node);
    start[node] = order.size() -1;
    int sum = 0;
    for(auto el: g[node]) {
        limit[el] = dfs(el);
        sum += limit[el];
    }
    return sum + g[node].size();
}


int main(){ _

    cin >> n >> q;

    limit.resize(n);

    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        g[a].insert(i);
    }

    limit[0] = dfs(0);

    // for(auto el : order) cout << el + 1 << " ";
    // cout << endl;


    // for(auto el : limit) cout << el << " ";
    // cout << endl;

    // for(auto [key, val]: start){
    //     cout << key << " " << val << endl;
    // }

    while(q --){
        int u, k; cin >> u >> k; u --, k --;
        if(limit[u] < k) cout << -1 << endl;
        else cout << order[start[u] + k] + 1 << endl;
    }


    return 0;
} 
