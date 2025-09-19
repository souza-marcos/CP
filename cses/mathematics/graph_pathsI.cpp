#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> arr;

    Matrix(int sz){
        arr.resize(sz, vector<ll>(sz));
    }

    static Matrix eye(int n){
        Matrix a(n);
        for(int i = 0; i < n; i ++) a.arr[i][i] = 1;
        return a;
    }

    friend Matrix operator*(Matrix& a, Matrix& b){
        Matrix res(sz(b.arr));
        int n = sz(b.arr);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                for(int k = 0; k < n; k ++){
                    res.arr[i][j] += a.arr[i][k] * b.arr[k][j];
                    res.arr[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    friend Matrix operator^(Matrix a, ll e){
        int n = a.arr.size();
        Matrix res(n);
        for(int i = 0; i < n; i ++)
            res.arr[i][i] = 1;

        while(e){
            if(e&1) res = res * a;
            a = a * a;
            e >>= 1;
        }
        return res;
    }

};


int32_t main(){
    int n, m, k; cin >> n >> m >> k;
    Matrix s(n);
    for(int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        a --, b--;
        s.arr[a][b] += 1;
    }

    s = s ^ k;
    cout << s.arr[0][n-1] << endl;
}
