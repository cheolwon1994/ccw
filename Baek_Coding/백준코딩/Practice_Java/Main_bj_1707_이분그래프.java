import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static class Info {
		int idx, color;

		public Info(int idx, int color) {
			this.idx = idx;
			this.color = color;
		}
	}

	static int node, edge, v[];
	static List<Integer> li[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 0; t < test; t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			node = Integer.parseInt(st.nextToken());
			edge = Integer.parseInt(st.nextToken());

			// ÃÊ±âÈ­
			v = new int[node + 1];
			li = new List[node + 1];
			for (int i = 1; i <= node; i++)
				li[i] = new ArrayList<Integer>();

			for (int i = 0; i < edge; i++) {
				str = br.readLine();
				st = new StringTokenizer(str);
				int s = Integer.parseInt(st.nextToken());
				int e = Integer.parseInt(st.nextToken());
				li[s].add(e);
				li[e].add(s);
			}
			boolean avail = true;
			for (int k = 1; k <= node; k++) {
				if(v[k]!=0) continue;
				Queue<Info> q = new LinkedList<>();
				q.offer(new Info(k, -1));
				v[k] = -1;
				Info ii;

				while (!q.isEmpty()) {
					ii = q.poll();
					int cidx = ii.idx;
					int cc = ii.color;
					for (int i = 0; i < li[cidx].size(); i++) {
						int next = li[cidx].get(i);
						if (v[next] == cc) {
							avail = false;
							break;
						} else if (v[next] == 0) {
							v[next] = -cc;
							q.offer(new Info(next, -cc));
						}
					}
				}
				if(!avail) break;
			}
			System.out.println(avail == true ? "YES" : "NO");
		}
	}
}