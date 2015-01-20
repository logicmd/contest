#include <iostream>
#include <vector>

using namespace std;

bool dfs(int Cp, int Cc, int Cf, int k, int N, vector<int> &P, vector<int> &C, vector<int> &F, int Gp, int Gc, int Gf) {
    if(Cp==Gp && Cc==Gc && Cf==Gf)
        return true;
    if(Cp>Gp || Cc>Gc || Cf>Gf)
        return false;
    if(k==N)
        return false;
    Cp+=P[k];
    Cc+=C[k];
    Cf+=F[k];
    if(dfs(Cp, Cc, Cf, k+1, N, P, C, F, Gp, Gc, Gf))
        return true;

    Cp-=P[k];
    Cc-=C[k];
    Cf-=F[k];
    if(dfs(Cp, Cc, Cf, k+1, N, P, C, F, Gp, Gc, Gf))
        return true;

    return false;
}

int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        int Gp, Gc, Gf;
        cin >> Gp >> Gc >> Gf;
        int N;
        cin >> N;
        vector<int> P, C, F;
        for(int j=0; j<N; j++) {
            int p, c, f;
            cin >> p >> c >> f;
            P.push_back(p);
            C.push_back(c);
            F.push_back(f);
        }
        cout << "Case #" << i <<": ";
        if(dfs(0, 0, 0, 0, N, P, C, F, Gp, Gc, Gf))
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
    return 0;
}
