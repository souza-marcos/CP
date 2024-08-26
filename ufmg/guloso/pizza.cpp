#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    int v[n];
    for(auto& el: v) cin >> el;
    
    int pre[n + 1], best[n + 1]; // best[i] => max((0..i)sum)

    pre[0] = best[0] = 0;
    for(int i = 0; i < n; i++){
        pre[i + 1] = pre[i] + v[i];
        best[i + 1] = max(best[i], pre[i + 1]);
    }

    int maxval = 0;
    for(int i = 1; i <= n; i ++){
        maxval = max(maxval, best[i-1] + (pre[n] - pre[i]));
    }

    int k = 0;
    for(auto el: v){
        k = max(0, el + k);
        maxval = max(maxval, k);
    }

    cout << maxval << endl;

    return 0;
} 
