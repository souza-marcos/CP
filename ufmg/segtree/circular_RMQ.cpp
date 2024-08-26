#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

const int MAX = 2e5 + 10;

int seg[4 * MAX], lz[4 * MAX];
int arr[MAX];

// Minimal element inside the interval

int build(int p, int l, int r){
    if(l == r){
        lz[p] = 0;
        return seg[p] = arr[l];
    } 

    int m = (l + r)/2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r)); 
}

void unlazy(int p, int l, int r){
    if (lz[p] == 0) return;

    seg[p] += lz[p];
    if(l != r) seg[2 * p] += lz[p], seg[2 * p + 1] += lz[p];
    lz[p] = 0;
}

int update(int a, int b, int x, int p, int l, int r){
    unlazy(p, l, r);

    if(b < l or r < a) return seg[p];
    if(a <= l and r <= b){
        lz[p] += x;
        unlazy(p, l ,r);
        return seg[p];
    }

    int m = (l + r)/2;
    return seg[p] = min(update(a, b, x, 2 * p, l, m), update(a, b, x, 2 * p + 1, m + 1, r));
}

int query(int a, int b, int p, int l, int r){
    unlazy(p, l, r);
    if(b < l or a > r) return INF;
    if(a <= l and r <= b) return seg[p];

    int m = (l + r)/2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

int main(){ _
    int n, q; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n - 1);

    cin >> q;
    while(q --){
        int l, r, v; cin >> l >> r;
        
        bool w = (cin.peek() == '\n');

        if(!w) { // update
            cin >> v;

            if(l > r){
                update(0, r, v, 1, 0, n -1);
                update(l, n - 1, v, 1, 0, n -1);
            }
            else{
                update(l, r, v, 1, 0, n - 1);
            }
        }else{

            if(l > r){
                cout << min(query(0, r, 1, 0, n -1), query(l, n -1, 1, 0, n - 1)) << endl;
            }
            else{
                cout << query(l, r, 1, 0, n -1) << endl;
            }
        }
    }
    return 0;
} 
