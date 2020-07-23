import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int conn[];
	static List<Integer> li[], ans;
	static boolean visit[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		// √ ±‚»≠
		conn = new int[n + 1];
		visit = new boolean[n + 1];
		ans = new ArrayList<>();
		li = new List[n + 1];
		for (int i = 1; i <= n; i++)
			li[i] = new ArrayList<>();

		for (int i = 0; i < m; i++) {
			s = br.readLine();
			st = new StringTokenizer(s);
			int len = Integer.parseInt(st.nextToken());
			int pre = -1, val, post;
			for (int j = 0; j < len; j++) {
				val = Integer.parseInt(st.nextToken());
				if (pre == -1) {
					pre = val;
					continue;
				} else
					post = val;
				li[pre].add(post);
				conn[post]++;
				pre = post;
			}
		}

		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i <= n; i++)
			if (conn[i] == 0)
				q.offer(i);		
		
		boolean finish = true;
		while (!q.isEmpty()) {
			int idx = q.poll();
			visit[idx]=true;
			ans.add(idx);
			for(int i=0;i<li[idx].size();i++) {
				int next = li[idx].get(i);
				if(visit[next]) continue;
				conn[next]--;
				if(conn[next]==0) 
					q.offer(next);				
			}
		}
		for(int i=1;i<=n;i++)
			if(!visit[i])
				finish=false;
		if(!finish)		System.out.println("0");
		else {
			for(Integer i : ans)
				System.out.println(i);
		}
	}
}