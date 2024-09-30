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
int freq[MAXV], cnt[MAXV], p2[MAXN];
bool primo[MAXV];
int mb[MAXV]; // Mobius function
// 1 se eh multiplo de numero par de primos elevados a 1  
// -1 se eh multiplo de numero impar de primos elevados a 1
// 0 se eh pussui algum primo elevado a >=2 na fatoração

int res[MAXV];

int main(){ _

    cin >> n;
    p2[0] = 1;
    for(int i = 1; i <= n; i ++){
        p2[i] = p2[i-1] << 1;
        if(p2[i] >= MOD) p2[i] -= MOD; 
    }

    while(n --) cin >> k, freq[k] ++;

    primo[1] = 0, mb[1] = 1;
    for(int i = 2; i < MAXV; i ++) mb[i] = 1, primo[i] = 1;

    for(int i = 1; i < MAXV; i ++) {
        if(primo[i]){   
            for(ll j = 1LL*i*i; j < MAXV; j +=i) primo[j] = 0;
            for(int j = i; j <MAXV; j += i) mb[j] *= -1;
            for(ll j = 1LL * i * i; j < MAXV; j += 1LL * i * i) mb[j] = 0;
        }
        if(mb[i] != 0){
            for(int j = i; j <MAXV; j += i) cnt[i] += freq[j];
            for(int j = i; j <MAXV; j += i) res[j] += cnt[i] * mb[i];
        }
    }

    int q; cin >> q;
    while(q--){
        cin >> k; 
        cout << p2[res[k]] << endl;
    }

    return 0;
} 
