// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int cnt=0,r=n+1,l=0,ru=n+1,rd=0,ld=0,lu=n+1,u=n+1,d=0;      //대각선은 y기준
    for(int i=0;i<obstacles.size();i++){
        int y = obstacles[i][0];
        int x = obstacles[i][1];
        if(y==r_q){     //높이가 같은 경우
            if(x>c_q)       //오른쪽
                r = min(r, x);
            else
                l = max(l, x);
        }
        else if(x==c_q){        //세로가 같은경우
            if(y>r_q)   //위
                u = min(u,y);
            else        //아래
                d = max(d, y);
        }
        else if(r_q + c_q==x+y){        //11->5시 방향
            if(y>r_q)       //11시
                lu = min(lu, y);
            else
                rd = max(rd, y);
        }
        else if(r_q - c_q == y - x){        //1 -> 7시 방향
            if(y>r_q)       //1시
                ru = min(ru, y);
            else
                ld = max(ld, y);
        }
    }
    //가로
    cnt += (r - c_q - 1);
    cnt += (c_q - l - 1);
    //세로
    cnt += (u - r_q - 1);
    cnt += (r_q - d - 1);
    //대각선
    
    cnt += min(c_q - 1, lu - r_q - 1);
    cnt += min(c_q - 1, r_q - ld - 1);
    cnt += min(n - c_q, r_q - rd - 1);    
    cnt += min(n - c_q, ru - r_q - 1);
    return cnt;
}
