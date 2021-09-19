//
//  s6q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
/*
     [Video Games File System operating instructions]
 *** Please modify the absolute path of the input and output files if you want to verify this program.
 * The system default has 5 games, so you can first through the menu in 1) load the data from the txt file.
 * When you want modify the record, please use "/" instead of "space".
 * It is a good habit to save it all the time.
 
*/

// Declares the absolute path to the input/output file.
const char *FILE_PATH = "/Users/lewiszhang/Documents/Xcode/S6/GameData.txt";

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 30  // The maximum number of characters in the string of Game Info.
#define N 1000  // The maximum number of games the system can store.

struct Game // Game information structure.
{
    char title[len];        // Game title.
    char platform[len];     // Game platform.
    char year[len];         // Game release year.
    char developer[len];    // Game developer.
    char status[len];// Game borrow status.
    char name[len];         // leasee name.
    char date[len];         // lease date.
}Game[N]; // Defines an array of structs.

/* Defines the global variable:
n represents the number of games currently recorded;
m represents the number of newly increased games. */
int k=1,n=0, m=0;
                   
// Declare some functions.
void seek(void);        // "Seek info" function.
void modify(void);      // "modify info" function.
void insert(void);      // "insert info" function.
void del(void);         // "delete info" function.
void display(void);     // "display info" function.
void menu(void);        // "Menu" function.
void save(void);        // "Save info to file" function.
void get(void);         // "Get info from file" function.

int main()
{
    while(k)
    {
        menu(); // Call "Menu" function.
    }
    
    return 0;
}

// "Seek" function.
void seek()
{
    int i,flag; // "flag" indicates whether the search was successful.
    char tem[len];
    
    flag=0;
    printf("Please enter the name of the game you want to query:\n");
    scanf("%s",tem);
    for(i=0;i<n;i++)
    {
        if(strcmp(Game[i].title,tem)==0)
        {
            flag=1;
            printf(" Game_Title       Platform      Release_Year      Developer        Status        leasee name      lease_date\n");
            printf("--------------------------------------------------------------------------------------------------------------\n");
            printf("%10s     %10s     %10s         %10s     %10s     %10s         %10s\n",Game[i].title,Game[i].platform,Game[i].year,Game[i].developer,Game[i].status,Game[i].name,Game[i].date);
        }
    }
    if(0==flag)
    {
        printf("This game does not exist!\n");
    }
    printf("\n\n");
}

// "Modify" fuction.
void modify()
{
    // "item" represents the submenu number to be modified.
    // "num" saves the sequence number of the game to be modified.
    int i,item,num=-1;
    char tem[len],Ttem[len],Ptem[len],Ytem[len],Btem[len],Dtem[len],Ntem[len],Datetem[len]; // Declare some temporary strings.
    printf("Please enter the title of the game you want to modify:\n");
    scanf("%s",tem);
    for(i=0;i<n;i++)
    {
        if(strcmp(Game[i].title,tem)==0) // Find out if this game is in the system.
        {
            num=i; // Assign the sequence number to "num".
        }
        
        if(num!=-1)
        {// Display the submenu.
            printf("1.Modified game title\n");
            printf("2.Modified game platform\n");
            printf("3.Modified release date\n");
            printf("4.Modify developer\n");
            printf("5.Modify status\n");
            printf("6.Modify leasee name\n");
            printf("7.Modify lease date\n");
            printf("8.Save & Exit current menu\n");
            while(1)
            {
                printf("Please select the submenu number:");
                scanf("%d",&item);
                printf("Please use \"/\" instead of \"space\".\n");
                // Respond accordingly based on user input.
                switch(item)
                {
                case 1:
                    printf("Please enter new game title:\n");
                    scanf("%s",Ttem);
                    strcpy(Game[num].title,Ttem);
                        break;
                case 2:
                    printf("Please enter new game platform:\n");
                    scanf("%s",Ptem);
                    strcpy(Game[num].platform,Ptem);
                        break;
                case 3:
                    printf("Please enter new release date:\n");
                    scanf("%s",Ytem);
                    strcpy(Game[num].year,Ytem);
                        break;
                case 4:
                    printf("Please enter new developer:\n");
                    scanf("%s",Dtem);
                    strcpy(Game[num].developer,Dtem);
                        break;
                case 5:
                    printf("Please enter new status:\n");
                    scanf("%s",Btem);
                    strcpy(Game[num].status,Btem);
                        break;
                case 6:
                    printf("Please enter new leasee name:\n");
                    scanf("%s",Ntem);
                    strcpy(Game[num].name,Ntem);
                        break;
                case 7:
                    printf("Please enter new lease date:\n");
                    scanf("%s",Datetem);
                    strcpy(Game[num].date,Datetem);
                        break;
                case 8:
                        save();
                        return;
                default:
                        printf("Please choose between 1-8\n");
                }
                printf("\nRevised successfully!\nEnter 8 to save and exit from sub-menu.\n\n");
            }
        }
    }
    if (num==-1)
    {
        printf("Revision failed!\n\n");
    }
}

