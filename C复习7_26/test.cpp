#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//模拟实现memcpy(内存拷贝)
void* my_memcpy(void* dest, const void * src, int n)
{
	//传递进来的数据类型不确定，强转为char,一个字节一个字节拷贝
	char* m_dest = (char*)dest;
	const char* m_src = (const char*)src;
	for (int i = 0; i < n; ++i)
	{
		m_dest[i] = m_src[i];
	}
	return dest;
}

int main()
{
	char dest[] = "abcdef";
	char src[] = "xyzopq";
	printf("%s\n", dest);
	printf("%s\n", src);
	my_memcpy(dest, src, sizeof(src));
	printf("%s\n", dest);
	printf("%s\n", src);
	return 0;
}
/*
//模拟实现strstr
char* my_strstr(const char* dest, const char* src)
{
	const char* str1 = dest;
	const char* str2 = src;
	const char* str3 = NULL;
	assert(dest);
	assert(src);
	while (*dest)
	{
		str3 = str1;
		//从str3位置开始判断是否相等
		while (*str1 && *str2 && *str1 == *str2)
		{
			++str1;
			++str2;
		}
		//如果退出str2指向\0，
		if (*str2 == '\0')
		{
			//返回str3指向的位置
			return (char*)str3;
		}
		//如果不相等str1向前走一个位置
		str1 = str3 + 1;
		//str2回到开始位置
		str2 = src;
	}
	return NULL;
}
void main()
{
	char dest[] = "abcdef simple";
	char src[] = "mp";
	printf("%s\n",my_strstr(dest, src));
}
/*
//模拟实现strcmp
int my_strcmp(const char* dest, const char* src)
{
	assert(dest);
	assert(src);
	while (*dest && *src)
	{
		if (*dest > *src)
		{
			return 1;
		}
		else if(*dest < *src)
		{
			return -1;
		}
		else
		{
			++dest;
			++src;
		}
	}
	if (*dest)
	{
		return 1;
	}
	else if (*src)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void main()
{
	char dest[] = "abc";
	char src[] = "abc";
	int ret = my_strcmp(dest, src);
	printf("%d\n", ret);
}

/*
//模拟实现strcat
char* my_strcat(char* dest, const char* src)
{
    assert(dest);
	assert(src);
	//先让dest走到'\0'处
	while (*dest)
	{
		++dest;
	}
	//追加拷贝
	while (*dest = *src)
	{
		++dest;
		++src;
	}
	*dest = '\0';
	return dest;
}
void main()
{
	char dest[20] = "hello haha";
	char src[] = "world";
	printf("%s\n", dest);
	printf("%s\n", src);
	strcat(dest, src);
	//my_strcat(dest, src);
	printf("%s\n", dest);
	printf("%s\n", src);

}
/*
//模拟实现strcpy
char* my_strcpy(char* dest, const char* src)
{
    assert(dest);
	assert(src);
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return dest;
}

void main()
{
	char dest[] = "hello haha";
	char src[] = "world";
	printf("%s\n", dest);
	printf("%s\n", src);
	my_strcpy(dest, src);
	printf("%s\n", dest);
	printf("%s\n", src);

}
/*
//模拟实现strlen
size_t my_strlen(const char* str)
{
	int len = 0;
	while (*str != '\0')
	{
		++len;
		++str;
	}
	return len;
}

void main()
{
	char str[] = "abcd";
	printf("%d\n",my_strlen(str));
}


/*
//用联合判断大小端
//联合的成员共用一块空间
union Un
{
	int a;
	char b;
};
int main()
{
	Un un;
	un.a = 1;
	un.b = 0x00;
	if (un.a == 1)
	{
		printf("大端\n");
	}
	else
	{
		printf("小端\n");
	}
	return 0;
}
*/