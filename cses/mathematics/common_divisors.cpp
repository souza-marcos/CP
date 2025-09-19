#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6 + 10; 

int main(){ _ 

    // Crivo mas contrario?? 
    int n; cin >> n;
    vector<int> arr(MAX);
    for(int i = 0; i < n; i ++){
        int a; cin >> a;
        arr[a] += 1;
    }

    for(int i = 2; i < MAX; i ++){
        for(int j = 2*i; j < MAX; j += i){
            arr[i] += arr[j];
        }
    }


    int res = 1;
    for(int i = MAX-1; i >= 0; i --){
        if(arr[i] >= 2) { res = i; break; }
    }
    cout << res << endl;
    return 0;
} 
