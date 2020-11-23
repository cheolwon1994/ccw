char arr[9][9];
// Complete the encryption function below.
string encryption(string s) {
    string str = "", result = "";
    int len = s.size();
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if ('a' <= c && c <= 'z') str += c;
    }
    len = str.size();
    int row, col;
    row = floor(sqrt(len));
    col = ceil(sqrt(len));
    if (row*col < len) row++;

    int cnt = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arr[i][j] = 'A';
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = str[cnt++];
            if (cnt == len) break;
        }
        if (cnt == len) break;
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (arr[j][i] == 'A') break;
            else result += arr[j][i];
        }
        result += " ";
    }
    return result;
}