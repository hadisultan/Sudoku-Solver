#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

const int n = 9;
char dobanner;

int initial(int puzz[][n]);
void own(int puzz[][n]);
int check(int puzz[][n], int row, int column, int value);
int placevalues(int puzz[][n]);
int getzero(int puzz[][n], int&row,int&column);
void print(int puzz[][n]);
void randboard(int puzz[][n]);
void banner();

int main()
{
    system("Color 4E");
    if(dobanner!='N')
    {
        banner();
    }

    char ans;
    int puzz[n][n]  = {0};
    cout<<"Enter A if you would like to make your own grid to be solved or B if you would like for the program to create a random grid to solve: ";
    cin>>ans;
    while(true)
    {
        if(ans=='B'||ans=='A'||ans=='b'||ans=='a')
        {
            break;
        }
        else
        {
            cout<<"You did not enter A or B!"<<endl<<"Enter A if you would like to make your own grid to be solved or B if you would like for the program to create a random grid to solve: ";
            cin>>ans;
        }
    }
    if(ans=='A'||ans=='a')
    {
        cout<<endl;
        own(puzz);
    }
    if(ans=='B'||ans=='b')
    {
        cout<<endl;
        randboard(puzz);
    }
    char leave;
    cout<<endl<<"Do you want to exit? (Enter N for No and anything else for Yes.) ";
    cin>>leave;
    if(leave=='N'||leave=='n')
    {
        cout<<endl<<endl;
        dobanner='N';
        main();
    }

    return 0;
}

void banner()
{
    cout <<" *****  **  **  *****    ******  **   **  **  **      *****  ******  **      **   **  ******  *****   "<<endl;
	cout <<"**      **  **  **  **   **  **  **  **   **  **     **      **  **  **      **   **  **      **  **  "<<endl;
	cout <<" **     **  **  **   **  **  **  ****     **  **      **     **  **  **      **   **  ******  ** **   "<<endl;
	cout <<"   **   **  **  **   **  **  **  ****     **  **        **   **  **  **      **   **  ******  ****    "<<endl;
	cout <<"    **  **  **  **  **   **  **  **  **   **  **         **  **  **  **       ** **   **      ** **   "<<endl;
	cout <<"*****   ******  *****    ******  **   **  ******     *****   ******  ******    **     ******  **  **  "<<endl;
	cout <<"****************************************************************************************************  "<<endl;
	cout <<"                                By Abdulhadi Sultan Qureshi (20100065) & Abdullah Shamail (20100024)  "<<endl<<endl;

}

void randboard(int puzz[][n])
{
    srand (time(NULL));
    int randrow;
    int rancolumn;
    int randval;
    char diff;
    cout<<"Select difficulty of the grid (Enter 'E' for easy, 'M' for medium or 'H' for hard): ";
    cin>>diff;
    while(true)
    {
        if(diff=='E'||diff=='e'||diff=='M'||diff=='m'||diff=='H'||diff=='h')
        {
            break;
        }
        else
        {
            cout<<"You entered an invalid answer (Enter 'Easy', 'Medium' or 'Hard'): ";
            cin>>diff;
        }
    }
    int box;
    if(diff=='E'||diff=='e')
    {
        box=32;
    }
    if(diff=='M'||diff=='m')
    {
        box=27;
    }
    if(diff=='H'||diff=='h')
    {
        box=22;
    }
    int temp[n][n]={0};
    int checkpuzz = 0;
    do
    {

        for(int i = 0; i<n; i++)
        {
            for(int m =0; m<n; m++)
            {
                temp[i][m]=0;
                puzz[i][m]=0;
            }
        }
        for(int i=0;i<box;)
        {
            int randrow = rand()%(8 + 1);
            int randcolumn = rand()%(8 + 1);
            int randval = rand()%(9-1 + 1) + 1;
            if(check(puzz,randrow,randcolumn,randval)==0&&puzz[randrow][randcolumn]==0)
            {
                puzz[randrow][randcolumn]=randval;
                temp[randrow][randcolumn]=randval;
                i++;
            }

        }
        checkpuzz = placevalues(temp);
    }
    while(checkpuzz==-1);
    cout<<endl<<"Here is the random grid: ";
    print(puzz);
    string solve;
    cout<<endl<<"Enter 'Solve' when you are done to get the solution: ";
    cin>>solve;
    while(solve!="Solve"&&solve!="solve")
    {
        cout<<"You did not enter 'Solve'! Please enter again: ";
        cin>>solve;
    }
    placevalues(puzz);
    print(puzz);
}

