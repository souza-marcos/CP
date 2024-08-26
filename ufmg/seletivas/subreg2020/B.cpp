#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

bool grid[10][10];

int main(){ _
    int n; cin >> n;
    vector<tuple<int, int, int, int>> v(n);

    for(int i = 0; i < 10; i ++) for(int j = 0; j < 10; j ++) grid[i][j] = false;

    for(auto &[d, l, r, c] : v) 
        cin >> d >> l >> r >> c;

    for(auto [d, l, r, c] : v){
        c --, r --; 
        if(d){
            if(r + l - 1 >= 10){ cout << "N\n"; return 0; }
            for(int i = 0; i < l; i ++){
                if(grid[r + i][c]){ cout << "N\n"; return 0; }
                grid[r + i][c] = true;
            }
        }else{
            if(c + l -1 >= 10){ cout << "N\n"; return 0; }
            for(int i = 0; i < l; i ++){
                if(grid[r][c + i]){ cout << "N\n"; return 0; }
                grid[r][c + i] = true;
            }
        }
    }
    // for(int i = 0; i < 10; i ++){
    //     for(int j = 0; j < 10; j ++) cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    cout << "Y\n";
    return 0;
} 
