#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> spiral(m, vector<int>(n, -1));

        char dir = 'r';
        int lc = 0;
        int lr = 0;
        int hc = n - 1;
        int hr = m - 1;

        int i = 0;
        int j = 0;

        while (head != NULL)
        {
            spiral[i][j] = head->val;

            if(dir == 'r') {
                if(j < hc)
                    j++;
                else {
                    lr++;
                    i++;
                    dir = 'd';
                }
            } else if(dir == 'l') {
                if (j > lc)
                {
                    j--;
                }
                else
                {
                    hr--;
                    i--;
                    dir = 'u';
                }
            } else if(dir == 'd') {
                if (i < hr)
                    i++;
                else
                {
                    hc--;
                    j--;
                    dir = 'l';
                }
            } else if(dir == 'u') {
                if (i > lr)
                {
                    i--;
                }
                else
                {
                    lc++;
                    j++;
                    dir = 'r';
                }
            }

            head = head->next;
        }
        return spiral;
    }
};

int main()
{
    int m = 4;
    int n = 5;
    ListNode *one = new ListNode(3);
    ListNode *two = new ListNode(0);
    ListNode *three = new ListNode(2);
    ListNode *four = new ListNode(6);
    ListNode *five = new ListNode(8);
    ListNode *six = new ListNode(1);
    ListNode *seven = new ListNode(7);
    ListNode *eight = new ListNode(9);
    ListNode *nine = new ListNode(4);
    ListNode *ten = new ListNode(2);
    ListNode *eleven = new ListNode(5);
    ListNode *twelve = new ListNode(5);
    ListNode *thirteen = new ListNode(0);
    ListNode *fourteen = new ListNode(2);
    ListNode *fifteen = new ListNode(4);
    ListNode *sixteen = new ListNode(6);
    ListNode *seventeen = new ListNode(8);
    ListNode *eighteen = new ListNode(7);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = eleven;
    eleven->next = twelve;
    twelve->next = thirteen;
    thirteen->next = fourteen;
    fourteen->next = fifteen;
    fifteen->next = sixteen;
    sixteen->next = seventeen;
    seventeen->next = eighteen;

    ListNode *head = one;

    vector<vector<int>> spiral = Solution::spiralMatrix(m, n, head);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << spiral[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}