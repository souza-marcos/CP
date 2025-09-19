#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll
#define sz(x) (int)x.size()

int32_t main() { _

    int n, k; cin >> n >> k;
    
    map<pair<int, int>, int> mp;
    auto idx = [&mp](int i, int j) -> int {
        return mp[{i, j}];
    };
    int timer = 0;
    vector<pair<int, int>> inverse;
    vector<string> arr(n);
    vector<bool> col;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
        for(int j = 0; j < n; j ++){
            if(arr[i][j] != '#'){
                col.push_back(arr[i][j] == '1');
                mp[{i, j}] = timer ++;
                inverse.push_back({i, j});
            }
        }
    }
    

    vector<vector<bool>> matrix(sz(inverse), vector<bool>(sz(inverse)));

    for(int k = 0; k < sz(inverse); k ++){
        auto [i, j] = inverse[k];
        int myidx = k;
        for(int newi : {-1, 0, 1}){
            for(int newj : {-1, 0, 1}){
                int ni = newi + i, nj = newj + j;
                if(max(ni, nj) < n and min(ni, nj) >= 0 and arr[ni][nj] != '#'){
                    int toidx = idx(ni, nj);
                    matrix[myidx][toidx] = 1;
                }
            }
        }
    }
    

    auto mul = [&](vector<vector<bool>>& a, vector<vector<bool>>& b) -> vector<vector<bool>> {
        vector<vector<bool>> res(sz(a), vector<bool>(sz(a)));
        for(int i = 0; i < sz(a); i ++){
            for(int k = 0; k < sz(a); k ++){
                if(a[i][k] == 0) continue;
                for(int j = 0; j < sz(a); j ++){
                    res[i][j] = res[i][j] ^ b[k][j];
                }
            }
        }
        return res;
    };

    auto pow = [&](vector<vector<bool>> &matrix, int k) -> vector<vector<bool>> {
        vector<vector<bool>> res(sz(matrix), vector<bool>(sz(matrix)));
        for(int i = 0; i < sz(matrix); i ++) res[i][i] = 1;
        while(k){
            if(k & 1){
                res = mul(res, matrix);
            }
            matrix = mul(matrix, matrix);
            k >>= 1;
        }
        return res;
    };


    matrix = pow(matrix, k);
    vector<bool> post(sz(col));
    for(int i = 0; i < sz(col); i ++){
        for(int j =0; j < sz(col); j ++){
            if(matrix[i][j] and col[j])
                post[i] = post[i] ^ 1; 
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(arr[i][j] == '#'){
                cout << '#';
            }
            else {
                cout << post[idx(i, j)]; 
            }
        }
        cout << endl;
    }
}