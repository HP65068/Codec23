#include <stdio.h>
#include <string.h>
#include "codec/base64.h"
#include "codec/url.h"

void init()
{
	char type[16] = { '\0' };
	char method[16] = { '\0' };
	char in[1024] = { '\0' };
	char out[2048] = { '\0' };

	while(1)
	{
		printf("�㷨��");
		scanf("%s", type);
		printf("����(encode)�����(decode)��");
		scanf("%s", method);
		printf("�ַ�����");
		scanf("%s", in);
		if (!strcmp(type, "base64"))
		{
			if (!strcmp(method, "encode"))
			{
				base64_encode(in, out);
				printf("���ܺ��ַ�����%s\n", out);
			}
			else if (!strcmp(method, "decode"))
			{
				base64_decode(in, out);
				printf("���ܺ��ַ�����%s\n", out);
			}
		}
		if (!strcmp(type, "url"))
		{
			if (!strcmp(method, "encode"))
			{
				url_encode(in, out);
				printf("���ܺ��ַ�����%s\n", out);
			}
			else if (!strcmp(method, "decode"))
			{
				url_decode(in, out);
				printf("���ܺ��ַ�����%s\n", out);
			}
		}

		//Debug
		/*
		for (int i = 0; i < strlen(in); i++)
			printf("%c", (unsigned char)in[i]);
		printf("\n");
		for (int i = 0; i < strlen(out); i++)
			printf("%c ", (unsigned char)out[i]);
		printf("\n");
		printf("%d", strlen(in));
		printf("\n");
		*/

		system("pause");
		system("cls");
	}
}