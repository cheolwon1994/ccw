import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_5987_달리기 {
	static int node,edge;
	static long dp[],li[];		//16자리를 2진수로 바꿔서 생각 최대 2^17, 해당 선수가 들어오려면 어떤 선수들이 선두로 들어와 있어햐는지
	
	static long dfs(int idx) {		// 지금까지 누가 들어왓는지
		if(idx==(1<<(node+1))-2) return 1;
		if(dp[idx]!=0) return dp[idx];
		
		for(int i=1;i<=node;i++) {
			if((idx & 1<<i)>0)		//이미 해당 선수가 들어온 경우
				continue;
			if((idx & li[i])!=li[i]) continue;		//선두로 나와야하는 선수들이 아직 다 나오지 않은 경우
			dp[idx]+=dfs(idx|1<<i);
		}
		return dp[idx];
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			node = Integer.parseInt(st.nextToken());
			edge = Integer.parseInt(st.nextToken());
			//초기화
			li = new long[node+1];
			dp = new long[1<<(node+1)];
			
			int start,end;
			for(int i=0;i<edge;i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				start = Integer.parseInt(st2.nextToken());
				end = Integer.parseInt(st2.nextToken());
				li[end] = li[end]|1<<start;		//선두에 있어야하는 선수들
			}				
			System.out.println("#"+t+" "+dfs(0));
		}	
	}
}