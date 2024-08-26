#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto&el: a) cin >> el;
    for(auto&el: b) cin >> el;

    int i = 0, j = 0;
    while(i < n or j < m){
        if(i >= n) cout << b[j ++] << " ";
        else if(j >= m) cout << a[i ++] << " ";
        else if(a[i] <= b[j]) cout << a[i ++] << " ";
        else cout << b[j ++] << " ";
    }
    cout << endl;
    return 0;
} 
