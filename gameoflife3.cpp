// Draft of the game of life
#include <iostream>
#include <stdio.h>
using namespace std;
char world[10] [10];
char world2[10] [10];
int a = 0;
int xSeed[256]; //Initiating the variable that will get the user input for the X coordinate of the Seed
int ySeed[256]; //Same as the xSeed, except for the y coordinate
int Seeds; //Initiating the variable that will tell me how high I will have to list upwards in the array
int neighbors; //Used in the function birth to count how many neighbors a cell has
char var2[4]; //Variable used to enter another seed, only will be used once.
int inc = 0;
int inc2 = 0;
void clearScreen(){
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
//Creating function that will print the gameboard onto the screen.
void gameboard(){ // Making the gameboard. Helped to learn about line continuation :P but ended up just using nested for loops.
    int x, q;
    cout << "\n__| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10";
    for (int x = 1; x < 11; x++) {
                printf("\n%2d| ", x);
                for (q = 1; q < 11; q++) {
                        cout << " " << world[x][q] << "  ";
                }
        }
}
//Creating a function that places the cells on the board
void cells(){
    for(int b=0; b != 11; b++){
        for(inc = 0;inc != 11; inc++){
            world[inc] [b] = '-';
            world2[inc][b] = '-';
    }
    }
}
//Creating function that allows the user to create seed cells.
void seeds(){
    cout << "\n\nHow many seed cells would you wish to have? ";
    cin >> Seeds;
    cout << "\n\nPlease enter the X and Y coordinates for the seed.";
    cout << "\nX: ";
    cin >> xSeed[1];
    cout << "\nY: ";
    cin >> ySeed[1];
    int SeedY = 1;
    int q=1;
    while(SeedY != Seeds){
        SeedY++;
        q++;
        if(q <= Seeds){
        cout << "\n\nPlease enter the X and Y coordinates for the seed.";
        cout << "\nX: ";
        cin >> xSeed[q];
        cout << "\nY: ";
        cin >> ySeed[q];
        }
    }
    int q2 = q; //Alright, variable q is the number of seeds there are in the arrays in the variables xSeed and ySeed, this just assigns that number to a new variable.
    q = 0;
    while(q2 != 0){ //Finnally found a way to change all the seed cells to alive on the gameboard, and let the user chose how many he wants!
        world[xSeed[q2]] [ySeed[q2]] = '+';
        q2--;
    }
}
// Function that creates the neighbors of the seed cells :P
void calculate(){
    unsigned int neighbors;
     for (int m = 0; m < 11; m++)
     {
         for (int n = 0; n < 11; n++)
         {
             neighbors = 0;
             //Begin counting number of neighbors:
             if (world2[m-1][n-1] == '+')
             else if(world[m-1][n-1] == '+'){
                neighbors++;
             }
             if (world2[m-1][n] == '+')
             else if(world[m-1][n] == '+'){
                neighbors++;
             }
             if (world2[m-1][n+1] == '+')
             else if(world[m-1][n+1] == '+'){
                neighbors++
             }
             if (world[m][n-1] == '+') neighbors++;
             if (world[m][n+1] == '+') neighbors++;
             if (world[m+1][n-1] == '+') neighbors++;
             if (world[m+1][n] == '+') neighbors++;
             if (world[m+1][n+1] == '+') neighbors++;

             //Apply rules to the cell:
             if (world[m][n] == '+' && neighbors < 2)
                world[m][n] = '-';
             else if (world[m][n] == '+' && neighbors > 3)
                world[m][n] = '-';
             else if (world[m][n] == '+' && (neighbors == 2 || neighbors == 3))
                world[m][n] = '+';
             else if (world[m][n] == '-' && neighbors == 3)
                world[m][n] = '+';
             else if (world[m][n] == '-' && (neighbors <= 2 || neighbors >= 4))
                world[m][n] = '-';


         }
     }
}

int main(){
cells(); //Assigning values to world[] []
cout << "\t\t\tHello to Conway's Game of Life!";
cout << "\n\t\t\t_______________________________";
cout << "\n\t\t\t  Coded in C++ | By Casey Key";
cout << "\n\t\t\t ____________________________";
cout << "\nRule 1: Any live cell with fewer than two live neighbours dies, as if caused\n\t\t\t      by under-population.";
cout << "\nRule 2: Any live cell with two or three live neighbours lives on to the next\n\t\t\t\t  generation.";
cout << "\nRule 3: Any live cell with more than three live neighbours dies, as if by \n\t\t\t\tovercrowding.";
cout << "\nRule 4: Any dead cell with exactly three live neighbours becomes a live cell, as\n\t\t\t\tif by reproduct";
cout << "\n\t\t  This game is classified as a cellular automaton.";
cout << "\n________________________________________________________________________________";
cin.get();
clearScreen();
gameboard(); //Prints gameboard to screen
seeds();//Allows user to be prompted for seed coordinates
cout << "\n\nInput (Seed Cells)\n";
gameboard();
swap();
calculate();
cout << "\n\nOutput\n";
gameboard();
cin.sync();
cin.get();
return 0;
}
