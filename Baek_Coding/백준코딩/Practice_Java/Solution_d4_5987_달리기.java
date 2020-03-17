import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_5987_�޸��� {
	static int node,edge;
	static long dp[],li[];		//16�ڸ��� 2������ �ٲ㼭 ���� �ִ� 2^17, �ش� ������ �������� � �������� ���η� ���� �־������
	
	static long dfs(int idx) {		// ���ݱ��� ���� ���Ӵ���
		if(idx==(1<<(node+1))-2) return 1;
		if(dp[idx]!=0) return dp[idx];
		
		for(int i=1;i<=node;i++) {
			if((idx & 1<<i)>0)		//�̹� �ش� ������ ���� ���
				continue;
			if((idx & li[i])!=li[i]) continue;		//���η� ���;��ϴ� �������� ���� �� ������ ���� ���
			dp[idx]+=dfs(idx|1<<i);
		}
		return dp[idx];
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			node = Integer.parseInt(st.nextToken());
			edge = Integer.parseInt(st.nextToken());
			//�ʱ�ȭ
			li = new long[node+1];
			dp = new long[1<<(node+1)];
			
			int start,end;
			for(int i=0;i<edge;i++) {
				String str = br.readLine();
				StringTokenizer st2 = new StringTokenizer(str);
				start = Integer.parseInt(st2.nextToken());
				end = Integer.parseInt(st2.nextToken());
				li[end] = li[end]|1<<start;		//���ο� �־���ϴ� ������
			}				
			System.out.println("#"+t+" "+dfs(0));
		}	
	}
}