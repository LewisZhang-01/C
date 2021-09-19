//
//  s8q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
//  *** Please modify the absolute path of the input and output files if you want to verify this program.
//
#include <stdio.h>
#include <string.h>

// Declares the absolute path to the input/output file.
const char *COUNTIES_FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S8/s8q1/s8q1/counties.txt";
const char *TOWNS_FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S8/s8q1/s8q1/towns.txt";

// County structure definition.
struct county
{
    char *longName; // Define pointer longName.
    char *shortName; // Define pointer shortName.
    unsigned int population; // Define unsigned integer population.
};

// Town structure definition.
struct town
{
    char *name; // Define pointer name.
    unsigned int population; // Define unsigned integer population.
    struct county aCounty;// Nested structures.
};

int main(void)
{
    // Open for reading.
    FILE *fp_c = fopen(COUNTIES_FILE_PATH, "r" );
    FILE *fp_t = fopen(TOWNS_FILE_PATH, "r" );
    
    struct town Town;// Declaration of structure.

    if (fp_c == NULL )
    {   // Check does input file exist.
        puts("Error opening counties.txt file!\n");
        return -1;
    }
    else
    {
        if (fp_t == NULL )
        {   // Check does input file exist.
            puts("Error opening towns.txt file!\n");
            return -1;
        }
        
        // Read town name, population and county name from file.
        for(int i=0;i<5;i++)
        {
            fscanf(fp_t,"%s %u %s",&Town.name,&Town.population,&Town.aCounty.shortName);
            printf("%s %u %s ",&Town.name,Town.population,&Town.aCounty.shortName);
            
            char temp[10]; // Declare a temp array.
            strcpy(temp, &Town.aCounty.shortName); // Copy the county name to temp.
            int flag = 0; // Declare a flag to check if it is the first time.
            
            // Read county long name, short name and population.
            for(int j=0;j<4;j++)
            {
                fscanf(fp_c,"%s %s %u",&Town.aCounty.longName,&Town.aCounty.shortName,&Town.aCounty.population);
                
                // If it's the same county then print out the county information.
                if (strcmp(temp, &Town.aCounty.longName)==0)
                {
                    if (flag==0) // Check if it is the first time.
                    {
                        printf("%s %u\n",&Town.aCounty.shortName,Town.aCounty.population);
                        break;
                    }
                }
                else // Otherwise, find the county information corresponding to the given county name.
                {
                    // The struct starts over.
                    fclose(fp_c);
                    FILE *fp_c = fopen(COUNTIES_FILE_PATH, "r" );
                    
                    if (flag==0)
                    {
                        flag = 1; // Change the flag to have been passed once.
                        for (int i=0; i<4; i++)
                        {// Read county long name, short name and population.
                            fscanf(fp_c,"%s %s %u",&Town.aCounty.longName,&Town.aCounty.shortName,&Town.aCounty.population);
                            // If it's the same county then print out the county information.
                            if (strcmp(temp, &Town.aCounty.longName)==0)
                            {
                                printf("%s %u\n",&Town.aCounty.shortName,Town.aCounty.population);
                                break;
                            }
                        }
                    }
                }
            }
        }
    // Close the files.
    fclose(fp_t);
    fclose(fp_c);
    }
    return 0;
}
