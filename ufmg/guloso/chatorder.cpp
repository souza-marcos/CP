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

    int n; cin >> n;
    vector<pair<string, int>> arr(n);
    int i = 0;
    for(auto& el: arr){
        cin >> el.f;
        el.s = i++;
    } 

    vector<int> pos;
    set<string> con;
    for(int i = n -1; i >= 0; i--){
        if(con.count(arr[i].f) == 0){
            con.insert(arr[i].f);
            pos.push_back(i);
        }
    }
    for(auto el: pos) cout << arr[el].f << endl;
   
    return 0;
} 
