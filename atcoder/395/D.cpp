#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    int n, q; cin >> n >> q;

    vector<int> nest(n + 1), repr(n+1);
    iota(nest.begin(), nest.end(), 0), iota(repr.begin(), repr.end(), 0);




    while(q --){
        int t, a, b; cin >> t;
        if(t == 1){
            cin >> a >> b;
            nest[a] = repr[b];
        }
        else if(t == 2) {
            cin >> a >> b;
            swap(repr[a], repr[b]);
        }
        else {
            cin >> a;


        }
    }

    return 0;
} 
