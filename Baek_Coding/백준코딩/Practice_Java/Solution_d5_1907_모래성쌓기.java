import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_d5_1907_모래성쌓기 {
	static class Info {
		int x, y;

		public Info(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static int row, col, result;
	static int arr[][];
	final static int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	final static int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static Queue<Info> wave;

	static void crash() {
		while (true) {
			Info ii;
			int len =wave.size();
			for(int i=0;i<len;i++) {
				ii = wave.poll();
				int cy = ii.y;
				int cx = ii.x;
				for(int k=0;k<8;k++) {
					int nx = cx+dx[k];
					int ny = cy+dy[k];
					if(nx>=0 && ny>=0 && nx<col && ny<row) {
						if(arr[ny][nx]>0) {
							arr[ny][nx]--;
							if(arr[ny][nx]==0) {
								wave.offer(new Info(ny,nx));
							}
						}
					}
				}
			}
			if(wave.isEmpty()) break;
			else	result++;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			// 초기화
			arr = new int[row][col];
			result = 0;
			wave = new LinkedList<>();
			for (int i = 0; i < row; i++) {
				String str = br.readLine();
				for (int j = 0; j < col; j++) {
					char c = str.charAt(j);
					if (c == '.') {
						arr[i][j] = 0;
						wave.offer(new Info(i, j));
					} else
						arr[i][j] = c - '0';
				}
			}
			if(!wave.isEmpty())
				crash();
			System.out.println("#" + t + " " + result);
		}
	}
}