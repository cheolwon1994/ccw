import java.util.Scanner;

public class Solution_d4_4796_�Ǽ����ǿ�Ҽ��� {
	static int num;
	static long arr[];
	static int high[];
	static int low[];
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int test =sc.nextInt();
		for(int t=1;t<=test;t++) {
			num = sc.nextInt();
			//�ʱ�ȭ
			arr = new long[num+1];
			high = new int[num+1];
			low = new int[num+1];
			
			int hidx=0,lidx=0;
			for(int i=1;i<=num;i++) 
				arr[i]=sc.nextLong();
			if(arr[1]<arr[2]) low[lidx++]=1;		//���� �� �κ�
			for(int i=2;i<=num;i++) {
				if(i==num) {
					if(arr[i-1]>arr[i])	//������ ���κ�
						low[lidx++]=i;	
					 continue;
				}
				if(arr[i-1] < arr[i] && arr[i]>arr[i+1]) high[hidx++]=i;	//���츮
				else if(arr[i-1]> arr[i] && arr[i] < arr[i+1]) low[lidx++]=i;	//���� �κ�
			}		
			int l=0,h=0;
			int result=0;
			while(l<lidx && h<hidx) {
				if(high[h] < low[l]) h++;		//������ �������鼭 �����ϴ°��
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