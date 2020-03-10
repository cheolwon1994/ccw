import java.io.*;
import java.util.*;

public class Solution_d4_7701_¿°¶ó´ë¿ÕÀÇÀÌ¸§Á¤·ÄTreeset {
	
	static class Info implements Comparable<Info>{
		String str;
		public Info(String str) {
			this.str = str;
		}
		@Override
		public int compareTo(Info o) {
			if(this.str.length()==o.str.length())
				return this.str.compareTo(o.str);
			return Integer.compare(this.str.length(), o.str.length());
		}
	}
	static Set<Info> set;
	public static void main(String[] args) throws Exception{
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			set  = new TreeSet<>();
			int num = Integer.parseInt(br.readLine().trim());
			for(int i=0;i<num;i++) {
				String s = br.readLine().trim();
				set.add(new Info(s));				
			}			
			Iterator<Info> it = set.iterator();	 
			bw.write("#"+t+'\n');
	        while(it.hasNext()){
	        	bw.write(it.next().str+'\n');
	        }			
		}
		bw.flush();
        bw.close();
	}
}