#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, k, a, b; cin >> n >> k >> a >> b; // a -> L, b -> R
    vector<int> arr(n);
    for(int& el : arr) cin >> el;
    
    map<int, int> freql, freqr; // freql -> for ">= k" boundary, freqr -> for "> k" boundary
    int res = 0;
    int l = 0, r = 0; // exclusive right pointers: window is [i .. l-1] and [i .. r-1]
    
    int curkl = 0, curkr = 0; // distinct counts for freql and freqr
    for(int i = 0; i < n; i ++){
        // expand l until [i..l-1] has at least k distinct (or l == n)
        while(l < n && curkl < k){
            if(freql[arr[l]] == 0) curkl++;
            freql[arr[l]]++;
            l++;
        }
        // if even full suffix can't reach k distinct, no more starts i will work
        if(curkl < k && l == n) break;

        // expand r until [i..r-1] has > k distinct (or r == n)
        while(r < n && curkr <= k){
            if(freqr[arr[r]] == 0) curkr++;
            freqr[arr[r]]++;
            r++;
        }

        // inclusive right indices that give exactly k distinct:
        int lowerRight = l - 1; // smallest right index (inclusive) with >=k distinct
        int upperRight = (curkr > k ? r - 2 : r - 1); // largest right index (inclusive) with exactly k distinct

        // intersect with length constraints: right in [i+a-1, min(n-1, i+b-1)]
        int lenLow = i + a - 1;
        int lenHigh = min(n - 1, i + b - 1);

        int lb = max(lowerRight, lenLow);
        int ub = min(upperRight, lenHigh);

        if(ub >= lb) res += ub - lb + 1;

        // remove a[i] from both frequency maps before moving i -> i+1
        if(freql[arr[i]] == 1) curkl--;
        freql[arr[i]]--;
        if(freql[arr[i]] == 0) freql.erase(arr[i]);

        if(freqr[arr[i]] == 1) curkr--;
        freqr[arr[i]]--;
        if(freqr[arr[i]] == 0) freqr.erase(arr[i]);
    }
    cout << res << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t--) solve();
}
