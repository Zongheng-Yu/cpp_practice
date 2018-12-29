#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct UserData
{
    int test_line_num;
    int test_line[20];
};

int user_num = 0;
bool test_line_occupation[20];
UserData users[10];
int solution_num = 0;

void parse_input_file(const char* filename)
{
    ifstream fin(filename);
    string line, field;

    getline(fin, line);
    istringstream sin(line);
    getline(sin, field, ',');
    getline(sin, field, ',');
    user_num =stoi(field);
    for (int i = 0; i < user_num; i++)
    {
        getline(fin, line);
        sin = istringstream(line);
        int j = 0;
        while(getline(sin, field, ','))
        {
            users[i].test_line[j] = stoi(field) - 1;
            j++;
        }
        users[i].test_line_num = j;
    }
}


void search_solution(int depth)
{
    if (depth == user_num)
    {
        solution_num++;
        return;
    }

    for(int i = 0; i < users[depth].test_line_num; i++)
    {
        int test_line = users[depth].test_line[i];
        if (! test_line_occupation[test_line])
        {
            test_line_occupation[test_line] = true;
            search_solution(depth+1);
            test_line_occupation[test_line] = false;
        }
    }
}


int main(int argc, char* argv[])
{
    parse_input_file(argv[1]);
    search_solution(0);
    cout << solution_num << endl;
    return 0;
}