void own(int puzz[][n])
{
    cout<<"Here is the board: ";
    print(puzz);
    int rn, cn, num;
    cout<<"Enter your numbers with their row and column numbers below. (Enter -1 when you are done.) "<<endl<<endl;
    while(true)
    {
        cout<<"Enter row number: ";
        cin>>rn;
        if(rn==-1)
        {
            cout<<endl<<endl;
            break;
        }
        if(rn<1||rn>9&&rn!=-1)
        {
            while(true)
            {
                cout<<"Value entered is out of bounds, enter a value between 1 and 9: ";
                cin>>rn;
                if(rn>0&&rn<=9||rn==-1)
                {
                    break;
                }
            }
        }
        cout<<"Enter column number: ";
        cin>>cn;
        if(cn==-1)
        {
            cout<<endl<<endl;
            break;
        }
        if(cn<1||cn>9 && cn!=-1)
        {
            while(true)
            {
                cout<<"Value entered is out of bounds, enter a value between 1 and 9: ";
                cin>>cn;
                if(cn>0&&cn<=9||cn==-1)
                {
                    break;
                }
            }
        }

        cout<<"Enter value: ";
        cin>>num;
        if(num==-1)
        {
            cout<<endl<<endl;
            break;
        }

        if(num<1||num>9&&num!=-1)
        {
            while(true)
            {
                cout<<"Value entered is out of bounds, enter a value between 1 and 9: ";
                cin>>num;
                if(num>0&&num<=9||num==-1)
                {
                    break;
                }
            }
        }
        puzz[rn-1][cn-1]=num;
        cout<<"Here is your updated grid: ";
        print(puzz);
    }


     cout<<"Your Sudoku puzzle: ";
     print(puzz);
     if(initial(puzz)==-1)
     {
        cout<<endl<<"The grid is wrong!";
     }
     else
    {
        cout<<endl<<"Solution: ";
         if(placevalues(puzz)==0)
         {
             print(puzz);
         }
         else
         {
             cout<<"No solution.";
         }

    }
}



void print(int puzz[][n])
{
    cout << endl;
   for(int i =0; i<n; i++)
   {
       for(int m = 0 ; m<n; m++)
       {

           if(puzz[i][m]!=0)
           {
                cout<<" "<<puzz[i][m]<<" ";
                if(m+1!=n)
                {
                    cout<<"|";
                }
                if((m+1)%3==0&&(m+1)!=n)
                {
                    cout<<"|";
                }
           }
           else
           {
                cout<<"   ";
                if(m+1!=n)
                {
                    cout<<"|";
                }
                if((m+1)%3==0&&(m+1)!=n)
                {
                    cout<<"|";
                }

           }
       }
        cout<<endl;
        if((i+1)!=n)
        {
            cout<<"-------------------------------------"<<endl;
        }
        if((i+1)%3==0&&(i+1)!=n)
        {
            cout<<"-------------------------------------"<<endl;
        }
   }
}

int check(int puzz[][n],int row, int column, int value)
{
    int error = 0;
    for(int i = 0; i<n; i++)
    {
        if(puzz[row][i]==value)
        {
            error++;
        }
        if(puzz[i][column]==value)
        {
            error++;
        }
    }
    for(int i = 0; i<3; i++)
    {
        for(int m = 0; m<3; m++)
        {
            if(puzz[i+row-row%3][m+column-column%3]==value)
            {
                error++;
            }
        }
    }
    if(error==3)
    {
        return -2;
    }
    else if(error>0)
    {
        return -1;
    }
        return 0;
}

int placevalues(int puzz[][n])
{
    int row = 0;
    int column = 0;

    if(getzero(puzz, row, column) == -1)
       {
          return 0;
       }

    for(int value = 1;value<=9;value++)
    {
        if(check(puzz,row,column,value)==0)
        {
            puzz[row][column] = value;
            if(placevalues(puzz)==0)
            {
                return 0;
            }
            else
            {
                puzz[row][column]=0;
            }
        }
    }
    return -1;
}

int getzero(int puzz[][n], int&row,int&column)
{
   for (row = 0; row < n; row++)
   {
        for (column = 0; column < n; column++)
        {
            if (puzz[row][column] == 0)
            {
              return 0;
            }
        }
    }
    return -1;
}


int initial(int puzz[][n])
{
    int error=0;
    for(int i =0; i<n;i++)
    {
        for(int m = 0; m<n;m++)
        {
            if(puzz[i][m]==0)
            {
                continue;
            }
            else if(puzz[i][m]>0)
            {
                int val = puzz[i][m];
                if(check(puzz,i, m, val)==-1)
                {
                    error++;
                }
            }
        }
    }
    if(error>0)
    {
        return -1;
    }
    return 0;
}
