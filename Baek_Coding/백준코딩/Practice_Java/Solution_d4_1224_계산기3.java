package ws03_0128;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution_d4_1224_계산기3_서울6반_최철원 {
	public static String s = "3+(4+5)*6+7";
	public static Stack<Character> stack = new Stack<Character>();

	public static int getIcp(char c) {
		switch (c) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
			return 3;
		default:
			return 0;
		}
	}

	public static int getIsp() {
		char c = stack.empty() ? ' ' : stack.peek();
		switch (c) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
		default:
			return 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine());
			StringBuilder sb = new StringBuilder();

			s = br.readLine(); // String

			for (int i = 0; i < s.length(); i++) {
				char c = s.charAt(i);
				if ('0' <= c && c <= '9')
					sb.append(c);
				else if (c == ')') {
					char ch;
					while ((ch = stack.pop()) != '(') {
						sb.append(ch);
					}
				} else { // (+-*/
					while (getIcp(c) <= getIsp()) {
						sb.append(stack.pop());
					}
					stack.push(c);
				}
			}
			while (!stack.empty()) {
				sb.append(stack.pop());
			}
			
			Stack<Integer> stack2 = new Stack<>();
			String ss = sb.toString();
			for (int i = 0; i < ss.length(); i++) {
				char c = ss.charAt(i);
				if ('0' <= c && c <= '9')
					stack2.push(c - '0');
				else {
					int n2 = stack2.pop();
					int n1 = stack2.pop();
					int nn = 0;
					switch (c) {
					case '+':
						nn = n1 + n2;
						break;
					case '-':
						nn = n1 - n2;
						break;
					case '*':
						nn = n1 * n2;
						break;
					case '/':
						nn = n1 / n2;
						break;
					}
					stack2.push(nn);
				}
			}
			System.out.println("#"+t+" "+stack2.pop());

		}
	}
}