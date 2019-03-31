
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
 
#define VK_W 119
#define VK_A 97
#define VK_S 115
#define VK_D 100
#define VK_Q 113
#define VK_M 109
#define VK_R 114
#define VK_N 110
 
void print_map(void);          //打印地图，并在地图上随机打印2或4方块
void move_up(void);
void move_right(void);
void move_down(void);
void move_left(void);
void swap(int *a, int *b);     //交换方块
bool game_over(void);         //游戏失败判定
void read_save(void);         //读取游戏存档
void save_data(void);         //保存游戏
void save_high_score(void);   //保存最高分
void read_high_score(void);   //读取最高分
void check_move(void);        //检查是否可以移动（将数组M导入临时数组temp中）
int  is_move(void);           //检查是否可以移动（比较M和temp数组，如果相同，则无法移动）
 
unsigned int M[4][4] = { 0 }, temp[4][4] = { 0 };          //M为棋盘
int score = 0, step = 0, high_score = 0, flag = 0;        //flag用来判定是否可以移动或键盘输入指令是否合法
int *q = &score, *p = &high_score;
 
int main(void)
{
    int key_command;
    printf("--------------------GAME:2048---------------------\n按下R读取游戏存档，按下M键删除存档并开始游戏，按下其他键进行快速游戏\n操作说明:W上移\tD右移\tS下移\tA左移.\n");
    key_command = getch();
    switch (key_command)
    {
        case VK_R:read_save(); break;
        case VK_M:remove("save_data.bin"); break;
        default:break;
    }
    for (;;)
    {
        if (flag == 0)
        {
            system("cls");
            printf("----------------GAME:2048-----------------\n分数:%-10d 步数:%-4d 最高分:%d\n",score, step, high_score);
            print_map();
            step++;
        }
        key_command = getch();
        if (key_command == VK_M)save_data();
        else if (key_command == VK_Q)return 0;
        else if (key_command == VK_A)move_left();
        else if (key_command == VK_W)move_up();
        else if (key_command == VK_D)move_right();
        else if (key_command == VK_S)move_down();
        else { flag = -1; continue; }
        if (game_over() == false)return 0;
    }
    return 0;
}
 
void print_map(void)
{
    int i, j, m1, n1, m2, n2,num_zero=0,check;
    srand(time(0));
    if (step == 0)     //游戏开始阶段，随机在地图中导入2和4方块
    {
        m1 = rand() % 4, n1 = rand() % 4;
        M[m1][n1] = 2;
        m2 = rand() % 4, n2 = rand() % 4;
        M[m2][n2] = 4;
    }
    for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (M[i][j] == 0) num_zero++;     //记录空方块数量
    if (step != 0 && num_zero != 0)       //第二步开始，如果有空方块，在空方块中写入2或4.
        for (;;)
        {
            m1 = rand() % 4, n1 = rand() % 4; m2 = rand() % 4;
            if (M[m1][n1] == 0)
                if (m2 < 4 && m2>1) { M[m1][n1] = 2; break; }
                else { M[m1][n1] = 4; break; }
        }
    for (i = 0; i < 4; i++)
    {
        printf("     |-----|-----|-----|-----|\n");
        printf("     |%5d|%5d|%5d|%5d|\n", M[i][0], M[i][1], M[i][2], M[i][3]);
    }
    printf("     |-----|-----|-----|-----|\n");
    printf("\n按下M存档，按下Q退出游戏.\n");
}
 
