#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

const int MAX = 21;

int n, m;
int table[MAX][MAX];
bool vis[MAX][MAX];


bool canieat(int i, int j, int opi, int opj){
    if(!(i + 2 * opi >= 0 and i + 2 * opi < n and j +  2 * opj >=0 and j + 2 * opj < m)) return false;
    return (table[i + 2 * opi][j + 2 * opj] == 0 and table[i + opi][j + opj] == 2);
}
int cot = 0;

vector<pair<int, int>> moves{
    {-1, -1}, {-1, 1}, {1, 1}, {1, -1}
};
int dfs(int i, int j){
    int max_cur = 0; 
    for(auto [opi, opj]: moves){
        if(canieat(i, j, opi, opj) and !vis[opi + i][opj + j]){
            vis[i + opi][j + opj] = true;
            int cur = 1 + dfs(i + 2 * opi, j + 2 * opj);
            max_cur = max(max_cur, cur);
            vis[i + opi][j + opj] = false;
        }
    }
    return max_cur;
}


void solve(){
    memset(table, -1, sizeof(table));
    memset(vis, 0, sizeof(vis));
    for(int i = n - 1; i >= 0; i--){
        for(int j = (n - 1 - i) % 2 != 0; j < m; j+=2){
            cin >> table[i][j];
        }
    }

    int maxp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(table[i][j] == 1) {
                table[i][j] = 0;
                int qt = dfs(i, j);
                maxp = max(maxp, qt);
                table[i][j] = 1;
            }
        }
    }
    cout << maxp << endl;
}

int main(){//_

    while(cin >> n >> m and n != 0) solve();
    return 0;
}