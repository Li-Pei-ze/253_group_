#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;
int main()
{
    freopen("input.txt", "w", stdout);
    srand(time(0));
    for (int i = 0; i < 100000000; ++i)
    {
        cout << ((rand() & 1) ? '(' : ')');
    }

    return 0;
}
