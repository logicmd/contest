#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int min_cut(vector<vector<int>> &mat, int N, int M) {
    vector<vector<int>> count(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(i==0 && mat[i][j]==0) {
                count[i][j]=0;
                continue;
            }
            int tmp = i+1;
            if(i>0)
                tmp = min(tmp, count[i-1][j]);
            if(j>0)
                tmp = min(tmp, count[i][j-1]);
            count[i][j] = tmp + mat[i][j];
        }
    }

    int res = N;
    for(int i=0; i<N; i++) {
        for(int j=M-1; j>=0; j--) {
            if(j<M-1)
                count[i][j] = min(count[i][j], count[i][j+1]+mat[i][j]);

            if(i==N-1)
                res = min(res, count[i][j]);
        }
    }

    return res;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int ti=0; ti<T; ti++) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mat;
        for(int i=0; i<N; i++) {
            vector<int> row;
            vector<int>().swap(row);
            for(int j=0; j<M; j++) {
                int c;
                cin >> c;
                row.push_back(c);
            }
            mat.push_back(row);

        }
        cout << min_cut(mat, N, M) << endl;
    }
    return 0;
}
