#include <iostream>
#include <algorithm>
#include <cstring>
#include <omp.h>

using namespace std;

int arr[17];
char str[1000000];

int func(int len, int par)
{
    cin >> str;
    int sum = 0;
    #pragma omp parrallel for num_threads(par) shared(sum)
    {
        for (int i = 0; i < len; ++i)
        {
            sum += (str[i] - '0') * arr[((len - i - 1) % 17)];
            //cout << sum << endl;
        }
    }
    return sum % 17;
}
int main(int argc, char **argv)
{
    arr[0] = 1;
    for (int i = 1; i < 17; ++i)
    {
        arr[i] = (arr[i - 1] * 10) % 17;
    }
    cout << func(4, 2) << endl;
    return 0;
}
