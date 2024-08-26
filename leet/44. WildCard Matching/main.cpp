#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // element by element
        const char* star = NULL;
        const char* ss = s;
        while(*s){
            if((*p == '?') or (*p == *s)){s ++, p++; continue;}
            if(*p == '*'){ star = p++; ss = s; continue;}
            if(star){p = star + 1; s = ++ss; continue;}

            return false;
        }

        while(*p == '*'){p++;}
        return !*p;
    }
};

int main(){ _
    char s[100], p[100]; cin >> s >> p;
    Solution so;
    cout << so.isMatch(s, p) << endl;
    return 0;
} 
