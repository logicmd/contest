#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;
class Solution {
public:
    int gcd(int x, int y)
    {
        int r;
        while(y>0)
        {
            r=x%y;
            x=y;
            y=r;
        }
        return x;
    }

    void make_relatively_prime(int &x, int &y)
    {
        int d = gcd(x,y);
        x/=d;
        y/=d;
    }
    // http://wenku.baidu.com/view/653a835f804d2b160b4ec017.html
    long getH(int m, int n)
    {
        int *a = new int[m+1];
        memset(a, 1, sizeof(a)/sizeof(int));
        int sum = 0;


        int mul = 1;
        for (int i = 1; i <= m; ++i)
        {
            mul*=a[i];
        }

        return sum;
    }

};
int main()
{
    Solution s;
    int x=40, y=24;
    s.make_relatively_prime(x, y);
    cout << x << " " << y << endl;
    system("PAUSE");
    return 0;
}

