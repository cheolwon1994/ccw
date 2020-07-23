import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int pri[] = {2,3,5,7};
	
	static boolean check(int val) {
		for(int i=2;i*i<=val;i++) 
			if(val%i==0) 
				return false;
		return true;
	}
	
	static void dfs(int idx, int sum) {
		if(idx==n) {
			System.out.println(sum);
			return;
		}
		for(int i=1;i<10;i++) {
			int tt = sum*10+i;
			if(check(tt))
				dfs(idx+1,tt);
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine().trim();
		StringTokenizer st = new StringTokenizer(s);
		n = Integer.parseInt(st.nextToken());
		for(int i=0;i<4;i++)
			dfs(1,pri[i]);
	}
}