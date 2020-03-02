import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_7699_수지의수지맞는여행 {
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	static char arr[][];
	static int row,col,result;
	static boolean alpha[];
	static void dfs(int y, int x, int sum) {
		alpha[arr[y][x]-'A']=true;
		int tt=sum+1;
		result=Math.max(tt, result);
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 & ny>=0 && nx<col && ny<row) {
				if(!alpha[arr[ny][nx]-'A']) {
					alpha[arr[ny][nx]-'A']=true;
					dfs(ny,nx,sum+1);
					alpha[arr[ny][nx]-'A']=false;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			result=0;
			StringTokenizer st = new StringTokenizer(s);
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			arr = new char[row][col];
			alpha = new boolean[26];
			
			for(int i=0;i<row;i++) {
				String str = br.readLine();
				for(int j=0;j<col;j++)
					arr[i][j]=str.charAt(j);
			}
			dfs(0,0,0);
			System.out.print("#"+t+" "+result+'\n');
		}
	}
}