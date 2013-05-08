#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> get(int N, int S)
{
    vector<int> v;
    if ( N * N * 2 < S )
    {
        return v;
    }
    else
    {
        for (int i = 0; i < 12; ++i)
        {
            v.push_back(0);
        }
        return v;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int N, S;
        cin >> N >> S;
        vector<int> six = get(N, S);
        if (six.size() == 0)
        {
            cout << "impossible" << endl;
        }
        else
        {
            for (vector<int>::iterator i = six.begin(); i != six.end(); ++i)
            {
                cout << *i << " ";
            }
            cout << endl;
        }
    }
    //system("PAUSE");
    return 0;
}