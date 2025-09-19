#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    ll n, m, k; cin >> n >> m >> k;
    k--;
    if(n <= 2){
        cout << -1 << endl;
        return 0;
    }

    if(m <= n) {
        cout << -1 << endl;
        return 0;
    }

    ll val = (n - 2) * (n - 1) / 2 + 3; 
    if(m > val){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> edges;
    edges.emplace_back(0, n-1);
    edges.emplace_back(n-1, n-2);
    edges.emplace_back(n-2, 0);

    m -= 3;
    for(int step = 1; step <= n-2; step ++){
        if(m <= 0) break;
        for(int i = 0; i <= n-3; i ++){
            edges.emplace_back(i, (i + step) % (n-2));
            m --;
            if(m <= 0) break;
        }
    }


    // swap 0 - k
    for(auto& [i, j] : edges){
        if(i == 0) i = k;
        else if(i == k) i = 0;
        
        if(j == 0) j = k;
        else if(j == k) j = 0; 
    }

    for(auto [i, j] : edges) cout << i + 1 << " " << j + 1 << endl;

} 
