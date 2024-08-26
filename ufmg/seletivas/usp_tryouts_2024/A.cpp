#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    vector<tuple<int, int, int>> v(n);
    vector<pair<int, int>> out;
    for(auto& [t, m, c]: v) {
        cin >> t >> m >> c;
        if(c) out.push_back({t, m});
    }

    sort(v.begin(), v.end());    
    sort(out.begin(), out.end());

    ll time = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if
    }
    return 0;
} 
