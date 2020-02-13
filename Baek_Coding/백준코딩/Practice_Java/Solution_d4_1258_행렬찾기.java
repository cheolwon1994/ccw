package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Info{
	int x,y;
	public Info(int y, int x) {
		this.y=y;
		this.x=x;
	}
}
class Arr implements Comparable<Arr>{
	int row,col;
	public Arr(int row, int col) {
		this.row=row;
		this.col=col;
	}
	@Override
	public int compareTo(Arr o) {
		int tt=this.row*this.col;
		if(tt==o.row*o.col)
			return Integer.compare(this.row,o.row);
		return Integer.compare(tt, o.row*o.col);
	}
}

public class Solution_d4_1258_행렬찾기 {
	static int arr[][];
	static boolean check[][];
	static int num;
	final static int dx[]= {1,0};
	final static int dy[]= {0,1};
	static ArrayList<Arr> ans; 
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		for(int t=1;t<=test;t++) {
			num = Integer.parseInt(br.readLine());
			
			//초기화
			arr = new int[num][num];
			check = new boolean[num][num];
			ans = new ArrayList<Arr>();
			
			for(int i=0;i<num;i++) {
				String str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				for(int j=0;j<num;j++) 
					arr[i][j]=Integer.parseInt(st.nextToken());	
			}
			for(int i=0;i<num;i++) {
				for(int j=0;j<num;j++) {
					if(arr[i][j]!=0 && !check[i][j]) {
						int mi=1,mj=1;
						Queue<Info> q = new LinkedList<Info>();
						q.add(new Info(i,j));
						check[i][j]=true;
						while(!q.isEmpty()) {
							int cx=q.peek().x;
							int cy=q.peek().y;
							if(mi<cy-i+1)	mi=cy-i+1;
							if(mj<cx-j+1)	mj=cx-j+1;
							q.poll();
							for(int k=0;k<2;k++) {
								int nx=cx+dx[k];
								int ny=cy+dy[k];
								if(nx>=0 && ny>=0 && nx<num && ny<num && !check[ny][nx] && arr[ny][nx]!=0) {
									check[ny][nx]=true;
									q.add(new Info(ny,nx));
								}
							}
						}
						ans.add(new Arr(mi,mj));
					}
				}
			}		
			Collections.sort(ans);
			System.out.print("#"+t+" "+ans.size());
			for(int i=0;i<ans.size();i++)
				System.out.print(" "+ans.get(i).row + " "+ans.get(i).col);
			System.out.println();
		}
	}
}