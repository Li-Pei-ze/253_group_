#include <iostream>
#include <string>
#include <cstring>
#include <omp.h>

using namespace std;

string str;
int s1[10], s2[10];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin >> str;
    bool flag = true;
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    int n = str.length();
    int blocksize = n / 4;
    double t = omp_get_wtime();
    #pragma omp parallel for num_threads(4) schedule(static)
    for (int i = 0; i < n; ++i)
    {
        int num = i / blocksize;
        if (str[i] == '(')
        {
            s1[num]++;
        }
        else
        {
            if (s1[num] > 0)
                s1[num]--;
            else s2[num]++;
        }
    }
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        sum += s1[i];
        sum -= s2[i];
        if (sum < 0) flag = false;
    }
    if (sum > 0) flag = false;
    cout << flag << endl;
    cout << omp_get_wtime() - t << endl;
    return 0;
}
