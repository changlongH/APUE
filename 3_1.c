#include<stdio.h>
//#include <stdlib.h>
//#include <memory.h>
// 括号匹配问题
int main()
{
	int cast,len, n, num,left,right = 0;
	char* arr2;
	scanf("%d",&cast);
	while(cast)
	{
		scanf("%d",&len);
		arr2 = (char *)malloc(sizeof(char)* len*2);
		//memset(arr2, 0, sizeof(char)*len*2);
		for(n = 0; n < len; n++)
		{
			scanf("%d", &num);
			arr2[num + n] = 1;
			left = 0, right = 1;
			while( arr2[--num+n] ? ++right : ++left){if(left>=right)break;};
			printf("%d ", left);
		}
		--cast;
		printf("\n");
		free(arr2);
	}
	return 0;
}
