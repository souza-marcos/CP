#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'


int main(){ _

    string n; int d; cin >> n >> d;
    vector<vector<ll>> qtd(2, vector<ll>(d, 0));
    const int MOD = 1e9 + 7;



    for(int i = 0; i < 10; i ++){
        qtd[0][i%d]+= 1; 
    }
    for(int i = 0; i < sz(n); i ++){
        for(int j = 0; j < d; j ++){
            qtd[(i + 1)&1][j] = qtd[i&1][j];  
        }
        for(int j = 0; j < d; j++){
            for(int k = 1; k < d; k ++){
                qtd[(i+1)&1][(j+k)%d] += qtd[i&1][j];
                qtd[(i+1)&1][(j+k)%d] %= MOD;
            }
        }
    }
    cout << max(qtd[0][0], qtd[1][0]) << endl;
}