#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size() 

int main(){ _
    int n; cin >> n;
    pair<int, int> a, b, c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    set<pair<int, int>> vis;
    vector<pair<int, int>> mvs = {{1,0},{-1,0},{0,1},{0,-1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    queue<pair<int,int>> q;
    q.push(b), vis.insert(b);
    while(sz(q)){
        auto [i, j] = q.front(); q.pop();

        if(i == c.first and j == c.second){
            cout << "YES\n";
            return 0;
        }
        for(auto [newi, newj ] : mvs){
            newi += i, newj += j;
            if(min(newi, newj) > 0 and max(newi, newj) <= n){

                if(newi == a.first) continue;
                if(newj == a.second) continue;

                int diffx = newi - a.first, diffy = newj - a.second;
                // cout << "DIFF(" << newi << "," << newj << "): " << diffx << " " << diffy << endl;
                if(abs(diffx) == abs(diffy)) continue;

                if(vis.count({newi, newj}) == 0) 
                    q.push({newi, newj}), vis.insert({newi, newj});
            }
        }
    }
    cout << "NO\n";
    return 0;
} 
