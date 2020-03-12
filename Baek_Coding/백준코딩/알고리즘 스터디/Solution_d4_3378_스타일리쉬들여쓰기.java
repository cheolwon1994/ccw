import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_3378_스타일리쉬들여쓰기 {
	static String str1[][];
	static int master_op[], my_op[], rcs[],ans[];
	static int master, me;
	static boolean avail;
	static void start(int idx, int cnt, int dot) { // 해당 줄, ,필요한 점의 갯수
		if (idx==0 && cnt == master || idx==1 && cnt==me)
			return;
		int d = 0;
		boolean fin = false;
		for (int i = 0; i < str1[idx][cnt].length(); i++) {
			if (idx == 0) {
				if (str1[idx][cnt].charAt(i) == '.' && !fin)
					d++;
				else if (str1[idx][cnt].charAt(i) != '.' && !fin) {
					fin = true;
					if (dot != d) { // 들여쓰기가 필요한 갯수만큼 되어 있지 않은 경우
						avail = false;
						break;
					}
				}
			}
			if (str1[idx][cnt].charAt(i) == '(') {
				if (idx == 0)
					master_op[0]++;
				else
					my_op[0]++;
			} else if (str1[idx][cnt].charAt(i) == ')') {
				if (idx == 0)
					master_op[1]++;
				else
					my_op[1]++;
			} else if (str1[idx][cnt].charAt(i) == '{') {
				if (idx == 0)
					master_op[2]++;
				else
					my_op[2]++;
			} else if (str1[idx][cnt].charAt(i) == '}') {
				if (idx == 0)
					master_op[3]++;
				else
					my_op[3]++;
			} else if (str1[idx][cnt].charAt(i) == '[') {
				if (idx == 0)
					master_op[4]++;
				else
					my_op[4]++;
			} else if (str1[idx][cnt].charAt(i) == ']') {
				if (idx == 0)
					master_op[5]++;
				else
					my_op[5]++;
			}
		}
		if (idx == 1) {
			if(ans[cnt]==-2)		ans[cnt]=dot;	//처음 들어가는 경우			
			else if(ans[cnt]!=dot) 	ans[cnt]=-1;
		}
		
		if (avail) {
			if (idx == 0)
				start(idx, cnt + 1, rcs[0] * (master_op[0] - master_op[1]) + rcs[1] * (master_op[2] - master_op[3])
						+ rcs[2] * (master_op[4] - master_op[5]));
			else
				start(idx, cnt + 1, rcs[0] * (my_op[0] - my_op[1]) + rcs[1] * (my_op[2] - my_op[3])
						+ rcs[2] * (my_op[4] - my_op[5]));
		}
	}

	static void dfs(int cnt) {
		if (cnt == 3) {
			avail = true;
			for (int i = 0; i < 6; i++)
				master_op[i] = 0;
			start(0, 0, 0);
			if (avail) 
				start(1, 0, 0);			
			return;
		}
		for (int i = 1; i < 21; i++) {
			rcs[cnt] = i;
			dfs(cnt + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for (int t = 1; t <= test; t++) {
			String s1 = br.readLine();
			StringTokenizer st = new StringTokenizer(s1);
			master = Integer.parseInt(st.nextToken());
			me = Integer.parseInt(st.nextToken());
			// 초기화
			rcs = new int[3];
			master_op = new int[6];
			my_op = new int[6];
			ans = new int[me];
			for(int i=0;i<me;i++)
				ans[i]=-2;
			str1 = new String[2][80];
			
			for (int i = 0; i < master; i++) {
				String ss = br.readLine().trim();
				str1[0][i] = ss;
			}
			for (int i = 0; i < me; i++) {
				String ss = br.readLine().trim();
				str1[1][i] = ss;
			}
			System.out.print("#" + t + " ");
			dfs(0);
			for(int i=0;i<me;i++)
				System.out.print(ans[i]+" ");
			System.out.println();
		}
	}
}