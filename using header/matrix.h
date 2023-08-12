#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include<stdio.h>
#define MAX 10

void print_mat(float arr[][MAX],int m)
{
    for (int i=0; i<m ; i++)
    {
        for (int j=0; j<m ; j++)
        {
            printf("%-8.2f",(*(*(arr+i)+j)));
        }
        printf("\n");
    }
}
void get_mat(float arr[][MAX],int m)
{
    for (int i=0; i<m ; i++)
        for (int j=0; j<m ; j++)
                scanf("%f",(*(arr+i)+j));
}
float det(float mat[MAX][MAX],int n)
{
    int i,j,k;
    int sign = 1;
    float sum = 0 ,prod;
    float submat[MAX][MAX];
    float temp[MAX];

    if(n == 1)
            return mat[0][0];

    else
    {
        for(i=0;i<n;i++)
            {
                int a=0, b=0;
                for(j=1;j<n;j++)
                    for(k=0;k<n;k++)
                    {
                        if(k != i)
                            {
                                submat[a][b++] = mat[j][k];
                                if(b == n-1)
                                {
                                    a++;
                                    b=0;
                                }
                            }
                    }
                    sum += sign * mat[0][i] * det(submat,n-1);
                    sign *= -1;
            }
            return sum;
    }
    }
void submat(float mat[MAX][MAX],int n,float sub[MAX][MAX],int row, int col)
{
    int a=0, b=0 ;
    for(int i=0;i<n;i++)
    {
        if(i == row) continue;
        else
        {
            for(int j=0;j<n;j++)
            {
                if(j == col) continue;
                else
                {
                    *(*(sub + a) + b) = *(*(mat + i) + j);
                    b++;
                    if(b== n-1)
                    {
                        a++;
                        b=0;
                    }
                }
            }
        }
    }
}
void T(float mat[MAX][MAX],float trsp[MAX][MAX],int n)
{
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                *(*(trsp + i) + j) = *(*(mat + j) + i);
}
void cofact(float mat[MAX][MAX],int n,float cfact[MAX][MAX])
{
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                float temp[MAX][MAX];
                submat(mat,n,temp,i,j);

                *(*(cfact + i) + j) = power( -1 , i+j ) * det(temp,n-1);
            }
}
void inv_mat(float mat[MAX][MAX],int n,float inverse[MAX][MAX])
{
    if (n==1)
        *(*(inverse+0)+0) = 1/mat[0][0] ;
    else
    {
        float d = det(mat,n);
        float temp1[MAX][MAX] , temp2[MAX][MAX];
        cofact(mat,n,temp1);
        T(temp1,temp2,n);
        if(d != 0)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    *(*(inverse + i) + j) =  (*(*(temp2 + i) + j)) / d ;
        }
    }

}
int power(int a, int b)
{
    int temp = 1;
    for (int i=0 ;i<b;i++)
            temp *= a ;
    return temp;
}
void solve_system(float coefficient[MAX][MAX], int n , float constants[MAX] , float x[MAX])
{
    float temp[MAX][MAX];
    inv_mat(coefficient,n,temp);

    zeros(x,n);

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            *(x + i) += temp[i][j] * constants[j] ;
        }
    }
}
void zeros(float a[MAX] , int n)
{
    for(int i=0 ; i<n ; i++)
        *(a+i) = 0;
}
void mult_mat(float a[MAX][MAX] , int m, int n , float b[MAX][MAX], int p , float axb[MAX][MAX])
{
    // a[m][n]
    // b[n][p]
    //axb [m][p]

    for(int i=0 ; i<m;i++)
            for(int j=0 ; j<p;j++)
            {
                *(*(axb + i) + j)=0;
                for(int k=0;k<n;k++)
                   *(*(axb + i) + j) += a[i][k] * b[k][j] ;
            }

}

#endif // MATRIX_H_INCLUDED
