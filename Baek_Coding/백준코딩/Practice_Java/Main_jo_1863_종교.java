package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_jo_1863_Á¾±³ {
	static int p[];

	static int find(int x) {
		if (p[x] == x)
			return x;
		return p[x] = find(p[x]);
	}

	static void union(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y)
			p[y] = x;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		int num = Integer.parseInt(st.nextToken());
		int order = Integer.parseInt(st.nextToken());
		p = new int[num + 1];
		for (int i = 1; i <= num; i++)	p[i] = i;
		for (int i = 0; i < order; i++) {
			String ss = br.readLine();
			StringTokenizer st2 = new StringTokenizer(ss);
			int start = Integer.parseInt(st2.nextToken());
			int end = Integer.parseInt(st2.nextToken());
			union(start, end);
		}
		int result = 0;
		for (int i = 1; i <= num; i++) 
			if(p[i]==i) result++;
		
		System.out.println(result);
	}
}