#include <bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> set_t;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

bool board[8][8], col[8], d1[15], d2[15];

int search(int line){
    if(line == 8) return 1;
    int cnt = 0;
    for(int j = 0; j < 8; j ++){
        if(board[line][j] and col[j] and d1[j - line + 7] and d2[j + line]){
            col[j] = d1[j-line + 7] = d2[j + line] = false;
            cnt += search(line + 1);
            col[j] = d1[j-line + 7] = d2[j + line] = true;
        }
    }

    return cnt;
}

int main(){ _

    for(int i = 0; i < 8; i ++){
        col[i] = true;
        string s; cin >> s;
        for(int j = 0; j < 8; j ++){
            board[i][j] = (s[j] == '.');
        }
    }
    for(int i = 0; i < 15; i ++) d1[i] = d2[i] = true;
    int res = search(0);
    cout << res << endl;
    return 0;
} 
