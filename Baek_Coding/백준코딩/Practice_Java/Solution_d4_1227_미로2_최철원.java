package ws03_0128;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution_d4_1227_미로2_서울6반_최철원 {

	static int sx, sy, ex, ey;
	static boolean finish;
	static int dx[] = {0,1,0,-1};
	static int dy[] = {-1,0,1,0};
	static int arr[][];
	static boolean check[][];
	
	static void dfs(int y, int x) {
		int cx,cy,nx,ny;
		cx = x;
		cy = y;
		if(cx==ex && cy==ey) {
			finish=true;
			return;
		}
		for(int i=0;i<4;i++) {
			nx=cx+dx[i];
			ny=cy+dy[i];
			if(nx>=0 && ny>=0 && nx<100 && ny<100) {
				if(arr[ny][nx]!=1 && !check[ny][nx]) {
					check[ny][nx]=true;
					dfs(ny,nx);
					check[ny][nx]=false;
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine());
			arr=new int[100][100];
			check=new boolean[100][100];
			finish=false;
			int tt;
			for (int i = 0; i < 100; i++) {
				String ss = br.readLine(); // String
				for (int j = 0; j < 100; j++) {
					tt = ss.charAt(j)-'0';
					if (tt == 2) {sx = j;sy = i;}
					else if(tt==3) { ex=j;ey=i;}
					arr[i][j]=tt;
				}
			}
			check[sy][sy]=true;
			dfs(sy,sx);
			if(finish)
				System.out.println("#"+t+" "+1);
			else
				System.out.println("#"+t+" "+0);
		}
	}
}
