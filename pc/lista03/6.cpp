#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

#define MAXTAB 101
#define MAXPAWN 16


int n, m, k;
int cod[MAXTAB][MAXTAB], dist[MAXPAWN][MAXPAWN];
int memo[1<<MAXPAWN][MAXPAWN];

void fill_dist(int piece, int x, int y){
    vector<pair<int, int>> mvs = {
        {-2, -1},{-1, -2},{1, -2},{2, -1},
        {-2, 1},{-1, 2},{1, 2},{2, 1}
    };

    queue<tuple<int, int, int>> q; q.push({x, y, 0});
    int vis[n][m]; memset(vis, -1, sizeof vis);
    vis[x][y] = 0;

    while(!q.empty()){
        auto [i, j, val] = q.front(); q.pop();
        if(cod[i][j] >= 0) dist[piece][cod[i][j]] = val;

        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(newi >= 0 and newi < n and newj >= 0 and newj < m 
                and cod[newi][newj] != -2 and vis[newi][newj] < 0){
                q.push({newi, newj, val + 1});
                vis[newi][newj] = val + 1;
            }
        }
    }
}

int dp(int qtd, int mask, int cur){
    if(qtd == k) return dist[cur][0]; // Distancia do ultimo peao vis para a pos inicial do cavalo
    
    int &p = memo[mask][cur];
    if(p != -1) return p;

    int minmove = INF;
    for(int i = 1; i <= k; i++){
        if(mask & (1 << i)) continue; // Ja comeu o peao

        minmove = min(minmove, 
            dp(qtd + 1, mask | (1 << i), i) + dist[cur][i]
        );
    }
    return p = minmove;
}

void solve(){

    int pawn = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s; 
        for(int j = 0; j < m; j++){
            if(s[j]=='P') cod[i][j] = ++pawn;
            else if(s[j] == 'C') cod[i][j] = 0;
            else if(s[j] == '#') cod[i][j] = -2;
            else cod[i][j] = -1;
        }
    }

    for(int i = 0; i <= k; i ++){
        for(int j = 0; j <= k; j++){
            dist[i][j] = INF;
        }
    }

    // BFS
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(cod[i][j] >= 0) fill_dist(cod[i][j], i, j);
        }
    }

    // for(int i = 0; i <= k; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dist[i][j] << " ";
    //     } cout << endl;
    // }
    // cout << "========\n";

    memset(memo, -1, sizeof memo);

    // DP
    int minmove = INF;
    for(int i = 1; i <= k; i ++){
        minmove = min(minmove, dp(1, 1 << i, i) + dist[0][i]);
    }
    cout << minmove << endl;
}

int main(){_
    while(cin >> n >> m >> k and n != 0) solve();
    return 0;
}