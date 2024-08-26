#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MAX = 1e5 + 10; 
int seg[MAX * 4];

int update(int p, int l, int r, int i){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = 1;
    int m = (l + r)/2;
    return seg[p] = update(p << 1, l, m, i) + update(p << 1 | 1, m + 1, r, i);
} 

int query(int p, int l, int r, int k){
    if(r < k) return 0;
    if(l >= k) return seg[p];
    int m = (l + r)/2;
    return query(p << 1, l, m, k) + query(p << 1 | 1, m + 1, r, k);
}

int main(){ _
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int a; cin >> a; a--;
        cout << query(1, 0, n-1, a + 1) << " ";
        update(1, 0, n-1, a);
    }
    cout << endl;
    return 0;
} 
