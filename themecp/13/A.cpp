#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(auto& el : arr) cin >> el;

    if(k == 4){ 

        vector<int> two;
        int minv = INF;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < k; j ++){
                if((arr[i] + j) % 4 == 0) minv=min(minv, j);
                if((arr[i] + j) % 2 == 0 and j < 2) two.push_back(j);
            }
        }
        sort(two.begin(), two.end());
        if(sz(two) >= 2){
            cout << min(two[0] + two[1], minv) << endl;
        } else cout << minv << endl;
    } else {
        int minv = INF;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < k; j ++){
                if((arr[i] + j) % k == 0) minv=min(minv, j);
            } 
        }
        cout << minv << endl;
    }

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
