#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pair pair;

struct pair
{
    int numligne;
    char haut;
    char bas;
};

int firstline(char *ligne,pair *tab,int n)
{
    int i;
    int j=0;
    for(i=0;i<n;i+=3)
    {
            tab[j].numligne=j;
            tab[j].haut=ligne[i];
            j++;
    }
    return j;
}
void stdline(char *ligne,pair *tab,int n,int lanes)
{
    int l=0;
    int i;
    int j=0;
    for(i=1;i<n;i++)
    {
        if(ligne[i]=='|')
        {
           l++; 
        }
        else if(ligne[i]==' ')
        {
            i++;
        }
        else if(ligne[i]=='-')
        {
            for(j=0;j<lanes;j++)
            {
                if(tab[j].numligne==l)
                {
                    (tab[j].numligne)++;
                }
                else if(tab[j].numligne==(l+1))
                {
                    (tab[j].numligne)--;
                }
            }
            i++;
        }
    }
}
void lastline(char *ligne,pair *tab,int n,int lanes)
{
    int i;
    int k;
    int j=0;
    for(i=0;i<n;i++)
    {
        if(ligne[i]!=' ')
        {
            for(k=0;k<lanes;k++)
            {
                if(tab[k].numligne==j)
                {
                    tab[k].bas=ligne[i];
                }
            }
            j++;
        }
    }
}

int main()
{
    int W;
    int H;
    int lanes;
    pair tab[500];
    int tour=0;
    int i;
    scanf("%d%d", &W, &H); fgetc(stdin);
    for (int i = 0; i < H; i++) {
        char line[1025];
        fgets(line, 1025, stdin);
        if(tour>0 && tour<H-1)
        {
            stdline(line,tab,W,lanes);
            tour++;
        }
        else if(tour==0)
        {
            lanes=firstline(line,tab,W);
            tour++;
        }
        else
        {
            lastline(line,tab,W,lanes);
        }
    }
    for(i=0;i<lanes;i++)
    {
        printf("%c%c\n",tab[i].haut,tab[i].bas);
    }

    return 0;
}
