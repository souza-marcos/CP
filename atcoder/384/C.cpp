#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int v[5]; cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
    vector<pair<ll, string>> arr;
    for(int i = 1; i < 32; i ++){
        string cur;
        ll cost = 0;
        for(int j = 0; j < 5; j ++){
            if((i >> j) & 1) cur.push_back('A' + j), cost += v[j];
        }
        arr.push_back({-cost, cur});
    }

    // sort(arr.begin(), arr.end(), [&](auto a, auto b){
    //     ll costa = 0;
    //     for(auto c: a) costa += v[c-'A'];
    
    //     ll costb = 0;
    //     for(auto c: b) costb += v[c-'A'];
    
    //     return (costa <= costb);
    // });

    sort(arr.begin(), arr.end());
    for(auto [c, el] : arr)
        cout  << el << endl;
    

    return 0;
} 
