import java.util.HashMap;
import java.util.Scanner;

public class FindtheMin {

    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        for (int i=1; i<N+1; ++i) {
            int n = input.nextInt();
            int k = input.nextInt();
            int a = input.nextInt();
            int b = input.nextInt();
            int c = input.nextInt();
            int r = input.nextInt();

            System.out.println("Case #" + i + ": " + get(n,k,a,b,c,r));
        }
        input.close();
    }

    static int get(int n, int k, int a, int b, int c, int r) {
        long[] m = new long[n];
        HashMap<Long, Character> bflag = new HashMap<Long, Character>();
        //char[] bflag = new char[r];
        m[0] = a;
        //System.out.println(m[0]);
        int extra = -1;
        if (a<r && a>=0) {
            bflag.put(m[0],(char)1);
        } else {
            extra=a;
        }

        for (int i=1; i<r; ++i) {
            if (i<k) {
                m[i] = (b * m[i - 1] + c) % r;
                incr(bflag, m[i]);
            } else {
                if (i!=k) {
                    decr(bflag, m[i]);
                }
                for (long j=0; j<r; ++j) {
                    if (!bflag.containsKey(j) || bflag.get(j)==0) {
                        m[i] = j;
                        incr(bflag, j);
                        break;
                    }
                }
            }
            //System.out.println(m[i]);
        }

        return (int)m[r-1];
    }

    static void incr(HashMap<Long, Character> bflag, long k) {
        if (bflag.containsKey(k)) {
            bflag.put(k, (char)(bflag.get(k)+1));
        } else {
            bflag.put(k, (char)1);
        }
    }

    static void decr(HashMap<Long, Character> bflag, long k) {
        if (bflag.containsKey(k) && bflag.get(k)>0) {
            bflag.put(k, (char)(bflag.get(k)-1));
        } else {
            bflag.put(k, (char)0);
        }
    }

}