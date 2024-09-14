#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18


int main(){ _

    int n, m;  cin >> n >> m;
    vector<int> fire(m);
    for(auto &el : fire) cin >> el;

    int j = 0;
    for(int i = 1; i <= n; i++){
        if(i == fire[j]){
            cout << 0 << endl;
            j++;
        }else{
            cout << fire[j] - i << endl;
        }
    }

    return 0;
} 
