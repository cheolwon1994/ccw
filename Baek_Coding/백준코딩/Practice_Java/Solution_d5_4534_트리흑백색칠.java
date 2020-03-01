import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_d5_4534_Æ®¸®Èæ¹é»öÄ¥ {
	final static long MOD = 1000000007;
	static int num;
	
	static class Node{
		ArrayList<Node> list;
		long white,black;
		boolean visit;
		public Node() {
			list = new ArrayList<Node>();
			white=1;
			black=1;
			visit=false;
		}
		public void cal() {
			this.visit=true;
			for(Node n : this.list) {
				if(!n.visit) {
					n.cal();
					this.white = this.white*(n.white+n.black)%MOD;
					this.black = this.black*(n.white)%MOD;
				}
			}
		}
	}
	static Node[] Tree;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			num = Integer.parseInt(br.readLine());
			int start,end;
			//ÃÊ±âÈ­
			Tree = new Node[num+1];
			for(int i=1;i<=num;i++)
				Tree[i] = new Node();
			
			for(int i=0;i<num-1;i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				start = Integer.parseInt(st.nextToken());
				end = Integer.parseInt(st.nextToken());
				Tree[start].list.add(Tree[end]);
				Tree[end].list.add(Tree[start]);
			}
			Tree[1].cal();
			System.out.print("#"+t+" "+(Tree[1].black + Tree[1].white)%MOD+'\n');
		}
	}
}