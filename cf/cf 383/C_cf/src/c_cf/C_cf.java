package c_cf;

import java.math.BigInteger;
import java.util.Scanner;

public class C_cf {

    
    public static int n;
    public static int a[] = new int[100100];
    public static boolean f[] = new boolean[100100];
    public static int id[] = new int[100100];
    public static int sum[] = new int[100100];
    
    public static BigInteger LCM( BigInteger a , BigInteger b ) {
        BigInteger c = a.gcd( b ) ;
        return a.multiply( b.divide( c ) ) ; 
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) a[i] = sc.nextInt();

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        if (f[i] == false) {

            cnt++;
            f[i] = true;

            int sv = i;
            int cur = i;
            id[i] = cnt;
            
        int dem = 1;
        while (true) {
            cur = a[cur];

            if (f[cur]) {
                if (cur != sv) {
                    System.out.println("-1");
                    System.exit(0);
                }
                sum[cnt] = dem;
                break;
            }
            f[cur] = true;
            id[cur] = cnt;
            dem++;
        }
    }

    BigInteger ret = BigInteger.ONE;
    for (int i = 1; i <= n; i++) {
            int val = sum[id[i]];
            if (val % 2 == 0) val /= 2;
            ret = LCM(ret, BigInteger.valueOf(val));
    }

        System.out.println(ret);
    }
    
}
