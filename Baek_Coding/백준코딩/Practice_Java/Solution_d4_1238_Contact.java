import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_d4_1238_Contact {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean connect[][];
		int visit[];
		Queue<Integer> q = new LinkedList<>();
		for (int t = 1; t <= 10; t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int num = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			connect = new boolean[num + 1][num + 1];
			visit = new int[num + 1];
			int from, to;
			String str2 = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str2);
			while (st2.hasMoreTokens()) {
				from = Integer.parseInt(st2.nextToken());
				to = Integer.parseInt(st2.nextToken());
				connect[from][to] = true;
			}
			q.add(start);
			visit[start] = -1;
			int cnt = 1;
			while (!q.isEmpty()) {
				int len = q.size();
				for (int i = 0; i < len; i++) {
					int cidx = q.poll();
					for(int j=1;j<=num;j++) {
						if(connect[cidx][j] && visit[j]==0) {
							visit[j]=cnt;
							q.add(j);
						}
					}
				}
				if(!q.isEmpty())
					cnt++;
			}
			int maxi=-1;
			for(int i=num;i>0;i--) {
				if(visit[i]==cnt-1) {
					maxi=i;
					break;
				}
			}
			System.out.println("#"+t+" "+maxi);
		}
	}
}
