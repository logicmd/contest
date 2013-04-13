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

int main()
{

    long c, q, n, x;
    char ccc;
    long m;
    map<long, int> hashmap;
    do {

        cin >> c >> q >> n >> x;
        map<long, int>().swap(hashmap);

        m = c;
        hashmap.insert(make_pair(m, 0));
        if (c == x)
        {
            cout << 0 << endl;
            continue;
        }
        int d = 1 << n;
        int i = 1;
        while(1) {
            int q_d = (q%d * q%d)%d;
            int m_d = m%d;
            m = (q_d * m_d + 1)%d;

            if (m==x)
            {
                cout << i << endl;
                break;
            }
            map<long, int>::iterator got = hashmap.find(m);
            if (got == hashmap.end())
            {
                hashmap.insert(make_pair(m, i));
                i++;
            }

            else
            {

                if (got->first == x)
                {

                    cout << got->second << endl;
                }
                else
                {
                    cout << -1 << endl;
                }
                break;
            }
        }

    } while((ccc=getchar())!=EOF);

    // system("PAUSE");
    return 0;
}

