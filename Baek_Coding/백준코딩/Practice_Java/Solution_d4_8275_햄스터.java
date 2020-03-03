import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_d4_8275_햄스터 {
	static class Info implements Comparable<Info> {
		int start, end, tot;
		public Info(int start, int end, int tot) {
			this.start = start;
			this.end = end;
			this.tot = tot;
		}
		@Override
		public int compareTo(Info o) {
			if (this.end == o.end)
				return -Integer.compare(this.start, o.start);
			return -Integer.compare(this.end, o.end);
		}
	}
	static List<Integer> vv[];
	static int hamster[];
	static boolean flag[];
	static int num, limit, cmd, result,maxi;
	static List<Info> li;

	static void dfs(int idx, int start, int end, int cnt, int sum, int cidx) {
		if (idx == end + 1) {
			if(cnt==sum) {
				cal(cidx-1);
			}
			return;
		}
		if ((end - idx + 1) * limit + cnt < sum)
			return;
		if (flag[idx])
			dfs(idx + 1, start, end, cnt + hamster[idx], sum,cidx);
		else {
			for (int i = 0; i <= limit; i++) {
				hamster[idx] = i;
				flag[idx]=true;
				dfs(idx + 1, start, end, cnt + i, sum,cidx);
				hamster[idx] = 0;
				flag[idx]=false;
			}
		}
	}

	static void cal(int idx) {
		if (idx == -1) {
			// 계산
			long tt=0;
			int sum=0;
			for(int i=1;i<=num;i++) {
				tt*=10;			
				if(!flag[i]) 
					sum+=limit;				
				else 
					sum+=hamster[i];				
			}
			if(vv[sum].size()==0) {
				for(int i=1;i<=num;i++) {
					if(!flag[i]) 
						vv[sum].add(limit);					
					else 
						vv[sum].add(hamster[i]);
				}
				maxi =Math.max(maxi, sum);
			}
			return;
		}
		int s = li.get(idx).start;
		int e = li.get(idx).end;
		int t = li.get(idx).tot;
		dfs(s, s, e, 0, t,idx);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			num = Integer.parseInt(st.nextToken());
			limit = Integer.parseInt(st.nextToken());
			cmd = Integer.parseInt(st.nextToken());
			// 초기화
			hamster = new int[num + 1];
			flag = new boolean[num + 1];
			vv = new List[61];
			for (int i = 0; i <= 60; i++)
				vv[i] = new ArrayList<Integer>();
			li = new ArrayList<Info>();
			li = new ArrayList<Info>();
			maxi=-1;
			for (int i = 0; i < cmd; i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				int start = Integer.parseInt(st2.nextToken());
				int end = Integer.parseInt(st2.nextToken());
				int tot = Integer.parseInt(st2.nextToken());
				li.add(new Info(start, end, tot));
			}
			Collections.sort(li);
			cal(li.size() - 1);
			System.out.print("#"+t+" ");
			if(maxi==-1)
				System.out.println(-1);
			else {
				for(int i=0;i<num;i++)
					System.out.print(vv[maxi].get(i)+" ");
				System.out.println();
			}
		}
	}
}