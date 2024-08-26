#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3 + 10;

int n, m;
vector<string> g(MAX);

bool valid(int i, int j){
    if(i == 0 or i == n - 1 or j == 0 or j == m - 1) return true;
    return i >= 0 and i < n and j >= 0 and j < m and g[i][j] == '.';
}

int main(){ _

    cin >> n >> m;
    for(auto& el: g) cin >> el;

    vector<pair<int, int>> movs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int cont = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(g[i][j] == '#'){
            for(auto [newi, newj]: movs){
                if(valid(newi + i, newj + j)){
                    cont ++; break;
                }
            }
        }
    }
    cout << cont << endl;

    return 0;
} 
