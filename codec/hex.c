#include "hex.h"
#include <string.h>

void hex_encode(const char* origin_str, char* output)
{
	//±àÂë±í
	char encode_table[17] = "0123456789ABCDEF";

	int str_len = strlen(origin_str);
	int index = 0;
	int i = 0;
	for (i = 0; i < str_len; i++)
	{
		output[index++] = encode_table[(origin_str[i] >> 4) & 0xF];
		output[index++] = encode_table[origin_str[i] & 0xF];
	}

	output[index++] = '\0';
}

void hex_decode(const char* origin_str, char* output)
{
	//½âÂë±í
	short decode_table[71] = { 0,0,0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,0,
				   0,0,0,0,0,0,0,0,0,1,
				   2,3,4,5,6,7,8,9,0,0,
				   0,0,0,0,0,10,11,12,13,14,15 };

	int str_len = strlen(origin_str);
	int index = 0;
	int i = 0;
	for (i = 0; i < str_len; i += 2)
	{
		output[index++] = (decode_table[origin_str[i]] << 4) | decode_table[origin_str[i + 1]];
	}

	output[index++] = '\0';
}