void move_left(void)
{
    int i, k;
    check_move();
    for (i = 0; i < 4; i++)         //对一排方块进行4次排列
        for (k = 1; k < 4; k++)
        {
            if (M[i][0] == 0 && M[i][1] != 0) swap(&M[i][0], &M[i][1]);
            if (M[i][1] == 0 && M[i][2] != 0) swap(&M[i][1], &M[i][2]);
            if (M[i][2] == 0 && M[i][3] != 0) swap(&M[i][2], &M[i][3]);
        }
    for (i = 0; i < 4; i++)          //如果相邻两方块相同，则进行相加操作，另一方块变为空方块
    {
        if (M[i][0] == M[i][1]) M[i][0] *= 2, M[i][1] = 0, score += M[i][0] * 2;
        if (M[i][1] == M[i][2]) M[i][1] *= 2, M[i][2] = 0, score += M[i][1] * 2;
        if (M[i][2] == M[i][3]) M[i][2] *= 2, M[i][3] = 0, score += M[i][2] * 2;
    }
    for (i = 0; i < 4; i++)         //再次进行排列
        for (k = 1; k < 4; k++)
        {
            if (M[i][0] == 0 && M[i][1] != 0) swap(&M[i][0], &M[i][1]);
            if (M[i][1] == 0 && M[i][2] != 0) swap(&M[i][1], &M[i][2]);
            if (M[i][2] == 0 && M[i][3] != 0) swap(&M[i][2], &M[i][3]);
        }
    flag = is_move();
}
 
void move_right(void)
{
    int i, k;
    check_move();
    for (i = 0; i < 4; i++)
        for (k = 1; k < 4; k++)
        {
            if (M[i][3] == 0 && M[i][2] != 0) swap(&M[i][3], &M[i][2]);
            if (M[i][2] == 0 && M[i][1] != 0) swap(&M[i][1], &M[i][2]);
            if (M[i][1] == 0 && M[i][0] != 0) swap(&M[i][1], &M[i][0]);
        }
    for (i = 0; i < 4; i++)
    {
        if (M[i][3] == M[i][2]) M[i][3] *= 2, M[i][2] = 0, score += M[i][3] * 2;
        if (M[i][2] == M[i][1]) M[i][2] *= 2, M[i][1] = 0, score += M[i][2] * 2;
        if (M[i][1] == M[i][0]) M[i][1] *= 2, M[i][0] = 0, score += M[i][1] * 2;
    }
    for (i = 0; i < 4; i++)
        for (k = 1; k < 4; k++)
        {
            if (M[i][3] == 0 && M[i][2] != 0) swap(&M[i][3], &M[i][2]);
            if (M[i][2] == 0 && M[i][1] != 0) swap(&M[i][1], &M[i][2]);
            if (M[i][1] == 0 && M[i][0] != 0) swap(&M[i][1], &M[i][0]);
        }
    flag = is_move();
}
 
void move_up(void)
{
    int i, k;
    check_move();
    for (i = 0; i < 4; i++)
        for(k = 1; k < 4; k++)
        {
            if (M[0][i] == 0 && M[1][i] != 0) swap(&M[0][i], &M[1][i]);
            if (M[1][i] == 0 && M[2][i] != 0) swap(&M[1][i], &M[2][i]);
            if (M[2][i] == 0 && M[3][i] != 0) swap(&M[2][i], &M[3][i]);
        }
    for (i = 0; i < 4; i++)
    {
        if (M[0][i] == M[1][i]) M[0][i] *= 2, M[1][i] = 0, score += M[0][i] * 2;
        if (M[1][i] == M[2][i]) M[1][i] *= 2, M[2][i] = 0, score += M[1][i] * 2;
        if (M[2][i] == M[3][i]) M[2][i] *= 2, M[3][i] = 0, score += M[2][i] * 2;
    }
    for (i = 0; i < 4; i++)
        for (k = 1; k < 4; k++)
        {
            if (M[0][i] == 0 && M[1][i] != 0) swap(&M[0][i], &M[1][i]);
            if (M[1][i] == 0 && M[2][i] != 0) swap(&M[1][i], &M[2][i]);
            if (M[2][i] == 0 && M[3][i] != 0) swap(&M[2][i], &M[3][i]);
        }
    flag = is_move();
}
 
