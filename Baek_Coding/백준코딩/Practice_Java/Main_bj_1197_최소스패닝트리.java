import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_bj_1197_최소스패닝트리 {
	static class Info implements Comparable<Info>{
		int idx;
		long val;
		public Info(int idx, long val) {
			this.idx = idx;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {		
			return Long.compare(this.val, o.val);
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		int node = Integer.parseInt(st.nextToken());
		int edge = Integer.parseInt(st.nextToken());
		boolean visit[] = new boolean[node+1];
		List<Info> li[];
		li = new List[node+1];
		for(int i=1;i<=node;i++)
			li[i] = new ArrayList<>();
		
		for(int i=0;i<edge;i++) {
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);
			int start = Integer.parseInt(st2.nextToken());
			int target = Integer.parseInt(st2.nextToken());
			long val = Integer.parseInt(st2.nextToken());
			li[start].add(new Info(target,val));
			li[target].add(new Info(start,val));
		}
		long result=0;
		PriorityQueue<Info> pq = new PriorityQueue<>();
		Deque<Integer> dq = new ArrayDeque<>(); 
		dq.offer(1);
		while(!dq.isEmpty()) {
			int cidx = dq.poll();
			visit[cidx]=true;
			for(int i=0;i<li[cidx].size();i++) {
				int next = li[cidx].get(i).idx;
				long nv = li[cidx].get(i).val;
				if(!visit[next]) {
					pq.offer(new Info(next,nv));
				}
			}
			while(!pq.isEmpty()) {
				int next = pq.peek().idx;
				long nv = pq.peek().val;
				pq.poll();
				if(!visit[next]) {
					visit[next]=true;
					dq.add(next);
					result+=nv;
					break;
				}
			}		
		}
		System.out.println(result);
	}
}