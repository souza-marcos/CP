#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int main(){ _
    int n, k; cin >>n >> k;
    vector<vector<int>> blocks(k);
    vector<int> colors_ord(n);

    for(int i= 0 ; i< n; i ++){
        int b, c; cin >> b >> c; c--;
        blocks[c].push_back(b);
        colors_ord[i] = c;
    }

    for(auto& row: blocks) sort(row.begin(), row.end());

    vector<int> pts(k, 0);

    int cur = -INF;
    for(auto color_cur : colors_ord){
        if(cur > blocks[color_cur][pts[color_cur]]){
            cout << "N\n"; return 0;
        }
        cur = blocks[color_cur][pts[color_cur]];
        pts[color_cur] ++;
    }
    cout << "Y\n";
    return 0;
} 
