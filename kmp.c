#include<stdio.h>
#include<string.h>

char text[100], pattern[10];
int table[100], m, n;

void kmptable();
int kmp();

int main()
{
int match;
printf("\nEnter the text:");
scanf("%s",text);
printf("\nEnter the pattern:");
scanf("%s",pattern);
m=strlen(text);
n=strlen(pattern);
match=kmp();
if(match>=0)
printf("\nMatch found at position%d\n\n",match);
else
printf("\nNo match found\n\n");
return 0;
}

int kmp()
{
int i;
kmptable();
int k=1;
for(i=0;i<m;i++)
{
while(k>=1&&pattern[k+1]!=text[i])
{
k=table[k];
}
if(text[i]==pattern[k+1])
k++;
if(k==n-1)
return i-k+1;
}
return -1;
}

void kmptable()
{
int k=1;
int i=1;
table[0]=k;
for(i=1;i<n;i++)
{
while(k>=1&&pattern[k+1]!=pattern[i])
{
k=table[k];
}
if(pattern[i]==pattern[k+1])
k++;
table[i]=k;
}
}
