#include <iostream>
#include <algorithm>
#include <string>



using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        string s;
        long long N;
        cin >> s >> N;

        string str;
        int n = s.size();
        if(n == 0) {
            ;
        } else if(n == 1) {
            for(long long i = 0; i < N; i++) {
                str.push_back(s[0]);
            }
        } else {

            while(N>0) {
                if(N%n==0) {
                    str.push_back(s[n-1]);
                    N=N/n-1;
                } else {
                    str.push_back(s[N%n-1]);
                    N=N/n;
                }

            }
            reverse(str.begin(), str.end());
        }

        cout << "Case #" << (t + 1) << ": " << str << endl;


    }
    return 0;
}