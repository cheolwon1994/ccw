import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d3_2814_최장경로 {
	static int node,edge,result;
	static int arr[][];
	static boolean check[];
	
	static void dfs(int idx, int cnt) {
		result = Math.max(result, cnt);
		for(int i=1;i<=node;i++) {
			if(!check[i] && arr[idx][i]==1) {
				check[i]=true;
				dfs(i,cnt+1);
				check[i]=false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			node = Integer.parseInt(st.nextToken());
			edge = Integer.parseInt(st.nextToken());
			//초기화
			result=1;
			arr = new int[node+1][node+1];
					
			for(int i=0;i<edge;i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				int start = Integer.parseInt(st2.nextToken());
				int end = Integer.parseInt(st2.nextToken());
				arr[start][end]=1;
				arr[end][start]=1;
			}
			for(int i=1;i<=node;i++) {
				check = new boolean[node+1];
				check[i]=true;
				dfs(i,1);
			}
			System.out.println("#"+t+" "+result);
		}
	}
}