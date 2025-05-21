#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    vector<pair<int, int>> movies; // end - start
    for(int i = 0; i < n; i ++){
        int a, b; cin >> a >> b;
        movies.emplace_back(b, a);
    }    
    sort(movies.begin(), movies.end());
    int cur = 0, cnt = 0;
    for(auto [end, start]: movies){
        if(cur <= start) cur = end, cnt ++;
    }
    cout << cnt << endl;
    return 0;
} 
