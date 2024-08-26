#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

int main(){ _
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto&el : a) cin >> el;
    for(auto&el : b) cin >> el;

    int i = 0, j = 0;
    ll cnt = 0;
    while(i < n and j < m){
        if(a[i] == b[j]){
            int inew = i, jnew = j;
            while(inew < n and a[inew] == a[i]) inew ++;
            while(jnew < m and b[jnew] == b[j]) jnew ++;
            cnt += ((ll)(inew - i)) * (jnew - j);
            i = inew, j = jnew;
        }
        else if(a[i] < b[j]) i ++; 
        else j ++;
    }
    cout << cnt << endl;
    return 0;
} 
