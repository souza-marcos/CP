#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n, k; cin >> n >> k;
    vector<ll> arr(n), diff(n + 1); for(auto &el: arr) cin >> el;
    // A ideia eh olhar para o array de diferenca e notar que fazemos modificação das pontas do retangulo (k + 1)
    // => Podemos separar os elementos em classes mod k => Todo subarray de cada grupo deve ter soma == 0

    for(int i = 0; i < n-1; i ++){
        diff[i + 1] = arr[i + 1] - arr[i];
    }
    diff[0] = arr[0];
    diff[n] = 0 - arr[n-1];
    vector<vector<ll>> groups(k, vector<ll>(1, 0)); 

    for(int i = 0; i < n + 1; i ++)
    for(int j = 0; j < k; j ++){
        groups[j].push_back(groups[j].back());
        if(i % k == j) groups[j].back() += diff[i]; 
    }


    for(auto el : diff) cout << el << " ";
    cout << endl;

    int i = 0;
    for(auto &el: groups){
        cout << i ++ << ": "; 
        for(auto it : el) cout << it << " ";
        cout << endl;
    }

    int q; cin >> q;
    while (q --){
        int l, r; cin >> l >> r;
        
        // For each group we must check the sum could be 0
        bool ok = true;
        for(int i = 0; i < k; i ++){
            ll sum = groups[i][r] - groups[i][l-1];
            if(sum != 0) ok = false;
            cout << "sum " << i << ": " << sum << endl;
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
} 
