#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& c: grid) cin >> c;

    pair<int, int> first = {INF, INF}, last = {-1, -1};


    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#'){
                first.first = min(first.first, i);
                first.second = min(first.second, j);

                last.first = max(last.first, i);
                last.second = max(last.second, j);
            }
        }
    }

    // cout << first.first << " " << first.second << endl;
    // cout << last.first << " " << last.second << endl;

    if(first.first == INF) return cout <<"Yes\n", 0;

    for(int i = first.first; i <= last.first; i ++){
        for(int j = first.second; j <= last.second; j ++){
            if(grid[i][j] == '.') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";


    return 0;
} 
