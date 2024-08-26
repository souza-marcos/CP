#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
const int MOD = 13371337;

struct Matrix
{
    vector<vector<ll>> cont;
    Matrix(int n, int m){ cont.resize(n, vector<ll>(m)); }
    Matrix(vector<vector<ll>> cont){this->cont = cont; }
    
    Matrix friend operator* (const Matrix& a, const Matrix& b){
        Matrix res(sz(a.cont), sz(b.cont[0]));
        auto &cont = res.cont;

        for(int i = 0; i < sz(a.cont); i++){
            for(int j = 0; j < sz(b.cont[0]); j++){
                for(int k = 0; k < sz(b.cont); k++){
                    cont[i][j] = (cont[i][j] + a.cont[i][k] * b.cont[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix friend operator^ (const Matrix& base, int n){
        Matrix a = base;
        Matrix res(sz(base.cont), sz(base.cont));
        for(int i = 0; i < sz(res.cont); i++) res.cont[i][i] = 1;

        while (n)
        {
            if(n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }

    void print(){
        for(int i =0; i < sz(cont); i ++){
            for(int j = 0; j <sz(cont[0]); j++){
                cout << cont[i][j] << " ";
            }
            cout << endl;
        }
    }

};


int main(){ _
    int n;
    while(cin >> n and n != 0){
        int a, b, c, d; cin >> a >> b >> c >> d;
        vector<vector<ll>> cont = {
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0}
        };

        Matrix base(cont);

        vector<vector<ll>> conta = {{d}, {c}, {b}, {a}};
        Matrix ma(conta);

        Matrix res = (base ^ (n- 3));

        res = res * ma;
        cout << res.cont[0][0] << endl;
    }

    return 0;
} 
