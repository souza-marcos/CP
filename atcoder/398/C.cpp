#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    int n; cin >> n;
    map<int, int> cnt, index;
    for(int i=1; i <= n; i ++){
        int a; cin >> a;
        cnt[a] ++;
        index[a] = i;
    }

    for(auto it = cnt.rbegin(); it != cnt.rend(); ++it){
        auto [k, val] = *it;
        if(val > 1) continue;

        cout << index[k] << endl;
        return 0;
    }
    cout << -1 << endl;


    return 0;
} 
