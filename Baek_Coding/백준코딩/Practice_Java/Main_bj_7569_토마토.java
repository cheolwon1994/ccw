package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_bj_7569_토마토 {

	static class Info {
		int x, y, z;

		public Info(int y, int x, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}

	final static int dx[] = { 0, 1, 0, -1, 0, 0 };
	final static int dy[] = { -1, 0, 1, 0, 0, 0 };
	final static int dz[] = { 0, 0, 0, 0, 1, -1 };
	static int arr[][][];
	static int check[][][];
	static int col, row, height;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ss = br.readLine();
		StringTokenizer st = new StringTokenizer(ss);
		col = Integer.parseInt(st.nextToken());
		row = Integer.parseInt(st.nextToken());
		height = Integer.parseInt(st.nextToken());
		// 초기화
		arr = new int[row][col][height];
		check = new int[row][col][height];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				for (int k = 0; k < height; k++)
					check[i][j][k] = -1;

		Queue<Info> q = new LinkedList<Info>();
		for (int k = 0; k < height; k++) {
			for (int i = 0; i < row; i++) {
				String str = br.readLine();
				st = new StringTokenizer(str);
				for (int j = 0; j < col; j++) {
					arr[i][j][k] = Integer.parseInt(st.nextToken());
					if (arr[i][j][k] == 1) {
						q.add(new Info(i, j, k));
						check[i][j][k] = 0;
					}
				}
			}
		}
		while (!q.isEmpty()) {
			int cx = q.peek().x;
			int cy = q.peek().y;
			int cz = q.peek().z;
			int cv = check[cy][cx][cz];
			arr[cy][cx][cz] = 1;
			q.poll();
			for (int i = 0; i < 6; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nz = cz + dz[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && nz >= 0 && nz < height) {
					if (arr[ny][nx][nz] == 0 && check[ny][nx][nz] == -1) {
						q.add(new Info(ny, nx, nz));
						check[ny][nx][nz] = cv + 1;
					}
				}
			}
		}
		boolean finish = true;
		int maxi = 0;
		for (int k = 0; k < height; k++) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (arr[i][j][k] == 0) {
						finish = false;
						break;
					}
					if (check[i][j][k] > maxi)
						maxi = check[i][j][k];
				}
				if (!finish)
					break;
			}
		}
		if (!finish)
			maxi = -1;
		System.out.println(maxi);
	}
}