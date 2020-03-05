import java.util.Scanner;

public class Solution_d4_4796_의석이의우뚝선산 {
	static int num;
	static long arr[];
	static int high[];
	static int low[];
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int test =sc.nextInt();
		for(int t=1;t<=test;t++) {
			num = sc.nextInt();
			//초기화
			arr = new long[num+1];
			high = new int[num+1];
			low = new int[num+1];
			
			int hidx=0,lidx=0;
			for(int i=1;i<=num;i++) 
				arr[i]=sc.nextLong();
			if(arr[1]<arr[2]) low[lidx++]=1;		//왼쪽 끝 부분
			for(int i=2;i<=num;i++) {
				if(i==num) {
					if(arr[i-1]>arr[i])	//오른쪽 끝부분
						low[lidx++]=i;	
					 continue;
				}
				if(arr[i-1] < arr[i] && arr[i]>arr[i+1]) high[hidx++]=i;	//봉우리
				else if(arr[i-1]> arr[i] && arr[i] < arr[i+1]) low[lidx++]=i;	//낮은 부분
			}		
			int l=0,h=0;
			int result=0;
			while(l<lidx && h<hidx) {
				if(high[h] < low[l]) h++;		//시작이 내려오면서 시작하는경우
				else {
					int tt=high[h]-low[l];
					tt*=(low[l+1]-high[h]);
					l++; h++;
					result+=tt;
				}
			}
			System.out.println("#"+t+" "+result);
		}
	}
}