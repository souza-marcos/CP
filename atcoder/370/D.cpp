#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()
vector<set<int>> cols, rows;

void eraseCell(int r, int c) { rows[r].erase(c), cols[c].erase(r); }; 

int main(){ _
    int h, w, q; cin >> h >> w >> q;
    cols.resize(w), rows.resize(h);

    for(int i= 0; i < h; i ++) for(int j= 0; j < w; j++){
        rows[i].insert(j);
        cols[j].insert(i);
    }


    int r, c; 
    while(q --){
        cin >> r >> c; r--, c--;
        if(rows[r].count(c)){
            eraseCell(r, c);
            continue;
        }
        auto itrow = rows[r].lower_bound(c), itcol = cols[c].lower_bound(r);        
        // Left
        if(itrow != rows[r].begin()) eraseCell(r, *prev(itrow));

        // Right
        if(itrow != rows[r].end()) eraseCell(r, *itrow); 

        // Up
        if(itcol != cols[c].begin()) eraseCell(*prev(itcol), c);

        // Down 
        if(itcol != cols[c].end()) eraseCell(*itcol, c);  
    }
    int cnt = 0;
    for(auto row: rows) cnt += sz(row);
    // printAll();
    cout << cnt << endl;
    return 0;
} 
