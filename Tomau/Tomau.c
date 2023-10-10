#include<stdio.h>
#include<limits.h>
#define INPUT "tomau.inp"
#define MAX 100 

//bien toan cuc 
FILE *fp; 
int sodinh; 
int mtk[MAX][MAX]; 
int bacdt[MAX]; 
int V[MAX];
int COLOR[MAX];
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
            fscanf(fp,"%d",&mtk[i][j]);
        }
    }
    fclose(fp); 
  }
  //in ra cac gia tri 
  printf("\nSo dinh cua do thi: %d", sodinh);
  printf("\nMTK[]: \n"); inmt(mtk, sodinh); 
}

void init(int m[], int size, int value) 
{
  for(int i = 0; i < size; i++)
  {
    m[i] = value;
  }
}

void inmang(int m[], int size) 
{
  for(int i = 0; i < size; i++)
  {
    printf("%d ", m[i]);
  }
}

void bacdothi() 
{
 init(bacdt,sodinh,0);
 //tinh bac cua cac dinh
 for(int i = 0; i < sodinh; i++)
 {
    int count = 0;
    for(int j = 0; j<sodinh; j++)
    {
        if(mtk[i][j]==1)
        {
            count++; 
        }
    }
    bacdt[i] = count;
 }
  printf("\nBac cua cac dinh: "); inmang(bacdt, sodinh);
}

void timmax(int m[], int size) 
{
  int max = m[0];
  int posmax = 0;
  for(int i = 0; i < size; i++)
  {
    if(max < m[i])
    {
        max = m[i];
        posmax = i; 
    }
    return posmax; 
  }
}

void tomau() 
{
    int max = timmax(bacdt,sodinh);
    //tao mang V chua gia tri cua cac thanh pho
    for(int i = 0; i<sodinh; i++)
    {
        V[i]=i;
    }
    printf("\nCac thanh pho can to mau: "); inmang(V, sodinh);
    //tao mang Color chua gia tri mau cua cac thanh pho
    init(COLOR, sodinh, 0);
    for(int color = 1; color <= 3; color++)
    {
        //tim dinh co bac do thi lon nhat 
        printf("\nThanh pho co bac dt = max: %d", V[max]);
        COLOR[V[max]]=color;
        //to mau cho cac dinh ke cua V[max]
        for(int i = 0; i<sodinh; i++)
        {
            if(mtk[V[max]][i] == 0 && COLOR[i]==0)
            {
                for(int j = 0; j<sodinh; j++)
                {
                    if(mtk[i][j]==0)
                    {
                        COLOR[V[i]]=color;
                    }
                } 
            }
        }
    }
    printf("\nCOLOR[]: "); inmang(COLOR, sodinh);
    //gan gia tri do thi co bac lon nhat thanh vo cung be
    
}


int main() 
{
    readfile();
    bacdothi(); 
    tomau(); 
    return 0; 
}