#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
int arr[20][20],dup[20][20],origin[60][60];
int m,n;

void rotate(){
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            dup[j][m-1-i] = arr[i][j];
    memcpy(arr,dup,sizeof(arr));    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int hole=0,cnt;
    m = key.size();
    n = lock.size();
    
    for(int i=m;i<n+m;i++)
        for(int j=m;j<n+m;j++){
            origin[i][j]=lock[i-m][j-m];
            if(lock[i-m][j-m]==0) 
                hole++;
        }        
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            arr[i][j]=key[i][j];
    bool finish=false;
    for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n + m; i++) {
			for (int j = 0; j < n + m; j++) {
				cnt = 0;
				for (int l = 0; l < m; l++) 
					for (int p = 0; p < m; p++) 
						if (arr[l][p] == 1) 
							if (m <= i + l && i + l < n + m && m <= j + p && j + p < n + m) {
                                if(origin[i + l][j + p] == 0)
								    cnt++;
                                else 
                                    cnt = -1;
                            }
				if (cnt == hole) {
					finish = true;
					break;
				}
			}
			if (finish) break;
		}
		if (finish) break;
		rotate();
	}
    answer = finish;
    return answer;
}