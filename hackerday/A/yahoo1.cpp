#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int gets(int A, int B, int M, int D)
{

    if (B == 0)
    {
        return 0;
    }

    long long x = 1, k = 1, kk=0;
    while (1)
    {
        x = 10 * x;
        long long y = 1;
        bool flag = false;
        for (int i=0; i<k-1; i++)
        {
            if ((x-y)%B==0)
            {
                flag = true;
                kk = i;
                break;
            }
            else
            {
               y = y*10;
            }
        }
        if (flag)
        {
            break;
        }
        k++;
    }
    cout << k << " " << kk << endl;

    int loop_len = k - kk;
    int non_loop_len = kk;

    double xx = (double) (A * 1.0) / B;

    map<int, vector<int> > mm;
    for (int i = 0; i < k; ++i)
    {
        xx *= 10;
        int d = floor(xx);
        map<int, vector<int> > iter = mm.find(d);
        if (iter == mm.end())
        {
            vector<int> pos;
            pos.push_back(i+1);
            mm.insert(make_pair(d, pos));
        }
        else
        {
            vector<int> pos = iter->second;
            pos.push_back(i+1);
            mm[d] = pos;
        }
    }

    map<int, vector<int> > got = mm.find(D);
    if (got == mm.end())
    {
        return 0;
    }
    else
    {
        vector<int> poslin = got->second;
        vector<int> once;
        vector<int> more;
        int ret = 0;
        int poss = 0;
        for (vector<int>::iterator i = poslin.begin(); i != poslin.end(); )
        {
            poss++;
            if ((*i) < kk)
            {
                M--;
                ret = (*i);
                poslin.erase(i);
            }
            else
            {
                ++i;
            }
        }
    }

    return 0;
}

int main()
{
    int n;
    cout << gets(20, 193 , 1, 3);
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     int A, B, M, D;
    //     cin >> A >> B >> M >> D;

    // }
    system("PAUSE");
    return 0;
}