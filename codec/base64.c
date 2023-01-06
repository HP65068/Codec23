#include "base64.h"
#include <string.h>

void base64_encode(const char* origin_str, char* output)
{
	//编码表
	static const char encode[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//判断长度
	int str_len = strlen(origin_str);
	if (str_len == 0)
	{
		output[0] = '\0';
		return;
	}

	int index = 0;
	char c = '\0';
	char last_c = '\0';
	int i;
	for (i = 0; i < str_len; i++)
	{
		c = origin_str[i];
		switch (i % 3)
		{
		case 0:
			output[index++] = encode[((c >> 2) & 0x3F)];
			break;
		case 1:
			output[index++] = encode[((c >> 4) & 0xF) | ((last_c & 0x3) << 4)];
			break;
		case 2:
			output[index++] = encode[((c >> 6) & 0x3) | ((last_c & 0xF) << 2)];
			output[index++] = encode[(c & 0x3F)];
			break;
		}
		last_c = c;
	}

	i = str_len % 3;
	if (i == 1)
	{
		output[index++] = encode[((c & 0x3) << 4)];
		output[index++] = '=';
		output[index++] = '=';
	}
	else if (i == 2)
	{
		output[index++] = encode[((c & 0xF) << 2)];
		output[index++] = '=';
	}

	output[index++] = '\0';
}

void base64_decode(const char* origin_str, char* output)
{
	//解码表
	static const char decode[] = { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 253, 255,
		255, 253, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 253, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 62, 255, 255, 255, 63,
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 255, 255,
		255, 254, 255, 255, 255, 0, 1, 2, 3, 4, 5, 6,
		7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
		19, 20, 21, 22, 23, 24, 25, 255, 255, 255, 255, 255,
		255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
		37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
		49, 50, 51, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 255};

	//判断长度
	int str_len = strlen(origin_str);
	if (str_len == 0)
	{
		output[0] = '\0';
		return;
	}

	int num_over = 3;

	int i = 0;
	int index = 0;
	int four_loop = 0;
	int four_char = 0;
	char c = '\0';
	for (i = 0; i < str_len; i++)
	{
		c = decode[origin_str[i]];
		if (c == 254)
			num_over--;
		four_char = (four_char << 6 | c);
		if (four_loop++ == 3)
		{
			output[index++] = (four_char >> 16) & 0xFF;
			if (num_over > 1)
				output[index++] = (four_char >> 8) & 0xFF;
			if (num_over > 2)
				output[index++] = (four_char) & 0xFF;
			four_loop = 0;
			four_char = 0;
		}
	}

	output[index++] = '\0';
}