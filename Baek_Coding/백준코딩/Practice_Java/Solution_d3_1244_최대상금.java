import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_d3_1244_최대상금 {
	static int num,len,change,result;
	static char arr[];
	static void start(int idx, int cnt) {
		if (cnt == change) { // 횟수만큼 다 바꾼 경우
			String s = new String(arr);
			int temp = Integer.parseInt(s);
			if(temp>result)
				result=temp;
			return;
		}
		if(idx+1==len-1) {		//이미 가장 크게 정렬되어 있는 경우
			boolean dup =false;
			int test[] = new int[10];
			for(int i=0;i<len;i++) {
				test[arr[i]-'0']++;
				if(test[arr[i]-'0']>1) {
					dup=true;
					break;
				}
			}
			if(dup) {
				String s = new String(arr);
				int temp = Integer.parseInt(s);
				if(temp>result)
					result=temp;
			}
			else {
				if((change-cnt)%2==1) {
					char c = arr[len-2];
					arr[len-2]=arr[len-1];
					arr[len-1]=c;
				}
				String s = new String(arr);
				int temp = Integer.parseInt(s);
				if(temp>result)
					result=temp;
			}
			return;
		}
		
		int maxi = 0;
		int ii = -1;
		for (int i = idx+1; i < len; i++)
			if (arr[i] - '0' > maxi) {
				maxi = arr[i] - '0';
				ii = i;
			}
		if (arr[idx]-'0' >=maxi)
			start(idx + 1,cnt); // 제일 큰값이 앞에 있는 경우
		else {
			for (int i = ii; i < len; i++) {
				if (arr[i] - '0' == maxi) {
					char c = arr[idx];
					arr[idx] = arr[i];
					arr[i]=c;
					start(idx+1,cnt+1);
					arr[i]=arr[idx];
					arr[idx]=c;
				}
			}
		}

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			result=-1;
			len=0;
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			String ss = st.nextToken();		
			len =ss.length();
			arr = new char[len];
			change = Integer.parseInt(st.nextToken());
			for(int i=0;i<len;i++)
				arr[i]=ss.charAt(i);
			start(0, 0);
			System.out.println("#"+t+" "+result);
		}
	}
}