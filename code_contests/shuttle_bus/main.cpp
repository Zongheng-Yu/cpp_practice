#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;
int row_num = 0;
int column_num = 0;

void parse_input_file(const char* filename)
{
    ifstream fin(filename);
    string line, field;

    getline(fin, line);
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {

            field = line.substr(0, i);
            column_num = stoi(field);
            field = line.substr(i+2);
            row_num =stoi(field);
            break;
        }
    }
    for (int i = 0; i < row_num; i++)
    {
        matrix.emplace_back(vector<int>{});
        getline(fin, line);
        for (unsigned int j = 0, pos = 0; j <= line.length(); j++)
        {
            if (line[j] == ',' || j == line.length())
            {
                field = line.substr(pos, j - pos);
                pos = j + 2;
                j++;
                matrix[i].emplace_back(stoi(field));
            }
        }
    }
}


int main(int argc, char* argv[])
{
    parse_input_file(argv[1]);

    for (int i = 1; i < row_num; i++)
    {
        matrix[i][0] += matrix[i-1][0];
    }
    for (int i = 1; i < column_num; i++)
    {
        matrix[0][i] += matrix[0][i-1];
    }
    for (int i = 1; i < row_num; i++)
    {
        for (int j = 1; j < column_num; j++)
        {
            if (matrix[i-1][j] > matrix[i][j-1])
            {
                matrix[i][j] += matrix[i-1][j];
            } else
            {
                matrix[i][j] += matrix[i][j-1];
            }

        }
    }
    cout << matrix[row_num-1][column_num-1] << endl;
    return 0;
}
