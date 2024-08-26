#include <iostream>
#define endl "\n"
using namespace std;
int main(){
	int n, m;cin >> n >> m;
	int ter[n][m];
	int maxL = 0, maxC = 0;
	for(int i = 0; i < n; i++){
		int cont = 0;
		for(int j =0; j < m; j++){
			cin >> ter[i][j];
			cont += ter[i][j];
		}
		if(cont > maxL) maxL = cont;
	}
	
	for(int i= 0; i < m;i ++){
		int cont = 0;
		for(int j = 0; j < n; j++) cont += ter[j][i];
		if(cont > maxC) maxC = cont;
	}
	cout << max(maxC, maxL) << endl;

	return 0;
}
