#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _

    int l, c; cin >> l >> c;
    int m[l][c];

    char temp;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> temp;
            m[i][j] = (temp == '.' ? 0: 1);
        }
    }

    int cont = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == 0) continue;

            if(i == 0 || i == l - 1 || j == 0 || j == c - 1){ // borders
                cont ++;
                continue;
            }
            
            if(i - 1 >= 0 && m[i - 1][j] == 0) cont ++; // left
            else if(i + 1 < l && m[i + 1][j] == 0) cont ++; //right 
            else if(j - 1 >= 0 && m[i][j - 1] == 0) cont ++; // up
            else if(j + 1 < c && m[i][j + 1] == 0) cont ++; // down
        }
    }
    cout << cont << endl;

    return 0;
} 
