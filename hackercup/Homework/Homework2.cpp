#include <iostream>
#include <cmath>
#include <vector>

#define MAX_PRIME 10000000
#define MAX_PRIME_SQUARE 3163

using namespace std;

void generate_prime(vector<int> &prime){
    int i, j, k;
    vector<int> p(MAX_PRIME, 0);

    prime.push_back(2);
    int prime_num = 1;

    for(i=3; i<MAX_PRIME_SQUARE; i+=2){
        if(p[i] == 1)
            continue;
        k = 2*i;
        for(j=i*i; j<MAX_PRIME; j+=k){
            p[j] = 1;
        }
    }

    for(i=3; i<MAX_PRIME; i+=2){
        if(p[i] == 0)
            prime.push_back(i);
    }
}

int main() {
    vector<int> prime;
    generate_prime(prime);
    //cout << "size: " << prime.size() << endl;
    int T;
    cin >> T;
    vector<int> all;
    all.push_back(0);
    for(int i=1; i<=10000000; i++) {
        int k=0;
        int cur=i;
        for(int j=0; j<prime.size(); j++) {
            int p=prime[j];
            if(cur%p==0) {
                while(cur%p==0) {
                    cur/=p;
                }
                k++;
            }
            if(cur==1)
                break;
        }
        all.push_back(k);
    }
    for(int t=1; t<=T; t++) {
        int A, B, K, res=0;
        cin >> A >> B >> K;
        for(int i=A; i<=B; i++) {
            int k=all[i];
            if(k==K)
                res++;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
