#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl '\n'
#define sz(x) (int)x.size()

struct Matrix{
    vector<vector<double>> cont;
    Matrix(int n, int m){cont.resize(n, vector<double>(m));}
    Matrix(vector<vector<double>>& x){
        cont = x;
    }

    friend Matrix operator*(const Matrix& a, const Matrix& b){
        assert(sz(a.cont[0]) == sz(b.cont));
        Matrix res(sz(a.cont), sz(b.cont[0]));
        auto& cc = res.cont;

        for(int i = 0; i < sz(a.cont); i ++){
            for(int j = 0; j < sz(b.cont[0]); j ++){
                cc[i][j] = 0;
                for(int k = 0; k < sz(b.cont); k ++){
                    cc[i][j] += a.cont[i][k] * b.cont[k][j];
                }
            }
        } 

        return res;
    }


    friend Matrix operator^(Matrix a, ll n){
        vector<vector<double>> cc = {{1.0, 0.0}, {0.0, 1.0}};
        Matrix res(cc);
        while(n){
            if(n&1) res = res * a; 
            a = a * a;
            n >>= 1;
        }
        return res;
    }
    
};


int main(){ _

    cout << fixed << setprecision(10);
    int n; cin >> n;
    double p; cin >> p;
    Matrix m(2, 2);
    m.cont[0][0] = m.cont[1][1] = 1-p;
    m.cont[0][1] = m.cont[1][0] = p;

    Matrix fr(2, 1); fr.cont[0][0] = 1;
    Matrix res = (m ^ n) * fr;

    cout << res.cont[0][0] << endl;

    return 0;
} 
