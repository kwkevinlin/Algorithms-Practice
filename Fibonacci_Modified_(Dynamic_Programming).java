import java.io.*;
import java.util.*;
import java.math.BigInteger;

/* Fibonacci Modified

    Given the nth and (n+1)th terms, the (n+2)th can be computed by the following relation: 
    T(n+2) = (T(n+1))^2 + T(n)

    Adapted from HackerRank:
        Fibonacci Modified
        https://www.hackerrank.com/challenges/fibonacci-modified

*/

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        int fib0, fib1, findThis;
        
        Scanner reader = new Scanner(System.in);
        fib0 = reader.nextInt();
        fib1 = reader.nextInt();
        findThis = reader.nextInt();
        
        BigInteger[] fib = new BigInteger[findThis];
        fib[0] = BigInteger.valueOf(fib0);
        fib[1] = BigInteger.valueOf(fib1);
        
        for (int i = 2; i < findThis; i++) {
            BigInteger tmp = fib[i-1].pow(2);
            fib[i] = tmp.add(fib[i-2]);
        }
        
       System.out.println(fib[findThis-1]);
  
    }
}