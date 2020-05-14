import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_bj_2468_안전영역 {
	
	public static class Info{
		int x,y;
		public Info(int y, int x) {
			this.x=x;
			this.y=y;
		}
	}
	
	static int num,arr[][];
	static boolean check[][];
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine().trim();
		StringTokenizer st = new StringTokenizer(s);
		num = Integer.parseInt(st.nextToken());
		arr = new int[num][num];
		int mini=101,maxi=-1,result=1;
		for(int i=0;i<num;i++) {
			s = br.readLine().trim();
			st = new StringTokenizer(s);
			for(int j=0;j<num;j++) {
				arr[i][j]=Integer.parseInt(st.nextToken());
				mini = Math.min(mini, arr[i][j]);
				maxi = Math.max(maxi, arr[i][j]);
			}
		}
		for(int t=mini;t<=maxi;t++) {
			check = new boolean[num][num];
			int cnt=0;
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					if(!check[i][j] && arr[i][j]>t) {
						Queue<Info> q = new LinkedList<>();
						check[i][j]=true;
						cnt++;
						q.offer(new Info(i,j));
						while(!q.isEmpty()) {
							Info ii = q.poll();
							int cx = ii.x;
							int cy = ii.y;
							for(int k=0;k<4;k++) {
								int nx = cx+dx[k];
								int ny = cy+dy[k];
								if(nx>=0 && ny>=0 && nx<num && ny<num && !check[ny][nx] && arr[ny][nx]>t) {
									q.offer(new Info(ny,nx));
									check[ny][nx]=true;
								}
							}
						}
					}
				}
			}
			result = Math.max(result, cnt);
		}
		System.out.println(result);
	}
}