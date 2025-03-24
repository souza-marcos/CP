#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    // Temos N comidas cada uma delas tem C_i calorias, podemos consumir no máxino X calorias
    // Queremos maximizar o menor valor entre as vitaminas tomadas.

    int n, X; cin >> n >> X;
    vector<int> tipo(n), vitamin(n), calor(n);
    
    for(int i = 0; i < n; i ++){
        cin >> tipo[i] >> vitamin[i] >> calor[i];
    }


    // minimo diferenca nos i primeiros elementos

    vector<vector<ll>> dp(n, vector<ll>(X, INF));


    for(int i = 0; i < n; i ++){
            
    }



    return 0;
} 
