import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution_d6_1263_사람네트워크2 {
	static class Info implements Comparable<Info>{
		int idx,val;
		public Info(int idx,int val) {
			this.idx=idx;
			this.val=val;
		}
		@Override
		public int compareTo(Info o) {
			return Integer.compare(this.val, o.val);
		}
	}
	static int arr[][];
	static int dist[];
	static boolean visit[];
	static List<Info> li[];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int num = Integer.parseInt(st.nextToken());
			int result = Integer.MAX_VALUE;
			//초기화
			//arr = new int[num][num];
			li = new List[num];
			for(int i=0;i<num;i++)
				li[i]=new ArrayList<>();
			
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					int val =Integer.parseInt(st.nextToken());
					//arr[i][j]=val;
					if(val==1)
						li[i].add(new Info(j,1));
				}
			}
			
			for(int i=0;i<num;i++) {
				dist = new int[num];
				for(int j=0;j<num;j++)
					dist[j]=Integer.MAX_VALUE;
				visit = new boolean[num];
				dist[i]=0;
				PriorityQueue<Info> pq = new PriorityQueue<>();
				pq.offer(new Info(i,0));
				Info ii;
				
				while(!pq.isEmpty()) {
					ii = pq.poll();
					int cidx = ii.idx;
					int cv = ii.val;
					if(visit[cidx]) continue;
					visit[cidx]=true;
					for(int j=0;j<li[cidx].size();j++) {
						int next = li[cidx].get(j).idx;
						int nv = li[cidx].get(j).val;
						if(dist[next]>cv+nv) {
							dist[next]=cv+nv;
							pq.offer(new Info(next,nv+cv));
						}
					}
				}
				int cnt=0;
				for(int j=0;j<num;j++)
					cnt+=dist[j];
				result = Math.min(result, cnt);
			}
			System.out.println("#"+t+" "+result);
		}
	}
}