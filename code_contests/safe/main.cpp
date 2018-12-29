#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Item
{
    int index;
    int value;
    bool choose = false;
    vector<int> dependencies;
};

int item_num = 0;
vector<int> features;
vector<Item> items;
int max_value = 0;
using Result = set<int>;
Result result;
Result tmp_result;

void parse_input_file(const char* filename)
{
    ifstream fin(filename);
    string line, field;

    getline(fin, line);
    istringstream sin(line);
    item_num =stoi(line);
    items.emplace_back(Item());
    for (int i = 0; i < item_num; i++)
    {
        Item item;
        item.index = i + 1;
        getline(fin, line);
        sin = istringstream(line);
        getline(sin, field, ' ');
        item.value = stoi(field);
        while(getline(sin, field, ' '))
        {
            item.dependencies.emplace_back(stoi(field));
        }
        if (item.value > 0)
        {
            features.emplace_back(item.index);
        }
        items.emplace_back(item);
    }
}

void add_dependency(int i)
{
    queue<int> q;
    q.emplace(i);
    unsigned int count = 0;
    while (q.size() > 0)
    {
        count++;
        int index = q.front();
        for (int each: items[index].dependencies)
        {
            if (tmp_result.find(each) == tmp_result.end())
            {
                tmp_result.insert(each);
                q.emplace(each);
            }
        }
        q.pop();
        if (count > items.size())
        {
            break;
        }
    }
}

int calculate_tmp_result()
{
    int value = 0;
    for (const int each: tmp_result)
    {
        value += items[each].value;
    }
    return value;
}

void update_result()
{
    tmp_result.clear();
    for (int i: features)
    {
        if (items[i].choose)
        {
            if (tmp_result.find(i) == tmp_result.end())
            {
                tmp_result.insert(i);
                add_dependency(i);
            }
        }
    }
    int tmp_value = calculate_tmp_result();
    if (tmp_value > max_value || (tmp_value == max_value && tmp_result.size() < result.size()))
    {
        max_value = tmp_value;
        result = tmp_result;
    }
}

void search_solution(unsigned int depth)
{
    if (depth == features.size())
    {
        update_result();
        return;
    }
    items[features[depth]].choose = false;
    search_solution(depth+1);
    items[features[depth]].choose = true;
    search_solution(depth+1);
}

int main(int argc, char* argv[])
{
    parse_input_file(argv[1]);
    search_solution(0);
    cout << max_value << endl;
    for (const int index: result)
    {
        cout << index << endl;
    }
    return 0;
}
