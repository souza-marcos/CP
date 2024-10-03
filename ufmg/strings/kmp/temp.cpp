#include <iostream>
#include <vector>
using namespace std;
#define sz(x) (int)x.size()

vector<int> pif(string s){ 
    vector<int> p(sz(s));
    for(int i = 1, j = 0; i < sz(s); i ++){
        while(j > 0 and s[j] != s[i]) j = p[j-1];
        if(s[j] == s[i]) j ++;
        p[i] = j;
    }
    return p;
}

vector<int> matching(string& t, string& pat){
    vector<int> pi = pif(pat + '$'), match;
    for(int i = 0, j = 0; i < sz(t); i ++){
        while(j > 0 and pat[j] != t[i]) j = pi[j-1];
        if(pat[j] == t[i]) j ++;
        if(j == sz(pat)) match.push_back(i-j+1);
    }
    return match;
}

int main(){
    string text, pattern;
    cin >> text >> pattern;
    auto res = matching(text, pattern);
    for(auto el: res) cout << el << " ";
    cout << endl;
}