#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;
#define MAX 1e5 + 10

vector<int> nec(MAX), disp(MAX);
int n; ll k;

bool valid(ll times){
    ll camisas = 0;
    for(int i = 0; i < n; i++){
        auto cur_disp = disp[i], cur_nec = nec[i];
        if(cur_disp / cur_nec >= times) continue;
        camisas += (times * cur_nec - cur_disp);
        if(camisas > k) return false;
    }
    return camisas <= k;
}

int main(){_

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> nec[i];
    for(int i = 0; i < n; i++) cin >> disp[i];

    ll l = 0, r = 2 * INF;
    while(l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
}