import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_bj_2252_줄세우기 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer st = new StringTokenizer(s);
		int node = Integer.parseInt(st.nextToken());
		int edge = Integer.parseInt(st.nextToken());
		List<Integer> li[] = new List[node+1];
		int conn[] = new int[node+1];
		for(int i=1;i<=node;i++)
			li[i] = new ArrayList<Integer>();
		
		for(int i=0;i<edge;i++) {
			s = br.readLine();
			st = new StringTokenizer(s);
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			li[start].add(end);
			conn[end]++;
		}
		Queue<Integer> q = new LinkedList<Integer>();
		for(int i=1;i<=node;i++) {
			if(conn[i]==0) {
				q.offer(i);
			}
		}
		while(!q.isEmpty()) {
			int cidx= q.poll();
			System.out.print(cidx+" ");
			for(int i=0;i<li[cidx].size();i++) {
				int next = li[cidx].get(i);
				conn[next]--;
				if(conn[next]==0) {
					q.offer(next);
				}
			}
		}
	}
}