#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()

int main(){ _

    int n; cin >> n;
    map<int, int> vals;
    while(n --){

        string s; cin >> s;
        int res = 0;
        for(int i = 0; i < sz(s); i ++){
            res = res ^ (1 << (s[i] - 'a'));
        }
        vals[res] ++;
    }


    ll cnt = 0;
    for(auto [key, el] : vals){
        cnt += el -1;
        // cout << key << " " << el << endl;

        for(int i = 0; i <= 26; i ++){
            int mask = key ^ (1 << i);
            if(vals.count(mask)){
                cnt += el * vals[mask]; 
                // cout << key << " " << el << " " << mask << " " << cnt << endl;
            }
        }
    }

    cout << cnt << endl;
    return 0;
} 
