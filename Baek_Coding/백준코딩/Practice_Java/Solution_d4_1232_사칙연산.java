import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_1232_사칙연산_서울_06_최철원 {
	static int num;
	static class Tree {
		class Node {
			String data;
			Node left, right;
		}

		Node root;

		public Node getRoot() {
			return root;
		}

		public void setRoot(Node root) {
			this.root = root;
		}

		public Node makeTree(Node left, String data, Node right) {
			Node node = new Node();
			node.left = left;
			node.data = data;
			node.right = right;
			return node;
		}

		public int inorder(Node node) {
			if (node != null) {
				if(node.data.equals("-"))
					return inorder(node.left) - inorder(node.right);
				else if(node.data.equals("+"))
					return inorder(node.left) + inorder(node.right);
				else if(node.data.equals("*"))
					return inorder(node.left) * inorder(node.right);
				else if(node.data.equals("/"))
					return inorder(node.left) / inorder(node.right);
				else
					return Integer.parseInt(node.data);
//				System.out.print(node.data);
//				inorder(node.right);
			}
			return 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Tree t;
		Tree.Node[] tn;
		for (int test = 1; test <= 10; test++) {
			num = Integer.parseInt(br.readLine());
			int result=0;
			t = new Tree();
			tn = new Tree.Node[num + 1];
			for (int i = 1; i <= num; i++) {
				tn[i] = t.makeTree(null, " ", null);
			}
			for (int i = 1; i <= num; i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				st.nextToken();
				tn[i].data = st.nextToken();
				int l=-1,r=-1;
				if(st.hasMoreTokens())
					l= Integer.parseInt(st.nextToken());
				if(st.hasMoreTokens())
					r= Integer.parseInt(st.nextToken());
				if(l!=-1) {
					tn[i].left = tn[l];
					if(r!=-1)
						tn[i].right=tn[r];
				}
			}
			result = t.inorder(tn[1]);
			System.out.println("#"+test+" "+result);
		}
	}
}