// "insert" function.
void insert()
{
    printf("How many games do you want to add:\n");
    scanf("%d",&m);
    if(m>0)
    {
        for(int i=n; i<n+m; i++) // Display the submenu.
        {
            printf("Please use \"/\" instead of \"space\".\n");
            printf("Please enter the \"Title\" of the %d game:\n",i+1);
            scanf("%s",Game[i].title);
            printf("Please enter the \"Platform\" of the %d game:\n",i+1);
            scanf("%s",Game[i].platform);
            printf("Please enter the \"Release year\" of the %d game:\n",i+1);
            scanf("%s",Game[i].year);
            printf("Please enter the \"Developer\" of the %d game:\n",i+1);
            scanf("%s",Game[i].developer);
            printf("Please enter the \"Status\" of the %d game\n",i+1);
            scanf("%s",Game[i].status);
            printf("Please enter the \"leasee name\" of the %d game:\n",i+1);
            scanf("%s",Game[i].name);
            printf("Please enter the \"lease date\" of the %d game:\n",i+1);
            scanf("%s",Game[i].date);
        }
        n+=m; // "n+m" update the number of existing games and assign the result to "n".
    }
    printf("Information added successfully！\n\n");
    printf("\n\n");
}

// "Delete" function.
void del()
{
    int i,j,flag=0; // "flag" is show if the search success, 0 means the search failure, 1 means the search success.
    char tem[len+1];
    printf("Please enter the title of the game you want to delete:\n");
    scanf("%s",tem);
    
    for(i=0;i<n;i++) // Find the game record to delete.
    {
        if(strcmp(Game[i].title,tem)==0)
        {
            flag=1;
            for(j=i;j<n-1;j++)
            {
                Game[j]=Game[j+1]; // The following game records move forward.
            }
        }
        if(flag==1)
        {
            printf("Delete successfully!\n");
            n--; // After successful deletion, the number of students will be reduced by 1.
        }
    }
    if(flag==0) // Some solutions for search failures.
    {
        printf("This game does not exist！\n");
    }
    printf("\n\n");
}

// "Display" function
void display()
{
    int i;
    printf("Total %d game records:\n",n);
    if(0!=n)
    {
        printf(" Game_Title       Platform      Release_Year      Developer        Status        leasee name      lease_date\n");
        printf("--------------------------------------------------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("%10s     %10s     %10s         %10s     %10s     %10s         %10s\n",Game[i].title,Game[i].platform,Game[i].year,Game[i].developer,Game[i].status,Game[i].name,Game[i].date);
        }
    }
    printf("\n\n");
}
 
// "Menu" function.
void menu()
{
    int num;
    // Display the Main Menu.
    printf("[Video Games File System]\n");
    printf("  Menu\n");
    printf("  1.Load the game records from the file\n  2.Query game record\n  3.Modify game record\n  4.Add game record\n  5.Delete game records\n  6.Display current all game records\n  7.Save\n  8.Exit system\n");
    printf("Please select the menu number:");
    scanf("%d",&num);
    switch(num) // Respond accordingly based on user input.
    {
        case 1:get();
                break;
        case 2:seek();
                break;
        case 3:modify();
                break;
        case 4:insert();
                break;
        case 5:del();
                break;
        case 6:display();
                break;
        case 7:save();
                break;
        case 8:k=0;
                break;
        default:printf("Please choose between 1-8\n");
    }
    printf("\n");
}

// "Save" function, write records to txt file.
void save()
{
    
    FILE *fp = fopen(FILE_PATH, "w+" );
    
        if (fp == NULL)
        {   // Check does input file exist.
            puts("Error opening myFile.txt file!\n");
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                fprintf(fp,"%s %s %s %s %s %s %s\n",Game[i].title,Game[i].platform,Game[i].year,Game[i].developer,Game[i].status,Game[i].name,Game[i].date);
            }
            fclose(fp);
        }
        
        printf("Save successfully!！");
        printf("\n\n");
}

// "Get" function, read records from txt file.
void get()
{
    FILE *fp = fopen(FILE_PATH, "r" );
    int a,i;
    printf("Please enter the number of games to read:");
    printf("(Hint, the system has 5 games by default.)\n");
    scanf("%d",&a);
    
    if (fp == NULL)
    {   // Check does input file exist.
        puts("Error opening myFile.txt file!\n");
    }
    else
    {
        for(i=0;i<a;i++)
        {
            fscanf(fp,"%s %s %s %s %s %s %s\n",Game[i].title,Game[i].platform,Game[i].year,Game[i].developer,Game[i].status,Game[i].name,Game[i].date);
        }
        fclose(fp);
    }
    // Display the records which get from file.
    printf(" Game_Title       Platform      Release_Year      Developer        Status        leasee name      lease_date\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<a;i++)
    {
        printf("%10s     %10s     %10s         %10s     %10s     %10s         %10s\n",Game[i].title,Game[i].platform,Game[i].year,Game[i].developer,Game[i].status,Game[i].name,Game[i].date);
    }
    n=a; // Assign a to n , refresh current records.
    printf("\n\n");
}
