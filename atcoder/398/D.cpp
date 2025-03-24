#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n, xPlayer, yPlayer; cin >> n >> xPlayer >> yPlayer;
    int xFire = 0, yFire = 0;
    string s; cin >> s;

    set<pair<int, int>> smokes;
    smokes.insert({0, 0});

    for(int i = 0; i < n; i++){

        int newi = 0, newj = 0;
        if(s[i] == 'N') newi ++;
        else if(s[i] == 'S') newi --;
        else if(s[i] == 'W') newj ++;
        else newj --;  

        xFire += newi, yFire += newj;
        xPlayer += newi, yPlayer += newj;

        // cout << xFire << " " << yFire << endl;
        // cout << xPlayer << " " << yPlayer << endl;

        if(smokes.count({xFire, yFire}) == 0) smokes.insert({xFire, yFire});
        if(smokes.count({xPlayer, yPlayer}) == 0){
            cout << 0;
        } else cout << 1;

        // cout << endl;
    }

    cout << endl;

    return 0;
} 
