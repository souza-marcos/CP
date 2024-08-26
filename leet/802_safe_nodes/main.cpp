#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
private:

    vector<int> vis;
    

public:


    bool dfs(vector<vector<int>>& g, int i){
        vis[i] = 0;

        if(g[i].size() == 0){ // Terminal node
            vis[i] = 1;
            return true;
        }
        for(auto neigh : g[i]){
            if(vis[neigh] == -1) 
                if(dfs(g, neigh)){
                    vis[neigh] = 1;
                    return true;
                }
        }
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vis.resize(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(vis[i] == 0) dfs(graph, i);
        }
        vector<int> res;
        for(int i = 0; i < vis.size(); i++){
            if(vis[i] == 1) res.push_back(i); 
        }
        return res;

    }
};

int main(){ _

    Solution sol;
    vector<vector<int>> v = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    auto t = sol.eventualSafeNodes(v);
    for(auto el : t){
        cout << el << " ";
    }
    return 0;
} 
