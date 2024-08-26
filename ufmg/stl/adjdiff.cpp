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

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    list<int> aux;
    for(auto& el:arr) cin >> el;
    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1;
    while(l <= r){
        if(l < r){
            aux.push_front(arr[r]);
            aux.push_front(arr[l]);
        }else{
            aux.push_front(arr[l]);
        }
        l ++; r --;

    }

    for(auto el : aux) cout << el << " ";
    cout << endl;
}


int main(){ _
    int t; cin >> t;
    while(t--) solve();
    return 0;
} 
