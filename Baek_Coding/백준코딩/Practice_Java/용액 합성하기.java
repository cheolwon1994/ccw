import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static long arr[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine().trim());
		arr = new long[num];
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		for (int i = 0; i < num; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		int low, mid, high;
		long ans=arr[0]+arr[1];
		boolean flag=false;
		for (int i = 0; i < num; i++) {
			long f = arr[i];
			low = i + 1;
			high = num - 1;
			while (low <= high) {
				mid = low + (high - low) / 2;
				long v = f+arr[mid];
				if (f + arr[mid] == 0) {
					ans = 0;
					flag = true;
					break;
				}
				if(Math.abs(ans) > Math.abs(v))	ans = v;
				else if(f+arr[mid]<0)	low = mid+1;
				else	high = mid-1;
			}
			if(flag==true) break;
		}
		System.out.println(ans);
	}
}