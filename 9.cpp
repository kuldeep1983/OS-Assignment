#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
int i,j,n,a[10],frame[10],no,k,avail,count=0,digit;
            printf("Enter the number of pages:\n");
            scanf("%d",&n);
            srand ( time(NULL) );
       
        for (i = 0; i< n; i++)  
		    {
            int digit = rand()%10;
            a[i] = digit;
            }
            printf("Randomly generated page-reference string is:");
            for(i=0;i<n;i++)
            printf(" \n%d",a[i]);
            printf("\nEnter the number of frames:");
            scanf("%d",&no);
for(i=0;i<no;i++)
            frame[i]= -1;
                        j=0;
                        printf("ref string\t page frames\n");
for(i=0;i<n;i++)
                        {
                                    printf("%d\t\t",a[i]);
                                    avail=0;
                                    for(k=0;k<no;k++)
if(frame[k]==a[i])
                                                avail=1;
                                    if (avail==0)
                                    {
                                                frame[j]=a[i];
                                                j=(j+1)%no;
                                                count++;
                                                for(k=0;k<no;k++)
                                                printf("%d\t",frame[k]);
}
                                    printf("\n");
}
                        printf("Page Fault Is %d",count);
                        return 0;
}


