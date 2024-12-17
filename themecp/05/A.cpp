#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    vector<int> copy = arr;

    int j = n - (n%2 == 0);
    for(int i = 0; i < n; i += 2) arr[i] = j, j -= 2; 
    
    if(n % 2 == 0){
        for(int i = 0; i < n; i += 2){
            swap(arr[i], arr[i + 1]);
        }
    }

    
    for(auto el : arr) cout << el << " ";
    cout << endl;



}   

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
