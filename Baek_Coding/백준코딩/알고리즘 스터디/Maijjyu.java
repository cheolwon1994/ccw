import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution_마이쮸 {

	static int num[] = new int[20];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 20; i++)
			num[i] = 1;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(1);
		int maijjiu = 20;
		int result = -1;
		while (maijjiu > 0) {
			for (int k = 2;; k++) {
				sc.nextLine();
				System.out.println("큐에 있는 사람의 수: " + q.size());
				for (int i = 1; i <= q.size(); i++)
					System.out.println(i + "번째 사람은: " + num[i] + "개 받을 예정");
				System.out.println("나눠준 사탕 수: " + (20 - maijjiu));
				
				int tt = q.poll();
				
				maijjiu-=num[tt];
				if(maijjiu<=0) {
					result=tt;
					break;
				}
				num[tt]++;
				q.add(tt);
				q.add(k);			
			}
		}
		System.out.println();
		System.out.println("마지막 사탕을 가져가는 사람: " + result);
	}
}