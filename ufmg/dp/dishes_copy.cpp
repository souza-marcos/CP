#include <bits/stdc++.h>

using namespace std;

#define MAXMASK (1 << 18)
#define MAXN 20

int n, m, k;

		//x   y   = c
int rules[MAXN][MAXN];
int dishes[MAXN];
 // 01010

long long int dp[MAXMASK][MAXN];
int seen[MAXMASK][MAXN];

long long int solve(int qtd, int mask, int last){
	if(qtd == m) return dp[mask][last] = 0;
	
	if(seen[mask][last] == 1) return dp[mask][last];

	long long int answer = 0;
	
	for(int i = 0; i < n;i++){
		if((mask >> i) & 1) continue;
		answer = max(answer, solve(qtd + 1, mask | (1 << i), i) + dishes[i] + rules[last][i]);
	}
	
	seen[mask][last] = 1;
	return dp[mask][last] = answer;
}

int main(){
	cin >> n >> m >> k;
	
	//dishes
	for (int i = 0; i < n; i++){
		cin >> dishes[i];
	}
	
	//rules
	for (int i = 0; i < k; i++){
		int x, y, c;
		cin >> x >> y >> c;
		x--; y--;
		rules[x][y] = c;
	}
	
	long long int answer = -1;
	
	int qtd = -1, mask = -1, last = -1;
	
	vector<int> recover;
	
	for(int i = 0; i < n;i++){
		answer = max(answer, solve(1, 1 << i, i) + dishes[i]);
	}
	for (int i = 0; i < n; i++){
		if(answer == solve(1, 1 << i, i) + dishes[i]){
			qtd = 1;
			mask = 1 << i; 
			last = i;
			recover.clear();
			recover.push_back(i + 1);
			break;
		}
	}
	
	cout << answer << endl;
	
	while(qtd != m){
		for(int i = 0; i < n;i++){
			if((mask >> i) & 1) continue;
			if(dp[mask][last] == solve(qtd + 1, mask | (1 << i), i) + dishes[i] + rules[last][i]){
				//significa que ele foi nesse ramo
				qtd++;
				mask = mask | (1 << i);
				last = i;
				recover.push_back(i + 1);
				break;
			}
		}
	}
	
	cout << recover.size() << endl;
	for(int i = 0; i < recover.size(); i++){
		cout << recover[i] << " ";
	}
	cout << endl;
	
	return 0;
}