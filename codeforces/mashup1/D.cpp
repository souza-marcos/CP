#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n, x1,y1,x2,y2; cin >> n >> x1 >> y1 >> x2 >> y2;

    set<pair<int, int>> vis;
    queue<tuple<int, int, int>> q;
    q.push({x1,y1, 0});
    vis.insert({x1,y1});



    while(!q.empty()){
        auto [x,y, dis] = q.front(); q.pop();

        if(x == x2 and y == y2){
            cout << dis << endl;
            return 0;
        }

        if(x == 0 or x == n){
            if(y < n and vis.count({x,y+1}) == 0)
                vis.insert({x,y+1}), q.push({x,y+1, dis+1});
            if(y > 0 and vis.count({x,y-1}) == 0)
                vis.insert({x,y-1}), q.push({x,y-1, dis+1});
        }

        if(y == 0 or y == n){
            if(x < n and vis.count({x+1,y}) == 0)
                vis.insert({x+1,y}), q.push({x+1,y, dis+1});
            if(x > 0 and vis.count({x-1,y}) == 0)
                vis.insert({x-1,y}), q.push({x-1,y, dis+1});
        }
    }

    
    return 0;
} 
