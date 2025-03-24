#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    vector<int> arr(7); for(auto & el : arr) cin >> el;

    bool ok = false;

    sort(arr.begin(), arr.end());
    for(int i = 0; i < (1 << 7); i ++){
        if(__builtin_popcount(i) == 5){
            map<int, int> mp;

            for(int j = 0; j < 7; j ++){
                if((i >> j) & 1) mp[arr[j]] ++;
            }

            if(sz(mp) == 2){
                for(auto [k, val] : mp){
                    if(val == 3 or val == 2) ok = true;
                    break;
                }
            }
            if(ok) break;

        }

    }

    cout << (ok? "Yes\n" : "No\n");

    return 0;
} 
