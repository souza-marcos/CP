#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n; cin >> n;
    vector<int> custo(n);
    for(auto &el : custo) cin >> el;

    sort(custo.begin(), custo.end());
    int q; cin >> q;
    while(q--){
        int a; cin >> a;
        auto it = upper_bound(custo.begin(), custo.end(), a);
        //if(it == custo.end()) cout << "0" << endl;
        cout << it - custo.begin() << endl; 
    }

    return 0;
}