#include <stdio.h>

char board1[4][5];
char board2[4][4];
char nameX[20], nameO[20];
int gPos, row, column;
void enterElement(char ch);

void introToTicTacToe()
{
    printf("TIC TAC TOE \n");
    printf("Users please enter grid position less than or equal to 16\n");
    printf("'x' user please enter your name ");
    scanf("%s",nameX);
    printf("'o' user please enter your name ");
    scanf("%s",nameO);
    //printBoardWithgPos();
}

void printBoardWithgPos()
{
    for(int i = 0;i < 4; i++)
    {
        for(int j =0;j < 5;j++)
        {
            printf("%c",board1[i][j]);
        
            if((i!=4) && (j!=4))
                printf("%d", ((4*i)+(j+1)));
        }
    printf("\n");
    }
}

void drawBoard()
{
    for(int i = 0;i < 4; i++)
    {
        for(int j =0;j < 5;j++)
        {
            board1[i][j] = '|';
        
            if((i!=4) && (j!=4))
                board2[i][j] = '_';
        }
    }
}

void enterGridPosX()
{
    printf("%s please enter your grid position ", nameX);
    scanf(" %d",&gPos);
    enterElement('X');
}

void enterGridPosO()
{
    printf("%s please enter grid position ",nameO);
    scanf(" %d",&gPos);
    enterElement('O');
}

void printBoard()
{
    for(int i = 0;i < 4; i++)
    {
        for(int j =0;j < 5;j++)
        {
            printf("%c",board1[i][j]);
        
            if((i!=4) && (j!=4))
                printf("%c",board2[i][j]);
        }
        printf("\n");
    }
}

void enterElement(char ch)
{
    if((gPos % 4) != 0)
    {
        row = gPos/4;
        column = (gPos%4)-1;
    }
    else
    {
        row = (gPos/4) - 1;
        column = (gPos%4) +3;
    }
    
    for (int i = 0;i < 4;i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if((i==row) && (j==column))
            {
                board2[i][j] = ch;
            }
        }    
        
    }  
}


char checkHortVert()
{
    int countXH = 0;
    int countXV = 0;
    int countOH = 0;
    int countOV = 0;
  
    for(int i = 0;i < 4; i++)
    {
        for(int j =0;j < 4; j++)
        {   
            if(board2[i][j] == 'X')
                countXH++;    
        
            if(board2[j][i] == 'X') 
                countXV++;
        
            if(board2[i][j] == 'O')
                countOH++;
        
            if(board2[j][i] == 'O') 
                countOV++;
        }
        if((countXH == 4) || (countXV == 4))
        {
            printf("%s is winner  CHV\n",nameX);
            return 'X';
        }
        else if((countOH == 4) || (countOV == 4))
        {    
            printf("%s is winner CHV \n",nameO);
            return 'O';
        }
        countOH = 0;
        countXH = 0;
        countOV = 0;
        countXV = 0;
    }
    return 0;  
}

char checkDiag()
{
    int countXLR =0;
    int countXRL =0;
    int countORL = 0;
    int countOLR = 0;
    for(int i = 0;i < 4;i++)
    {
        for(int j =0;j < 4;j++)
        {   
            if(i==j)
            {
                if(board2[i][j] == 'X')
                {
                    countXLR++;
                    //printf("countXLR : %d\n", countXLR);
                }
                if(board2[i][j] == 'O')
                {
                    countOLR++;
                    //printf("countOLR :%d\n", countOLR);
                }
            }
            
            if((i+j) == 3)
            {
                if(board2[i][j] == 'X')
                {
                    countXRL++;
                    //printf("countXRL: %d\n", countXRL);
                }
                if(board2[i][j] == 'O')
                {
                    countORL++;
                    //printf("countORL :%d\n", countORL);
                }
            }
        }
        if((countXRL == 4) || (countXLR == 4))
        {
            printf("%s is winner CDLR \n",nameX);
            return 'X';
        }
        else if((countORL == 4) || (countOLR == 4))
        {
            printf("%s is winner CDLR \n",nameO);
            return 'O';
        }
    }
    return 0;
}


int checkWinner()
{
    char ch1 = ' ';
    char ch2 = ' ';
    //printf("in checkWinner");
    ch1 = checkHortVert();
    ch2 = checkDiag();
    
    if((ch1 != ' ') || (ch2 != ' '))
    {
        if((ch1 == 'X') || (ch2 == 'X'))
        {    
            printf("%s is the winner CW\n",nameX);
            return 1;
        }
        else if((ch1 == 'O') || (ch2 == 'O'))
        {
            printf("%s is the winner CW\n",nameO);
            return 1;
        }
        
    }
    else 
        return 0;
}


int main()
{   
    int check ;
    introToTicTacToe();
    drawBoard();
    for(int moves = 0; moves < 8; moves++)
    {
        enterGridPosX();
        enterGridPosO();
        printBoard();
        if(moves > 2)
        {
            check = checkWinner();
            if( check == 1)
            {
                printf(" winner found Main\n");
                break;
            }
            else if((check == 0) && (moves == 7))
                printf("Game is a Tie\n");
        }
    }
   printf("C =%d",check);
   return 0;
}
