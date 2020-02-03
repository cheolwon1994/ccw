package com.ssafy.ccw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_백준_오목_최철원 {
	static int arr[][];
	final static int dx[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
	final static int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	static boolean finish = false;
	static int rock, ty, tx;

	static void bfs(int y, int x) {
		int contin[] = { 1, 1, 1, 1 };
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x;
			ny = y;
			for (int j = 0; j < 5; j++) {
				nx += dx[i];
				ny += dy[i];
				if (nx > 0 && ny > 0 && nx < 20 && ny < 20) {
					if (arr[ny][nx] == arr[y][x])
						contin[i]++;
					else 	break;											
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			if (contin[i] == 5) {
				nx = x + dx[i + 4];
				ny = y + dy[i + 4];
				if (nx > 0 && ny > 0 && nx < 20 && nx < 20) {
					if (arr[ny][nx] == arr[y][x])
						break;
				}
				finish = true;
				ty = y;
				tx = x;
				rock = arr[y][x];
				break;				
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[20][20];
		for (int i = 1; i < 20; i++) {
			String str = br.readLine();
			int cnt = 1;
			for (int j = 0; j < str.length(); j += 2) {
				arr[i][cnt++] = str.charAt(j) - '0';
			}
		}

		for (int i = 1; i < 20; i++) {
			for (int j = 1; j < 20; j++)
				if (arr[i][j] != 0) {
					bfs(i, j);
					if (finish)
						break;
				}
			if (finish)
				break;
		}
		if (finish) {
			System.out.println(rock);
			System.out.print(ty + " " + tx);
		} else
			System.out.println(0);
	}
}