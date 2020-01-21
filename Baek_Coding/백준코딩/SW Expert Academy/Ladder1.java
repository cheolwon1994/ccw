package array1;

import java.util.Scanner;

public class Solution_d4_1210_Ladder1_ÃÖÃ¶¿ø {
	static int arr[][] = new int[100][100];

	public static void main(String[] args) {
		int dx[] = { -1, 1 };
		int tx=0;
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			int finish=-1;
			int tt = sc.nextInt();
			for (int i = 0; i < 100; i++) 
				for (int j = 0; j < 100; j++) {
					arr[i][j] = sc.nextInt();	
					if(arr[i][j]==2)
						tx=j;
				}
			int nx;
			for(int i=99;i>=0;i--) {
				for(int j=0;j<2;j++) {
					nx = tx+dx[j];
					if(nx>=0 && nx<100 && arr[i][nx]==1) {
						for(int k=1;;k++) {
							nx +=dx[j];
							if(nx<0 || nx>99 ||arr[i][nx]==0) {
								nx-=dx[j];
								break;
							}
						}
						tx=nx;
						break;
					}
				}
			}
			System.out.println("#"+t+" "+tx);			
		}
		sc.close();
	}
}