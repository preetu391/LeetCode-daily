#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int students_count = students.size(), cir = 0, squ = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
                cir++;
            else
                squ++;
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0)
            {
                if (cir > 0)
                {
                    cir--;
                    students_count--;
                }
                else
                {
                    return students_count;
                }
            }
            else
            {
                if (squ > 0)
                {
                    squ--;
                    students_count--;
                }
                else
                {
                    return students_count;
                }
            }
        }
        return 0;
    }
};