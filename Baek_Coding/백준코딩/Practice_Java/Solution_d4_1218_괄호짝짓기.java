package ws03_0128;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution_d4_1218_괄호짝짓기_서울6반_최철원 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int t = 1; t <= 10; t++) {
			int n = Integer.parseInt(br.readLine());
			String ss = br.readLine(); // String
			Stack<Character> s = new Stack<>();
			char c;
			for (int i = 0; i < ss.length(); i++) {
				c = ss.charAt(i);
				if(c=='['||c=='('||c=='<'||c=='{')
					s.push(c);
				else {
					if(c=='}' && s.peek()=='{' || c==']' && s.peek()=='[' || c==')' && s.peek()=='(' || c=='>' && s.peek()=='<')
						s.pop();
					else
						s.push(c);
				}
			}
			if(!s.empty())
				System.out.println("#"+t+" "+0);
			else
				System.out.println("#"+t+" "+1);
		}
	}
}
