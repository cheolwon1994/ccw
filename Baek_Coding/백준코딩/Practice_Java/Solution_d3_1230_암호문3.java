package list;
import java.util.LinkedList;
import java.util.Scanner;

public class Solution_d3_1230 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		for(int t=1;t<=10;t++) {
			int l =sc.nextInt();
			LinkedList<String> li = new LinkedList<>();
			for(int i=0;i<l;i++) {
				int temp = sc.nextInt();
				li.addLast(String.valueOf(temp));
			}
			int op = sc.nextInt();
			for(int i=0;i<op;i++) {
				char c = sc.next().charAt(0);
				int idx = sc.nextInt();
				if(c=='I') {
					int ll = sc.nextInt();
					for(int j=0;j<ll;j++) {
						int k = sc.nextInt();
						li.add(idx+j,String.valueOf(k));
					}
				}
				else if(c=='D') {
					int ll = sc.nextInt();
					for(int k=0;k<ll;k++)
						li.remove(idx);
				}
				else if(c=='A') {
					for(int j=0;j<idx;j++) {
						int k = sc.nextInt();
						li.addLast(String.valueOf(k));
					}
				}
			}
			System.out.print("#"+t+" ");
			for(int i=0;i<10;i++)
				System.out.print(li.get(i)+" ");
			System.out.println();
		}
	}
}