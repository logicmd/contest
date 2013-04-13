// WTF
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long nChoosek( long n, long k );
long long a[10010];

int main() {
  int n; cin >> n;
    for(int t = 0; t < n; t++) {
        int N, K; cin >> N >> K;
        set<long long> st;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            st.insert(a[i] % 1000000007);
        }
        int c = 0;
        long long sum = 0;
        for (set<long long>::iterator it = st.begin(); it != st.end(); ++it)
        {
            c++;
            if (c>=K)
            {
                sum += ((long long) nChoosek(c-1,K-1)) * (*it);
                sum %= 1000000007;
            }
        }
        sum %= 1000000007;


        cout << "Case #" << (t + 1) << ": " << sum << endl;
    }
    return 0;
}

long long nChoosek( long n, long k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
        result %= 1000000007;
    }
    return result %= 1000000007;
}