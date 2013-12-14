#include <iostream>
#include <algorithm>
#include <string>



using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int N, K, C;
        cin >> N >> K >> C;


        int each = K / N;
        int rest = N - (K - each * N);

        int res = 2147483647;

        if(C <= each * N) {
            res = C;
        } else {
            int mm = each + 1;
            while(mm <= K) {
                res = min(res, N - K / mm + C);
                mm++;
            }
        }

        cout << "Case #" << (t + 1) << ": " << res << endl;

    }
    return 0;
}