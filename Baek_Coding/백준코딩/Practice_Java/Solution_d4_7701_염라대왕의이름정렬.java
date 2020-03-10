import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.PriorityQueue;

public class Solution_d4_7701_¿°¶ó´ë¿ÕÀÇÀÌ¸§Á¤·Ä {
	static class Info implements Comparable<Info>{
		String str;
		int len;
		public Info(String str, int len) {
			this.str = str;
			this.len=len;
		}
		@Override
		public int compareTo(Info o) {
			if(this.len==o.len)
				return this.str.compareTo(o.str);
			return Integer.compare(this.len, o.len);
		}
	}
	static PriorityQueue<Info> pq;
	static HashMap<String, Integer> map;
	public static void main(String[] args) throws Exception{
		
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			pq = new PriorityQueue<>();
			map = new HashMap<>();
			int num = Integer.parseInt(br.readLine().trim());
			for(int i=0;i<num;i++) {
				String s = br.readLine().trim();
				map.put(s, s.length());				
			}			
			Iterator<String> mapIter = map.keySet().iterator();	 
	        while(mapIter.hasNext()){
	            String key = mapIter.next();
	            int len = map.get(key);
	            pq.add(new Info(key,len));
	        }			
			Info ii;
			System.out.println("#"+t);
			while(!pq.isEmpty()) {
				ii=pq.poll();
				System.out.print(ii.str+'\n');
			}
		}
	}
}