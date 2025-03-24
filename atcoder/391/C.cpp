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
    vector<int> pigeon(n); iota(pigeon.begin(), pigeon.end(), 0);
    vector<int> nest(n, 1);
    int cnt = 0;

    while(q --){
        int tipo; cin >> tipo;

        if(tipo == 1){
            int p, h; cin >> p >> h; p--, h--;

            if(nest[pigeon[p]] == 2) cnt --;
            nest[pigeon[p]] --;

            pigeon[p] = h;
            if(nest[h] == 1) cnt ++;
            nest[h] ++;
        } else {
            cout << cnt << endl;
        }
    }

    return 0;
} 
