#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX_SIZE = 1e5 + 10;

vector<vector<int>> arr;
int vis[MAX_SIZE];

int find_1edge(int x){
    vis[x] = 1;
    if(arr[x].size() == 1) return x;
    for(auto neig: arr[x]) if(vis[neig] == 0){
        int res = find_1edge(neig);
        if(res != -1) return res;
    }
    return -1;
}

void solve(){
    arr.clear(); // Fucking clear
    memset(vis, 0, sizeof vis);

    int n, m, temp_a, temp_b; cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < m; i++){
        cin >> temp_a >> temp_b; temp_a --; temp_b --;
        arr[temp_a].push_back(temp_b);
        arr[temp_b].push_back(temp_a);
    }

    int a = find_1edge(0); 
    int x = arr[a].at(0);
    
    int y = -1;
    for(auto el: arr[x]) if(arr[el].size() != 1) y = el;

    cout << arr[y].size() << " " << arr[x].size() -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();

    return 0;
} 
