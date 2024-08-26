#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> left(n), right(m);
    for(auto &el: left) cin >> el;
    for(auto &el: right) cin >> el;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(left[i] + right[j] <= k) cont ++;
            else break;
        }
    }
    cout << cont << endl;

}


int main(){ _
    int t; cin >> t;
    while(t --) solve();


    return 0;
} 
