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

/*
F_n = F_{n-1} + ... + F_{n-6}

1 1 1 1 1 1   1
1 0 0 0 0 0   0
0 1 0 0 0 0   ...
    1
      1
0 0 0 0 1 0   0

*/


int32_t main(){

    ll n; cin >> n;
    
    Matrix a(6);
    for(int i = 0; i < 6; i ++)
        a.arr[0][i] = 1;
        
    for(int i = 0; i < 5; i ++) 
        a.arr[i+1][i] = 1;
    
    a = a ^ n;
    cout << a.arr[0][0] << endl;
}

// 1 + 1 + 1
// 1 + 2
// 2 + 1
// 3