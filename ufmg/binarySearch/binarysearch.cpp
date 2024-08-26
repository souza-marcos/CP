#include <bits/stdc++.h>
using namespace std;
    
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
    
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
    
int main(){ _
    
    int n, k, q; cin >> n >> k;
    
    int arr[n];
    for(auto& el: arr) cin >> el;
    for(int i = 0; i < k; i++){
        cin >> q;
    
        int l = -1, r = n;
        bool found = false;
        while(l + 1 < r){
            int m = (l + r)/2;
            if(q > arr[m]) l = m;
            else if(q < arr[m]) r = m;
            else {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if(!found) cout << "NO" << endl;
    
    }
    
    return 0;
} 