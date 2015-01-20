#include <iostream>

using namespace std;

void dfsfree(int a, int b, int ca, int cb, int &res) {
    if(a==ca && b==cb) {
        res++;
        return;
    }
    if(a>ca) {
        dfsfree(a, b, ca+1, cb, res);
    }
    if(b>cb && ca>cb+1) {
        dfsfree(a, b, ca, cb+1, res);
    }
}


void dfsful(int a, int b, int ca, int cb, int &res) {
    if(a==ca && b==cb) {
        res++;
        return;
    }
    if((a>ca && ca<cb) || b==cb){
        dfsful(a, b, ca+1, cb, res);
    }
    if(b>cb) {
        dfsful(a, b, ca, cb+1, res);
    }
}

int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int a, b;
        char minus;
        cin >> a >> minus >> b;
        if(minus=='-' && a>b) {
            int stressfree=0;
            dfsfree(a, b, 1, 0, stressfree);
            int stressful=0;
            dfsful(a, b, 0, 1, stressful);
            cout << "Case #" << t << ": " << stressfree << " " << stressful << endl;
        }
    }
    return 0;
}
