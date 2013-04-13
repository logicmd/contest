/*************************************************************************
Author: HongYihong
Created Time: Sun 03 Feb 2013 01:40:51 PM CST
File Name: Code/code/hackercup/round1/cardgame.cpp
Description:
************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;

    for ( int i = 1; i <= t; i++ )
    {
        cin >> n >> k;
        vector<long long> a, arrs;
        vector<long long>().swap(a);
        vector<long long>().swap(arrs);
        long long temp;
        for ( int j = 0; j < n; j++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());

/*        cout  << n << " " << k << endl;
        for (int j=0;j<n;j++)
          cout << a[j] << " ";
        cout << endl;*/
        arrs.push_back(1);
        for ( int j = k; j < n; j++)
        {
            temp = (j * arrs[j - k] / (j - k + 1)) % 1000000007;
       //     cout << temp << endl;
            arrs.push_back(temp);
        }

        long long sums = 0;

        for ( int j = k-1; j < n; j++)
          sums = (sums + (a[j] * arrs[j-k+1]) % 1000000007 ) % 1000000007;
        cout << "Case #" << i << ": " << sums % 1000000007 << endl;
    }
}