#include <iostream>
#include <string>
#include <algorithm>
#define MAX 26

using namespace std;

class Tries {
private:
    class TriesNode {
    public:
        int v;
        TriesNode *next[MAX];
        TriesNode() {
            v=1;
            for(int i=0; i<MAX; i++) {
                next[i]=NULL;
            }
        }
    };
    TriesNode *root;
    //TriesNode *cur;
public:
    Tries() {
        root=new TriesNode();
        root->v=-1;
    }
    int insert(string &s) {
        TriesNode *cur = root;
        int match=0;
        for(char c:s) {
            int i=c-'a';
            if(cur->next[i]==NULL) {
                TriesNode *n=new TriesNode();
                n->v=1;
                cur->next[i]=n;
            } else {
                cur->next[i]->v++;
                match++;
            }
            cur=cur->next[i];   
        }
        cur->v=-1;
        if(match+1<s.size())    return match+1;
        return s.size();
    }
};




int main() {
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        int N;
        cin >> N;
        int res=0;
        Tries *tries=new Tries();
        for(int i=0; i<N; i++) {
            string s;
            cin >> s;
            int r=tries->insert(s);
            res+=r;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
