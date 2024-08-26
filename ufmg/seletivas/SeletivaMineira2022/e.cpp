#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<pair<int,int>> seg(n);
    
    cin >> seg[0].f >> seg[0].s;
    int lmin = seg[0].f, rmax = seg[0].s;
    for(int i = 1; i < n; i++){
        cin >> seg[i].f >> seg[i].s;
        if(seg[i].f < lmin) lmin = seg[i].f;
        if(seg[i].s > rmax) rmax = seg[i].s;
    }
    int index = -1;
    for(int i= 0; i < n; i++) {
        //cout << "lmin: " << lmin << ", rmax: " << rmax << ", " << seg[i].f << " " << seg[i].s << endl;
        if(seg[i].f == lmin && seg[i].s == rmax) {
            index = i; break;
        }
    }

    cout << index + 1 << endl;


    return 0;
} 
