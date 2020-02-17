package ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution_d2_1970_쉬운거스름돈 {
	static int payment[];
	final static int bill[] = {50000,10000,5000,1000,500,100,50,10};
	static int num;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			payment = new int[8];
			num = Integer.parseInt(br.readLine());
			for(int i=0;i<8;i++) {
				int tt = num/bill[i];
				payment[i] = tt;
				num-=tt*bill[i];
			}
			System.out.println("#"+t);
			for(int i=0;i<8;i++)
				System.out.print(payment[i]+" ");
			System.out.println();
		}
	}
}
