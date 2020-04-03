import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_d4_9659_다항식계산 {
	static class Info {
		int t, a, b;
		public Info(int t, int a, int b) {
			this.t = t;
			this.a = a;
			this.b = b;
		}
	}
	static final long MOD = 998244353l;
	static int n, m, x;
	static long dp[];
	static List<Info> li[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for (int tc = 1; tc <= test; tc++) {
			n = Integer.parseInt(br.readLine().trim());
			dp = new long[n + 1];
			dp[0] = 1;
			li = new List[n + 1];
			for (int i = 2; i <= n; i++)
				li[i] = new ArrayList<>();

			for (int i = 2; i <= n; i++) {
				String s = br.readLine();
				StringTokenizer st = new StringTokenizer(s);
				int t = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				li[i].add(new Info(t, a, b));
			}
			m = Integer.parseInt(br.readLine().trim());
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);

			System.out.print("#" + tc + " ");
			for (int i = 0; i < m; i++) {
				x = Integer.parseInt(st2.nextToken());
				dp[1] = x;
				for(int j=2;j<=n;j++) {
					int t = li[j].get(0).t;
					int a = li[j].get(0).a;
					int b = li[j].get(0).b;
					if(t==1) dp[j] = (dp[a]+dp[b])%MOD;
					else if(t==2) dp[j]= (a*dp[b])%MOD;
					else if(t==3) dp[j] = (dp[a]*dp[b])%MOD;
				}
				System.out.print(dp[n]+" ");
			}
			System.out.println();
		}
	}
}