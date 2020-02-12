import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_3289_서로소집합 {
	static int root[];
	static int find(int node) {
		if(root[node]==node) return node;
		else {
			int p = find(root[node]);
			root[node]=p;
			return p;
		}
	}
	
	static void uni(int parent, int child) {
		parent = find(parent);
		child = find(child);
		if(parent!=child)	root[child]=parent;		
	}
	
	static void check(int parent, int child) {
		int r_parent = find(parent);
		int r_child = find(child);
		if(r_parent==r_child) System.out.print(1);
		else System.out.print(0);
	}
	
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int num = Integer.parseInt(st.nextToken());
			int op = Integer.parseInt(st.nextToken());
			root = new int[num+1];
			for(int i=1;i<=num;i++)
				root[i]=i;
			System.out.print("#"+t+" ");
			for(int i=0;i<op;i++) {
				String ss = br.readLine();
				StringTokenizer st2 = new StringTokenizer(ss);
				int cmd = Integer.parseInt(st2.nextToken());
				int par = Integer.parseInt(st2.nextToken());
				int chi = Integer.parseInt(st2.nextToken());
				if(cmd==0) 	uni(par,chi);			
				else if(cmd==1) check(par,chi);
			}
			System.out.println();
		}
	}
}