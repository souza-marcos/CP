#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e5 + 10;

vector<int> arr;

struct SegTree {
    pair<int,int> seg[4*MAX];

    pair<int, int> merge(pair<int, int> a, pair<int, int> b){
        a.first += (a.second + b.second) >= 10; 
        a.second = (a.second + b.second) % 10;
        return a;
    }

    pair<int, int> build(int offset = 0, int p, int l, int r){
        if(l == r) return seg[p] = {0, arr[l]};
        int m = (l + r)/2;
        return seg[p] = merge(build(offset, p << 1, l, m), build(offset, p << 1 | 1, m, r)); 
    }

    pair<int, int> query(int p, int l, int r, int lq, int rq){

        if(l >= lq and r <= rq) return seg[p];
    
    }

};

int main(){ _

    // Constroi duas segtrees.



    return 0;
} 
