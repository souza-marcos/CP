#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

const int MAX = 1e5 + 10;
int BIT[MAX];

// Função para atualizar o BIT
void update(int index, int val, int n) {
    while (index <= n) {
        BIT[index] += val;
        index += index & -index;
    }
}

// Função para consultar o BIT
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}

int main() { _
    int n; 
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = query(p[i] - 1); // Conta quantos elementos maiores que p[i] já foram vistos
        update(p[i], 1, n); // Atualiza o BIT para incluir p[i]
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
