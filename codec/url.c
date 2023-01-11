#include "url.h"

void url_encode(char* in, char* out)
{
	//判断长度
	int str_len = strlen(in);
	if (str_len == 0)
	{
		out[0] = '\0';
		return;
	}

	//编码表
	char encode_table[17] = "0123456789ABCDEF";

	int i = 0;
	int index = 0;
	while (i < str_len)
	{
		if ((in[i] >> 7 == 1))
		{
			out[index++] = '%';
			out[index++] = encode_table[((in[i] >> 4) & 0xF)];
			out[index++] = encode_table[(in[i] & 0xF)];
			i++;
			out[index++] = '%';
			out[index++] = encode_table[((in[i] >> 4) & 0xF)];
			out[index++] = encode_table[(in[i] & 0xF)];
		}
		
		switch (in[i])
		{
		case '.':
		case '-':
		case '*':
		case '_':
			out[index++] = in[i];
			break;
		case ' ':
			out[index++] = '+';
			break;
		default:
			if ((in[i] >= '0' && in[i] <= '9') ||
				(in[i] >= 'A' && in[i] <= 'Z') ||
				(in[i] >= 'a' && in[i] <= 'z'))
			{
				out[index++] = in[i];
				break;
			}
			out[index++] = '%';
			out[index++] = encode_table[((in[i] >> 4) & 0xF)];
			out[index++] = encode_table[(in[i] & 0xF)];
			break;
		}

		END:
		i++;
	}

	out[index++] = '\0';
}

void url_decode(char* in, char* out)
{
	//判断长度
	int str_len = strlen(in);
	if (str_len == 0)
	{
		out[0] = '\0';
		return;
	}

	//解码表
	short decode_table[71] = { 0,0,0,0,0,0,0,0,0,0,
							   0,0,0,0,0,0,0,0,0,0,
							   0,0,0,0,0,0,0,0,0,0,
							   0,0,0,0,0,0,0,0,0,0,
							   0,0,0,0,0,0,0,0,0,1,
							   2,3,4,5,6,7,8,9,0,0,
							   0,0,0,0,0,10,11,12,13,14,15 };

	int i = 0;
	int index = 0;
	while (i < str_len)
	{
		if (in[i] == '%')
		{
			i++;
			out[index++] = ((decode_table[in[i]] << 4) | (decode_table[in[i + 1]]));
			i++;
		}
		else
		{
			out[index++] = in[i];
		}
		i++;
	}

	out[index++] = '\0';
}
