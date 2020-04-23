import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d3_5215_햄버거다이어트 {
	
	static int num, limit,result;
	static int val[], weight[],dp[][];
	
	static int knapsack(int idx, int remain) {
		if(idx==num) return 0;
		int temp = dp[idx][remain];
		if(temp!=-1) return temp;
		if(weight[idx]<=remain) 
			temp = knapsack(idx+1,remain-weight[idx])+val[idx];
		temp = Math.max(temp, knapsack(idx+1,remain));
		result = Math.max(result, temp);
		return dp[idx][remain]=temp;	
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			num = Integer.parseInt(st.nextToken());
			limit = Integer.parseInt(st.nextToken());
			result=0;
			val = new int[num];
			weight = new int[num];
			dp = new int[num][limit+1];
			for(int i=0;i<num;i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				val[i] = Integer.parseInt(st2.nextToken());
				weight[i] = Integer.parseInt(st2.nextToken());
				for(int j=0;j<=limit;j++)
					dp[i][j]=-1;
			}
			knapsack(0,limit);
			System.out.println("#"+t+" "+result);
		}
	}
}