void move_down(void)
{
    int i, k;
    check_move();
    for (i = 0; i < 4; i++)
        for (k = 1; k < 4; k++)
        {
            if (M[3][i] == 0 && M[2][i] != 0) swap(&M[3][i], &M[2][i]);
            if (M[2][i] == 0 && M[1][i] != 0) swap(&M[2][i], &M[1][i]);
            if (M[1][i] == 0 && M[0][i] != 0) swap(&M[1][i], &M[0][i]);
        }
    for (i = 0; i < 4; i++)
    {
        if (M[3][i] == M[2][i]) M[3][i] *= 2, M[2][i] = 0, score += M[3][i] * 2;
        if (M[2][i] == M[1][i]) M[2][i] *= 2, M[1][i] = 0, score += M[2][i] * 2;
        if (M[1][i] == M[0][i]) M[1][i] *= 2, M[0][i] = 0, score += M[1][i] * 2;
    }
    for (i = 0; i < 4; i++)
        for (k = 1; k < 4; k++)
        {
            if (M[3][i] == 0 && M[2][i] != 0) swap(&M[3][i], &M[2][i]);
            if (M[2][i] == 0 && M[1][i] != 0) swap(&M[1][i], &M[2][i]);
            if (M[1][i] == 0 && M[0][i] != 0) swap(&M[1][i], &M[0][i]);
        }
    flag = is_move();
}
 
bool game_over(void)
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (M[i][j] == 0)return true;
    if (i == 0 && j == 0)
        if (M[0][0] == M[0][1] || M[0][0] == M[1][0])return true;
    if (i == 0 && j == 3)
        if (M[0][3] == M[0][2] || M[0][3] == M[1][3])return true;
    if (i == 3 && j == 0)
        if (M[3][0] == M[3][2] || M[3][0] == M[2][0])return true;
    if (i == 3 && j == 3)
        if (M[3][3] == M[3][2] || M[3][3] == M[2][3])return true;
    if (M[0][1] == M[0][2])return true;
    if (M[1][0] == M[2][0])return true;
    if (M[1][3] == M[2][3])return true;
    if (M[3][1] == M[3][2])return true;
    for (i = 1; i < 3; i++)
        for (j = 1; j < 3; j++)
            if (M[i][j] == M[i - 1][j] || M[i][j] == M[i][j - 1] || M[i][j] == M[i + 1][j] || M[i][j] == M[i][j + 1])
                return true;
    if (score > high_score)
    {
        high_score = score;
        printf("你创造了新的纪录:%d\n", high_score);
        save_high_score(); 
        return false;
    }
    else printf("你的分数为:%d\n", score);
    return false;
}
 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
void read_save(void)
{
    FILE *fp = fopen("save_data.bin", "rb");
    if (fp == NULL)
    {
        printf("无法找到或打开存档，按下N新建存档并开始\n");
        if (getch() == VK_N)save_data();
        return;
    }
    fread(M, sizeof(M[0][0]), sizeof(M) / sizeof(M[0][0]), fp);
    fread(q, sizeof(score), 1, fp);
    fclose(fp);
    read_high_score();
}
 
void save_data(void)
{
    FILE *fp = fopen("save_data.bin", "wb");
    if (fp == NULL)
    {
        printf("无法找到或打开存档\n");
        return;
    }
    fwrite(M, sizeof(M[0][0]), sizeof(M) / sizeof(M[0][0]), fp);
    fwrite(q, sizeof(score), 1, fp);
    printf("存档成功.\n");
    fclose(fp);
}
 
void save_high_score(void)
{
    FILE *fp = fopen("save_data_highscore.bin", "wb");
    FILE *del = fopen("save_data.bin", "w");
    if (fp == NULL)
    {
        printf("无法找到或打开存档\n");
        return;
    }
    fwrite(p, sizeof(high_score), 1, fp);
    fclose(fp);
    fclose(del);
}
 
void read_high_score(void)
{
    FILE *fp = fopen("save_data_highscore.bin", "rb");
    fread(p, sizeof(high_score), 1, fp);
    fclose(fp);
}
 
void check_move(void)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[i][j] = M[i][j];
}
 
int is_move(void)   //如果M和temp不一致，则代表可以移动，返回0；如果一致，则代表不可移动，返回-1
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (M[i][j] != temp[i][j])
                return 0;
    return -1;

--------------------- 
作者：A__Plus 
来源：CSDN 
原文：https://blog.csdn.net/abc123lzf/article/details/77788718 
版权声明：本文为博主原创文章，转载请附上博文链接！