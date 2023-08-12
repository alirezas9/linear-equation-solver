#include <stdio.h>
#include "matrix.h"

int main()
{
    int m,n;
    scanf("%d %d",&m ,&n);

    float a[MAX][MAX];
    for(int i=0 ; i<m;i++)
        {
            for(int j=0 ;j<n;j++)
            scanf("%f",&a[i][j]);
        }
    int p;
    scanf("%d ",&p);

    float b[MAX][MAX];
    for(int i=0 ; i<n;i++)
        for(int j=0 ;j<p;j++)
            scanf("%f",&b[i][j]);


    float c[MAX][MAX];
    mult_mat(a,m,n,b,p,c);

        for(int i=0 ; i<m;i++)
        {
        for(int j=0 ;j<p;j++)
            printf("%-8.3f",c[i][j]);
        printf("\n");
        }


    return 0;
}
