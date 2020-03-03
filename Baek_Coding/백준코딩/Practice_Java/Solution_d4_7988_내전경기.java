import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_d4_7988_내전경기 {
	static boolean check[];
	static int flag[];
	static HashMap<String, Integer> map;
	static List<Integer> li[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			int num = Integer.parseInt(br.readLine());
			int cnt = 0;
			map = new HashMap<>();
			li = new List[201];
			flag = new int[201];
			check = new boolean[201];

			for (int i = 0; i < 201; i++)
				li[i] = new ArrayList<Integer>();

			for (int i = 0; i < num; i++) {
				String s = br.readLine();
				StringTokenizer st = new StringTokenizer(s);
				String s1 = st.nextToken();
				String s2 = st.nextToken();
				if (!map.containsKey(s1)) {
					map.put(s1, cnt);
					cnt++;
				}
				if (!map.containsKey(s2)) {
					map.put(s2, cnt);
					cnt++;
				}
				li[map.get(s1)].add(map.get(s2));
				li[map.get(s2)].add(map.get(s1));
			}
			Queue<Integer> q = new LinkedList<Integer>();
			q.offer(0);
			flag[0] = -1;
			check[0] = true;
			boolean avail = true;
			while (!q.isEmpty()) {
				int cidx = q.poll();
				int cv = flag[cidx];
				for (int i = 0; i < li[cidx].size(); i++) {
					if(flag[li[cidx].get(i)]==cv) {		//연결되어 있고 같은색인 경우
						avail=false;
						break;
					}
					if(!check[li[cidx].get(i)]) {		//연결되어 있고 방문하지 않은 경우
						check[li[cidx].get(i)]=true;
						flag[li[cidx].get(i)]=-cv;
						q.offer(li[cidx].get(i));
					}
				}
				if(!avail) break;
			}
			if(avail) System.out.print("#"+t+" "+"Yes"+'\n');
			else System.out.print("#"+t+" "+"No"+'\n');
		}
	}
}