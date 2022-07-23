#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution
{
public:
    static string decode(string key, string message)
    {
        unordered_map<char, char> map;
        char alp[]{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int i = 0;
        for (char k : key)
        {
            if (!isspace(k) && map.find(k) == map.end())
            {
                map.insert({k, alp[i]});
                i++;
            }
        }

        string result;
        for (char m : message)
        {
            if (m == ' ')
                result += ' ';
            else
                result += map[m];
        }

        return result;
    }
};

int main()
{
    string key = "eljuxhpwnyrdgtqkviszcfmabo";
    string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    cout << Solution::decode(key, message) << "\n";
    return 0;
}