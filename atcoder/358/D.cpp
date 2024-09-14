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
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll sum = 0;
    int j =0, i = 0;

    while(i < n and j < m){
        if(a[i] >= b[j]){
            sum += a[i];
            j ++;
        }
        i ++;
    }

    if (j < m) cout << -1 << endl;
    else cout << sum << endl;

    return 0;
} 
