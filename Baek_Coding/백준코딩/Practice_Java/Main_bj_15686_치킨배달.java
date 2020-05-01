import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main_bj_15686_치킨배달 {
	static class Info{
		int x,y;
		public Info(int y, int x) {
			this.y=y;
			this.x=x;
		}
	}
	static int num,limit,arr[][],result,check[],dist[][];
	static List<Info> li_one,li_two;
	static List<Integer> choose;
	
	static void cal() {
		for(int i=0;i<li_one.size();i++) {
			int cx=li_one.get(i).x;
			int cy=li_one.get(i).y;
			for(int j=0;j<li_two.size();j++) {
				int nx = li_two.get(j).x;
				int ny = li_two.get(j).y;
				int temp = Math.abs(nx-cx) + Math.abs(ny-cy);
				dist[j][i]=temp;
			}
		}
		
	}
	
	static void dfs(int cnt, int idx) {
		if(cnt==limit) {
			int t_result=0;
			//계산
			for(int i=0;i<li_one.size();i++) {
				int tt=Integer.MAX_VALUE;
				for(int j=0;j<choose.size();j++) 
					tt=Math.min(tt, dist[choose.get(j)][i]);
				t_result+=tt;
			}
			result = Math.min(result, t_result);
		}
		for(int i=idx;i<li_two.size();i++) {
			if(check[i]==1) continue;
			check[i]=1;
			choose.add(i);
			dfs(cnt+1,i+1);
			choose.remove(choose.size()-1);
			check[i]=0;
		}
	}
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		num = Integer.parseInt(st.nextToken());
		limit = Integer.parseInt(st.nextToken());
		arr = new int[num][num];
		dist = new int[1000][1000];
		check = new int[1000];
		li_one = new ArrayList<Info>();
		li_two = new ArrayList<Info>();
		result=Integer.MAX_VALUE;
		choose = new ArrayList<Integer>();
		
		for(int i=0;i<num;i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for(int j=0;j<num;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j]==1)
					li_one.add(new Info(i,j));
				else if(arr[i][j]==2)
					li_two.add(new Info(i,j));
			}
		}
		cal();
		dfs(0,0);
		System.out.println(result);
	}
}