import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_1231_중위순회 {
	static class Tree {
		class Node {
			char data;
			Node left, right;
		}
		Node root;

		public Node getRoot() {
			return root;
		}

		public void setRoot(Node root) {
			this.root = root;
		}

		public Node makeTree(Node left, char data, Node right) {
			Node node = new Node();
			node.left = left;
			node.data = data;
			node.right = right;
			return node;
		}

		public void inorder(Node node) {
			if (node != null) {
				inorder(node.left);
				System.out.print(node.data);
				inorder(node.right);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Tree t;
		Tree.Node[] tn;
		
		for (int k = 1; k <= 10; k++) {
			int num = Integer.parseInt(br.readLine());
			t = new Tree();
			tn = new Tree.Node[num+1];
			for(int i=1;i<=num;i++) 
				tn[i] = t.makeTree(null, ' ', null);
			for (int i = 1; i <= num; i++) {	
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				st.nextToken();
				char c = st.nextToken().charAt(0);
				tn[i].data=c;
				int l=-1,r=-1;
				while(st.hasMoreTokens()) {
					l = Integer.parseInt(st.nextToken());
					if(st.hasMoreTokens())
						r = Integer.parseInt(st.nextToken());
				}
				if(l!=-1 && r!=-1) {
					tn[i].left = tn[l];
					tn[i].right = tn[r];
				}
				else if(l!=-1 && r==-1)
					tn[i].left = tn[l];
			}
			System.out.print("#"+k+" ");
			t.inorder(tn[1]);
			System.out.println();
		}
	}
}