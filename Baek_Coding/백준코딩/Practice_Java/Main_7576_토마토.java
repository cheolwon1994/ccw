package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info {
	int x, y;

	public Info(int y, int x) {
		this.x = x;
		this.y = y;
	}
}

public class Main_7576_토마토 {
	final static int dx[] = { 0, 1, 0, -1 };
	final static int dy[] = { -1, 0, 1, 0 };
	static int arr[][];
	static int check[][];
	static int col, row;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ss = br.readLine();
		StringTokenizer st = new StringTokenizer(ss);
		col = Integer.parseInt(st.nextToken());
		row = Integer.parseInt(st.nextToken());
		// 초기화
		arr = new int[row][col];
		check = new int[row][col];
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				check[i][j]=-1;
		
		Queue<Info> q = new LinkedList<Info>();
		for (int i = 0; i < row; i++) {
			String str = br.readLine();
			st = new StringTokenizer(str);
			for (int j = 0; j < col; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] == 1) {
					q.add(new Info(i, j));
					check[i][j]=0;
				}
			}
		}
		while (!q.isEmpty()) {
			int cx = q.peek().x;
			int cy = q.peek().y;
			int cv = check[cy][cx];
			arr[cy][cx]=1;
			q.poll();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(nx>=0 && ny>=0 && nx<col && ny<row) {
					if(arr[ny][nx]==0 && check[ny][nx]==-1) {
						q.add(new Info(ny,nx));
						check[ny][nx]=cv+1;
					}
				}
			}
		}
		boolean finish = true;
		int maxi=0;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(arr[i][j]==0) {
					finish=false;
					break;
				}
				if(check[i][j]>maxi)
					maxi=check[i][j];
			}
			if(!finish) break;
		}
		if(!finish) maxi=-1;
		System.out.println(maxi);
	}
}
