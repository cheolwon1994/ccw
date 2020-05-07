import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Jungol_1681_해밀턴순환회로 {
	static int arr[][],num,result;
	static boolean visit[];
	static List<Integer> li;
	static void TSP(int sum, int now) {
		for(int i=1;i<=num;i++) {
			if(visit[i] || arr[now][i]==0) continue;
			visit[i]=true;			
//			li.add(i);
			TSP(sum+arr[now][i],i);
			visit[i]=false;
//			li.remove(li.size()-1);
		}
		boolean finish=true;
		for(int i=1;i<=num;i++)
			if(!visit[i]) {
				finish=false;
				break;
			}
		if(finish && arr[now][1]!=0) 
			result = Math.min(result, sum+arr[now][1]);
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		num = Integer.parseInt(br.readLine().trim());
		arr = new int[num+1][num+1];
		visit = new boolean[num+1];
		li = new ArrayList<Integer>();
		result = Integer.MAX_VALUE;
		for(int i=1;i<=num;i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			for(int j=1;j<=num;j++) 
				arr[i][j] = Integer.parseInt(st.nextToken());
		}
		visit[1]=true;
//		li.add(1);
		TSP(0,1);
		System.out.println(result);
	}
}