#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <future>

using namespace std;

int arr[17];
vector <future <int> > fu;
char str[1000000];

int res(int st, int ed, int len)
{
    int sum = 0;
    for (int i = st; i < ed; ++i)
    {
        sum += (str[i] - '0') * arr[((len - i - 1) % 17)];
    }
    return sum % 17;
}
int func(int len, int par)
{
    cin >> str;
    int sum = 0;
    fu.clear();
    for (int i = 0; i < par; ++i)
    {
        fu.push_back(async(res, i * len / par, (i + 1) * len / par, len));
    }
    for (int i = 0; i < par; ++i)
    {
        sum += fu[i].get();
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
