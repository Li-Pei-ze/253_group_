#include <iostream>
#include <cmath>
#include <vector>
#include <omp.h>


using namespace std;

struct point
{
    double x, y;
};
#define sqr(x) ((x)*(x))
double dist(point a, point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int n;
vector<point> V;
int main(int argc, char **argv)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        point tmp;
        cin >> tmp.x >> tmp.y;
        V.push_back(tmp);
    }
    double dis = 0;
    double dis1 = 0;
    double dis2 = 0;
    double dis3 = 0;
    int fin1_i = 0, fin1_j = 0;
    int fin2_i = 0, fin2_j = 0;
    int fin3_i = 0, fin3_j = 0;
    int fini = 0, finj = 0;

    int n1 = (int)((double)(-sqrt(3)*sqrt(8*n*n-8*n+3)-3)/6.0+n);
    int n2 = (int)((double)(3 - sqrt(3)*sqrt(4*n*n-4*n+3))/6.0+n);
    #pragma omp parallel sections
    {
        #pragma omp section
        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (dis1 < dist(V[i], V[j]))
                {
                    dis1 = dist(V[i], V[j]);
                    fin1_i = i;
                    fin1_j = j;
                }
            }
        }
        #pragma omp section
        for (int i = n1; i < n2; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (dis2 < dist(V[i], V[j]))
                {
                    dis2 = dist(V[i], V[j]);
                    fin2_i = i;
                    fin2_j = j;
                }
            }
        }
        #pragma omp section
        for (int i = n2; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (dis3 < dist(V[i], V[j]))
                {
                    dis3 = dist(V[i], V[j]);
                    fin3_i = i;
                    fin3_j = j;
                }
            }
        }
    }
    if (dis1 <= dis2)
    {
        dis = dis2;
        fini = fin2_i;
        finj = fin2_j;
    }
    else
    {
        dis = dis1;
        fini = fin1_i;
        finj = fin1_j;
    }
    if (dis < dis3)
    {
        dis = dis3;
        fini = fin3_i;
        finj = fin3_j;
    }
    cout << dis << endl;
    cout << fini << " " << finj << endl;
    return 0;
}
