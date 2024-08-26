#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

const int MAX = 1e5 + 10;

int arr[MAX];
pair<int, int> seg[4* MAX]; // min, #min

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return a;
    if(a.first > b.first) return b;
    return {a.first, a.second + b.second};
}

pair<int, int> build(int p, int l, int r){

    if(l == r) return seg[p] = {arr[l], 1};

    int m = (l + r)/2;
    return seg[p] = combine(build(2*p, l, m), build(2*p + 1, m + 1, r));
}


pair<int, int> update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = {x, 1};

    int m = (l + r)/2;
    return seg[p] = combine(update(i, x, 2 * p, l , m), update(i, x, 2*p + 1, m + 1, r));
}

pair<int, int> query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return {INF, 0};

    // intervalo do no esta inteiramente contido no intervalo da query
    if( a <= l and r <= b) return seg[p];

    int m = (l + r)/2;
    return combine(query(a, b, 2 * p, l , m), query(a, b, 2*p + 1, m + 1, r));
}


int main(){ _

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);

    while (m --)
    {
        int q; cin >> q;
        if(q == 2){ // Consulta
            int l, r; cin >> l >> r;
            r --;
            auto [x, y] = query(l, r, 1, 0, n - 1);
            cout << x << " " << y << endl;

        }else{ // Atualização 

            int i, x; cin >> i >> x;
            update(i, x, 1, 0, n - 1);

        }
    }
    return 0;
} 
