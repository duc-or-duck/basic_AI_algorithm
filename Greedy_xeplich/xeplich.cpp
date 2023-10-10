#include <stdio.h> 
#include <limits.h>
#define INPUT "new1.txt"
#define MAX 100

//khai bao bien
FILE *fp;
int numjob;
int nummc;
int T[MAX];//thoi gian thuc hien
int M[MAX];//So may can thuc hien
int J[MAX];//so cong vien can thuc hien

void inMang(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
}

void readFile(){
    fp = fopen(INPUT, "r");
    if(fp == NULL){
        printf("404");
    }
    else{
        fscanf(fp, "%d %d" , &numjob, &nummc);
        for(int i=0;i<numjob;i++){
            fscanf(fp, "%d" , &T[i]);
        }
        fclose(fp);
    }
    printf("%d %d\n" ,numjob,nummc);
    inMang(T,numjob);
}
void init(int arr[], int size){
    for(int i=0;i<size;i++){
        arr[i] = i;
    }
}
void init2(int arr[], int size, int value){
    for(int i=0;i<size;i++){
        arr[i] = value;    
    }
}
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}
void sort(){
    for(int i=0;i<numjob-1;i++){
        for(int j=i+1;j<numjob;j++){
            if(T[i] < T[j]){
                swap(T[i],T[j]);
                swap(J[i],J[j]);
            }
        }  
    }
}

int MIN(int m[], int size)
{
  int min = m[0]; 
  int posmin = 0; 
  for(int i = 1; i < size; i++)
  {
    if(min > m[i])
    {
      min = m[i];
      posmin = i;
    }
  }
  return posmin; 
}

void Xeplich() 
{
    init2(M, nummc,-1);
    printf("\nSo may can thuc hien: "); inMang(M,nummc); 
    //cac cong vien voi thoi gian hoan thanh
    init(J, numjob);
    printf("\nCac cong viec can thuc hien: "); inMang(J, numjob);
    //thoi gian hoan thanh cac cong viec tuong ung
    printf("\nThoi gian can thuc hien cac c.viec:"); inMang(T,numjob);
    printf("\n-----------------------------------------------------\n");
    sort();
    printf("\nCac cong viec sau thuc hien: "); inMang(J, numjob);
    //thoi gian hoan thanh cac cong viec tuong ung
    printf("\nThoi gian can thuc hien cac c.viec:"); inMang(T,numjob);
    //phan cong nummc cong viec vao nummc may
    int dem = 0; 
    int Tmax = T[0];//T[0] c0 gia tri max tfon
    for(int i=0; i<nummc; i++)
    {
      M[i]=T[i];//may [i] = co thoi gian hoan thanh = T[i]
      dem++;
    }
    printf("\nThoi gian cac may sau lan phan cong viec lan dau tien: \n"); 
    inMang(M, nummc);
    //Phan viec vao cac may trong lan dau tien
    while(dem < numjob)
    {
      int tmin = M[MIN(M, nummc)];
      while (tmin<=Tmax && dem<numjob) 
      {//thoi gian cua may min < Tmax va con viec de phan
        /* code */
        M[MIN(M, nummc)]+=T[dem];
        //In ra trang thai cua cac may sau khi cap nhat lai cong viec
        printf("\nThoi gian hoan thanh cua cac may: "); 
        inMang(M, nummc); 
        dem++; 
      }
      Tmax=M[MIN(M, nummc)]; 
      printf("\nTmax sau khi cap nhat: %d", Tmax);
      //tim Max cua thoi gian hoan thanh cac may M[i]
      int max = M[0]; 
      for(int i=1; i<numjob; i++)
      {
        if(max<M[i]){
            max=M[i];
        }
      }
      printf("\nMax cua thoi gian hoan thanh cua cac cong viec la: %d", max);
    }   
}


int main(){
 readFile();
 Xeplich(); 
 return 0;
}
