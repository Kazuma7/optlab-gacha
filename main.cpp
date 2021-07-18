#include <iostream>
#include <vector>
using namespace std;

void csvload(char filename[], vector<double> &ItemNum, vector<string> &ItemName, vector<double> &ItemWeight){
    int i;
    int j = 0;
    char c[10000];
    char *c1;
    char *ends;
    char s[] = " ,\n"; //カンマ、スペース、改行

    /*ファイルオープン*/
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL){
        printf("Can't open file.\n");
        abort();
    }

    //1行分を文字列としてcに読み込む
    while ((fgets(c, sizeof(c), fp)) != NULL){
        //c1にカンマ、スペース、改行で区切った文字列を代入
        c1 = strtok(c, s);
        j=0;
        while (c1 != NULL){

            if(j==0){
                ItemNum.push_back(strtod(c1, &ends));
            }
            else if(j==1){
                ItemName.push_back(c1);
            }
            else if(j==2){
                ItemWeight.push_back(strtod(c1, &ends));
            }
            j++;
            //NULL文字で終わり
            c1 = strtok(NULL, s);
        }
    }
    fclose(fp);
}

int main(){
    //アイテムの番号の配列
    vector<double> ItemNum;
    //アイテムの名前
    vector<string> ItemName;
    //アイテムの確率(重み)
    vector<double> ItemWeight;
    csvload("test.csv", ItemNum, ItemName, ItemWeight);
}