#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define ss second 
#define ff first 
#define sz(x) (int)x.size()

int32_t main() { _
	
    int n, m; cin >> n >> m;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(n, LINF);
    dist[0] = 0;
    pq.push({0, 0});
    while(sz(pq)){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist[v] < d) continue;
        for(auto [u, w]: g[v]) {
            int newd = max(d, w);
            if(newd < dist[u]){
                dist[u] = newd;
                pq.push({newd, u});
            }
        }
    }

    int d; cin >> d;
    vector<pair<int, int>> dests(d);
    vector<int> escadas(d);
    for(auto& [el, idx] : dests) {
        cin >> idx;
        idx--;
        el = dist[idx];
    }
    for(int& el : escadas) cin >> el;
    sort(dests.begin(), dests.end());
    sort(escadas.begin(), escadas.end());


    int cnt = 0;
    int i = 0, j = 0;
    while(i < d and j < d){
        if(escadas[i] >= dests[j].first){
            i += 1, j += 1;
            cnt ++ ;
        }
        else i ++;
    }

    cout << cnt << endl;
}