#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 100005

int l1, l2, cnt_char, cnt_fat, cnt_lock;
char gene[MAXN], fat_gene[MAXN];
int pos_fat[MAXN];
int colored[MAXN];
//bool colored[MAXN];
bool locked[MAXN];

int read()
{
    int res = 0, flg = 1; char chr = getchar();
    while(! isdigit(chr)) {if(chr == '-') flg = -1; chr = getchar();}
    while(isdigit(chr)) {res = res * 10 + chr - '0'; chr = getchar();}
    return (res * flg);
}

int main()
{
	memset(colored, 0, sizeof(colored));
	memset(locked, false, sizeof(locked));


    l1 = read(), l2 = read();
    for(int i = 1; i <= l1 + 1; ++ i)
    {
    	gene[i] = getchar();
    }
    for(int i = 1; i <= l2; ++ i)
    {
    	fat_gene[i] = getchar();
    }
    
    for(int i = 1; i <= l1 - l2 + 1; ++ i)
    {
    	bool flag = true;
    	if(gene[i] == fat_gene[1])
    	{
    		for(int j = 1; j <= l2; ++ j)
    		{
    			if(gene[i + j - 1] != fat_gene[j])
    			{
    				flag = false;
    				break;
    			}
    		}

    		if(flag)
    		{
    			pos_fat[++ cnt_fat] = i;
    			for(int j = i; j <= i + l2 - 1; ++ j)
    			{
    				/*
    				if(!colored[j]) ++ cnt_char;
    				colored[j] = true;
					*/
					if(!colored[j]) ++ cnt_char;
					++ colored[j];
    			}
    		}
    	}
    }
    
    /*
    for(int i = 1; i <= cnt_fat; ++ i)
    {
    	bool flag = false;
    	{
    		for(int j = pos_fat[i]; j <= pos_fat[i] + l2 - 1; ++ j)
    		{
    			if(locked[j])
    			{
    				flag = true;
    				break;
    			}
    		}
    	}

    	if(!flag)	//if not been locked
    	{
    		locked[pos_fat[i] + l2 - 1] = true;
    		++ cnt_lock;
    	}
    }
    */
    for(int i = 1; i <= cnt_fat; ++ i)
    {
    	bool flag = false;
    	for(int j = pos_fat[i]; j <= pos_fat[i] + l2 - 1; ++ j)
    	{
    		if(locked[j])
    		{
    			flag = true;
    			break;
    		}
    	}

    	if(! flag)
    	{
    		int maxn = 0, pos = 1;
    		for(int j = pos_fat[i]; j <= pos_fat[i] + l2 - 1; ++ j)
    		{
    			if(colored[j] > maxn)
    			{
    				maxn = colored[j], pos = j;
    			}
    		}

    		locked[pos] = true, ++ cnt_lock;
    	}
    }

    std :: cout << cnt_char << " " << cnt_lock << std :: endl;
}
