import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d3_1240_단순2진암호코드 {
	static int row, col, sx, sy;
	static char arr[][];
	static int ans[];
	final static String cmp[] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111",
			"0111011", "0110111", "0001011" };

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			// 초기화
			arr = new char[row][col];
			ans = new int[8];

			for (int i = 0; i < row; i++) {
				String str = br.readLine();
				for (int j = 0; j < col; j++)
					arr[i][j] = str.charAt(j);
			}
			loop: for (int i = 0; i < row; i++) {
				for (int j = col - 1; j >= 0; j--) {
					if (arr[i][j] == '1') {
						sx = j;
						sy = i;
						break loop;
					}
				}
			}
			sx -= 55;
			int cnt = 0;
			for (int i = sx; i < sx + 56; i += 7) {
				char c[] = new char[7];
				for (int j = 0; j < 7; j++)
					c[j] = arr[sy][i + j];
				String ss = new String(c);
				for (int j = 0; j < 10; j++) {
					if (ss.equals(cmp[j])) {
						ans[cnt++] = j;
						break;
					}
				}
			}
			int t_result = (ans[0] + ans[2] + ans[4] + ans[6]) * 3 + (ans[1] + ans[3] + ans[5] + ans[7]);			
			t_result %= 10;
			if (t_result == 0) {
				t_result = 0;
				for (int i = 0; i < 8; i++)
					t_result += ans[i];
				System.out.println("#" + t + " " + t_result);
			}
			else
				System.out.println("#"+t+" "+0);
		}
	}
}