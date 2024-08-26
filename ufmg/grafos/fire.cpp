#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;
int n, m;
char M[MAX][MAX];

bool vis[MAX][MAX];
int dist[MAX][MAX];

vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(pair<int, int> pos){
    return pos.f >=0 && pos.f < n && pos.s >= 0 && pos.s < m && M[pos.f][pos.s] != '#' && !vis[pos.f][pos.s];
}

void bfs_ms(vector<pair<int,int>> ms){
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);

    queue<pair<int, int>> q;
    for(auto s: ms) q.push(s), vis[s.f][s.s] = true, dist[s.f][s.s] = 0;

    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();

        for(auto w: mov){
            w.f += v.f, w.s += v.s;
            if(val(w)){
                q.push(w); vis[w.f][w.s] = true;
                dist[w.f][w.s] = dist[v.f][v.s] + 1;
            }
        }
    }

}

int bfs(pair<int, int> s){

    memset(vis, 0, sizeof vis);

    queue<pair<int, int>> q;
    q.push(s); vis[s.f][s.s] = true; dist[s.f][s.s] = 0;



    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();

        if(v.f == 0 || v.s == 0 || v.f == n-1 || v.s == m-1) 
            return dist[v.f][v.s] + 1; 

        for(auto w: mov){
            w.f += v.f, w.s += v.s;

            if(val(w) and dist[v.f][v.s] + 1 < dist[w.f][w.s]){
                q.push(w), vis[w.f][w.s] = true;
                dist[w.f][w.s] = dist[v.f][v.s] + 1;
            }
        }
    }
    return -1;
}

int main(){ _

    int t; cin >> t;
    while(t --){
        cin >> m >> n;

        vector<pair<int, int>> ms;
        pair<int, int> s;

        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            cin >> M[i][j];

            if (M[i][j] == '*') ms.push_back({i, j});
            else if (M[i][j] == '@') s = {i, j};

        }

        bfs_ms(ms);

        int ans = bfs(s);
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
} 
