package ws0213;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_d3_1873_상호의배틀필드 {
	static char arr[][];
	static int row,col;
	static int sx,sy,dir;
	static String command;
	final static int dx[]= {0,1,0,-1};
	final static int dy[]= {-1,0,1,0};
	
	static void start(int idx) {
		if(idx==command.length()) {	
			char tank;
			if(dir==0) tank='^';
			else if(dir==1) tank='>';
			else if(dir==2) tank='v';
			else tank='<';
			arr[sy][sx]=tank;
			return;
		}
		
		char c =command.charAt(idx);
		char pos= arr[sy][sx];
		int nx,ny;
		if(c=='U' ||c=='D' || c=='L' || c=='R') {
			if(c=='U')	dir=0;
			else if(c=='D') dir=2;
			else if(c=='L') dir=3;
			else if(c=='R') dir=1;
			nx=sx+dx[dir];
			ny=sy+dy[dir];
			if(nx>=0 && ny>=0 && nx<col && ny<row && arr[ny][nx]=='.') {
				sx=nx;
				sy=ny;
			}
			start(idx+1);			
		}
		else if(c=='S') {
			nx=sx; ny=sy;
			for(int i=0;;i++) {
				nx+=dx[dir];
				ny+=dy[dir];
				if(nx>=0 && ny>=0 &&nx<col && ny<row) {
					if(arr[ny][nx]=='*') {
						arr[ny][nx]='.';
						break;
					}
					else if(arr[ny][nx]=='#') 
						break;					
				}
				else	break;
			}
			start(idx+1);
		}		
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		
		for(int t=1;t<=test;t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			row = Integer.parseInt(st.nextToken());
			col = Integer.parseInt(st.nextToken());
			arr = new char[row][col];
			for(int i=0;i<row;i++) {
				String ss = br.readLine();
				for(int j=0;j<col;j++) {
					arr[i][j]=ss.charAt(j);
					if(arr[i][j]=='>') {	sx=j; sy=i; dir=1; arr[i][j]='.';}
					else if(arr[i][j]=='<') {	sx=j; sy=i; dir=3;arr[i][j]='.';}
					else if(arr[i][j]=='^') {	sx=j; sy=i; dir=0;arr[i][j]='.';}
					else if(arr[i][j]=='v') {	sx=j; sy=i; dir=2;arr[i][j]='.';}
				}
			}
			br.readLine();
			command = br.readLine();
			start(0);
			System.out.print("#"+t+" ");
			for(int i=0;i<row;i++) {
				for(int j=0;j<col;j++)
					System.out.print(arr[i][j]);
				System.out.println();
			}
		}
	}
}