int minimumSwaps(vector<int> arr) {
    int cnt=0;
    for(int i=0;i<arr.size()-1;i++){
        int num = arr[i];
        if(i==num-1) continue;
        int a = arr[num-1];
        arr[num-1] = num;
        arr[i] = a;
        cnt++;
        i--;
    }
    return cnt;
}