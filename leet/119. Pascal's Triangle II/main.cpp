#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    vector<int> generate(int n) {
        vector<int> arr(n + 1, 1);
        int carry;
        for(int i = 0; i <= n; i++){
            carry = arr[0];
            for(int j = 1; j < i; j ++){
                int last = arr[j];
                arr[j] = arr[j] + carry;
                carry = last;
            }
        }
        return arr;
    }
};

int main(){ _
    int n; cin >> n;
    Solution s; 
    for(auto it : s.generate(n)){
        cout << it << " ";
    }
    return 0;
} 
