#include<stdio.h>
void main()
{
    char STR[100],PAT[100],REP[100],ans[100];
    int i,j,k,c,m,flag=0;
    printf("\n ENter the main string \n");
    scanf("%[^\n]",STR);
    printf("\n ENter a pattern string\n");
    scanf("%s",PAT);
    printf("\n ENter a replace string\n");
    scanf("%s",REP);
    i=m=c=j=0;
    while(STR[c]!='\0')
    {
        if(STR[m]==PAT[i])
        {
            i++;
            m++;
            flag=1;
            if (PAT[i]=='\0')
            {
                for(k=0;REP[k]!='\0';k++,j++)
                ans[j]=REP[k];
                i=0;
                c=m;
            }
        }
        else{
            ans[j]=STR[c];
            j++;
            c++;
            m=c;
            i=0;

        }
    }
    if(flag==0)
    {
        printf("PAttern doesnt exist");

    }
    else{
        ans[j]='\0';
        printf("\nThe resultant string is %s\n",ans);

    }
}
