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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int> tn;
        vector<vector<int>> inv(graph.size());
        for(int i = 0; i < graph.size(); i++){
            for(auto el: graph[i]){
                inv[el].push_back(i);
            }
            if(graph[i].size() == 0) 
                tn.push_back(i);
        }

        
        set<int> sn;
        for(auto el: tn){
            sn.insert(el);
            for(auto i: inv[el]) sn.insert(i);
        }cout << endl;
        tn.resize(0);
        for(auto el: sn) tn.push_back(el); 
        
        return tn;
    }
};

int main(){ _
    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    Solution s;
    vector<int> ans = s.eventualSafeNodes(graph);
    for(auto el: ans) cout << el << endl;
    return 0;
} 
