import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_d5_7396_종구의딸이름짓기 {
	static class Info{
		int x,y;
		public Info(int y, int x) {
			this.x=x;
			this.y=y;
		}
	}
	final static int dx[]= {0,1};
	final static int dy[]= {1,0};
	static int row,col;
	static char arr[][];
	static boolean check[][];
	static String ans;
	static Queue<Info> q;
	static Queue<Info> nq;
	
	static void start() {
		Info ii;
		q=new LinkedList<>();
		nq=new LinkedList<>();
		q.offer(new Info(0,0));
		while (ans.length() < row + col - 1) {
			char c = 'z' + 1;		
			while (!q.isEmpty()) {
				ii = q.poll();
				int cx = ii.x;
				int cy = ii.y;
				for (int i = 0; i < 2; i++) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx < col && ny < row && !check[ny][nx]) {
						check[ny][nx] = true;
						if (arr[ny][nx] < c) {
							c = arr[ny][nx];
							while (!nq.isEmpty()) nq.poll();					
							nq.offer(new Info(ny,nx));
						}
						else if (arr[ny][nx] == c) {
							nq.offer(new Info(ny,nx));
						}
					}
				}
			}
			ans += c;
			q.addAll(nq);
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s," ");
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			//초기화
			arr = new char[row][col];
			check = new boolean[row][col];		
			ans="";
			
			for(int i=0;i<row;i++) 
				arr[i]=br.readLine().toCharArray();
			ans+=arr[0][0];
			check[0][0]=true;
			start();			
			System.out.println("#"+t+" "+ans);
		}
	}
}