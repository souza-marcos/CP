#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
// #define int ll

int32_t main(){ _
    
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));

    vector<ll> arr(k); for(auto& el: arr) cin >> el;
    
    vector<queue<pair<int, int>>> to_process(k);

    vector<ll> cnt(k);
    vector<vector<int>> dist(n, vector<int>(m,-1));
    for(int i = 0; i < n; i ++){
        string s; cin >> s;
        for(int j = 0; j < m; j ++){
            if(s[j] != '.' and s[j] != '#'){
                to_process[s[j]-'1'].push({i, j});
                cnt[s[j]-'1'] += 1;
                dist[i][j] = 0;
            }
            grid[i][j] = (s[j] == '.' ? 1 : 0); 
        }
    }

    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<ll> can(k);
    for(int round = 0; round < 2 * n * m ; round ++){
        for(int p = 0; p < k; p ++){
            can[p] += arr[p];
            while(sz(to_process[p])){
                auto [x, y] = to_process[p].front();
                if(dist[x][y] >= can[p]) break;
                to_process[p].pop();

                for(auto [newx, newy] : mvs){
                    newx += x, newy += y;
                    if(min(newx, newy) >= 0 and newx < n and newy < m and dist[newx][newy] == -1 and grid[newx][newy]){
                        to_process[p].push({newx, newy});
                        cnt[p] ++;
                        dist[newx][newy] = dist[x][y] + 1;
                    }
                }
                
            }

        }
    }

    for(int i = 0; i < k; i ++) cout << cnt[i] << " ";
    cout << endl;

    return 0;
} 