vector<int> rotLeft(vector<int> a, int d) {
    int num = a.size();
    vector<int> v(num);
    for(int i=0;i<num;i++){
        int newLoc = i-d;
        if(newLoc<0) newLoc +=num;
        v[newLoc] = a[i];
    }
    return v;
}