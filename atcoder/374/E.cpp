#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'
int main(){ _
    // Ideia dp[i][j] calcular o min de dinheiro nec para fazer j proutos no i processo
    // Depois busca binaria para ver qual o maximo que consigo


    int n, x; cin  >> n >> x;
    struct Machine{
        int u, cost;
    };
    vector<pair<Machine, Machine>> arr(n);
    for(auto &[m1, m2]: arr) cin >> m1.u >> m1.cost >> m2.u >> m2.cost;

     



    return 0;
} 
