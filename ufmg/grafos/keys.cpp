#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:

    vector<bool> vis;

    void dfs(vector<vector<int>>& g, int v){
        vis[v] = true;
        for(auto el: g[v]){
            if(!vis[el]) dfs(g, el);
        }
        
    } 

    // verify if is connected the graph
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(), false);
        dfs(rooms, 0);
        for(auto el: vis){
            if(!el) return false;
        }
        return true;
    }
};

int main(){ _
    vector<vector<int>> g = {{1,3},{3,0,1},{2},{0}};
    Solution s;
    cout << s.canVisitAllRooms(g) << endl;

    return 0;
} 
