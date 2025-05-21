#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n; cin >> n;
    vector<int> arr;
    for(int i = 1; i <= n; i ++) arr.emplace_back(i);

    for(int i = 0; i < sz(arr); i ++){
        if(i%2 == 0) arr.push_back(arr[i]);
        else cout << arr[i] << " ";
    }
    cout << endl;
    return 0;   
} 
