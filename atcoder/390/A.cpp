#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

int main(){ _

    vector<int> arr(5); for(int& el: arr) cin >> el;
    vector<bool> corr(5, false);
    int cnt = 0;
    for(int i = 0; i < 5; i ++)
        corr[i] = (arr[i] == (i + 1)), cnt += (1 - corr[i]);
    
    if(cnt != 2) {
        cout << "No\n";
        return 0;
    }

    for(int i = 0; i < 4; i ++){
        if (corr[i] == false and corr[i+1] == false){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
} 
