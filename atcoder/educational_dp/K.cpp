#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

int main(){ _
    int n, k; cin >> n >> k;
    vector<int> arr(n); for(int& el: arr) cin >> el;
    
    bool memo[k + 1];
    memset(memo, 0, sizeof memo);

    memo[0] = 1;
    int ptr_i = 0;
    for(int i = 1; i <= k; i ++){
        if(memo[i] == arr[ptr_i]){
            ptr_i ++; continue; // Sempre otimo o primeiro escolher peso e ganhar
        }

        bool val = 0;
        for(int j = 0; j < n and arr[j] <= i; j ++){
            if(memo[i - arr[j]]) { val = 1; break; }     
        }
        memo[i] = !val;
    }

    // for(int i = 0; i <= k; i ++) cout << memo[i] << " ";
    // cout << endl;

    cout << (memo[k]?"Second":"First") << endl;
    return 0;
} 
