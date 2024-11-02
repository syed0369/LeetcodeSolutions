class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i, n;
        sentence += " ";
        n = sentence.size();
        for(i = 0; i < n; i++) {
            if(sentence[i] == ' ')
                if(sentence[(i + 1) % n] != sentence[i - 1])
                    return false;
        }
        return true;
    }
};
