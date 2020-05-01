import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Solution_d4_4366_정식이의은행업무 {
	static HashMap<Long, Integer> map;
	static String two,three;
	static long ans;
	static void bfs(String str, int num) {
		for(int i=0;i<str.length();i++) {
			int v = str.charAt(i)-'0';
			for(int k=0;k<num;k++) {
				if(v==k) continue;
				String dup = "";
				for(int j=0;j<str.length();j++) {
					if(j==i) {
						char c = (char) (k+'0');
						dup+=c;
					}
					else dup+=str.charAt(j);
				}
				long val = Long.parseLong(dup,num);
				if(map.containsKey(val)) {
					ans=val;
				}
				else
					map.put(val,1);
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			two = br.readLine();
			three = br.readLine();
			map = new HashMap<>();
			bfs(two,2);
			bfs(three,3);
			System.out.println("#"+t+" "+ans);
		}
	}
}