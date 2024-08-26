#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;

        if(s.size() == 0) return true;

        for(auto el: t){
            if(s[i] == el) i ++;
            if(i >= s.size()) return true;
        }
        return false;
    }
};

int main(){ _
    string s, t; cin >> s >> t;
    Solution so;
    cout << so.isSubsequence(s, t) << endl;
    return 0;
} 
