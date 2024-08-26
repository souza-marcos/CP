#include <iostream>
using namespace std;
int main(){
	int n, c, p, cont = 1;cin >> n;
	while(n != 0){
		for(int i=1; i<=n; i++){
			cin >> p;
			if(p == i) c = p;
		}
		cout << "Teste " << cont ++;
		cout << "\n" << c << "\n";
		cin >> n;
	}
	return 0;
}
