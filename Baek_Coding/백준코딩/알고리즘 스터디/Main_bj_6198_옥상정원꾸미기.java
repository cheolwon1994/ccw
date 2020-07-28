import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	
	static class Info{
		int idx,height;
		public Info(int idx, int height) {
			this.idx = idx;
			this.height = height;
		}
	}
	
	static int n;
	static int arr[];
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().trim();
		StringTokenizer st = new StringTokenizer(str);
		n = Integer.parseInt(st.nextToken());
		arr = new int[n+2];
		int maxi = 0;
		for(int i=1;i<=n;i++) {
			str = br.readLine().trim();
			st= new StringTokenizer(str);
			arr[i]=Integer.parseInt(st.nextToken());
			maxi = Math.max(maxi, arr[i]);
		}
		long cnt=0;
		Stack<Info> s = new Stack<>();
		s.add(new Info(n+1,maxi+1));
		
		for(int i=n;i>0;i--) {
			int ch = arr[i];		//현재 건물의 높이
			while(!s.isEmpty()) {
				int hh = s.peek().height;
				if(hh>=ch) {
					cnt+=(s.peek().idx-i-1);
					s.add(new Info(i,ch));
					break;
				}
				else 
					s.pop();
			}
		}
		System.out.println(cnt);
	}
}