import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_bj_2579_계단오르기 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine().trim());
		int arr[] = new int[num + 1];
		int dp[] = new int[num + 1];
		for (int i = 1; i <= num; i++) {
			int val = Integer.parseInt(br.readLine().trim());
			arr[i] = val;
		}
		if (num == 1)
			System.out.println(arr[1]);
		else {
			dp[1] = arr[1];
			dp[2] = arr[1] + arr[2];
			for (int i = 3; i <= num; i++)
				dp[i] = Math.max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
			System.out.println(dp[num]);
		}
	}
}