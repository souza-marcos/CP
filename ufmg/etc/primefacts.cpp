#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> primes;



    int number, qt_primos, k = 0, raiz_number, isPrime = 1;

    printf("Enter the number\n");
    scanf("%d", &number);

    raiz_number = sqrt(number);

    qt_primos = raiz_number - 1;
    int *primes = (int *)
        malloc((raiz_number + 1) * sizeof(int));
    // Setando todos valores como falso
    for (int j = 0; j <= raiz_number; j++)
        primes[j] =
            0;
    for (int i = 2; i <= raiz_number; i++)
        if (primes[i] == 0)
            for (int j = i * 2; j <= raiz_number; j += i)
                if (primes[j] == 0)
                {
                    primes[j] = j;
                    qt_primos--;
                }
    int *lista_primos =
        malloc(qt_primos * sizeof(int));
    for (int i = 2; i <= raiz_number; i++)
    {
        if (primes[i] == 0)
            lista_primos[k++] = i;
    }
    for (int i = 0; i < qt_primos; i++)
        if (number % lista_primos[i] == 0)
        {
            isPrime = 0;
            break;
        }
    if (number == 1 || !isPrime)
        printf("O numero %d, nao eh primo\n",
               number);
    else
        printf("O numero %d, eh primo\n", number);
    return 0;
    return 0;
}