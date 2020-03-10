import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution_d4_1251_하나로_Prim {
	static class Info implements Comparable<Info> {
		int idx;
		double val;
		public Info(int idx, double val) {
			this.idx = idx;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {
			return Double.compare(this.val, o.val);
		}
	}

	static boolean flag[];
	static double x[], y[];
	static double mul;
	static List<Info> li[];

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			int num = Integer.parseInt(br.readLine().trim());
			// 초기화
			flag = new boolean[num + 1];
			x = new double[num + 1];
			y = new double[num + 1];
			li = new List[num + 1];
			for(int i=1;i<=num;i++)
				li[i] = new ArrayList<>();

			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			double vv;
			for (int i = 1; i <= num; i++) {
				vv = Double.valueOf(st.nextToken());
				x[i] = vv;
			}
			s = br.readLine();
			st = new StringTokenizer(s);
			for (int i = 1; i <= num; i++) {
				vv = Double.valueOf(st.nextToken());
				y[i] = vv;
			}
			mul = Double.parseDouble(br.readLine().trim());
			double start_x, start_y, end_x, end_y, dx, dy;
			for (int i = 1; i < num; i++) {
				start_x = x[i];
				start_y = y[i];
				for (int j = i + 1; j <= num; j++) {
					end_x = x[j];
					end_y = y[j];
					dx = (start_x - end_x) * (start_x - end_x);
					dy = (start_y - end_y) * (start_y - end_y);
					li[i].add(new Info(j, dx + dy));
					li[j].add(new Info(i, dx + dy));
				}
			}
			List<Info> temp;
			double result = 0;
			PriorityQueue<Info> pq = new PriorityQueue<>();
			Deque<Integer> dq = new ArrayDeque<>();
			dq.add(1);
			Info ii;
			while(!dq.isEmpty()) {
				int curNode =dq.poll();
				flag[curNode]=true;
				temp=li[curNode];
				for(int i=0;i<temp.size();i++) {
					int next = temp.get(i).idx;
					if(!flag[next]) {
						pq.add(new Info(next,temp.get(i).val));
					}
				}
				while(!pq.isEmpty()) {
					ii=pq.poll();
					if(!flag[ii.idx]) {
						flag[ii.idx]=true;
						dq.add(ii.idx);
						result+=ii.val;
						break;
					}
				}
				
			}
			System.out.println("#" + t + " " + Math.round(mul * result));
		}
	}
}