#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n, k; cin >> n >> k;
    k --;
    vector<int> arr(n);
    for(int& el: arr) cin >> el;
    int init = arr[k];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
  //  for(int el : arr) cout << el << " ";
  //  cout << endl;
    
    int cur = 1;
    int i = 0;
    while(arr[i] <= init) i ++;

    for(; i < sz(arr); i ++){
        int tempo = arr[i] - init;
//        cout << "Estou em " << init << "->  " << arr[i] << ", water => " << cur << endl;  
        if(tempo > init - cur + 1){
            cout << "NO\n";
            return;
        }
        cur += tempo;
        init = arr[i];
    }
    cout << "YES\n";
}


int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
} 
