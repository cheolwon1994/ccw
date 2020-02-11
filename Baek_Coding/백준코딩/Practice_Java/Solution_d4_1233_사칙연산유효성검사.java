import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_1233_사칙연산유효성검사 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int num = Integer.parseInt(br.readLine());
			int result=1;
			for (int i = 0; i < num; i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				st.nextToken();
				if (i < num / 2) {
					char c =st.nextToken().charAt(0);
					if (c == '-' || c == '+'|| c == '*' ||c == '/')
						continue;
					else {
						result=0;
					}
				}
				while (st.hasMoreTokens()) {
					st.nextToken();
				}
			}		
			System.out.println("#"+t+" "+result);
		}
	}
}
