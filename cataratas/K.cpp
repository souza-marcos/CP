#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

int32_t main(){ _

    int n, l, k; cin >> n >> l >> k;
    map<string, int> mp;
    vector<vector<int>> g(n);
    int cur_add_node = n;

    for(int i = 0; i < n; i ++){
        string s; cin >> s;

        for(int j = 0; j + k <= sz(s); j ++){
            int val = -1;
            if(mp.count(s.substr(j, k)) == 0){
                val = cur_add_node ++;
                mp[s.substr(j, k)] = val;
                g.push_back({});
            }
            else 
                val = mp[s.substr(j, k)];
            
            g[i].push_back(val);
            g[val].push_back(i);
        }
    }

    if(n == 1){
        cout << 0 << endl;
        exit(0);
    }

    vector<int> dist(sz(g), -1);
    queue<int> q; q.push(0);
    dist[0] = 0;
    while(sz(q)){
        auto v = q.front();
        q.pop();

        if(v == n-1){
            cout << dist[v]/2 -1 << endl;
            exit(0);
        }

        for(auto u : g[v]){
            if(dist[u] == -1){
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    cout << -1 << endl;
} 
