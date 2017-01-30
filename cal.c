#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
float decode(char a[100], int k)
{
	int l=0, c;
	float str1;
	char str[100];
	for(c=k+1;c<strlen(a);c++,l++)
	{
		if(a[c]!='0'&&a[c]!='1'&&a[c]!='2'&&a[c]!='3'&&a[c]!='4'&&a[c]!='5'&&a[c]!='6'&&a[c]!='7'&&a[c]!='8'&&a[c]!='9'&&a[c]!='.')
		break;
		else
		str[l]=a[c];
	}
	for(c=0;c<strlen(a);c++)
	{
		str[l]='\0';
	}
	str1=atof(str);
	return str1;
}
void check(char a[100], int i, char c)
{
	int j, k, n, t=0;
	float s1, s2;
	char s[100], b[100];
	for(j=i-1;j>=0;j--)
	{
		if(a[j]!='0'&&a[j]!='1'&&a[j]!='2'&&a[j]!='3'&&a[j]!='4'&&a[j]!='5'&&a[j]!='6'&&a[j]!='7'&&a[j]!='8'&&a[j]!='9'&&a[j]!='.')
		break;
	}
	for(k=i+1;k<strlen(a);k++)
	{
		if(a[k]!='0'&&a[k]!='1'&&a[k]!='2'&&a[k]!='3'&&a[k]!='4'&&a[k]!='5'&&a[k]!='6'&&a[k]!='7'&&a[k]!='8'&&a[k]!='9'&&a[k]!='.')
		break;
	}
	s2=decode(a, i);
	s1=decode(a, j);
	if(c=='/')
		s1=s1/s2;
	else if(c=='*')
		s1=s1*s2;
	else if(c=='+')
		s1=s1+s2;
	else if(c=='^')
		s1=pow(s1,s2);
	else
		s1=s1-s2;
	sprintf(s, "%f", s1);
	for(n=0;n<=j;n++)
	b[n]=a[n];
	for(n=0;n<strlen(s);n++,j++)
		b[j+1]=s[n];
	for(n=k;n<strlen(a);n++,j++)
		b[j+1]=a[n];
	for(t=0;t<=strlen(a);t++)
		b[j+1]='\0';
	strcpy(a,b);
	printf("%f\n",s1);
}
int main()
{
	char a[100];
	float s1, s2;
	int i, j;
	printf("*************************CALCULATOR***************************\n");
	printf("expression\n");
	scanf("%s", a);
	for(i=0;i<j;i++)
	{
		if(a[i]=='^')
		{
			check(a, i, '^');i=0;
		}
	}
	for(i=0;i<j;i++)
	{
		if(a[i]=='/')
		{check(a, i, '/');i=0;}
		j=strlen(a);
	}
	for(i=0;i<j;i++)
	{
		if(a[i]=='*')
		{check(a, i, '*');i=0;}
		j=strlen(a);
	}
	for(i=0;i<j;i++)
	{
		if(a[i]=='+')
		{check(a, i, '+');i=0;}
		j=strlen(a);
	}
	for(i=0;i<j;i++)
	{
		if(a[i]=='-')
		{
			check(a, i, '-');i=0;
		}
		j=strlen(a);
	}
}
 

