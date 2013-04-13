#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
string &compose(string *s, int len);

int main()
{
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int m; string k1, k2;
        cin >> m >> k1 >> k2;
        int l = k1.size() / m;
        string *s1 = new string[m];
        string *s2 = new string[m];
        for (int i = 0; i < m; ++i)
        {
            s1[i].append(k1, i * l, (i + 1) * l);
            s2[i].append(k2, i * l, (i + 1) * l);
        }
        cout << "hello";
        cout << compose(s1, m);
        cout << compose(s2, m);
        //cout << "Case #" << (t + 1) << ": " << sum << endl;
    }
    return 0;
}

string &compose(string *s, int len)
{
    string ret;
    for (int i = 0; i < len; ++i)
    {
        ret += s[i];
    }
    string &retref = ret;
    return retref;
}