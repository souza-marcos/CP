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

typedef struct{
    int notes[9]; // 0 - 8 notes

} Freq;

Freq seg[4 * MAX]; // 8 values
int lz[4 * MAX];


// Propagation of deltas
void unlazy(int p, int a, int b){

    if(lz[p] == 0) return; // Nada pra propagar

    if(a != b) lz[2 * p] += lz[p], lz[2 * p + 1] += lz[p];

    int aux[10];
    for(int i = 0; i < 9; i ++) aux[i] = seg[p].notes[i];

    for(int i = 0; i < 9; i ++){
        int pos = (i + lz[p]) % 9;
        seg[p].notes[pos] = aux[i]; 
    }
    lz[p] = 0;
}

void combine(Freq& a, Freq& b, Freq& c){
    for(int i = 0; i < 9; i++){
        c.notes[i] = a.notes[i] + b.notes[i];
    }
}

int getFreq(Freq& a){
    pair<int,int> mfreq = {-1, -1};
    for(int i = 0; i < 9; i ++){
        if(a.notes[i] > mfreq.s) mfreq = {i, a.notes[i]};
        if(a.notes[i] == mfreq.s) mfreq.f = max(mfreq.f, i);
    }
    return mfreq.f;
}

// Update a range by +x in this case
void update(int a, int b, int x, int p, int l, int r){
    unlazy(p, l, r);

    if(b < l or a > r) return; // Disjuntos
    if(a <= l and r <= b){
        lz[p] += x;
        unlazy(p, l, r);
        return;
    } 
    
    int m = (l + r)/2;
    update(a, b, x, 2*p, l, m), update(a, b, x, 2*p + 1, m + 1, r);
    combine(seg[2*p], seg[2*p + 1], seg[p]);
}

Freq query(int a, int b, int p, int l, int r ){
    unlazy(p, l, r);
    
    if(r < a or b < l) return Freq();
    if(a <= l and r <= b) return seg[p]; // Cobre o caso da folha

    int m = (l + r)/2;
    Freq ap = query(a, b, 2*p, l, m), bp = query(a, b, 2*p + 1, m + 1, r);

    Freq res;
    combine(ap, bp, res);
    return res;
}

void build(int p, int l, int r){
    lz[p] = 0;
    if(l == r){
        seg[p].notes[1] = 1;
        return;
    }

    int m = (l + r)/ 2;

    build(2*p, l, m), build(2*p + 1, m + 1, r);
    combine(seg[2*p], seg[2*p + 1], seg[p]);

}

void getAll(int p, int l, int r){
    unlazy(p, l, r);

    if(l == r) {
        for(int i = 0; i < 9; i++) if(seg[p].notes[i] != 0){
            cout << i << endl;
            break;
        }     
        return;
    }

    int m = (l + r)/2;
    getAll(2 * p, l, m);
    getAll(2 * p + 1, m + 1, r);
}

int main(){ _
    int n, q; cin >> n >> q;

    build(1, 0, n - 1);

    while(q --){
        int a, b; cin >> a >> b;
        Freq res = query(a, b, 1, 0, n - 1);
        auto freq = getFreq(res); 

        // cout << "Freq: " << freq << endl;

        update(a, b, freq, 1, 0, n - 1);
    }
    getAll(1, 0, n - 1);

    return 0;
} 
