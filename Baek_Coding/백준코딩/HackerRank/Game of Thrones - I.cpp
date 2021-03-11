int alpha[26];

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    for(int i=0;i<s.size();i++){
        char c = s[i];
        alpha[c-'a']++;
    }
    bool avail=true;
    bool odd = false;
    for(int i=0;i<26;i++){
        if(alpha[i]%2==1){
            if(odd) return "NO";
            else odd=true;
        }
    }
    return "YES";
}