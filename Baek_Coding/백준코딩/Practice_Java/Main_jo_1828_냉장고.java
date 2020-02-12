import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Info2 implements Comparable<Info2>{
	int start,end;
	public Info2(int start, int end){
		this.start = start;
		this.end =end;
	}
	@Override
	public int compareTo(Info2 o) {
		if(this.end==o.end)
			return Integer.compare(this.start,o.start);
		return Integer.compare(this.end,o.end);
	}
}

public class Main_jo_1828_≥√¿Â∞Ì {
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		List<Info2> arr= new ArrayList<Info2>();
		Info2 ii;
		for(int i=0;i<num;i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			ii=new Info2(start,end);
			arr.add(ii);
		}
		Collections.sort(arr);
		int result=1;
		int maxi=arr.get(0).end;
		for(int i=1;i<num;i++) {
			int s = arr.get(i).start;
			if(s>maxi) {
				result++;
				maxi=arr.get(i).end;
			}
		}
		System.out.println(result);
	}
}