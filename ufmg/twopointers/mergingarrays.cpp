#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;

    int j = 0, k = 0;
    while(j < n or k < m){
        if(j >= n) cout << b[k ++] << " ";
        else if(k >= m) cout << a[j ++] << " ";
        else if(a[j] <= b[k]) cout << a[j ++] << " ";
        else cout << b[k ++] << " ";
    }
    cout << endl;

    return 0;
} 
