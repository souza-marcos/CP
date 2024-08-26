#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, l ,r; cin >> n >> l >> r;

    for(int i = 1; i < l; i++) cout << i << " ";
    for(int i = r; i >=l; i--) cout << i << " ";
    for(int i = r + 1; i<= n; i++) cout << i << " ";
    cout << endl;

    return 0;
} 
