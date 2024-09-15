#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18



int main(){ _
    vector<vector<int>> arr(10, vector<int>(10, -1));
    int n = 10;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int res = min(i, j) + 1;
            arr[i][j] = res;
            arr[n - i - 1][j] = res;
            arr[i][n - j - 1] = res;
            arr[n - i - 1][n - j - 1] = res;
        }
    }
    int t; cin >> t;
    while(t--){
        int sum = 0;
        for(int i = 0; i < 10; i ++)
            for(int j = 0; j < 10; j++){
                char temp; cin >> temp;
                if(temp == 'X') sum += arr[i][j];
            }
        cout << sum << endl;
    }
    return 0;
} 
