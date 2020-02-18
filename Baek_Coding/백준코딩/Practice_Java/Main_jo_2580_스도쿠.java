import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2580_½ºµµÄí {
	static int arr[][] = new int[9][9];
	static boolean finish = false;
	static void backtrack(int y, int x) {
		if(finish) return;
		if(x==9) {
			x=0;
			y+=1;
		}
		if(y==9) {
			finish=true;
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++)
					System.out.print(arr[i][j]+" ");
				System.out.println();
			}
			return;
		}
		if(arr[y][x]!=0) backtrack(y,x+1);
		else {
			boolean test[]=new boolean[10];
			for(int i=0;i<9;i++) {
				test[arr[y][i]]=true;
				test[arr[i][x]]=true;
			}
			int ty = (y/3)*3;
			int tx = x/3;
			for(int i=0;i<9;i++) {
				for(int j=0;j<9;j++) {
					if((i/3)*3 == ty && j/3==tx) {
						test[arr[i][j]]=true;
					}
				}
			}
			for(int i=1;i<10;i++)
				if(!test[i]) {
					arr[y][x]=i;
					backtrack(y,x+1);
					arr[y][x]=0;
				}
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<9;i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			for(int j=0;j<9;j++) {
				int num = Integer.parseInt(st.nextToken());
				arr[i][j]=num;
			}
		}
		backtrack(0,0);
	}
}