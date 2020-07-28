import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int arr[][];
	static int l[], r[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine().trim());

		// √ ±‚»≠
		arr = new int[n + 1][n + 1];
		l = new int[n + 1];
		r = new int[n + 1];
		for (int i = 1; i < n; i++)
			for (int j = i; j <= n; j++) {
				if (i == j)
					arr[i][j] = 0;
				else {
					arr[i][j] = 987654321;
					arr[j][i] = 987654321;
				}
			}

		for (int i = 1; i <= n; i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			l[i] = Integer.parseInt(st.nextToken());
			r[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				if ((l[i] <= l[j] && l[j] <= r[i]) || (l[i] <= r[j] && r[j] <= r[i])
						||(l[j] <= l[i] && l[i] <= r[j]) || (l[j] <= r[i] && r[i] <= r[j])) {
					arr[i][j] = 1;
					arr[j][i] = 1;
				}

		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];

		int query = Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < query; i++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			System.out.println(arr[a][b] == 987654321 ? -1 : arr[a][b]);
		}
	}
}