package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_17135_캐슬디펜스 {
	static int arr[][];
	static int dup[][];
	static int Ax[]; // 궁수 위치
	static int Ay[];
	static int row, col, dist, result, t_result;
	static boolean flag[];
	final static int dx[] = { 0,1,0,-1 };
	final static int dy[] = { -1,0,1,0 };

	static class Info implements Comparable<Info>{
		int x, y, val;
		public Info(int y, int x, int val) {
			this.x = x;
			this.y = y;
			this.val = val;
		}
		@Override
		public int compareTo(Info o) {
			if(this.val==o.val)
				return Integer.compare(this.x, o.x);
			return Integer.compare(this.val,o.val);
		}
	}
	
	static void attack() {
		for (int k = 0; k < row; k++) {		
			boolean check[][];
			Queue<Info> die = new LinkedList<Info>();
			for (int i = 0; i < 3; i++) {
				LinkedList<Info> ans = new LinkedList<Info>();
				check = new boolean[row+1][col];
				boolean find = false;
				Queue<Info> q = new LinkedList<Info>();
				q.add(new Info(Ay[i], Ax[i], 0));
				while (!q.isEmpty()) {
					int cx = q.peek().x;
					int cy = q.peek().y;
					int cv = q.peek().val;
					q.poll();
					if (dup[cy][cx] == 1) {
						find = true;
						ans.add(new Info(cy, cx,cv));
					}
					if (find)	continue;
					for (int j = 0; j < 4; j++) {
						int nx = cx + dx[j];
						int ny = cy + dy[j];
						if (nx >= 0 && ny >= 0 && nx < col && ny <= row && !check[ny][nx] && cv + 1 <= dist) {
							check[ny][nx] = true;
							q.add(new Info(ny, nx, cv + 1));
						}
					}
				}
				if (!ans.isEmpty()) {
					Collections.sort(ans);					
					die.add(ans.poll());
				}
			}
			Info ii;
			while (!die.isEmpty()) {
				ii = die.poll();
				if (dup[ii.y][ii.x] == 1) {
					dup[ii.y][ii.x] = 0;
					t_result++;
				}
			}
			// 밑으로 1칸 이동
			for (int i = row - 1; i > 0; i--) {
				for (int j = 0; j < col; j++) {
					dup[i][j] = dup[i - 1][j];
				}
			}
			for (int j = 0; j < col; j++)
				dup[0][j] = 0;
		}
	}

	static void setArcher(int idx, int cnt) {
		if (cnt == 3) {
			// dup복제, 초기화
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					dup[i][j] = arr[i][j];
			for (int j = 0; j < col; j++)	dup[row][j]=0;
			t_result = 0;
			attack();
			if(result<t_result)
				result=t_result;
			return;
		}
		for (int i = idx; i < col; i++) {
			if (!flag[i]) {
				Ax[cnt] = i;
				flag[i] = true;
				setArcher(i + 1, cnt + 1);
				Ax[cnt] = -1;
				flag[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		dist = Integer.parseInt(st.nextToken());

		// 초기화
		arr = new int[row][col];
		dup = new int[row+1][col];
		Ax = new int[3];
		Ay = new int[3];
		result = 0;
		flag = new boolean[col];
		for (int i = 0; i < 3; i++)
			Ay[i] = row;

		for (int i = 0; i < row; i++) {
			String ss = br.readLine();
			StringTokenizer st2 = new StringTokenizer(ss);
			for (int j = 0; j < col; j++)
				arr[i][j] = Integer.parseInt(st2.nextToken());
		}
		setArcher(0, 0);
		System.out.println(result);
	}
}