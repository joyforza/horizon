
package proc;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;

public class ProC {

    public static class Pair {
		public int fi, se;
		public Pair(int fi, int se) {
			this.fi = fi; this.se = se;
		}
	}
	
	public static int n, cnt, del;
	public static long sum[] = new long[1000010];
	public static boolean f[] = new boolean[1000010];
	public static int w[] = new int[1000010];
	public static Vector<Vector<Integer>> a = new Vector<Vector<Integer>>();
	public static int hv[] = new int[1000010]; // is have?
	public static Vector<Pair> ed = new Vector<Pair>();
	public static long tot;
	public static int fi = -1, se = -1;
	public static int vt;
	
	public static int map[] = new int[1000010];
	
	public static void dfs(int u) {
		f[u] = true;
		sum[u] = w[u];
               // System.out.println("dfs at " + u);
		for (int i = 0; i < a.get(u).size(); i++) {
			int ide = a.get(u).get(i);
			int v = (ed.get(ide).fi != u ? ed.get(ide).fi : ed.get(ide).se);
			if (f[v] == false) {
				dfs(v);
				sum[u] += sum[v];
				if (sum[v] == tot) {
					if (fi == -1) {
						fi = ide;
                                                vt = v;
                                        }
					else
                                            if (se == -1)
						se = ide;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		
		for (int i = 1; i <= n + 1; i++)
			a.add(new Vector());
		
		int root = 1;
		for (int i = 1; i <= n; i++) {
			int u = sc.nextInt();
			int c = sc.nextInt();
			if (u > 0) {
				ed.add(new Pair(i, u));
				a.get(i).add(ed.size() - 1);
				a.get(u).add(ed.size() - 1);
				map[ed.size() - 1] = i;
			}
			else 
				root = i;
			w[i] = c; 
			tot += c;
		}
		if (tot % 3 != 0) {
			System.out.println(-1);
			System.exit(0);
		}	
		tot /= 3;
		dfs(root);
                
		if (fi == -1) {
			System.out.println(-1);
			System.exit(0);
		}
		Arrays.fill(f, false);
		Arrays.fill(sum, 0);
		f[vt] = true;


                dfs(root);
                
		if (se == -1) {
			System.out.println(-1);
			System.exit(0);
		}
                
		System.out.println(map[fi] + " " + map[se]);
		
	}
    
}
