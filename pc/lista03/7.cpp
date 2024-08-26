#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n, l, m, p;
const int MAX = 2010;

vector<int> manut, venda;
int memo[MAX][MAX];
bool mov[MAX][MAX];

int dp(int ano, int idade){
    if(idade > m) return INF;
    if(ano == n) return 0;

    int& ped = memo[ano][idade];
    if(ped != -1) return ped;

    int fica =     dp(ano + 1, 1) + manut[0] - venda[idade] + p;
    int continua = dp(ano + 1, idade + 1) + manut[idade];

    mov[ano][idade] = 1;
    if(continua < fica) mov[ano][idade] = 0; 

    return ped = min(fica, continua);
}

void solve(){
    manut.resize(m + 1), venda.resize(m + 1);
    for(int i = 0; i < m; i++) cin >> manut[i];
    for(int i = 1; i <= m; i++) cin >> venda[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0, l) << endl;

    int idade = l;
    vector<int> trocas;
    for(int i = 0; i < n; i++){
        if(mov[i][idade]) trocas.push_back(i + 1);
        idade = (mov[i][idade]? 1: idade + 1);
    }

    if(trocas.empty()) cout << 0;
    else{
        for(int i = 0; i < trocas.size(); i++){
            cout << trocas[i] << (i + 1 == (int)trocas.size()?"":" ");
        }
    }

}

int main(){_

    while(cin >> n >> l >> m >> p) solve(), cout << endl;

    return 0;
}