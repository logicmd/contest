#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    // cpp 传参尽量传&
    static bool interval_Comparator(const Interval &i, const Interval &j) {
        return (i.start < j.start);
    }

    void merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1)
        {
            return ;
        }
        sort(intervals.begin(), intervals.end(), interval_Comparator);
        for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end() - 1; )
        {
            if ((i+1)->start > (i)->end) // point *(i) or (i)->member
            {
                ++i;
                continue;
            }
            if ((i+1)->start <= (i)->end && (i+1)->end >= (i)->end)
            {
                (i)->end = (i+1)->end;

            }
            intervals.erase(i+1);

        }
    }

    int get(vector<Interval> &intervals)
    {
        merge(intervals);
        int max = 0;
        for (vector<Interval>::iterator i = intervals.begin(); i != intervals.end(); ++i)
        {
            int minus = i->end - i->start;
            if (minus > max)
            {
                max = minus;
            }
        }
        return max;
    }

};


int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<Interval> inter;
    for (int i = 0; i < n; i++)
    {
        Interval interval;
        cin >> interval.start >> interval.end;
        inter.push_back(interval);
    }
    cout << s.get(inter);
    //system("PAUSE");
    return 0;
}