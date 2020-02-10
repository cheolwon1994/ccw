import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Info {
	int idx, val;

	public Info(int idx, int val) {
		this.idx = idx;
		this.val = val;
	}
}

public class Solution {
	public static void main(String[] args) {
		Queue<Info> q = new LinkedList<>();
		boolean check[] = new boolean[100001];
		Scanner sc = new Scanner(System.in);
		int start = sc.nextInt();
		int end = sc.nextInt();
		Info tmp = new Info(start, 0);
		q.add(tmp);
		int cnt = 0;
		int result=0;
		while (cnt == 0) {
			int len = q.size();
			for (int i = 0; i < len; i++) {
				int cidx = q.peek().idx;
				int cv = q.peek().val;
				q.poll();
				check[cidx]=true;
				if(cidx==end) {
					cnt++;
					result = cv;
					continue;
				}
				if(cidx-1>=0 && !check[cidx-1]) 	q.add(new Info(cidx-1,cv+1));
				if(cidx+1<=100000 && !check[cidx+1]) 	q.add(new Info(cidx+1,cv+1));
				if(2*cidx<=100000 && !check[2*cidx]) 	q.add(new Info(2*cidx,cv+1));
			}
		}
		System.out.print(result +"\n"+cnt);
		sc.close();
	}

}