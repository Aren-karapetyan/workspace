#include <stdio.h>
#include <stdlib.h>

void sizeof2(int n, int *size)
{
	*size = 0;
	int i = 0;
	while(n)
	{
		i ++;
		n/=2;
	}
	*size = i;
	
	printf("%d\n", *size);
}
char* decimalToBinary(int n, int *size)
{
	int n1 = n;
	char* str = (char*)malloc(*size + 1);
	if (n < 0)
		n *= (-1);
	sizeof2(n, size);

	for (int i = 1; i <= *size; i ++)
	{
		str[*size - i] = '0' + (n % 2);
		n/=2;
	}

	if (n1 < 0)
	{
		int i = *size - 1;
		for ( ; i >= 0; i--)
		{
			str[i] = str[i] ^ 1;
			if (str[i] == '0')
				break;
			str[i] = str[i] ^ 1;
		}
		for( ; i >= 0; i--)
		{
			str[i] = str[i] ^ 1;
		}
	}



        
        return str;
}
int main()
{
        int n;
        int size = 0;
        scanf("%d", &n);
        char* str = decimalToBinary(n, &size);
        printf("%s", str);

        return 0;
}
