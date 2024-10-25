#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<int> arr(n); 
    vector<int> inv(n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i], arr[i] --;
        inv[arr[i]] = i;
    }   

    int cnt = 0;
    for(int i = 0; i < n; i ++){
        if(arr[i] == i or i == arr[arr[i]]){
            continue;
        }

        int aux = arr[arr[i]]; 
        int address = inv[i];
        arr[arr[i]] = i;
        arr[address] = aux;
        cnt++;

        inv[aux] = address; inv[arr[i]] = i; 
        // cout << "AUX: " << aux << " END: " << address << endl; 
        // for(int el: arr) cout << el << " ";
        // cout << endl;

    }
    // for(int el: arr) cout << el << " ";
    // cout << endl;

    cout << cnt << endl;

}

int main(){ _ 
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
