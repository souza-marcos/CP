#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int r, c, k;
vector<vector<int>> m;

void solve(){
    m.assign(r +1, vector<int>(c + 2));
    for(int i = 0; i < r; i++) m[i][0] = 0;
    for(int i = 0; i < r; i++){
        string line; cin >> line;
        for(int j = 1; j <= c; j ++){
            m[i][j] = m[i][j-1] + (line[j-1] == '.');
        }
    }

    // for(int i = 0; i < r; i ++) {
    //     for(int j = 0; j <= c; j++) cout << m[i][j] << " ";
    //     cout << endl;
    // }

    int res = INF;
    for(int colin = 1; colin <= c; colin ++){
        for(int colfim = colin; colfim <= c; colfim ++){
            int acc = 0, rowin = 0;
            for(int rowfim = 0; rowfim < r; rowfim ++){
                acc += m[rowfim][colfim] - m[rowfim][colin-1];

                while(acc >= k){ // Tenho mais cadeiras dq nec => tento reduzir 
                    int ext = (colfim - colin + 1) * (rowfim - rowin + 1);
                    res = min(res, ext);  
                    acc -= m[rowin][colfim] - m[rowin][colin-1];
                    rowin ++;
                }
            }
        }
    }

    cout << res << endl;
}

int main(){_
    while(cin >> r >> c >> k and r != 0) solve();

    return 0;
}