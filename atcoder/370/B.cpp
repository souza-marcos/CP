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
    int a[n][n];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++) {
            cin >> a[i][j]; a[i][j] --;
        }
    }

    int cur = 0;
    for(int i = 0; i < n; i ++){
        // cout << cur + 1 << " ";
        if(cur >= i) cur = a[cur][i];
        else cur = a[i][cur];
    }
    cout << cur + 1 << endl;
    return 0;
} 
