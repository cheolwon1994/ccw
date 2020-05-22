import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_3234_준환이의양팔저울 {
	static int num,arr[],result,order[],tot;
	static boolean check[];
	
	static void dfs(int idx,int lsum, int rsum, int remain) {
		if(lsum>=rsum+remain) {
			int cnt=1;
			//남은 수들을 양쪽 어디에 넣어도 상관이 없다
			for(int i=0;i<num-idx;i++)
				cnt*=2;
			//남은 수들을 넣는 순서
			for(int i=1;i<=num-idx;i++)
				cnt*=i;
			result+=cnt;
			return;
		}		
		if(idx==num) {
			result++;
			return;
		}
		for(int i=0;i<num;i++) {
			if(!check[i]) {
				check[i]=true;
				if(rsum+arr[i]<=lsum) 
					dfs(idx+1,lsum,rsum+arr[i],remain-arr[i]);
				dfs(idx+1,lsum+arr[i],rsum,remain-arr[i]);
				check[i]=false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			num = Integer.parseInt(br.readLine().trim());
			//초기화
			arr = new int[num];
			order = new int[num];
			result=0;
			check = new boolean[num];
			tot=0;
			
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			for(int i=0;i<num;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
				tot+=arr[i];
			}
			dfs(0,0,0,tot);
			System.out.println("#"+t+" "+result);
		}
	}
}