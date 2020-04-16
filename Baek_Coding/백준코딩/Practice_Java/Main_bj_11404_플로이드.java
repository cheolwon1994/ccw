import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_bj_11404_플로이드 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int node = Integer.parseInt(br.readLine().trim());
		int edge = Integer.parseInt(br.readLine().trim());
		int arr[][] = new int[node+1][node+1];
		for(int i=1;i<=node;i++)
			for(int j=1;j<=node;j++) {
				arr[i][j]=Integer.MAX_VALUE/10;
				if(i==j) arr[i][j]=0;
			}
		for(int t=0;t<edge;t++) {
			String s =br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int val = Integer.parseInt(st.nextToken());
			arr[start][end] = Math.min(arr[start][end], val);
		}
		for(int k=1;k<=node;k++) {
			for(int i=1;i<=node;i++) {
				for(int j=1;j<=node;j++)
					arr[i][j]=Math.min(arr[i][j], arr[i][k]+arr[k][j]);
			}
		}
		for(int i=1;i<=node;i++) {
			for(int j=1;j<=node;j++) {
				if(arr[i][j]==Integer.MAX_VALUE/10)
					System.out.print(0+" ");
				else 
					System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}
}