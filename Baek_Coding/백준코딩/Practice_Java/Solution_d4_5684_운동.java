import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Solution_d4_5684_운동 {
	static class Info implements Comparable<Info>{
		int idx,val;
		public Info(int idx, int val) {		
			this.idx = idx;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {		
			return Integer.compare(this.val, o.val);
		}			
	}
	static Queue<Info> q;
	static int node,edge;
	static List<Info> li[];
	static int dist[];
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for(int t=1;t<=test;t++) {
			node = sc.nextInt();
			edge = sc.nextInt();
			//초기화
			li = new ArrayList[node+1];
			for(int i=1;i<=node;i++)
				li[i] = new ArrayList<>();
			for(int i=0;i<edge;i++) {
				int start = sc.nextInt();
				int end = sc.nextInt();
				int val = sc.nextInt();
				li[start].add(new Info(end,val));
			}
			int result = Integer.MAX_VALUE;
			for(int i=1;i<=node;i++) {
				dist=new int[node+1];
				q = new LinkedList<Info>();
				for(int j=1;j<=node;j++)
					dist[j]=Integer.MAX_VALUE;
				q.add(new Info(i,0));
				Info ii;
				while(!q.isEmpty()) {
					ii = q.poll();
					int cidx = ii.idx;
					int cv = ii.val;
					if(cv>result) continue;
					for(int j=0;j<li[cidx].size();j++) {
						int next = li[cidx].get(j).idx;
						int nv = li[cidx].get(j).val;
						if(dist[next]> cv + nv) {
							dist[next]=cv+nv;
							q.add(new Info(next,dist[next]));
						}
					}
				}
				result = Math.min(dist[i], result);				
			}
			if(result==Integer.MAX_VALUE) result=-1;
			System.out.println("#"+t+" "+result);
		}
	}
}