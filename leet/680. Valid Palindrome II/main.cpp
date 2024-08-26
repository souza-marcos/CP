#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


class Solution {
public:
    int verifyPalindrome(string s, int jmp){
        int i = 0, j = s.size() -1;
        while(i < s.size()/2 and j > s.size()/2){
            if(i == jmp) i += 1;
            if(j == jmp) j -= 1;
            if(s[i] != s[j]) return i;
        }
        return -1;
    }

    bool validPalindrome(string s) {
        bool valid = (verifyPalindrome(s, -1) == -1);
        for(int i = verifyPalindrome(s); i >= 0 and i < s.size(); i ++ ){
            string aux = s;
            aux.erase(i, 1);
            if(verifyPalindrome(aux) == -1){
                valid = true;
                break;
            }
        }

        return valid;
    }
};

// aba -> true
// abca --


int main(){ _
    
    string s;
    cin >> s;

    Solution so;
    cout << (so.validPalindrome(s) ?"true":"false") << endl; 

    return 0;
} 
