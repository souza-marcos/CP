#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
#define sz(a) (int)(a).size()

int main(){ _
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        int h = log2(n) + 2;
        int table[n][h];    
        for(int i = 0; i < n; i ++) {
            cin >> table[i][0];
        }

        for(int j = 1; j < h; j ++){
            for(int i = 0; i < n; i ++){
                table[i][j] = min(table[i][j-1], ((i + (1 << (j-1))) < n)? table[i + (1 <<(j-1))][j-1] : INF);
            }
        }

        int q; cin >> q;
        while(q --){
            int l, r; cin >> l >> r;
            if(l == r) cout << table[l][0] << endl;
            else {
                int szo = r - l + 1;
                int jump = 0;
                while((1 << (jump+1)) < szo) jump += 1;
                r = r-(1 << jump)+1;
                cout << min(table[l][jump], table[r][jump]) << endl;
            }
        }
    }
    return 0;
} 
