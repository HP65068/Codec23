#include <stdio.h>
#include <string.h>
#include "codec/base64.h"

void init()
{
	char type[16] = { '\0' };
	char method[16] = { '\0' };
	char in[1024] = { '\0' };
	char out[2048] = { '\0' };

	while(1)
	{
		printf("算法：");
		scanf("%s", type);
		printf("加密(encode)或解密(decode)：");
		scanf("%s", method);
		printf("字符串：");
		scanf("%s", in);
		if (!strcmp(type, "base64"))
		{
			if (!strcmp(method, "encode"))
			{
				base64_encode(in, out);
				printf("加密后字符串：%s\n", out);
			}
			else if (!strcmp(method, "decode"))
			{
				base64_decode(in, out);
				printf("解密后字符串：%s\n", out);
			}
			else
			{
				printf("语法错误，输入encode或decode\n");
			}
		}
		system("pause");
		system("cls");
	}
}