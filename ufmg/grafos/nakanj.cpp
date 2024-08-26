#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int tab[8][8];

bool valid(int i, int j){
    return !(i < 0 or i >= 8 or j < 0 or j >= 8);
}

void solve(){
    string a, b; cin >> a >> b;
    memset(tab, -1, sizeof tab);

    pair<int, int> src = {a[0]-'a', a[1]-'1'}, dest = {b[0]-'a', b[1]-'1'};
    // cout << src.first << " " << src.second << ", " << dest.first << " " << dest.second << endl;
    tab[src.first][src.second] = 0;

    vector<pair<int, int>> mvs = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

    queue<pair<int, int>> q; q.push(src);
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(auto [newi, newj]: mvs){
            newi += i, newj += j;
            if(valid(newi, newj) and tab[newi][newj] == -1){
                q.push({newi, newj});
                tab[newi][newj] = tab[i][j] + 1;
            }
        }
    }

    cout << tab[dest.first][dest.second] << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
