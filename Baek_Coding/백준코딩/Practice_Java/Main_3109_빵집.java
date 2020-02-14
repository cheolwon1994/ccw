package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_3109_»§Áý {
	static char arr[][];
	static boolean check[][];
	static boolean finish;
	final static int dx[]= {1,1,1};
	final static int dy[]= {-1,0,1};
	static int row,col,result;
		
	static void dfs(int r, int c) {
		if(c==col-1) {
			finish=true;
			return;
		}		
		if(r-1>=0 && !check[r-1][c+1] && arr[r-1][c+1]=='.') {
			check[r-1][c+1]=true;
			dfs(r-1,c+1);
			if(finish) return;
		}
		if(!check[r][c+1] && arr[r][c+1]=='.') {
			check[r][c+1]=true;
			dfs(r,c+1);
			if(finish) return;
		}
		if(r+1<row && !check[r+1][c+1] && arr[r+1][c+1]=='.') {
			check[r+1][c+1]=true;
			dfs(r+1,c+1);
			if(finish) return;
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		//ÃÊ±âÈ­
		arr = new char [row][col];
		check = new boolean [row][col];
		result=0;
		
		for(int i=0;i<row;i++) {
			String ss = br.readLine();
			if(ss.charAt(0)!='x')
				check[i][0]=true;
			for(int j=0;j<col;j++)
				arr[i][j]=ss.charAt(j);
		}
		for(int i=0;i<row;i++) {
			if(check[i][0]) {
				finish=false;
				dfs(i,0);
				if(finish)	result++;			
			}
		}
		System.out.println(result);
	}

}