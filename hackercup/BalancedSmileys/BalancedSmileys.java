import java.util.ArrayDeque;
import java.util.Scanner;

public class BalancedSmileys {

    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());
        for (int i=1; i<n+1; ++i) {
            System.out.println("Case #" + i + ": " +
                (isBalanced(input.nextLine(), new ArrayDeque<Character>())?"YES":"NO"));
        }
        input.close();
    }

    static boolean isBalanced(String s, ArrayDeque<Character> stack) {
        for ( int i = 0; i < s.length(); i++ ) {
            if (s.charAt(i)==':') {
                if (i+1 >= s.length()) {
                    continue;
                }
                if (s.charAt(i+1)=='(' || s.charAt(i+1)==')') {
                    return isBalanced(s.substring(i+1), stack.clone()) ||
                            isBalanced(s.substring(i+2), stack.clone());
                }
            }
            if (s.charAt(i)=='(') {
                stack.push('(');
                continue;
            }
            if (s.charAt(i)==')') {
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop();
                    continue;
                } else {
                    return false;
                }
            }

        }

        return stack.isEmpty();
    }

}