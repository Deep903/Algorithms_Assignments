#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char word1[100] = " ";
    char word2[100] = " ";

        while(strcmp(word1, "-1") || strcmp(word2, "-1") != 0)
        {




        printf("Enter two words sperated by a space (e.g.: cat someone).\nStop with: -1 -1\n");


        scanf("%s %s", word1, word2);

        printf("\n");
        //printf("%s\n%s \n \n", word1, word2);


        int j = strlen(word1); //Stores the length of word 1

        int k = strlen(word2); //Stores the length of word 2

       // printf("Length 1: %d\nLength 2: %d\n", j, k);

        int sol[j+1][k+1];

        int count1 = 0;
        int count2 = 0;
        int first = 0;


      //      printf("  |");
      //      printf("  |");
        int row1 = 0;
        while(row1 < k)
        {
          //  printf(" %c|", word2[row1]);
            row1++;
        }
       // printf("\n");

            while(count1 <= j)
            {
                while(count2 <= k)
                {
                    sol[count1][count2] = 0;

                    if(count1 == 0)
                        sol[count1][count2] = count2;

                    if(count2 == 0)
                        sol[count1][count2] = count1;

                    if(count2 == 0)
                    {
                        if(first == 0)
                        {
                            first = 1;
                          //  printf("  |");
                        }
                      //  else
                      //  printf(" %c|", word1[count1-1]);
                    }
                   // printf(" %d|", sol[count1][count2]);
                    count2++;
                }
              //  printf("\n");
                count2 = 0;
                count1++;
            }


                //LOOP TO FIND INTERIOR SOLUTIONS
            count1 = 0;
            count2 = 0;
            int minimum;
            int up;
            int left;
            int diagonal;

            while(count1 <= j)
            {
                while(count2 <= k)
                {
                    if(count1 == 0)
                        sol[count1][count2] = sol[count1][count2];
                    else if(count2 == 0)
                        sol[count1][count2] = sol[count1][count2];
                    else
                        {
                            up = sol[count1-1][count2];
                            left = sol[count1][count2-1];
                            diagonal = sol[count1-1][count2-1];


                            if(up <= left && up <= diagonal)
                                minimum = up;
                            if(diagonal <= up && diagonal <= left)
                                minimum = diagonal;
                            if(left <= up && left <= diagonal)
                                minimum = left;
                            sol[count1][count2] = minimum + 1;

                           // printf("Minimum: %d, up: %d, left: %d, diagonal: %d \n", minimum, up, left, diagonal);
                            char a = word1[count1-1];
                            char b = word2[count2-1];
                            if(a == b)
                            {
                                //printf("a:%c == b:%c", a, b);
                                sol[count1][count2] = diagonal;
                            }
                        }
                    //printf("sol[%d][%d]= %d  ", count1, count2, sol[count1][count2]);

                    count2++;
                }
                    //printf("\n");
                count2 = 0;
                count1++;
            }
    if(strcmp(word1, "-1") == 0)
        if(strcmp(word2, "-1") == 0)
            break;
//PRINT LOOP
           count1 = 0;
           count2 = 0;
           first = 0;


            printf("  |");
            printf("   |");
            row1 = 0;
        while(row1 < k)
        {
            printf("%3c|", word2[row1]);
            row1++;
        }
        printf("\n");

            while(count1 <= j)
            {
                while(count2 <= k)
                {
                    //sol[count1][count2] = 0;

                   // if(count1 == 0)
                        //sol[count1][count2] = count2;

                   // if(count2 == 0)
                        //sol[count1][count2] = count1;

                    if(count2 == 0)
                    {
                        if(first == 0)
                        {
                            first = 1;
                            printf("  |");
                        }
                        else
                        printf("%2c|", word1[count1-1]);
                    }
                    printf("%3d|", sol[count1][count2]);
                    count2++;
                }
                printf("\n");
                count2 = 0;
                count1++;
            }

        printf("\nedit distance: %d\n\n", sol[j][k]);
        printf("==============================================================================\n\n");



        }

        return 0;
}



