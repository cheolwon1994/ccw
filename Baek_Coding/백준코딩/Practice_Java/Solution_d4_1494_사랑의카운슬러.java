import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_d4_1494_사랑의카운슬러 {
	static int num;
	static long result;
	static int x[];
	static int y[];
	static int a[]; // 0: +, 1: -
	
	public static void swap(int[] a, int i, int j) {
		int T=a[i]; a[i]=a[j]; a[j]=T;
	}
	
	public static boolean nextPermutation() {
		int i=a.length-2;
		for(;i>=0;i--) {
			if(a[i]<a[i+1]) break;
		}
		if(i<0) return false;
		
		int j=a.length-1;
		for(;j>i;j--)
			if(a[i]<a[j]) break;
		swap(a,i,j);
		for(int ii=i+1,jj=a.length-1;ii<jj;ii++,jj--) {
			swap(a,ii,jj);
		}
		return true;
	}
	
	static void cal() {
		long tx=0;
		long ty=0;
		for(int i=0;i<num;i++) {
			if(a[i]==0) {
				tx+=x[i];
				ty+=y[i];
			}
			else {
				tx-=x[i];
				ty-=y[i];
			}
		}
		long tt = tx*tx + ty*ty;
		if(result>tt)
			result=tt;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for (int t = 1; t <= test; t++) {
			num = Integer.parseInt(br.readLine());
			// 초기화
			result = Long.MAX_VALUE;
			x = new int[num];
			y = new int[num];
			a = new int[num];
			for (int i = 0; i < num; i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				x[i] = Integer.parseInt(st.nextToken());
				y[i] = Integer.parseInt(st.nextToken());
			}
			for (int i = 0; i < num / 2; i++)
				a[i] = 0;
			for (int i = num / 2; i < num; i++)
				a[i] = 1;

			do {
				cal();
			}while(nextPermutation());
			System.out.println("#"+t+" "+result);
		}
	}
}