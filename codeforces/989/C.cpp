#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    bool vis[n][m]; memset(vis, 0, sizeof vis);
    
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i ++){
        if(arr[i][0] == 'L') vis[i][0] = 1, q.push({i, 0});
        if(arr[i][m-1] == 'R') vis[i][m-1] = 1, q.push({i, m-1});
    }
    for(int i = 0; i < m; i ++){
        if(arr[0][i] == 'U') vis[0][i] = 1, q.push({0, i});
        if(arr[n-1][i] == 'D') vis[n-1][i] = 1, q.push({n-1, i});
    }
    map<char, pair<int, int>> piece = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}, {'?', {1010, 1010}}};
    vector<pair<int, int>> mvs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();

        for(auto [newi, newj] : mvs){
            newi += i, newj += j;
            if(min(newi, newj) >= 0 and newi < n and newj < m){
                auto [k, l] = piece[arr[newi][newj]];
                if (newi + k == i and newj + l == j and !vis[newi][newj]){
                    vis[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
        }
    }
    int cnt = 0;    
    for(int i = 0; i < n; i ++){
        for(int j = 0 ; j < m; j ++){
            if(vis[i][j]) continue;

            bool ok = false;
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(min(newi, newj) >= 0 and newi < n and newj < m){
                    if(vis[newi][newj] == 0) {
                        ok = true;
                        break;
                    }
                }
            }

            // cout << i << " " << j << " => " << (ok ? " OK! ": " NO!") << endl;
            if(ok) cnt ++;
        }
    }
    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < m; j ++){
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << cnt << endl;
    // cout << "- --- -- - -- -\n";
}



int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
