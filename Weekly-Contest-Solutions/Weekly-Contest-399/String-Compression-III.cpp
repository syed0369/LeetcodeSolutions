class Solution {
public:
    string compressedString(string word) {
        int i, j;
        int count;
        string compressed;
        i = j = count = 0;
        compressed = "";
        while(j < word.size()){
            count = 0;
            while(j < word.size() && word[i] == word[j] && count < 9){
                j++;
                count++;
            }
            compressed += to_string(count) + word[i];
            i = j;
        }
        return compressed;
    }
};
