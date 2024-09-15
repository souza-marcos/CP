// https://br.spoj.com/problems/FATORIAL/
#include <iostream> 
#define endl '\n'
using namespace std;
typedef long long ll;

const int MAX = 1000010; const ll MOD = 1e12;
ll fat[MAX];

int main(){
	int n, i= 1, cur = 1;	
	fat[0] = 0, fat[1] = 1;
	auto printres = [&](){
		cout << "Instancia " << cur++ << endl;
		cout << fat[n]%10 << endl;
	};

	while(cin >> n){
		if(n <= i) {
			printres();		
			continue;
		}
		
		while(i < n){
			ll next = (i + 1) * fat[i];
			while(next%10==0) next/=10;
			fat[i + 1]= next%MOD;
			i ++;
		}

		printres();
	}

   return 0;
}
