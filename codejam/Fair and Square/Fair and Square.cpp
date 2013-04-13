#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


pair<int, int> get_bound(int l, int u) {
    int x, y;

    int ll = sqrt(l);
    if (ll * ll == l)
    {
        x = ll;
    }
    else
    {
        x = ll + 1;
    }

    y = sqrt(u);

    return make_pair(x, y);
}

bool is_palindromes(int x) {
    vector<int> v;
    while(x / 10 > 0) {
        v.push_back(x%10);
        x /= 10;
    }

    int i = 0;
    int j = v.size();
    while(j>i) {
        if (v[i] == v[j])
        {
            i++;
            j--;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
