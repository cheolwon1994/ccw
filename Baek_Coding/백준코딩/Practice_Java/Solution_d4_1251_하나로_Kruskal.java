import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_d4_1251_하나로_Kruskal {
	static class Info implements Comparable<Info> {
		int start, end;
		double val;

		public Info(int start, int end, double val) {
			this.start = start;
			this.end = end;
			this.val = val;
		}

		@Override
		public int compareTo(Info o) {
			return Double.compare(this.val, o.val);
		}
	}

	static int root[];
	static double x[], y[];
	static double mul;
	static List<Info> li;

	public static int parent(int idx) {
		if (root[idx] == idx)
			return idx;
		return root[idx] = parent(root[idx]);
	}

	public static void make_union(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(a<b) root[b]=a;
		else root[a]=b;
	}

	public static int find(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(a==b) return 1;
		else return 0;
	}
	
	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			int num = Integer.parseInt(br.readLine().trim());
			// 초기화
			x = new double[num + 1];
			y = new double[num + 1];
			li = new ArrayList<Info>();
			root = new int[num + 1];

			for (int i = 1; i <= num; i++)
				root[i] = i;

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
					li.add(new Info(i, j, dx + dy));
				}
			}
			Collections.sort(li);
			int cnt = 0;
			long result = 0;
			while (cnt < li.size()) {
				int start = li.get(cnt).start;
				int end = li.get(cnt).end;
				int res = find(start,end);
				if (res==1) { // 사이클 형성
					cnt++;
					continue;
				}
				make_union(start,end);
				result += li.get(cnt).val;
				cnt++;
			}
			System.out.println("#" + t + " " + Math.round(mul*result));
		}
	}
}