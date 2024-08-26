#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

class Solution {
public:
    // abccccdd
    // cc -> 4
    // dd -> 2
    // a -> 1 / b -> 1

    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for(auto el: s) count[el] ++;
        
        // Iterate, get one odd and all even
        int size = 0;
        bool odd = false;
        for(auto& el: count){
            int m = (el.second % 2);
            size += (el.second - m);
            
            if(!odd and m) {
                size ++; odd = true;
            }
        }

        return size;
    }
};


int main(){ _
    string s; cin >> s;
    Solution so;
    cout << so.longestPalindrome(s) << endl;
    return 0;
} 
