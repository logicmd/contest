#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        int N;
        cin >> N;
        string str=to_string(N);
        int min_i, max_i;
        char min_=10+'0', max_=-1+'0';

        for(int j=0; j<str.size(); j++) {
            if(str[j]<min_ && str[j]!='0') {
                min_=str[j];
                min_i=j;
            }
            if(str[j]>max_) {
                max_=str[j];
                max_i=j;
            }
        }

        string min_out=str;
        if(min_<10+'0')
            swap(min_out[0],min_out[min_i]);
        string max_out=str;
        swap(max_out[0],max_out[max_i]);
        cout << "Case #" << i << ": " << min_out << " " << max_out << endl;
    }
    return 0;
}
