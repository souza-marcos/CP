#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    int n; cin >> n;

    vector<vector<int>> res(n, vector<int>(n));
    vector<bool> used(2*n + 1, false);

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            used.assign(sz(used), false);
            for(int k = 0; k < i; k ++) used[res[k][j]] = 1;
            for(int k = 0; k < j; k ++) used[res[i][k]] = 1;
            
            for(int k = 0; k < sz(used); k++){
                if(not used[k]){
                    res[i][j] = k;
                    break;
                }
            }
        }
    }

    for(auto& row : res){
        for(int el : row){
            cout << el << " ";
        }
        cout << '\n';
    }

    return 0;
} 
