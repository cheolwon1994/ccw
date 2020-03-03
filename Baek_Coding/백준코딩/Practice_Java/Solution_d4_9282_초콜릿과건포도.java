import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_9282_초콜릿과건포도 {
	
	static int row,col,result;
	static int arr[][];
	static int val[][][][];
	
	static int cal(int sy, int sx, int r ,int c) {
		if(r==1 && c==1) return 0;
		int res = val[sy][sx][r][c];
		if(res!=-1) return res;
		int sum=0;
		res =Integer.MAX_VALUE;
		for(int i=sy;i<sy+r;i++)
			for(int j=sx;j<sx+c;j++)
				sum+=arr[i][j];
		for(int i=1;i<r;i++)
			res = Math.min(res, sum + cal(sy,sx,i,c)+cal(sy+i,sx,r-i,c));
		for(int j=1;j<c;j++)
			res = Math.min(res, sum+cal(sy,sx,r,j)+cal(sy,sx+j,r,c-j));
		val[sy][sx][r][c] = res;
		return res;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			//초기화
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			arr = new int[row][col];
			val = new int[row][col][row+1][col+1];
			result=0;
			for(int i=0;i<row;i++)
				for(int j=0;j<col;j++)
					for(int m=0;m<row+1;m++)
						for(int k=0;k<col+1;k++)
							val[i][j][m][k]=-1;
			
			for(int i=0;i<row;i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				for(int j=0;j<col;j++) {
					arr[i][j] = Integer.parseInt(st2.nextToken());
				}
			}
			int result = cal(0,0,row,col);
			System.out.println("#"+t+" "+result);
		}
	}
}