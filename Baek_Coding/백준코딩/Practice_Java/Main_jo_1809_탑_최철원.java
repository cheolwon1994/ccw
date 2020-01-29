package ws03_0128;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main_jo_1809_탑_서울6반_최철원 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int tt, idx = 0;
		String ss = br.readLine(); // String
		Stack<Integer> s = new Stack<>();
		Stack<Integer> ii = new Stack<>();
		
		StringTokenizer st = new StringTokenizer(ss);
		for (int i = 1; i <= n; i++) {
			tt = Integer.parseInt(st.nextToken());
			while (!s.empty()) {
				if (s.peek() < tt) {
					s.pop();
					ii.pop();
				}
				else {
					s.push(tt);
					System.out.print(ii.peek()+" ");
					ii.push(i);
					break;
				}
			}
			if (s.empty()) {
				s.push(tt);
				ii.push(i);
				System.out.print(0+" ");
			}
		}
	}
}