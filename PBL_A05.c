#include<stdlib.h>
#include<stdio.h> 
#include<conio.h>
int kl[100],gt[100],n,dp[101][101],klmax;
//hàm menu
void menu() 
 { 
             /*print menu screen*/ 
             //clrscr(); 
             printf("\t\t\t***********************************\n"); 
             printf("\t\t\t** WELCOME TO CURRENCY CONVERTER **\n"); 
             printf("\t\t\t***********************************\n"); 
             printf("\t\t\t             DINESH THAKUR \n"); 
             printf("\t\t\t***********************************\n"); 
             printf("\t\t\t\t\tMENU\n\n\n"); 
             printf("\t\t\t\t1-$US to EURO\n"); 
             printf("\t\t\t\t2-$US to SWISS FRANC\n"); 
             printf("\t\t\t\t3-$US to YEN\n"); 
             printf("\t\t\t\t4-$US to BRITISH POUND\n"); 
             printf("\t\t\t\t5-EURO to $US\n"); 
             printf("\t\t\t\t6-SWISS FRANC to $US\n"); 
             printf("\t\t\t\t7-YEN to $US\n"); 
             printf("\t\t\t\t8-BRITISH POUND to $US\n"); 
             printf("\t\t\t\tE-to exit at any time.\n\n\n"); 
             printf("\t\t\t***********************************\n\n\n"); 
             getch(); 
 }  
//hàm nhập
void Nhap(int n, int a[], int b[])
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("\n Nhap khoi luong vat %d: ",i); scanf("%d",&a[i]);
        printf("\n Nhap gia tri vat %d: ", i); scanf("%d",&b[i]);
    }
}
//hàm tìm max
int Maxit(int a, int b)
{
    return (a>b?a:b);
}
//hamf khởi tạo giá trị ban đầu
void KT()
{
     int i,j;
     for(i=0;i<=klmax;i++)
     dp[i][0]=0;
     for(j=0;j<=n;j++)
     dp[0][j]=0;
}
// trường hợp một vật được chọn nhiều lần
int TH1()
    {    int i,j,du;
        for(i=1;i<=klmax;i++)
       {printf("\n");
         for(j=1;j<=n;j++)

         { du=i-(i/kl[j])*kl[j];
           dp[i][j]=i/kl[j]*gt[j]+dp[du][n];
           dp[i][j]=(dp[i][j]>dp[i][j-1])?dp[i][j]:dp[i][j-1];
           //max=dp[i][j];
           printf("%5d",dp[i][j]);

          }
       }
    }
 //   trường hợp 1 vật chỉ được chọn 1 lần
 int TH2()
     {   int i,j;
         for(i=1;i<=klmax;i++)
         {
           printf("\n");
           for(j=1;j<=n;j++)
           {
             if(i>=kl[j])
             {
               dp[i][j]=gt[j]+dp[i-kl[j]][j-1];
               dp[i][j]=Maxit(dp[i][j],dp[i][j-1]);
             }
             else dp[i][j]=dp[i][j-1];
             printf("%6d",dp[i][j]);

           }
         }
     }

     // hàm main()
     int main()
     {   
         //C:\Users\HONG TRUONG\Desktop
         menu();
         
         printf("\n Nhap so luong do vat: "); scanf("%d",&n);
         printf("\n Nhap khoi luong toi da tui mang duoc: "); scanf("%d",&klmax);
         Nhap(n,kl,gt); KT();
         TH1();
         getch();
     }