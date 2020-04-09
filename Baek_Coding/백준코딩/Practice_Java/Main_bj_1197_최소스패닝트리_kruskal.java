import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main_bj_1197_최소스패닝트리_kruskal {
	static class Info implements Comparable<Info>{
		int start,target;
		long val;
		public Info(int start,int target, long val) {
			this.start = start;
			this.target = target;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {		
			return Long.compare(this.val, o.val);
		}
	}
	
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
	
	static int root[];
	static List<Info> li;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		int node = Integer.parseInt(st.nextToken());
		int edge = Integer.parseInt(st.nextToken());
		boolean visit[] = new boolean[node+1];
		
		li = new ArrayList<Info>();		
		root = new int[node + 1];
		for (int i = 1; i <= node; i++)
			root[i] = i;
		
		for(int i=0;i<edge;i++) {
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);
			int start = Integer.parseInt(st2.nextToken());
			int target = Integer.parseInt(st2.nextToken());
			long val = Integer.parseInt(st2.nextToken());
			li.add(new Info(start,target,val));
		}
		Collections.sort(li);
		int cnt = 0;
		long result = 0;
		while (cnt < li.size()) {
			int start = li.get(cnt).start;
			int end = li.get(cnt).target;
			int res = find(start,end);
			if (res==1) { 
				cnt++;
				continue;
			}
			make_union(start,end);
			result += li.get(cnt).val;
			cnt++;
		}
		System.out.println(result);
	}
}