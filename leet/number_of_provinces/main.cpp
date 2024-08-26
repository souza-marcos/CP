#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<bool> vis; 


class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int v){
        if(vis[v]) return;
        vis[v] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[v][i] == 1) 
                dfs(isConnected, i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vis.resize(isConnected.size(), false);
        int count = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]) count ++;
            dfs(isConnected, i);
        }     
        return count;
    }
};

int main(){ _

    Solution s;
    vector<vector<int>> v = {{1,1,0},{1,1,0},{0,0,1}};
    int res = s.findCircleNum(v);
    cout << res << endl;
    return 0;
} 
