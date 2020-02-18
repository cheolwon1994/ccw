import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution_d4_7965_ДыБо {
	static long dp[]= new long [1000001]; 
	static long sum[]=new long [1000001];
	static long power(long x, long y) {
		if(y==0) return 1;
		else if(y==1) return x;
		else if(y%2==0) {
			long tt = power(x,y/2);
			return (tt*tt)%1000000007;
		}
		else if(y%2!=0) {
			long tt = power(x,y-1);
			return (tt*x)%1000000007;
		}
		return 1;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		dp[1]=1;
		sum[1]=1;
		for(int i=2;i<1000001;i++)
			dp[i]=power(i,i);
		for(int i=2;i<1000001;i++)
			sum[i]=(sum[i-1]+dp[i])%1000000007;
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			int num = Integer.parseInt(br.readLine());
			System.out.println("#"+t+" "+sum[num]);
		}
	}
}