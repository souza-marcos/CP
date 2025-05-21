#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n); for(auto &el : arr) cin >> el;
    vector<int> divs;
    vector<bool> ehprimo(sqrt(arr[0]) + 10, true);
    const int MOD = 998244353;

    int el = arr[0];
    for(int i = 2; i*i <= el; i ++){
        if(ehprimo[i]){
            for(int j = i*i; j < sz(ehprimo); j += i)
                ehprimo[j] = false;
            if(el%i == 0) divs.push_back(i); 
            while(el%i == 0)    
                el /= i;
        }
    }
    if(el != 1) divs.push_back(el);

    // auto mmc = [&](int a, int b) -> int {
    //     return (a/__gcd(a, b)) * b;
    // };

    ll cur = 1;
    for(int i = 1; i < n; i ++){
        if(arr[i-1]%arr[i] != 0){
            cout << 0 << endl;
            return;
        }   
        vector<int> resto; int f = arr[i-1]/arr[i];
        for(auto el : divs) if(f%el == 0) 
            resto.push_back(el);

        // for(auto el : resto) cout << el << " ";
        // cout << endl;

        // => percorrer pela diferenca talvez
        ll val = m/arr[i];
        for(int j = 1; j < (1 << sz(resto)); j ++){
            int get = (__builtin_popcount(j)%2 == 0? +1: -1);
            int d = 1;
            for(int k = 0; k < sz(resto); k ++) 
                if(j & (1 << k)) d *= resto[k];
            val += get * (m/(arr[i] * d)); 
            // cout << get * (m/(arr[i] * d)) << " ";
        }
        // cout << "=> " << val << endl;
        val %= MOD;
        cur = (cur * val) % MOD;

        vector<int> newdivs;
        for(auto el : divs) if(arr[i]%el == 0) 
            newdivs.push_back(el);
        divs = newdivs;
    }
    // cout << endl;
    cout << cur << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
