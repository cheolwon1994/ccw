import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1953_탈주범검거 {
	static int row, col, ty, tx, tt, result, arr[][], check[][];
	final static int avail[][] = { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 1, 0, 1, 0 }, { 0, 1, 0, 1 }, { 1, 1, 0, 0 },
			{ 0, 1, 1, 0 }, { 0, 0, 1, 1 }, { 1, 0, 0, 1 } };
	final static int dx[] = { 0, 1, 0, -1 };
	final static int dy[] = { -1, 0, 1, 0 };

	public static class Info {
		int x, y, t;

		public Info(int y, int x, int t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}
	}

	static void ans() {
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (check[i][j] == 1)
					result++;
	}

	static void bfs() {
		Queue<Info> q = new LinkedList<>();
		q.offer(new Info(ty, tx, 1));
		int cx, cy, ct, nx, ny, ca, na;
		while (!q.isEmpty()) {
			Info ii = q.poll();
			cx = ii.x;
			cy = ii.y;
			ct = ii.t;
			ca = arr[cy][cx];
			if (ct == tt)
				continue;
			for (int i = 0; i < 4; i++) {
				boolean flag = false;
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < col && ny < row && check[ny][nx] == 0 && avail[ca][i] == 1) {
					na = arr[ny][nx];
					if(na<=0) continue;
					if (i == 0 && avail[na][2] == 1)
						flag = true;
					else if (i == 1 && avail[na][3] == 1)
						flag = true;
					else if (i == 2 && avail[na][0] == 1)
						flag = true;
					else if (i == 3 && avail[na][1] == 1)
						flag = true;
				}
				if (flag) {
					q.offer(new Info(ny, nx, ct + 1));
					check[ny][nx] = 1;
				}
			}
		}
		ans();
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for (int t = 1; t <= test; t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			ty = Integer.parseInt(st.nextToken());
			tx = Integer.parseInt(st.nextToken());
			tt = Integer.parseInt(st.nextToken());

			// 초기화
			result = 0;
			check = new int[row][col];
			arr = new int[row][col];

			for (int i = 0; i < row; i++) {
				str = br.readLine();
				st = new StringTokenizer(str);
				for (int j = 0; j < col; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			check[ty][tx] = 1;
			bfs();
			System.out.println("#" + t + " " + result);
		}
	}
}
