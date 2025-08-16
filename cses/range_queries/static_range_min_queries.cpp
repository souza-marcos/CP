#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

// Sparse Table -> O(nlogn) to precalculate and O(1) to ans min queries

int main(){ _

    auto log2 = [&](int val) -> int {
        return val > 0 ? __builtin_clz(1) - __builtin_clz(val) : -1;
    };

    int n, q; cin >> n >> q;
    vector<int> arr(n); for(auto &el : arr) cin >> el;

    int k = log2(n);
    int table[k + 1][n+1];
    
    for(int j = 0; j < n; j ++)
        table[0][j] = arr[j];

    for(int i = 1; i <= k; i ++){
        for(int j = 0; j + (1 << i) <= n; j ++){
            table[i][j] = min(table[i-1][j], table[i-1][j + (1 << (i-1))]);
        }
    }

    while(q --){
        int l, r; cin >> l >> r; r--, l--;
        int tam = log2(r-l+1);
        cout << min(table[tam][l], table[tam][r-(1 << tam)+1]) << endl;
    }

    return 0;
} 
