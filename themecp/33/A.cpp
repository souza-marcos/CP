#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){

    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<tuple<ll, ll, ll>> ran_points; // problems - penalty - id

    int id = 0;
    for(auto& row : grid){
        for(int& el : row) cin >> el;
        sort(row.begin(), row.end());
        ll acc = 0, pen = 0;
        
        int j = 0;
        while(j < sz(row) and acc + row[j] <= h){
            acc += row[j];
            pen += acc;
            j ++;
        }
        ran_points.push_back(make_tuple(-j, pen, id));
        id++;
    }
    sort(ran_points.begin(), ran_points.end());
    int res = 1;
    for(auto [pt, pen, id]: ran_points){
        // cout << pt << " " << pen << " " << id << "\n";
    
        if(id == 0){
            cout << res << endl;
            return;
        }
        res ++;
    }
    // cout << " ------ \n";
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
