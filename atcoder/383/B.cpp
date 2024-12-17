#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int h, w, d; cin >> h >> w >> d;
    vector<string> grid(h);
    for(auto& el: grid) 
        cin >> el;


    vector<pair<int, int>> fl;
    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            if(grid[i][j] == '.') fl.push_back({i, j});
        }
    }

    auto calc = [&](int i, int j){
        auto pos = fl[i];
        set<pair<int, int>> vis;
        int cnt = 0;
        
        queue<tuple<int, int, int>> q;
        q.push({pos.first, pos.second, d});
        q.push({fl[j].first, fl[j].second, d});
        while(sz(q)){
            auto [i, j, dist] = q.front(); q.pop();

            if(vis.count({i,j})) continue;
            if(grid[i][j] == '.') cnt ++;
            vis.insert({i, j});
            if(dist == 0) continue;

            if(i < h-1) q.push({i + 1, j, dist - 1});
            if(j < w-1) q.push({i, j + 1, dist - 1});
            if(i > 0) q.push({i - 1, j, dist - 1});
            if(j > 0) q.push({i, j - 1, dist - 1});
        }
        return cnt;
    };

    int maxv = 0; pair<int, int> best = {0, 0};
    for(int i = 0; i < sz(fl); i ++){
        for(int j = i + 1; j < sz(fl); j ++){
            int val = calc(i, j);
            if (maxv < val ) maxv = val, best = {i, j};  
        }
    }

    cout << maxv << endl;
    // cout << fl[best.first].first << " " << fl[best.first].second << "\n";
    // cout << fl[best.second].first << " " << fl[best.second].second << "\n";
    return 0;

} 
