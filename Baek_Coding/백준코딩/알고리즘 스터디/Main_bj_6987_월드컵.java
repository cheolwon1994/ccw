import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main_bj_6987_������ {
	static int win[],lose[],draw[],t1[],t2[];
	static HashMap<String, String> map;
	static boolean avail;
	
	static void dfs(int idx) {
		if(avail) return;
		if(idx==15) {
			avail=true;
			return;
		}
		int a = t1[idx];
		int b= t2[idx];
		//a�� �̱�� ���
		if(win[a]>0 && lose[b]>0) {
			win[a]--;
			lose[b]--;
			dfs(idx+1);
			win[a]++;
			lose[b]++;
		}
		//a�� b�� ���� ���
		if(draw[a]>0 && draw[b]>0) {
			draw[a]--;
			draw[b]--;
			dfs(idx+1);
			draw[a]++;
			draw[b]++;
		}
		//a�� ���� ���
		if(lose[a]>0 && win[b]>0) {
			lose[a]--;
			win[b]--;
			dfs(idx+1);
			lose[a]++;
			win[b]++;
		}
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cnt=0;
		t1 = new int[15];		//����ϴ� 2��
		t2 = new int[15];
		for(int i=0;i<5;i++) {
			for(int j=i+1;j<6;j++) {
				t1[cnt]=i;
				t2[cnt++]=j;
			}
		}
		for(int i=0;i<4;i++) {
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			win = new int[6];		
			lose = new int[6];		
			draw = new int[6];	
			avail=false;			
			int w=0,l=0,d=0;
			for(int j=0;j<6;j++) {
				w += win[j] = Integer.parseInt(st.nextToken());
				d += draw[j] = Integer.parseInt(st.nextToken());
				l += lose[j] = Integer.parseInt(st.nextToken());
			}
			if(w+d+l!=30)
				avail=false;
			else
				dfs(0);
			if(avail) System.out.print(1+" ");
			else System.out.print(0+" ");
		}
	}
}