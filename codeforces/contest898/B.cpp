#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        int min_val = INF, idx = -1;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            if(temp < min_val){ min_val = temp; idx = i;}
            arr[i] = temp;
        }
        arr[idx] ++;
        ll mult = 1;
        for(auto el:arr)
        {
            if(el == 0){ mult = 0; break;}
            mult *= el;
        } 
        cout << mult << endl;
    }

    return 0;
} 
