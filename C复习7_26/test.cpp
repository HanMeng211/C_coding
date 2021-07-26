#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//ģ��ʵ��memcpy(�ڴ濽��)
void* my_memcpy(void* dest, const void * src, int n)
{
	//���ݽ������������Ͳ�ȷ����ǿתΪchar,һ���ֽ�һ���ֽڿ���
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
//ģ��ʵ��strstr
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
		//��str3λ�ÿ�ʼ�ж��Ƿ����
		while (*str1 && *str2 && *str1 == *str2)
		{
			++str1;
			++str2;
		}
		//����˳�str2ָ��\0��
		if (*str2 == '\0')
		{
			//����str3ָ���λ��
			return (char*)str3;
		}
		//��������str1��ǰ��һ��λ��
		str1 = str3 + 1;
		//str2�ص���ʼλ��
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
//ģ��ʵ��strcmp
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
//ģ��ʵ��strcat
char* my_strcat(char* dest, const char* src)
{
    assert(dest);
	assert(src);
	//����dest�ߵ�'\0'��
	while (*dest)
	{
		++dest;
	}
	//׷�ӿ���
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
//ģ��ʵ��strcpy
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
//ģ��ʵ��strlen
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
//�������жϴ�С��
//���ϵĳ�Ա����һ��ռ�
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
		printf("���\n");
	}
	else
	{
		printf("С��\n");
	}
	return 0;
}
*/