#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution 
{
    public:
        static int numUniqueEmails(vector<string>& emails) {
            unordered_set<string> unique;

            for(string email: emails) {
                int j = 0;
                string cleanEmail;
                while(email[j] != '@') {
                    if(email[j] == '+') break;
                    if(email[j] != '.') cleanEmail += email[j];
                    j++;
                }
                while(email[j] != '@') j++;
                while(email[j] != '\0') cleanEmail += email[j++];
                unique.insert(cleanEmail);
            }

            return unique.size();
        }
};

int main() {
    vector<string> emails{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << Solution::numUniqueEmails(emails);

    return 0;
}