#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    static int uniqueMorseCode(vector<string> &words)
    {
        unordered_set<string> u;

        vector<string> codes{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        for (string w : words)
        {
            string codeWord = "";
            for (char c : w)
            {
                codeWord += codes[c - 'a'];
            }
            u.insert(codeWord);
        }

        return u.size();
    }
};

int main()
{
    vector<string> words{"gin", "zen", "gig", "msg"};

    cout << Solution::uniqueMorseCode(words);
    return 0;
}