#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

int cnt[27];
string s; int n;

bool valid()
{
	for(int i = 0; i < 26; i++)
	{
		if(cnt[i] >= 2) return false;
	}
	return true;
}

int main(){ _
	cin >> s;
	n = s.size();
	if(n < 26) {cout << -1; return 0;}
	
    for(int i = 25; i < n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = i; j >= i - 25; j--) cnt[s[j]-'A']++;
		
		if(valid()){
			int cur = 0;
			while(cnt[cur]>0) cur++;
			for(int j = i - 25; j <= i; j++){
				if(s[j] == '?'){
					s[j] = cur + 'A';
					cur++;
					while(cnt[cur]>0) cur++;
				}
			}

            for(int i = 0; i < n; i++){
                if(s[i] == '?') s[i] = 'A';
            }

			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}