#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int get_len(vector<vector<char> > &mat, int M, int N) {
    vector<vector<vector<int> > > dp(2, vector<vector<int> >(N, vector<int>(M, 0)));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(mat[i][j]=='#')
                continue;

            int cur=0;
            if(i-1>=0 && mat[i-1][j]!='#')
                cur = max(cur, dp[0][i-1][j]+1);

            if(j-1>=0 && mat[i][j-1]!='#')
                cur = max(cur, dp[0][i][j-1]+1);

            dp[0][i][j]=cur;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(mat[i][j]=='#')
                continue;

            int cur=0;
            if(i-1>=0 && mat[i-1][j]!='#')
                cur = max(cur, dp[0][i-1][j]+1);

            if(i+1<N && mat[i+1][j]!='#')
                cur = max(cur, dp[0][i-1][j]+1);


            if(j-1>=0 && mat[i][j-1]!='#')
                cur = max(cur, dp[0][i][j-1]+1);

            dp[1][i][j]=cur;
        }
    }

    return max(dp[0][N-1][M-1], dp[1][N-1][M-1])+1;
}

void print(vector<vector<char> > &mat, int M, int N) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout<<mat[i][j];
        }
        cout << endl;
    }

    return ;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> mat;
        for(int i=0; i<N; i++) {
            vector<char> row;
            vector<char>().swap(row);
            for(int j=0; j<M; j++) {
                char c;
                cin >> c;
                row.push_back(c);
            }
            mat.push_back(row);
        }

        //print(mat, M, N);

        cout << "Case #" << (t + 1) << ": " \
            << get_len(mat, M, N) << endl;

    }
    return 0;
}