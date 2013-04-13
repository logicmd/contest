import java.util.Arrays;
import java.util.Scanner;
public class BeautifulString {

    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());
        for (int i=1; i<n+1; ++i) {
            System.out.println("Case #" + i + ": " + get(input.nextLine()));
        }
        input.close();
    }

    static int get(String s) {
        int[] a = new int[26];
        for (int i=0; i<s.length(); ++i) {
            if (s.charAt(i)<='Z' && s.charAt(i)>='A' ) {
                a[s.charAt(i)-'A']++;
            } else if(s.charAt(i)<='z' && s.charAt(i)>='a' ) {
                a[s.charAt(i)-'a']++;
            }
        }

        Arrays.sort(a);
        int sum = 0;
        int i=0;
        for (int aa:a) {
            sum += aa*++i;
        }
        return sum;

    }

}