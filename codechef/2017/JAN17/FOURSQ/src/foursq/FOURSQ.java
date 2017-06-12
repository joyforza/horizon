package foursq;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;

public class FOURSQ {
    
    public static BigInteger[] T;
    public static int a[] = new int[100001];
    public static int n, m, P;
    public static int tr[] = new int[1000001];
    public static int tr2[] = new int[1000001];
    public static Vector<Integer> tmp = new Vector<Integer>();
    
    public static boolean IsSquare(int x) {
        int d = (int) Math.sqrt(x);
        return (d * d == x);
    }
    
    public static void split(int x) {
        int d1 = tr2[x];
        int d2 = x - d1;
        
        int a = (int)Math.sqrt(tr[d1]);
        int b = (int)Math.sqrt(d1 - tr[d1]);
        int c = (int)Math.sqrt(tr[d2]);
        int d = (int)Math.sqrt(d2 - tr[d2]);
        
        System.out.println(a + " " + b + " " + c + " " + d);
    }
    
    public static void init(int node, int l, int r) {
        if (l == r) {
            T[node] = BigInteger.valueOf(a[l] % P);
            return;
        }
        int mid = (l + r) >> 1;
        init(node * 2, l, mid);
        init(node * 2 + 1, mid + 1, r);
        T[node] = T[node * 2].multiply(T[node * 2 + 1]).mod(BigInteger.valueOf(P));
    }
    
    public static void change(int node, int l, int r, int pos, int val) {
        if (l > pos || r < pos) return;
        if (l == r) {
            T[node] = BigInteger.valueOf(val % P);
            a[pos] = val % P;
            return;
        }
        int mid = (l + r) >> 1;
        change(node * 2, l, mid, pos, val);
        change(node * 2 + 1, mid + 1, r, pos, val);
        T[node] = T[node * 2].multiply(T[node * 2 + 1]).mod(BigInteger.valueOf(P));
    }
    
    public static BigInteger get(int node, int l, int r, int u, int v) {
        if (l > v || r < u) return BigInteger.ONE;
        if (l >= u && r <= v) {
            return T[node];
        }
        int mid = (l + r) >> 1;
        return get(node * 2, l, mid, u, v).multiply(get(node * 2 + 1, mid + 1, r, u, v)).mod(BigInteger.valueOf(P));
    }
    
    public static void main(String[] args) {
        tr[0] = 0;
        Arrays.fill(tr, -1);
        Arrays.fill(tr2, -1);
        for (int i = 1; i <= 1000000; i++)
            if (IsSquare(i)) {
                for (int j = 0; j <= Math.sqrt(1000000 - i); j++)
                    tr[i + j * j] = i;
            }
            
        for (int i = 0; i <= 1000000; i++)
            if (tr[i] != -1) tmp.add(i);
        
        for (int i = 1; i <= 1000000; i++) {
            for (int j = 0; j < tmp.size(); j++) {
                if (i - tmp.get(j) < 0) break;
                if (tr[i - tmp.get(j)] != -1) {
                    tr2[i] = i - tmp.get(j);
                    break;
                }
            }
        }
        
        //split(6);
        
        Scanner sc = new Scanner(System.in);
        int nt = sc.nextInt();
        do {
            n = sc.nextInt();
            m = sc.nextInt();
            P = sc.nextInt();
             
            T = new BigInteger[4 * n + 1];
            
            for (int i = 1; i <= n; i++)
                a[i] = sc.nextInt();
            
            init(1, 1, n);
            
            for (int i = 1; i <= m; i++) {
                int tp = sc.nextInt();
                int u = sc.nextInt();
                int v = sc.nextInt();
                if (tp == 1) {
                    change(1, 1, n, u, v);
                }
                else {
                    int ret = Integer.parseInt(get(1, 1, n, u, v).toString());
                   
                    split(ret);
                }
            }
            nt--;
        }
        while (nt > 0);
    }
    
}
