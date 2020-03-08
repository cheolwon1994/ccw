import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_d5_7793_오나의여신님 {
	static class Info{
		int x,y;
		public Info(int y, int x) {
			this.x=x;
			this.y=y;
		}
	}
	
	static char arr[][];
	static int check[][];
	static int row,col;
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			row =Integer.parseInt(st.nextToken());
			col =Integer.parseInt(st.nextToken());
			//초기화
			arr=new char[row][col];
			check=new int[row][col];
			Queue<Info> evil = new LinkedList<>();
			Queue<Info> q = new LinkedList<>();
			
			for(int i=0;i<row;i++) {
				String ss = br.readLine().trim();
				arr[i]=ss.toCharArray();
				for(int j=0;j<ss.length();j++) {
					if(arr[i][j]=='*') 		evil.offer(new Info(i,j));					
					else if(arr[i][j]=='S')			q.offer(new Info(i,j));
				}
			}
			boolean finish=false;
			int result=0;
			Info ii;
			while(true) {
				//악마 이동
				int len = evil.size();
				for(int i=0;i<len;i++) {
					ii=evil.poll();
					int cx = ii.x;
					int cy = ii.y;
					for(int j=0;j<4;j++) {
						int nx = cx + dx[j];
						int ny = cy + dy[j];
						if(nx>=0 && ny>=0 && nx<col && ny<row && (arr[ny][nx]=='.' || arr[ny][nx]=='S')) {
							arr[ny][nx]='*';
							evil.offer(new Info(ny,nx));
						}
					}
				}
				//수연이 이동
				len = q.size();
				for(int i=0;i<len;i++) {
					ii=q.poll();
					int cx = ii.x;
					int cy = ii.y;
					if(arr[cy][cx]=='D') {
						finish=true;
						break;
					}
					for(int j=0;j<4;j++) {
						int nx = cx + dx[j];
						int ny = cy + dy[j];
						if(nx>=0 && ny>=0 && nx<col && ny<row && (arr[ny][nx]=='.' || arr[ny][nx]=='D')) {
							if(arr[ny][nx]!='D')
								arr[ny][nx]='S';
							q.offer(new Info(ny,nx));
						}
					}
				}
				if(finish || q.isEmpty()) break;				
				result++;
			}
			if(!finish) System.out.println("#"+t+" "+"GAME OVER");
			else System.out.println("#"+t+" "+result);
		}
	}
}