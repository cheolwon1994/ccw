import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	static int arr[][],check[][];
	static int num,mh,result,maxi,sx,sy;
	
	static void dfs(int y, int x,int cnt, int ch, boolean dig) {
		int cx, cy, ny, nx;
		cx = x;
		cy = y;
		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < num && ny < num) {
				if (nx == sx && ny == sy)
					continue;
				if (dig == true) {		//더이상 공사 불가
					if (arr[ny][nx] >= ch)
						continue;
					else if (arr[ny][nx] < ch && check[ny][nx]==0) {
						int t = check[ny][nx];
						check[ny][nx] = cnt + 1;
						dfs(ny, nx, cnt + 1, arr[ny][nx], dig);
						check[ny][nx] = t;
					}
				}
				else if(!dig){		//공사가 가능한 경우
					if (arr[ny][nx] < ch && check[ny][nx]==0) {
						int t = check[ny][nx];
						check[ny][nx] = cnt + 1;
						dfs(ny, nx, cnt + 1, arr[ny][nx], dig);
						check[ny][nx] = t;
					}
					else if (arr[ny][nx] >= ch) {
						for (int j = 1; j <= mh; j++) {
							if (ch + j > arr[ny][nx] && check[ny][nx]==0) {
								int t = check[ny][nx];
								int pre_arr = arr[ny][nx];
								check[ny][nx] = cnt + 1;
								arr[ny][nx] -= j;
								dfs(ny, nx, cnt + 1, arr[ny][nx], true);
								arr[ny][nx] = pre_arr;
								check[ny][nx] = t;
							}
						}
					}
				}
			}
		}
		result = Math.max(result, cnt);
		return;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			num = Integer.parseInt(st.nextToken());
			mh = Integer.parseInt(st.nextToken());
			arr = new int[num][num];
			check = new int[num][num];
			result=0;
			maxi=0;
			
			for(int i=0;i<num;i++) {
				s = br.readLine();
				st = new StringTokenizer(s);
				for(int j=0;j<num;j++) {
					arr[i][j]=Integer.parseInt(st.nextToken());
					maxi = Math.max(maxi, arr[i][j]);
				}
			}
			for(int i=0;i<num;i++)
				for (int j = 0; j < num; j++) {
					if (arr[i][j] == maxi) {
						for(int k=0;k<num;k++)
							for(int m=0;m<num;m++)
								check[k][m]=0;
						check[i][j] = 1;
						sx = j;
						sy = i;
						dfs(i, j, 1, maxi, false);
					}
				}
			System.out.println("#"+t+" "+result);
		}
	}
}