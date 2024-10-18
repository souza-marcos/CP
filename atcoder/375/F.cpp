#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 1e18;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAXN = 301;
int n, m, q;
vector<vector<ll>> mindist, g;
stack<tuple<int, int, int>> queries;

int main(){ _
    cin >> n >> m >> q;
    mindist.resize(n, vector<ll>(n, LINF));
    g.resize(n, vector<ll>(n, LINF));

    vector<tuple<int, int, ll>> roads;
    for(int i = 0; i < m; i ++){
        int a, b, c; cin >> a >> b >> c;
        a --, b--;
        g[a][b] = c;
        g[b][a] = c; 
        roads.push_back({a, b, c});
    }
    for(int i = 0; i < n; i ++) g[i][i] = 0;

    while(q --){
        int t, x, y; cin >> t;
        if(t == 1){
            cin >> x; x--;
            queries.push({1, x, 0});
            auto [a, b, c] = roads[x];
            g[a][b] = LINF;
            g[b][a] = LINF;
        }else{
            cin >> x >> y; x--, y --;
            queries.push({2, x, y});
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++)
            mindist[i][j] = g[i][j];
        mindist[i][i] = 0;
    }

    // Run floyd-warshal
    for(int k = 0; k < n; k ++){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
            }
        }
    }

    stack<int> res;
    while(!queries.empty()){
        auto [t, x, y] = queries.top(); queries.pop();
        if(t == 2){
            ll val = mindist[x][y];
            res.push(val>=1e15?-1:val);
        }
        else {
            auto [ra, rb, rc] = roads[x];
            mindist[ra][rb] = mindist[rb][ra] = min(mindist[ra][rb], rc);
            
            for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                mindist[i][j] = min(mindist[i][j], mindist[i][ra] + mindist[ra][j]);
            
            for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                mindist[i][j] = min(mindist[i][j], mindist[i][rb] + mindist[rb][j]);
        }
    }

    while(!res.empty())
        cout << res.top() << endl, res.pop();


    return 0;
} 
