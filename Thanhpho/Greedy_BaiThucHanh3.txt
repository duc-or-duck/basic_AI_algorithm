#include<stdio.h>
#include<limits.h>
#define INPUT "thanhpho.inp"
#define MAX 100 
int sodinh; 
int chiphi[MAX][MAX]; 
//bien toan cuc

void inmt(int mt[][MAX], int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++){
            printf("%5d", mt[i][j]);
        }
    }
}
void readfile() 
{
  FILE *fp;
  fp=fopen(INPUT,"r");
  if(fp == NULL)
  {
    printf("File not found"); 
    return; 
  }
  else 
  {
    fscanf(fp,"%d",&sodinh);
    for(int i=0; i<sodinh; i++)
    {
        for(int j=0; j<sodinh; j++)
        {
            fscanf(fp,"%d",&chiphi[i][j]);
        }
    }
    fclose(fp); 
  }
  //in ra cac gia tri 
  printf("\nSo dinh cua do thi: %d", sodinh);
  printf("\nChi phi di lai giua cac thanh pho: \n"); inmt(chiphi, sodinh); 
}

void inmang(int m[], int size) 
{
  for(int i = 0; i < size; i++)
  {
    printf("%d ", m[i]);
  }
}
void Greedy_TSP(int start)
{
    int n = start; 
    int dem = 0; 
    int CLOSE[MAX];
    int VET[MAX];

    printf("\nDinh xuat phat: %d\n", n);
    for(int i=0; i<sodinh; i++)
    {
        CLOSE[i] = i; 
    }
    CLOSE[n] = -1;
    printf("\nCLOSE[]: "); inmang(CLOSE, sodinh);
    //Luu lai duong di thu tu dinh da duyet
    VET[dem]=n;
    while (dem < sodinh-1)
    {
       int MIN = INT_MAX; 
       int pos;//Luu giu dinh co chi phi la min
       for(int i=0; i<sodinh; i++)
       {
        //tim min cua cac dinh ke voi n
        //i!=n => không phải đỉnh đang xét
        if(i!=n && MIN>chiphi[n][i] && CLOSE[i]!=-1)
        {
            MIN=chiphi[n][i]; 
            pos=i;
        }
       }
       //gan dinh ke tiep la dinh co pos = min 
       n = pos; 
       printf("\nDinh ke tiep: %d", n);
       CLOSE[n] = -1; 
       printf("\nCLOSE[]: "); inmang(CLOSE, sodinh); 
       //Luu VET cho dinh ke tiep
       VET[dem++]=n; 
       printf("\nThu tu cac thanh pho da di qua: "); inmang(VET, dem);
    }
    
}
int main() 
{
    readfile();
    Greedy_TSP(0); 
    return 0;
}