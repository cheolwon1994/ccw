import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_d4_6719_성수의프로그래밍강좌시청 {
	static int n,k;
	static int arr[];
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			//초기화
			arr = new int[n];
			String str = br.readLine();
			StringTokenizer st2 = new StringTokenizer(str);
			for(int i=0;i<n;i++) {
				int val = Integer.parseInt(st2.nextToken());
				arr[i]=val;
			}
			Arrays.sort(arr);
			float result=0;
			for(int i=n-k;i<n;i++) {
				result+=arr[i];
				result/=2;
			}
			String ss = String.format("%.6f", result);
			System.out.println("#"+t+" "+ss);
		}
	}
}