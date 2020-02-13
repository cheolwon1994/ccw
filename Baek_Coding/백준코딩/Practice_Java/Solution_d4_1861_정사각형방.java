package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_1861_정사각형방{
	final static int dx[] = { 0, 1, 0, -1 };
	final static int dy[] = { -1, 0, 1, 0 };
	static int num;
	static int arr[][];
	static int check[][];

	static int start(int y, int x) {
		if (y == 0 || x == 0 || y >num || x >num)	return 0;
		if (check[y][x] != 1)	return check[y][x];
		int cnt = check[y][x];
		int tt = arr[y][x] + 1;
		int maxi=0;
		for(int i=0;i<4;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(arr[ny][nx]==tt) {
				int temp = start(ny,nx);
				if(temp>maxi)
					maxi=temp;
			}
		}
		return maxi+cnt;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			num = Integer.parseInt(br.readLine());
			arr = new int[num+2][num+2];
			check = new int[num+2][num+2];
			// 초기화
			int result = 0;
			int idx = 1;

			for (int i = 0; i < num+2; i++)
				for (int j = 0; j < num+2; j++)
					check[i][j] = 1;

			for (int i = 1; i <= num; i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				for (int j = 1; j <= num; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			for (int i = 1; i <= num; i++)
				for (int j = 1; j <= num; j++)
					check[i][j] = start(i, j);
			
			for (int i = 1; i <= num; i++) {
				for (int j = 1; j <= num; j++)
					if(check[i][j]>result) {
						result=check[i][j];
						idx=arr[i][j];
					}
					else if(check[i][j]==result) {
						if(arr[i][j]<idx)
							idx=arr[i][j];
					}
			}
			System.out.println("#"+t+" "+idx+" "+result);
		}
	}
}