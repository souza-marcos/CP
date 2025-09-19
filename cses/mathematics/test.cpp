#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _ 

    int n; cin >> n;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    int cnt = 0;
    do{
        bool ok = true;
        for(int i = 0; i < n; i ++){
            if(arr[i] == i){
                ok = false;
                break;
            } 
        }
        if(ok){
            for(auto el : arr) cout << el + 1 << " ";
            cout << endl;
            cnt ++;
        }

    }while(next_permutation(arr.begin(), arr.end()));

    cout << "Total: " << cnt << endl;

    return 0;
} 
