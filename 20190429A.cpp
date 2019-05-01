#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

char preord[30], inord[30];

void recover(int preleft, int preright, int inleft, int inright)
{
	int root, leftsize, rightsize;
	if(preleft<=preright&&inleft<=inright)
	{
		for(root=inleft;root<=inright;root++)
		{
			if(preord[preleft] == inord[root])	
			{
				break;
			}
		}
		leftsize = root - inleft;
		rightsize = inright - root;
		if(leftsize > 0)	
		{
			recover(preleft + 1, preleft + leftsize, inleft, root - 1);
		}
		if(rightsize > 0)	
		{
			recover(preleft + leftsize + 1, preright, root + 1, inright);
		}
		std :: cout << inord[root];
	}
}

int main()
{
	while(scanf("%s%s",preord,inord) == 2)
	{
        int n = strlen(preord);
		recover(0, n - 1, 0, n - 1);
		std :: cout << std :: endl;
	}
    return 0;
}