#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Busca binaria na resposta

// binary search na stl
// lower_bound(nao eh menor que x) e upper_bound(eh maior que x)
// se nao encontrado retorna end()

// Problemas que envolvem minimizar ou maximizar
const int MAX = 1e5+10;

int N, C, T;
int pipocas[MAX];


// Parte gulosa do problema
bool possivel(ll chute){

    int comp = 1;
    ll resta = T*chute;

    for(int i=0; i<N; i++){
        if(resta >= pipocas[i]) resta -= pipocas[i];
        else{
            comp ++; 
            resta = T*chute;
            i--;
        }
        if(comp > C) return false;
    }
    return true;
}

int main(){ _

    cin >> N >> C >> T;
    for(int i=0; i<N; i++) cin >> pipocas[i];

    int l = 0, r = 1e9+1;
    while(l < r){
        int m = (l + r)/2;

        if(!possivel(m)) l = m+1;
        else r = m;

    }
    cout << l << endl;
    return 0;
} 
