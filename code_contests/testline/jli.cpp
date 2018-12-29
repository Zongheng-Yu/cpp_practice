Solution.cpp
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char inputstr[1000], teststr1[1000], teststr2[1000];
int inputp;
int testlinenum, usernum;

const int maxlen = 1024 + 5;
vector<vector<int>> map;
long long dp[20][maxlen];

bool getParam(char *infilename){
    FILE *f;
    f = fopen(infilename, "r");
    fscanf(f, "%d%*[^0-9]%d%*[^0-9]", &testlinenum, &usernum);

    map.resize(testlinenum);
    for(int i = 0; i < testlinenum; i++)
        map.clear();
    for(int i = 0; i < usernum; i++){
        fscanf(f, "%[^\n]\n", inputstr);
        inputp = 0;
        int id;
        while(inputp < strlen(inputstr)){
            sscanf((inputstr + inputp), "%d%*[, ]", &id);
            map[id - 1].push_back(i);
            sscanf((inputstr + inputp), "%[0-9]%[, ]", teststr1, teststr2);
            inputp += strlen(teststr1) + strlen(teststr2);
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("there are incorrect income file.\n");
        return 1;
    }

    if(!getParam(argv[1])){
        printf("there are incorrect income param.\n");
        return 2;
    }

    if(usernum == 0){
        printf("0\n");
        return 0;
    }

    int len = 1 << usernum;
    for(int i = 0; i < testlinenum; i++)
        for(int j = 0; j < len; j++)
            dp[i][j] = 0;

    dp[0][0] = 1;
    for(int i = 0; i < map[0].size(); i++)
        dp[0][1 << map[0][i]] = 1;

    for(int i = 1; i < testlinenum; i++)
        for(int j = 0; j < len; j ++)
        {
            dp[i][j] += dp[i - 1][j];
            for(int k = 0; k < map[i].size(); k++){
                if((j & (1 << map[i][k])) == 0)
                    continue;
                int frontid = j - (1 << map[i][k]);
                dp[i][j] += dp[i - 1][frontid];
            }
        }

    long long ans = dp[testlinenum - 1][len - 1];
    printf("%lld\n", ans);
}