#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

const int MAXN = 100100;
const int MAXV = 1000100;
const int MOD = 1e9 + 7;

int n, k;
int cnt[MAXV], p2[MAXN], fator[MAXV];

vector<int> lista, ret;

void gera_comb(int el){
    vector<int> primos;
    while(k > 1) {
        if(sz(primos) == 0 or primos.back() != fator[k])
            primos.push_back(fator[k]);
        k/=fator[k];
    }
    lista.clear(), ret.clear();
    for(auto x: primos) lista.push_back(x);

    for(int i = 0; i < (1 << sz(lista)); i ++){
        int res = 1;
        for(int j = 0; j < sz(lista); j ++){
            if(i & (1 << j)) res *= lista[j] * (-1);
        }
        ret.push_back(res);
    }
}

int main(){ _
    for(int i = 1; i < MAXV; i ++) 
        fator[i] = i;

    for(int i = 2; i < MAXV; i ++) if(fator[i] == i){   
        for(ll j = 2*i; j < MAXV; j +=i){
            fator[j] = i;
        }
    }

    cin >> n;
    p2[0] = 1;
    for(int i = 1; i <= n; i ++){
        p2[i] = p2[i-1] << 1;
        if(p2[i] >= MOD) p2[i] -= MOD; 
    }

    while(n --){
        cin >> k; gera_comb(k);
        for(auto el: ret) cnt[abs(el)] ++;
    }

    int q; cin >> q;
    while(q--){
        cin >> k; gera_comb(k);
        int sum = 0;
        for(auto el : ret) sum += cnt[abs(el)] * (el > 0? 1:-1);
        cout << p2[sum] << endl;
    }

    return 0;
} 
