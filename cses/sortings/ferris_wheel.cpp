#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, x; cin >> n >> x;
    vector<int> arr(n); for(int& el : arr) cin >> el;
    sort(arr.rbegin(), arr.rend());
    int i = 0, j = n - 1;
    int cnt = 0;
    while(i <= j){
        if(i == j){
            cnt ++; i ++;
        }else{
            if(arr[i] + arr[j] <= x)
                cnt ++, i ++, j --;
            else cnt ++, i ++;
        }
    }
    cout << cnt << endl;
    return 0;
} 
