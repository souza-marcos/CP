#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _
    
    int n; cin >> n;
    vector<int> arr(n); for(auto& el : arr) cin >> el;
    vector<int> last(1e6 + 10, INF);
    int mindiff = INF;

    for(int i = 0; i < n; i ++){
        int el = arr[i];
        if(last[el] != INF){
            mindiff= min(mindiff, i - last[el] + 1);
        }
        last[el] = i;
    }
    cout << (mindiff == INF? -1: mindiff) << endl;
    return 0;
} 
