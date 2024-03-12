#include <iostream>
#include <string>
#include <omp.h>


using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> str;
    bool flag = true;
    int counter = 0;
    double t = omp_get_wtime();

    for (char ch : str)
    {
        if (ch == '(')
        {
            ++counter;
        } else if (ch == ')')
        {
            --counter;
        }
        if (counter < 0)
        {
            flag = false;
        }
    }
    if (counter > 0) flag = false;
    cout << flag << endl;
    cout << omp_get_wtime() - t << endl;
    return 0;
}
