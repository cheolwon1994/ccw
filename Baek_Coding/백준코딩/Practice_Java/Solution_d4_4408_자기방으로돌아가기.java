package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution_d4_4408_자기방으로돌아가기 {
	static int check[];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(System.in);
//		int test = Integer.parseInt(br.readLine());
		int test = sc.nextInt();
		for(int t=1;t<=test;t++) {
			check= new int[201];
//			int num = Integer.parseInt(br.readLine());
			int num = sc.nextInt();
			for(int i=0;i<num;i++) {
//				String str = br.readLine();
//				StringTokenizer st = new StringTokenizer(str);
//				int start = Integer.parseInt(st.nextToken());
//				int end = Integer.parseInt(st.nextToken());
				int start = sc.nextInt();
				int end = sc.nextInt();
				if(start%2==1) start+=1;
				if(end%2==1) end+=1;
				if(end<start) {
					int temp = start; start=end; end=temp;
				}
				start/=2;
				end/=2;
				for(int j=start;j<=end;j++)
					check[j]++;
			}
			int result=0;
			for(int i=1;i<201;i++)
				if(check[i]>result)
					result=check[i];
			System.out.println("#"+t+" "+result);
		}
	}
}