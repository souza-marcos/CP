#include <iostream>
using namespace std;
int main(){
	int n; cin >> n;
	for(int i = 2; i*i <=n; i++){
		if(n % i == 0){
			cout << "nao\n";
			return 0;
		}
	}
	cout << "sim\n";
	return 0;
}
