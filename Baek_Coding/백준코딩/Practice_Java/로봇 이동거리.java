package workshop;

import java.util.Scanner;

public class Solution_로봇이동거리 {
	public static void main(String[] args) {
		int dx[]= {1,-1,0,0};
		int dy[]= {0,0,1,-1};
		
		Scanner sc = new Scanner(System.in);
		int test=sc.nextInt();
		for(int t=1;t<=test;t++) {
			int num=sc.nextInt();
			sc.nextLine();
			char arr[][]=new char[num][num];
			for(int i=0;i<num;i++) {
				String str=sc.nextLine();
				int cnt=0;
				for(int j=0;j<str.length();j+=2)
					arr[i][cnt++]=str.charAt(j);
			}
			int result=0;
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					if(0<=arr[i][j]-'A' && arr[i][j]-'A'<3) {
						int dir=arr[i][j]-'A'+1;
						if(dir==3) dir=4;
						for(int k=0;k<dir;k++) {
							int cx=j;
							int cy=i;
							if(cx+dx[k]>=0 && cy+dy[k]>=0 && cx+dx[k]<num && cy+dy[k]<num) {
								if(arr[cy+dy[k]][cx+dx[k]]=='S') {
									for(int m=0;;m++) {
										cx+=dx[k];
										cy+=dy[k];
										if(cx>=0 && cy>=0 && cx<num && cy<num) {
											if(arr[cy][cx]=='S') result++;
											else break;
										}
										else
											break;
									}
								}				
							}
						}
					}
				}
			}
			System.out.println("#"+t+" "+result);
		}
 	}
}