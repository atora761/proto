#include "../../include/system/system.h"

extern "C"{
void* MyMemset( void* src, char num, size_t size )
{
	char* p = (char*)src;
	size_t cnt = 0;
	
	/* 引数チェック */
	if( src == NULL ) {
		return NULL;
	}
	
	/* 塗りつぶし */
	while( cnt < size ) {
		*p = num;
		p ++;
		cnt ++;
	}
	return src;
}

void *my_memcpy(void *buf1, const void *buf2, size_t n)
{
	void *retStr = NULL;						///return ポインタ格納変数
	char *pBuff1 = (char *)buf1;				///キャスト格納
	const char *pBuff2 = (const char *)buf2;	///キャスト格納
	size_t i = 0;								///ループ変数

	/* 引数チェック */
	if (buf1 != NULL && buf2 != NULL && n > 0)
	{
		/* buf1アドレス格納 */
		retStr = buf1;

		for (i = 0; i < n; i++)
		{
			*pBuff1 = *pBuff2;
			pBuff1++;
			pBuff2++;
		}
	}

	/* buf1の値 */
	return retStr;
}
}