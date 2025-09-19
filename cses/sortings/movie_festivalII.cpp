#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int32_t main(){ _ 

    int n, k; cin >> n >> k;
    vector<pair<int, int>> movies(n); // end - start
    for(auto& [end, start] : movies){
        cin >> start >> end;
    }

    multiset<int> available_time;
    for(int i = 0; i < k; i ++) 
        available_time.insert(1);

    sort(movies.begin(), movies.end());

    // for(auto [end, start] : movies) cout << start << " " << end << endl;

    int cnt = 0;
    for(auto [end, start] : movies){
        auto it = available_time.upper_bound(start);
        if(it == available_time.begin()) continue;
        --it;
        available_time.erase(it);
        cnt++;
        available_time.insert(end);
    }
    cout << cnt << endl;

    return 0;       
}
