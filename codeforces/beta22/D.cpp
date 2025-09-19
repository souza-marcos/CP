#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<pair<int, int>> segs(n); // end - start
    for(auto& [end, start] : segs) {
        cin >> start >> end;
        if(start > end) swap(start, end);    
    }

    sort(segs.begin(), segs.end());


    // -1e5, 1e5

    const int MAX = 2e5 + 5;
    auto get_idx = [](int x) -> int {
        return x + 1e5;
    };

    vector<int> fenwinck(2e5 + 10);
    
    auto add = [&](int x, int delta) -> void {
        for(int i = x; i < MAX; i = i | (i + 1)){
            fenwinck[i] += delta;
        }
    };  

    auto sum = [&](int l, int r) -> int {
        int res = 0;
        while(r >= 0){
            res += fenwinck[r];
            r = (r & (r + 1)) -1;
        }
        l--;
        while(l >= 0){
            res -= fenwinck[l];
            l = (l & (l + 1)) -1;
        }
        return res;
    };

    vector<int> res;
    for(auto [end, start] : segs){
        if(sum(get_idx(start), get_idx(end)) == 0){
            res.push_back(end);
            add(get_idx(end), 1);
        }
    }

    cout << sz(res) << endl;
    for(auto i : res) cout << i << " ";
    cout << endl;
} 
