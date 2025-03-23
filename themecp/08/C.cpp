#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()


const int Max = 1e5 + 10;

int query(int* seg, int p, int l, int r, int lq, int rq){
    if(rq < l or lq > r) return INF;
    if(lq <= l and r <= rq) return seg[p];

    int m = (l + r)/2;
    return min(
        query(seg, 2 * p, l, m, lq, rq),
        query(seg, 2 * p + 1, m + 1, r, lq, rq)
    );
}

int update(int* seg, int p, int l, int r, int i, int x){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = seg[p] + x;

    int m = (l + r)/2;
    return seg[p] = min(
        update(seg, 2 * p, l, m, i, x),
        update(seg, 2 * p + 1, m + 1, r, i, x)
    );
}

void print(int* seg, int p, int l, int r){
    if(l == r) {
        cout << l << " => " << seg[p] << endl;
        return;
    };
    int m = (l + r)/2;
    print(seg, p << 1, l, m);
    print(seg, p << 1 | 1, m + 1, r);
}

int main(){ _
    int n, q; cin >> n >> q;
    
    int segx[4 * n], segy[4 * n];
    memset(segx, 0, sizeof segx);
    memset(segy, 0, sizeof segy);

    while(q --){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y; x--, y--;
            // cout << "Adding...\n";
            update(segx, 1, 0, n-1, x, 1);
            update(segy, 1, 0, n-1, y, 1);
        } else if (t == 2){
            int x, y; cin >> x >> y; x --, y --;
            update(segx, 1, 0, n-1, x, -1);
            update(segy, 1, 0, n-1, y, -1);
        }
        else {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            x1 --, x2--, y1 --, y2 --;

            int minx = query(segx, 1, 0, n-1, x1, x2);
            int miny = query(segy, 1, 0, n-1, y1, y2);
            int res = max(minx, miny);
            // cout << minx << ' ' << miny << endl;
            
            if(res == 0) cout << "No\n";
            else cout << "Yes\n";
            
            // print(segx, 1, 0, n-1); cout << endl;;
            // print(segy, 1, 0, n-1);

        }

    }

} 
