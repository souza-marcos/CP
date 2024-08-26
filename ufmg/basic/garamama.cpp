    #include <bits/stdc++.h>
    using namespace std;

    #define _ ios_base::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
    #define f first
    #define s second
    #define dbg(x) cout << #x << " = " << x << endl;

    typedef long long ll;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    int main(){ _
        string s1, s2;
        cin >> s1 >> s2;
        map<char , int> sh, sh2;
        for(int i = 0; i< s1.length(); i++){
            sh[s1[i]] ++;
            sh2[s2[i]] ++;
        }
        for(auto el: sh){
            if(el.second < sh2[el.first]) {
                cout << "N" << endl;
                return 0;
            }
        }
        for(auto el: sh2){
            if(el.second > sh[el.first] && el.first != '*'){
                cout << "N" << endl;
                return 0;
            }
        }
        cout << "S" << endl;

        return 0;
    } 
