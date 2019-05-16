#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

//The variables are used for the FAT32 Layout
char BS_OEMName[8];
int16_t BPB_BytsPerSec;
int8_t BPB_SecPerClus;
int16_t BPB_RsvdSecCnt;
int8_t BPB_NumFATs;
int16_t BPB_RootEntCnt;
char BS_VolLab[11];
int32_t BPB_FATSz32;
int32_t BPB_RootClus;

int32_t RootDirSectors = 0;
int32_t FirstDataSector = 0;
int32_t FirstSectorofCluster = 0;

//The below 2 structs are used to represent each record
struct __attribute__((__packed__)) DirectoryEntry{
    char DIR_Name[11];
    uint8_t DIR_Attr;
    uint8_t Unused[18];
    uint16_t DIR_FirstClusterHigh;
    uint8_t Unused2[4];
    uint16_t DIR_FirstClusterLow;
    uint32_t DIR_FileSize;
};

struct DirectoryEntry dir[16];

FILE *fp; //File pointer for the FAT32 we open


#define WHITESPACE " \t\n" //Used to split command line into tokens

#define MAX_COMMAND_SIZE 255 //The max command size is 255

#define Max_NUM_ARGUMENTS 5 //Up to 5 arguments can be entered, really we only need up to 4 though



/*
int LBAToOffset(int32_t sctor){
    return (((sector-2) * BPB_BytsPerSec) + (BPB_BytsPerSec * BPB_RsvdSecCnt) + (BPB_NumFATs * BPB_FATSz32 * BPB_BytsPerSec));
} */




int main()
{

    char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE ); //This stores the commands given by the user.

    while(1==1)
    {
         printf ("mfs> "); //Print mfs prompt to show program is ready for input
         while(!fgets(cmd_str, MAX_COMMAND_SIZE, stdin)); //Read all text in commandline
         char *token[Max_NUM_ARGUMENTS]; //Parse Input
         int token_count = 0;
         char *arg_ptr; //Pointer to token, parsed by strsep
         char *working_str = strdup(cmd_str);
         char *working_root = working_str; //Move the working_str pointer to remember its original value for deallocation
         while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) &&           //Tokenize the input string. Whitespace is the delimiter.
              (token_count<Max_NUM_ARGUMENTS))
                {
                token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
                if( strlen( token[token_count] ) == 0 )
                    {
                    token[token_count] = NULL;
                    }
                token_count++;
                }



        fp = fopen("fat32.img", "r");

        if(fp == NULL) perror("File system image not found.");

        //Reading and printing Bytes Per Sector
        fseek(fp, 11, SEEK_SET);
        fread(&BPB_BytsPerSec, 1, 2, fp);
        printf("BPB_BytesPerSec: %d, %x\n", BPB_BytsPerSec, BPB_BytsPerSec);

        //Reading and printing Sectors Per Cluster
        fseek(fp, 13, SEEK_SET);
        fread(&BPB_SecPerClus, 1, 1, fp);
        printf("BPB_SecPerClus: %d %x\n", BPB_SecPerClus, BPB_SecPerClus);

        //Reading and printing Reserved Sector Count
        fseek(fp, 14, SEEK_SET);
        fread(&BPB_RsvdSecCnt, 1, 2, fp);
        printf("BPB_RsvdSecCnt: %d %x\n", BPB_RsvdSecCnt, BPB_RsvdSecCnt);

        //Reading and printing the count of FAT data structures
        fseek(fp, 16, SEEK_SET);
        fread(&BPB_NumFATs, 1, 1, fp);
        printf("BPB_NumFATs: %d %x\n", BPB_NumFATs, BPB_NumFATs);

        //Reading and printing the count of FAT32 32-bit sectors that are occupied with one FAT.
        fseek(fp, 36, SEEK_SET);
        fread(&BPB_FATSz32, 1, 4, fp);
        printf("BPB_FATSz32: %d %x\n", BPB_FATSz32, BPB_FATSz32);




    fclose(fp);
    }




    return 0;
}
