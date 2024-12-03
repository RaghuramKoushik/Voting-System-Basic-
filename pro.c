//program to find the winner of a local election


#include<stdio.h>
#include<stdlib.h>
int voteAge[10];
//total possible candidates
int MaxCan = 5;

//highest vote number
int maxVote1=0,maxVote2=0,n1;

//total number of voters
int voters;

char symbol(int);

int VoterChoice[5];

int CandidateCount[5];

//available symbols
char symbols[5]= { '!', '@', '#', '$', '%' };

//symbol chosen by each candidate
char SymChoiceCan[10];

int voter(int);

//main function
int main()
{
    int n;
    printf("-----------Elections Year 2024-----------\n\n\n\n\n");
    printf("Enter the number of contesting candidates:\n");
    scanf("%d",&n);
    if(n>MaxCan)
     printf("Maximum number of candidates cannot exceed 5\n");
    else
    {
     symbol(n);
     voter(n);
     int winner=0;

// calculating highest voted candidate
    for(int i=0;i<n;i++){
       if(CandidateCount[i]>=maxVote1){
     if(CandidateCount[i]==maxVote1)
      n1++;
     else{
      maxVote2=maxVote1;
      maxVote1=CandidateCount[i];
      n1=1;
     }
 }
    }
    if(n1>1)
     printf("There is a tie between %d members\nReconduct!\n",n1);
    else{
     printf("Here is the list of votes of each candidate:\n");
     for(int i=0;i<n;i++)
     {
        printf("Candidate %c has a total of %d votes\n",SymChoiceCan[i],CandidateCount[i]);
     }
     printf("\033[1;31m");
     printf("THE WINNER IS: %c ,WITH A TOTAL OF %d VOTES\n",SymChoiceCan[winner],maxVote1);
     printf("\033[0m");
    }
}
return 0;
}


//function to check each voter choice
int voter(int n)
{
    printf("Enter total number of voters:\n");
    scanf("%d",&voters);

    for(int i=0;i<n;i++)
    {
        printf("Candidate %d Symbol: %c\n",i+1,SymChoiceCan[i]);
    }

    for (int i = 0; i < voters; i++)
     {
        printf("Enter birth year of voter %d: \n",i+1);
        scanf("%d",&voteAge[i]);
        if(voteAge[i]>2006){
         printf("Ineligible!\n");
         continue;
        }
        printf("Enter voter %d choice, between Candidates (1-%d):\n", i + 1, n);
        scanf("%d", &VoterChoice[i]);
        if (VoterChoice[i] >= 1 && VoterChoice[i] <= n)
         {
            CandidateCount[VoterChoice[i] - 1]++;
        } else
        {
            printf("Invalid choice! Enter again.\n");
            i--;
        }
    }
 return 0;
}

//function to assign symbols to each candidate
char symbol(int n)
{
    printf("Available Symbols: ");

    for (int i = 0; i < 5; i++)
     {
        printf("%c ", symbols[i]);
    }
    printf("\n");

    for (int i = 0,t=0; i < n; i++,t++)
    {
        printf("Enter symbol for candidate %d: ", i + 1);
        scanf(" %c", &SymChoiceCan[i]);
        int isValidSymbol = 0;

        for(int j = 0; j < 5; j++)
        {  // checking for valid choice from voter
            if(SymChoiceCan[i] == symbols[j]){
                isValidSymbol = 1;
                break;
            }
        }
        if(!isValidSymbol)
        {
          printf("Not a valid choice! Please select from the available symbols.\n");
          i--;
          // decrements value of i to reset current loop
        }
        else {
         // Check for duplicate symbols among previously chosen symbols
        for (int k = 0; k < i; k++) {
             if (SymChoiceCan[k] == SymChoiceCan[i]) {
                  printf("Symbols are repeated! Re-Enter!.\n");
                  exit(0);
                   // Exit the program if symbols are repeated
                }
            }
        }
    }
    return 0;
}

