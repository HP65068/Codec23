#include <stdio.h>
#include <string.h>
#include "codec/base64.h"
#include "codec/url.h"
#include "codec/md5.h"

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
				printf("加密后字符串: %s\n", out);
			}
			else if (!strcmp(method, "decode"))
			{
				base64_decode(in, out);
				printf("解密后字符串: %s\n", out);
			}
		}
		if (!strcmp(type, "url"))
		{
			if (!strcmp(method, "encode"))
			{
				url_encode(in, out);
				printf("加密后字符串z; %s\n", out);
			}
			else if (!strcmp(method, "decode"))
			{
				url_decode(in, out);
				printf("解密后字符串: %s\n", out);
			}
		}
		if (!strcmp(type, "md5"))
		{
			if (!strcmp(method, "encode"))
			{
				uint8_t* result;
				result = md5String(in);
				printf("加密后字符串: ");
				for (unsigned int i = 0; i < 16; ++i) {
					printf("%02x", result[i]);
				}
				printf("\n");
			}
			else if (!strcmp(method, "decode"))
			{

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