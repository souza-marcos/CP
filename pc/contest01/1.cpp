#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_
    int n; cin >> n;
    map<pair<int, int>, int> times;
    map<pair<int, int>, bool> vis; 
    while(n --){
        int c, d; cin >> c >> d;
        times[{c, 0}] ++;
        times[{0, d}] ++;
        vis[{c, 0}] = false;
        vis[{0, d}] = false;
    }
    int cont = 0;
    for(auto [fi, se]: times){
        if(vis[fi]) continue;
        if(fi.first != 0){
            auto vals = times[{0, fi.first}];
            cont += se * vals;
        }else{
            auto vals = times[{fi.second, 0}];
            cont += se * vals;
        }

        // cout << fi.first << ", " << fi.second << ": " << se << endl;
    }
    cout << cont/2 << endl;
    return 0;
}