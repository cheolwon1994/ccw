package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_bj_4963_섬의개수_dfs {

	final static int dx[] = {0,1,1,1,0,-1,-1,-1};
	final static int dy[] = {-1,-1,0,1,1,1,0,-1};
	static int row, col;
	static int arr[][];
	static int check[][];
	static int result;
	
	static void dfs(int y, int x) {
		check[y][x]=result;
		for(int i=0;i<8;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0 && ny>=0 && nx<col && ny<row && check[ny][nx]==0 && arr[ny][nx]==1) {
				dfs(ny,nx);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			col = Integer.parseInt(st.nextToken());
			row = Integer.parseInt(st.nextToken());
			if (col == 0 && row == 0)	break;
			// 초기화
			arr = new int[row][col];
			check = new int[row][col];
			result = 0;

			for(int i=0;i<row;i++) {
				String ss = br.readLine();
				StringTokenizer st2 = new StringTokenizer(ss);
				for(int j=0;j<col;j++) {
					int tt =Integer.parseInt(st2.nextToken());
					arr[i][j]=tt;
				}
			}
			for(int i=0;i<row;i++) {
				for(int j=0;j<col;j++) {
					if(check[i][j]==0 && arr[i][j]==1) {
						result++;
						dfs(i,j);
					}
				}
			}
			System.out.println(result);
		}
	}
}