import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_d4_4050_Àç°üÀÌÀÇ´ë·®ÇÒÀÎ {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test= Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			int num = Integer.parseInt(br.readLine().trim());
			int arr[] = new int[num];
			int rev[] = new int[num];
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			for(int i=0;i<num;i++) {
				int val = Integer.parseInt(st.nextToken());
				arr[i]=val;
			}
			Arrays.sort(arr);
			
			long result=0;
			if(num<3) {
				for(int i=0;i<num;i++)
					result+=arr[i];
			}
			else {
				int mod = num/3;
				int remain = num%3;
				int cnt=0;
				for(int i=num-1;i>=0;i--) 
					rev[cnt++]=arr[i];
				for(int i=0;i<mod;i++) 
					result+=(rev[3*i]+rev[3*i+1]);
				if(remain!=0) 
					for(int i=0;i<remain;i++)
						result+=arr[i];
			}
			System.out.println("#"+t+" "+result);
		}
	}
}
