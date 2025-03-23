#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, s1, s2; cin >> n >> s1 >> s2; s1--, s2--;
    int m1, m2; cin >> m1;
    vector<vector<int>> g(n), h(n);
    for(int i = 0; i < m1; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> m2;
    for(int i = 0; i < m2; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        h[a].push_back(b);
        h[b].push_back(a);
    }

    set<pair<int, int>> vis; 
    queue<pair<int, int>> q;
    q.push({s1,s2});

    map<pair<int, int>, int> what;
    int cnt = 1;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            what[{i, j}] = cnt ++;
        }
    }

    vector<vector<pair<int, int>>> out(n * n + 1); // to, weight

    while(sz(q)){   
        auto [v1, v2] = q.front(); q.pop();
        vis.insert({v1, v2});
         
        for(auto u1: g[v1]){
            if(u1 == v1) continue;

            for(auto u2: g[v2]){
                if(u2 == v2) continue;
                
                // cout << "FROM " << v1 << ", " << v2 << " TO: " << u1 << " " << u2 << endl;
                out[what[{v1, v2}]].push_back({what[{u1, u2}], abs(u1 - u2)});
                // out[what[{u1, u2}]].push_back({what[{v1, v2}], abs(v1 - v2)});
                if(vis.count({u1, u2}) == 0) q.push({u1, u2});
            }
        }
    }


    map<int, pair<int, int>> ids;
    for(auto [k, val]: what) 
        ids[val] = k;
    

    cout << "Vertices:" << endl;

    for(auto [val, k]: ids){
        cout << val << " => ";
        cout << "(" << k.first + 1 << "," << k.second + 1 << ")" << endl;
    }

    cout << "EDGES:\n";

    for(auto [val, k]: ids){
        for(auto u : out[val]){
            cout << val << " " << u.first  << endl;
        }
    }

} 
