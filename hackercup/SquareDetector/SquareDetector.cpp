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
        int N;
        cin >> N;
        vector<vector<char> > mat(N, vector<char>(N));
        int num=0;
        int minx=N, miny=N;
        int maxx=0, maxy=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                char c;
                cin >> c;
                mat[i][j]=c;
                if(c=='#') {
                    num++;
                    if(i<=minx && j<=miny) {
                        minx=i;
                        miny=j;
                    }
                    if(i>=maxx && j>=maxy) {
                        maxx=i;
                        maxy=j;
                    }
                }
            }
        }
        //printf("(%d,%d) (%d,%d)\n", minx, miny, maxx, maxy);
        int area=(maxx-minx+1)*(maxy-miny+1);

        bool flag=true;
        if(area!=num || maxx-minx != maxy-miny) {
            flag = false;
        } else {
            for(int i=minx; i<=maxx; i++) {
                for(int j=miny; j<=maxy; j++) {
                    if(mat[i][j]!='#'){
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
        }
        if(flag){
            cout << "Case #" << (t + 1) << ": YES" << endl;
        } else {
            cout << "Case #" << (t + 1) << ": NO" << endl;
        }



    }
    return 0;
}
