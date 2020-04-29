import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution_5658_보물상자비밀번호 {
	static Set<Long> set;
	static String str;

	static void rot() {
		char c = str.charAt(str.length()-1);
		String sub = str.substring(0,str.length()-1);
		str = c+sub;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for (int t = 1; t <= test; t++) {
			set = new TreeSet<Long>();
			int len, k;
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			len = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			str = br.readLine().trim();
			for (int i = 0; i <= len/4; i++) {
				int vv=len/4;
				for(int j=0;j<4;j++) {
					String s1=str.substring(j*vv,(j+1)*vv);
					long ll = Long.parseLong(s1,16);
					set.add(ll);
				}
				rot();
			}
			Iterator<Long> itr = set.iterator();
			long l1,ans=0;
			int cnt=0;
			while (itr.hasNext()) {
				l1=itr.next();
				if(cnt==set.size()-k) {
					ans=l1;
					break;
				}
				cnt++;
			}
			System.out.println("#"+t+" "+ans);
		}
	}
}