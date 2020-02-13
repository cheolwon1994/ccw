package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_게리맨더링 {
	static int a[];
	static int b[];
	static int a_idx, b_idx;
	static int num, result;
	static int population[];
	static boolean connect[][];
	static boolean flag[];

	static boolean test() {
		Queue<Integer> q = new LinkedList<Integer>();
		boolean check[] = new boolean[num + 1];
		boolean avail = true;
		for (int i = 1; i < a_idx; i++)
			check[a[i]] = true;
		q.add(a[0]);
		while (!q.isEmpty()) {
			int cidx = q.poll();
			for (int i = 1; i <= num; i++) {
				if (cidx == i)
					continue;
				if (check[i] && connect[cidx][i]) {
					check[i] = false;
					q.add(i);
				}
			}
		}
		for (int i = 1; i < a_idx; i++)
			if (check[a[i]]) {
				avail = false;
				break;
			}
		if (avail) {
			q = new LinkedList<Integer>();
			check = new boolean[num + 1];
			for (int i = 1; i < b_idx; i++)
				check[b[i]] = true;
			q.add(b[0]);
			while (!q.isEmpty()) {
				int cidx = q.poll();
				for (int i = 1; i <= num; i++) {
					if (cidx == i)
						continue;
					if (check[i] && connect[cidx][i]) {
						check[i] = false;
						q.add(i);
					}
				}
			}
			for (int i = 1; i < b_idx; i++)
				if (check[b[i]]) {
					avail = false;
					break;
				}
		}
		return avail;
	}

	static void dfs(int cnt, int idx) {
		if (cnt == num || idx == num + 1)
			return;
		if (cnt > 0) {
			a = new int[num+1];
			b = new int[num+1];
			a_idx = 0;
			b_idx = 0;
			int a_sum = 0;
			int b_sum = 0;
			for (int i = 1; i <= num; i++) {
				if (flag[i]) {
					a[a_idx++] = i;
					a_sum += population[i];
				} else {
					b[b_idx++] = i;
					b_sum += population[i];
				}
			}
			boolean success = test();
			if (success) {
				int t_result = Math.abs(a_sum - b_sum);
				if (result > t_result)
					result = t_result;
			}
		}
		for (int i = idx; i <= num; i++) {
			if (!flag[i]) {
				flag[i] = true;
				dfs(cnt + 1, idx + 1);
				flag[i] = false;
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		num = Integer.parseInt(br.readLine());
		connect = new boolean[num + 1][num + 1];
		population = new int[num + 1];
		result = Integer.MAX_VALUE;
		flag = new boolean[num + 1];

		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		for (int i = 1; i <= num; i++)
			population[i] = Integer.parseInt(st.nextToken());
		for (int i = 1; i <= num; i++) {
			String str2 = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str2);
			int tt = Integer.parseInt(st2.nextToken());
			for (int j = 0; j < tt; j++) {
				int end = Integer.parseInt(st2.nextToken());
				connect[i][end] = true;
			}
		}
		dfs(0, 1);
		if (result == Integer.MAX_VALUE)
			result = -1;
		System.out.println(result);
	}
}