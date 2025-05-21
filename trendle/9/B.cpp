#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()


int main(){ _ 
    int h, w, m; cin >> h >> w >> m;
    
    map<int, int> cntrow, cntcol;
    vector<pair<int, int>> points;

    int maxrow=-INF, maxcol = -INF;
    int cntmaxrow = 0, cntmaxcol = 0;
    for(int i = 0; i < m; i ++){
        int a, b; cin>> a >> b; a--, b--;
        points.push_back({a, b});
        int &crow = cntrow[a], &ccol = cntcol[b];
        crow ++, ccol ++;
        if(maxrow == crow) cntmaxrow ++;
        else if(maxrow < crow) maxrow = crow, cntmaxrow = 1;
        
        if(maxcol == ccol) cntmaxcol ++;
        else if(maxcol < ccol) maxcol = ccol, cntmaxcol = 1;
    }

    ll cntpoints = 0;
    for(auto [x, y] : points){
        if(cntrow[x] == maxrow and cntcol[y] == maxcol) 
            cntpoints ++;
    }

    if(cntpoints == 1LL* cntmaxcol * cntmaxrow)
        cout << maxrow + maxcol -1 << endl;
    else cout << maxrow + maxcol << endl;

    // cout << cntpoints << " " << cntmaxcol * cntmaxrow  << " " << maxrow + maxcol << endl;
} 
