#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;
#define endl "\n"
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    
    pair<int, int> maxh = {0, -INF};
    int secondmax = -INF;

    ll sum = 0;
    for(int i= 0; i < n; i++){
        auto& [w, h] = v[i];
        cin >> w >> h;
        sum += w;
        if(h > maxh.second){
            secondmax = maxh.second;
            maxh = {i, h};
        }else if(h > secondmax) secondmax = h;
    }

    for(int i = 0; i < n; i++){
        int curmaxh = (maxh.first == i? secondmax: maxh.second);
        ll curw = sum - v[i].first;
        cout << curw * curmaxh << " ";
    }

    return 0;
} 
