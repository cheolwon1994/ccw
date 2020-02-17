import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main_bj_1931_회의실배정 {
	
	static class Info implements Comparable<Info>{
		int start,end;
		public Info(int start, int end) {
			this.start=start;
			this.end=end;
		}
		@Override
		public int compareTo(Info o) {
			if(end==o.end)
				return Integer.compare(start,o.start);
			return Integer.compare(end,o.end);
		}
		
	}
	static List<Info> li = new ArrayList<Info>();
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num =Integer.parseInt(br.readLine());

		for(int i=0;i<num;i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			li.add(new Info(start,end));
		}
		Collections.sort(li);
//		for(int i=0;i<num;i++)
//			System.out.println(li.get(i).start + " "+li.get(i).end);
		int finish=li.get(0).end;
		int result=1;
		for(int i=1;i<num;i++) {
			if(li.get(i).start>=finish) {
				finish=li.get(i).end;
				result++;
			}
		}
		System.out.println(result);
	}
}