package workshop;

import java.util.Scanner;

public class Solution_º“±›¿Ô¿Ã¡ﬂ√∏ {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int dx[] = { 0, 0, 1 };
		int dy[] = { 0, 1, 0 };
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			int num = sc.nextInt();
			int bug = sc.nextInt();
			boolean check[][] = new boolean[num][num];
			boolean find = false;
			int result = 0;
			for (int i = 1; i <= bug; i++) {
				int cy = sc.nextInt();
				int cx = sc.nextInt();
				int dir = sc.nextInt();
				if(find)
					continue;
				if(check[cy][cx]) {
					find=true;
					result=i;
					continue;
				}
				boolean out=false;
				for(int j=3;j>0;j--) {
					cx+=dx[dir]*j;
					cy+=dy[dir]*j;
					if(cx>=0 && cy>=0 &&cx<num && cy<num) {
						if(!check[cy][cx]) {
							check[cy][cx]=true;
						}
						else {
							find=true;
							result=i;
							break;
						}
					}
					else {
						out=true;
						break;
					}
				}
			}
			System.out.println("#"+t+" "+result);
		}
	}
}