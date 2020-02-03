package com.ssafy.ccw;

import java.util.LinkedList;
import java.util.Scanner;

public class Solution_¿ä¸®»ç {
	static int arr[][];
	static int num;
	static boolean check[];
	static int result;
	static void dfs(int cnt, int idx) {
		if(cnt==num/2) {
			int aIdx=0;
			int bIdx=0;
			int a[] = new int[num/2];
			int b[] = new int[num/2];
			for(int i=0;i<num;i++) {
				if(!check[i]) 	a[aIdx++]=i;
				else b[bIdx++]=i;
			}
			int a_sum=0;
			int b_sum=0;
			for(int i=0;i<cnt;i++) {
				for(int j=0;j<cnt;j++) {
					if(i==j) continue;
					else {
						a_sum+=arr[a[i]][a[j]];
						b_sum+=arr[b[i]][b[j]];					
					}
				}
			}
			if(result >Math.abs(a_sum-b_sum))
				result = Math.abs(a_sum-b_sum);
			return;
		}
		for(int i=idx;i<num;i++) {
			if(!check[i]) {
				check[i]=true;
				dfs(cnt+1,i);
				check[i]=false;
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test=sc.nextInt();
		for(int t=1;t<=test;t++) {
			num = sc.nextInt();
			arr = new int[num][num];
			check = new boolean[num];
			for(int i=0;i<num;i++)
				check[i]=false;
			result = Integer.MAX_VALUE;
			
			for(int i=0;i<num;i++)
				for(int j=0;j<num;j++)
					arr[i][j]=sc.nextInt();
			dfs(0,0);
			System.out.println("#"+t+" "+result);
		}
		sc.close();
	}
}