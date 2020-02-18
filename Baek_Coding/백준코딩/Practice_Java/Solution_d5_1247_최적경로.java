import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_d5_1247_최적경로 {
	static int t2t[][];
	static int s2t[];
	static int t2h[];
	static int tx[];
	static int ty[];
	static int sx,sy,ex,ey,num,result;
	static int order[];
	static boolean flag[];
	static void dfs(int cnt) {
		if(cnt==num) {
			int temp=s2t[order[0]] + t2h[order[num-1]];
			for(int i=0;i<num-1;i++) 
				temp+=t2t[order[i]][order[i+1]];
			result = Math.min(temp, result);
			return;
		}
		for(int i=0;i<num;i++) {
			if(!flag[i]) {
				flag[i]=true;
				order[cnt]=i;
				dfs(cnt+1);
				order[cnt]=-1;
				flag[i]=false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			num = Integer.parseInt(br.readLine());
			t2t = new int[num][num];
			order = new int[num];
			flag = new boolean[num];
			s2t = new int[num];
			t2h = new int[num];
			tx = new int[num];
			ty = new int[num];
			result = Integer.MAX_VALUE;
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			sy = Integer.parseInt(st.nextToken());
			sx = Integer.parseInt(st.nextToken());
			ey = Integer.parseInt(st.nextToken());
			ex = Integer.parseInt(st.nextToken());
			for(int i=0;i<num;i++) {
				ty[i] = Integer.parseInt(st.nextToken());
				tx[i] = Integer.parseInt(st.nextToken());				
			}							
			for(int i=0;i<num;i++) {
				s2t[i] = Math.abs(Math.abs(sx-tx[i])+Math.abs(sy-ty[i]));
				t2h[i] = Math.abs(Math.abs(ex-tx[i])+Math.abs(ey-ty[i]));
			}
			for(int i=0;i<num;i++) {
				for(int j=i+1;j<num;j++) {
					int tt = Math.abs(Math.abs(tx[j]-tx[i])+Math.abs(ty[j]-ty[i]));
					t2t[i][j] = tt;
					t2t[j][i] = tt;
				}
			}
			dfs(0);
			System.out.println("#"+t+" "+result);
		}
	}
}