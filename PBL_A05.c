#include<stdlib.h>
#include<stdio.h> 
#include<conio.h>
int kl[100],gt[100],n,dp[101][101],klmax,v1[100],v2[50];
int dovat[100][100];
FILE *fp;


//hàm menu
void menu() 
 { 
             /*print menu screen*/ 
             //clrscr(); 
             printf("\t\t\t***********************************\n"); 
             printf("\t\t\t** WELCOME TO CURRENCY CONVERTER **\n"); 
             printf("\t\t***********************************\n"); 
             printf("\t\t\t             \n"); 
             printf("\t\t\t***********************************\n"); 
             printf("\t\t\tCach thuc hoat dong\n\n\n"); 
             printf("\t\t\tBuoc 1:Nhap du lieu\n"); 
             printf("\t\t\t   Chon 1 de nhap tu ban phim \n"); 
             printf("\t\t\t   Chon 2 de lay du lieu tu fife\n"); 
             printf("\t\t\tBuoc 2: Chon cach lay\n"); 
             printf("\t\t\t   Chon 3 de lay moi vat nhieu lan\n"); 
             printf("\t\t\t   Chon 4 de lay moi vat 1 lan\n"); 
             printf("\t\t\tBuoc 3: Xuat ket qua\n"); 
             printf("\t\t\t***********************************\n\n\n"); 
             printf("\n");
             printf("\t\t\t#Nhan enter de bat dau!\n");
             getch(); 
 }  
 //hàm chọn trên menu
 void chonM()
 {
   int i;
   printf("\nMoi chon cach nhap (1or2): ");
   scanf("%d",&i);
   switch(i)
   {
     case 1: Nhap(kl,gt);
             chon1();
             break;
     case 2: Input(kl,gt);
             chon1();
             break;
     default: printf("Nhap sai nhan enter de nhap lai!\n");
              getch();
              printf("\033[A\33[2K\r ");
              printf("\033[A\33[2K\r ");
              chonM();               
   }
 }
 //chọn lần 2
 void chon1()
 { 
   int i;
   char j;
   printf("\nChon cach lay do vat (3or4): "); scanf("%d",&i);
   switch(i)
   {
     case 3: TH1();
             printf("\nBan co muon thu truong hop con lai (Y or N): ");
             scanf("%c",&j);
             if(j==89||j==121) 
             TH2();
             getch();
             break;
     case 4: TH2();
             printf("\nBan co muon thu truong hop con lai (Y or N): ");
             scanf("%c",&j);
             if(j==89||j==121) 
             TH1();
             getch();
             break;
     default: printf("Nhap sai nhan enter de nhap lai!\n");
              getch();
              printf("\033[A\33[2K\r ");
              printf("\033[A\33[2K\r ");
              chon1();                
   }

 }
 //hàm kiểm tra so âm trong file
 void kiemtra1(int a)
 {
   if(a<=0)
   {
     printf("Error: Du lieu trong file khong phu hop, nhan enter de quay lai \n");
     getch();
     printf("\033[A\33[2K\r ");
     chonM();
     
   }
 }
//hàm kiểm tra số âm khi nhập
void kiemtra(int *a)
{
  while(*a<=0)
  {
     printf( "\033[A\33[2KT\r ");
     printf("Error: gia tri nhap vao khong hop le moi nhap lai:  "); scanf("%d", &*a);
  }
}
//hàm nhập
void Nhap( int a[], int b[])
{   
    printf("\n Nhap so luong do vat: "); 
    scanf("%d",&n); kiemtra(&n);

    printf("\n Nhap khoi luong toi da tui mang duoc: ");
    scanf("%d",&klmax); kiemtra(&klmax);

    int i;
    for(i=1;i<=n;i++)
    {
        printf("\n Nhap khoi luong vat %d: ",i); scanf("%d",&a[i]); kiemtra(&a[i]);
        
        printf("\n Nhap gia tri vat %d: ", i); scanf("%d",&b[i]); kiemtra(&b[i]);
         
    }
}
//hàm báo lỗi thiếu phần tử
void error1()
{
  printf("Error du lieu trong file khong chinh xac. Nhan enter de nhap lai \n");
  getch();
         printf("\033[A\33[2K\r ");
         printf("\033[A\33[2K\r ");
         chonM();
}

