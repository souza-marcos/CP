#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int children = 0, i = 0, j = 0;
        while(i < g.size() and j < s.size()){
            if(g[i] <= s[j]){
                children ++;

                i ++, j++;
                continue;
            }
            j ++;
        }
        return children;
    }
};

int main(){ _
    int n, m; cin >> n >> m;
    vector<int> g(n), s(m);
    for(auto& el: g) cin >> el;
    for(auto& el: s) cin >> el;

    for(int el: g) cout << el << " ";
    cout << endl;
    for(int el: g) cout << el << " ";
    cout << endl;


    Solution so;
    cout << so.findContentChildren(g, s) << endl; 

    return 0;
} 
