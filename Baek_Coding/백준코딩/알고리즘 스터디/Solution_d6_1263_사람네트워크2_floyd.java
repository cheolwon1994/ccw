import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution_d6_1263_사람네트워크2_floyd {
	static int arr[][];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int num = Integer.parseInt(st.nextToken());
			int result = Integer.MAX_VALUE;
			//초기화
			arr = new int[num][num];
			
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					int val =Integer.parseInt(st.nextToken());
					arr[i][j]=val;
					if(arr[i][j]==0 && i!=j)
						arr[i][j]=987654321;
				}
			}
			for(int k=0;k<num;k++) 
				for(int i=0;i<num;i++) 
					for(int j=0;j<num;j++) 
						arr[i][j] = Math.min(arr[i][j], arr[i][k]+arr[k][j]);
			for(int k=0;k<num;k++) {
				int temp=0;
				for(int i=0;i<num;i++) 
					temp+=arr[k][i];
				result = Math.min(result,temp);
			}
			System.out.println("#"+t+" "+result);
		}
	}
}