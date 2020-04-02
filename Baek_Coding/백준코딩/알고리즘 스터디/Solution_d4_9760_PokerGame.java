import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_d4_9760_PokerGame {
	static int number[],color[];		//1~13, 0:S, 1:D, 2:H, 3:C
	static boolean sflush,four,full,flush,straight,three,one;
	static int two;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=test;t++) {
			//초기화
			number = new int[14];
			color = new int[4];
			two=0;
			sflush=false; four=false; full = false; flush = false; straight = false; three = false; one = false;		
			
			String s = br.readLine();
			StringTokenizer st = new StringTokenizer(s);
			for(int i=0;i<5;i++) {
				String ss = st.nextToken();
				if(ss.charAt(0)=='S') color[0]++;
				else if(ss.charAt(0)=='D') color[1]++;
				else if(ss.charAt(0)=='H') color[2]++;
				else if(ss.charAt(0)=='C') color[3]++;
				
				char c = ss.charAt(1);
				if(c=='A')  number[1]++;
				else if(c=='T') number[10]++;
				else if(c=='J') number[11]++;
				else if(c=='Q') number[12]++;
				else if(c=='K') number[13]++;
				else number[c-'0']++;
			}
			//같은 무늬인지 확인
			for(int i=0;i<4;i++) {	
				if(color[i]==5) {
					flush=true;
					break;
				}
			}
			int contin=0;		//연속된 숫자의 갯수
			for(int i=1;i<=13;i++) {
				if(number[i]==1) 	contin++;
				else if(contin!=5 && number[i]!=1) contin=0;
				if(number[i]==4) four=true;		//포카드
				else if(number[i]==3) three=true;		//three카드
				else if(number[i]==2) two++;			//페어				
			}
			if(flush && contin!=5 && number[1]==1) {				
				for(int i=10;i<14;i++) {
					if(number[i]!=1) {
						contin=0;
						break;
					}
				}
			}
			String result;
			if(flush && contin==5) result = "Straight Flush";
			else if(four) result = "Four of a Kind";
			else if(three && two==1) result = "Full House";
			else if(flush) result = "Flush";
			else if(contin==5) result="Straight";
			else if(three) result = "Three of a kind";
			else if(two==2) result = "Two pair";
			else if(two==1) result = "One pair";
			else result = "High card";
			System.out.println("#"+t+" "+result);
		}
	}
}