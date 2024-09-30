#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

const int MAXN = 100100;
const int MAXV = 1000100;
const int MOD = 1e9 + 7;

int n, k;
int fact[MAXV],// MAX prime factor of i number
    cnt[MAXV];
vector<int> p_fact;  
set<int> comb, s_fact;

map<int, set<int>> pres;

void gen_comb(int el){
    if(pres.count(el)) {
        comb = pres[el];
        return;
    }

    p_fact.clear(), s_fact.clear(), comb.clear();
    while(el > 1) {
        s_fact.insert(fact[el]);
        el /= fact[el];
    }
    for(auto el: s_fact) p_fact.push_back(el);

    for(int i = 0; i < (1 << sz(p_fact)); i ++){
        int res = 1;
        for(int j = 0; j < sz(p_fact); j ++){
            if(i & (1 << j)) res *= p_fact[j] * (-1);
        }
        comb.insert(res);
    }
    pres[el] = comb;
};

int main(){ _
    for(int i = 0; i < MAXV; i ++) fact[i] = i;

    // Crivo
    for(int i = 2; i < MAXV; i ++) if(fact[i] == i){
        for(ll j = 1LL * i*i; j < MAXV; j += i){
            fact[j] = i;
        }
    }

    // Pre 2-power
    cin >> n;
    int pre[n + 1];
    pre[0] = 1;
    for(int i = 1; i <= n; i ++){
        pre[i] = pre[i-1]<<1;
        if(pre[i] >= MOD) pre[i] -= MOD;
    }

    for(int i = 0; i < n; i ++){
        p_fact.clear();
        cin >> k;
        gen_comb(k);
        for(int el: comb) cnt[abs(el)] ++;
    }

    int q; cin >> q;
    while(q --){
        cin >> k;
        gen_comb(k);
        int res = 0;
        for(int el: comb) res += cnt[abs(el)] * (el < 0? -1: 1);   
        cout << pre[res] << endl;
    }
    return 0;
} 
