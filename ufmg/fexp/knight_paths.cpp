#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()
const ll MOD = 4294967296;

struct Matrix{
    vector<vector<unsigned>> cont;
    Matrix(int n, int m){cont.resize(n, vector<unsigned>(m));}

    friend Matrix operator*(Matrix a, Matrix b){
        assert(sz(a.cont[0]) == sz(b.cont));
        Matrix res(sz(a.cont), sz(b.cont[0]));
        auto& cc = res.cont;

        for(int i = 0; i < sz(a.cont); i ++){
            for(int j = 0; j < sz(b.cont[0]); j ++){
                cc[i][j] = 0;
                for(int k = 0; k < sz(b.cont); k ++){
                    cc[i][j] += (a.cont[i][k] * b.cont[k][j]);
                }
            }
        }
        return res;
    }


    friend Matrix operator^(Matrix a, ll n){
        Matrix res(sz(a.cont), sz(a.cont));
        for(int i = 0; i < sz(a.cont); i ++) res.cont[i][i] = 1;
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
    int k; cin >> k;
    int aux[8][8], cnt = 0;
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            aux[i][j] = cnt, cnt ++;
        }
    }
    vector<pair<int, int>> mvs = {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {2, -1}, {2, 1}};
    
    Matrix a(65, 65);

    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j ++){
            for(auto [newi, newj] : mvs){
                newi += i, newj += j;
                if(newi < 0 or newi >= 8 or newj < 0 or newj >= 8) continue;
                a.cont[aux[i][j]][aux[newi][newj]] = 1;
                //a.cont[aux[i][j]][aux[i][j]] = 1;
            }
        }
    }
    for(int i=0; i < 65; i ++) a.cont[64][i] = 1;

    // for(auto& row: a.cont){
    //     for(auto el: row) cout << el << " ";
    //     cout << endl;
    // }

    Matrix b(65, 1); b.cont[0][0] = 1;
    Matrix res = (a ^ (k + 1)) * b;
    
    cout << res.cont[64][0] << endl;

    // for(int i = 0; i < 65; i ++){
    //     cout << res.cont[i][0] << " ";
    //     if((i + 1) % 8 == 0) cout << endl;
    // }cout << endl;
    return 0;
} 
