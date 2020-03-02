import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_8382_방향전환 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			int sx = Integer.parseInt(st.nextToken());
			int sy = Integer.parseInt(st.nextToken());
			int tx = Integer.parseInt(st.nextToken());
			int ty = Integer.parseInt(st.nextToken());
			int dx = Math.abs(sx-tx);
			int dy = Math.abs(sy-ty);
			int big,result=0;
			big = dx > dy ? dx:dy;
			if(Math.abs(dx-dy)%2==0) 	result = 2*big;			
			else result = 2*big-1;
			System.out.print("#"+t+" "+result+'\n');			
		}
	}
}