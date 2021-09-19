//
//  s9q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
//  *** Please modify the absolute path of the input and output files if you want to verify this program.
//
#include <stdio.h>
#define CUSTOMER_NUM 5

/* Declares the absolute path to the input/output file */
const char *OUTPUT_FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S9/s9q1/s9q1/cutomers.txt";

/* Declare myCustomers array */
int myCustomers [5][2] = {{86956, 1}, {36568, 3}, {6565, 0}, {999555, 22}, {85446, 88}};

/* zip_custs structure definition */
struct zip_custs
{
    int zip_code;
    int customer_count;
 };

int main(void)
{
    struct zip_custs azip_custs[CUSTOMER_NUM]; /* Define one struct zip_custs variable */
    
    for (int i=0; i<CUSTOMER_NUM; i++)
    {/* Store the elements of myCustomers into azip_custs */
        azip_custs[i].zip_code = myCustomers[i][0];
        azip_custs[i].customer_count = myCustomers[i][1];
    }
    
    /* Open for writing */
    FILE *fp = fopen(OUTPUT_FILE_PATH, "wb+" );
        
    if (fp == NULL)
        {   /* Check does input file exist */
            puts("Error creating/opening cutomers.dat file!\n");
        }
        else
        {
            for (int i=0; i<CUSTOMER_NUM; i++)
            {/* Print elements into cutomers.dat file */
                //printf("%d,%d\n",azip_custs[i].zip_code,azip_custs[i].customer_count);
                fwrite(&azip_custs[i], sizeof(struct zip_custs), 1, fp);
                //fprintf(fp, "%d,%d\n",azip_custs[i].zip_code,azip_custs[i].customer_count);
            }
            fclose(fp);/* Close file */
        }
    
    /* Tell the user the process is complete */
    printf("Data writes successfully!\n");
        
    return 0;
}
