package list;

import java.util.Scanner;

public class Solution_d3_6808 {
	static long factorial[] = new long[10];
	static int a[]=new int[9];
	static int b[]=new int[9];
	static boolean check[];
	static long win,lose;

	static void dfs(int cnt) {
		if(cnt==9) {
			int a_sum=0;
			int b_sum=0;
			for(int i=0;i<9;i++) {
				if(a[i]<b[i]) 	b_sum+=a[i]+b[i];
				else if(a[i]>b[i]) a_sum+=a[i]+b[i];
			}
			if(a_sum>b_sum) win++;
			else if(a_sum<b_sum) lose++;
			return;
		}
		for(int i=1;i<19;i++) {
			if(!check[i]) {
				check[i]=true;
				b[cnt]=i;
				dfs(cnt+1);
				b[cnt]=0;
				check[i]=false;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for (int t = 1; t <= test; t++) {
			check = new boolean[19];
			win=0;
			lose=0;
			for(int i=1;i<19;i++)
				check[i]=false;
			for(int i=0;i<9;i++) {
				a[i]=sc.nextInt();
				check[a[i]]=true;
			}
			dfs(0);
			System.out.println("#"+t+" "+ win + " " +lose);
		}
		sc.close();
	}
}