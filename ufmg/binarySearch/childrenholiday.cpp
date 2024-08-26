#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3+10;

int m, n;
vector<tuple<int, int, int>> assist(MAX);

bool valid(ll guess){
    int cont = 0;
    for(int i = 0; i < n; i++){
        auto [tbal, nbal, rest] = assist[i];

        int vezes_desc = guess/(tbal * nbal + rest);
        int restante = guess - (tbal * nbal + rest) * vezes_desc;
        
        int balls = vezes_desc * nbal;
        if(restante >= tbal) balls += min(restante/tbal, nbal); 
        cont += balls;

        if(cont >= m) return true;
    }
    return false;
}

int main(){ _
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        auto& [ti, zi, yi] = assist[i]; 
        cin >> ti >> zi >> yi;
    }

    ll l = 0, r = 1;
    while(!valid(r)) r *= 2;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    
    cout << r << endl;

    int cont = 0;
    for(int i = 0; i < n; i++){
        auto [tbal, nbal, rest] = assist[i];

        int vezes_desc = r / (tbal * nbal + rest);
        int restante   = r - (tbal * nbal + rest) * vezes_desc;
        
        int balls = vezes_desc * nbal;
        if(restante >= tbal) balls += min(restante/tbal, nbal); 

        if(cont + balls > m) {
            cout << m - cont << " "; cont = m;
        }
        else {
            cout << balls << " "; cont += balls;
        }
    }

    cout << endl;

    return 0;
} 