//hàm nhận giá trị từ file
void Input()
{    
    fp = fopen("C:\\Users\\HONG TRUONG\\Desktop\\bag.txt", "r");  
    if (fp == NULL)
  {
    printf("Error File khong ton tai. Nhan enter de nhap lai \n");
    getch();
    printf("\033[A\33[2K\r ");
    printf("\033[A\33[2K\r ");
    chonM();
    
  }
  else
  {
    int i = 1;
    n = 0;
    klmax = 0;
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &klmax);
    for (i; i <= n; i++)
    {
      kl[i] = 0;
      fscanf(fp, "%d", &kl[i]);
      gt[i] = 0;
      fscanf(fp, "%d", &gt[i]);
    }

    if (n <= 0||klmax <= 0)
    {
      error1();
      return 0;
    }
    
    else
    {
      for (i = 1; i <= n; i++)
      {
        if (kl[i] <= 0)
        {
          error1();
          return 0;
        }
        if (gt[i] <= 0)
        {
          error1();
          return 0;
        }
      }
    }

    printf("#Du lieu doc tu file\n");
    printf("Co tat ca %d do vat\n", n);
    printf("Khoi luong toi da tui mang duoc: %d\n", klmax);

    for (i = 1; i <= n; i++)
    {
      printf("Khoi luong vat %d la: %d\n", i, kl[i]);
      printf("Gia tri vat %d la:    %d\n", i, gt[i]);
    }
  }

}

//hàm tinhs tổng dãy
int S(int a[])
{
    int i,s;
    s=0;
    for(i=1;i<=n;i++) s=s+a[i];
    return s;
}
//hamf khởi tạo giá trị ban đầu
void KTao()
{
     int i,j;
     for(i=0;i<=klmax;i++)
     dp[i][0]=0;
     for(j=0;j<=n;j++)
     dp[0][j]=0;
}
//hàm xuất TH1
     int output1()
    {
      int j,i, z;
      j=v1[1];
      i=klmax;
      printf("\n");
      printf("\n");
      while(i>0&&i>kl[j])
      {
        z=v1[i];
        
        printf(" vat %d lay %d lan,",z,i/kl[z] );
        i=i-i/kl[z]*kl[z];
      }
      printf("\b.");
    }
//hàm xuất TH2
      int output2()
      {
         int j,i,z;
         j=dovat[1][n];
         i=klmax;
         printf("\nNhung vat duoc lay la: ");
         while(n>0)
         { 
           if(z!=dovat[i][n])
           {
           z=dovat[i][n];
           if(z!=0) printf(" vat %d,", z);
           i=i-kl[z];
           n--;
           }
           else n--;
         }
         printf("\b.");
      }
    
// trường hợp một vật được chọn nhiều lần
int TH1()
    {   
        int i,j,du;
        v1[1]=0;
        for(i=1;i<=klmax;i++)
       {  
           printf("\n");
           for(j=1;j<=n;j++)
          { 
           du=i-(i/kl[j])*kl[j];
           dp[i][j]=i/kl[j]*gt[j]+dp[du][n];
           
           if(dp[i][j]>dp[i][j-1]) 
           v1[i]=j;

           else dp[i][j]=dp[i][j-1];
           printf("%5d",dp[i][j]);

          }
          if(v1[i-1]==0) v1[1]=v1[i];
          
       }
       output1();
    }
 //   trường hợp 1 vật chỉ được chọn 1 lần
 int TH2()
     {          
     int i,j;
   if(klmax>=S(kl))
        {
          printf("\n gia tri toi da co the lay la: %d",S(gt));
          printf("\n Nhung vat duoc lay la: ");
          for(i=1;i<=n;i++) printf(" vat %d,",i);
          printf("\b.");
        }
   else{
         for(i=1;i<=klmax;i++)
         {
           printf("\n");
           for(j=1;j<=n;j++)
           {
             if(i>=kl[j])
             {
               dp[i][j]=gt[j]+dp[i-kl[j]][j-1];
               if(dp[i][j]>dp[i][j-1]) dovat[i][j]=j;
               else {
                     dp[i][j]=dp[i][j-1]; 
                     dovat[i][j]=dovat[i][j-1];
                    }
             }
             else 
                    {
                     dp[i][j]=dp[i][j-1]; 
                     dovat[i][j]=dovat[i][j-1];
                    }
             printf("%6d",dp[i][j]);
             printf("(%d)",dovat[i][j]);
           } 
         }
         output2();
     }
     }
 

     // hàm main()
     int main()
     {   
         FILE *fp;
         //C:\Users\HONG TRUONG\Desktop
         menu();
         chonM();
        
        fclose(fp);
        getch();
     }