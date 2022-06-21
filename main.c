#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

//declaring global variables
char mode;
char T[9] = {'_','-','_','-','_','-','-','_','-'};
char Tres[9] = {'_','-','_','-','_','-','-','_','-'};
char comp,player;
int x,comp_turn,p1_turn , p2_turn , player_turn = 1 ,winner = 0,draw = 0,turn = 0;
int p1_score  = 0,p2_score = 0,min = 1, max = 9;
//drawing the menu interface
void menu_draw (){
     printf("\n\n\n\n\n");
     printf("__________________________________TIC TAC TOE___________________________________");
     printf("              |__|__|            |__X__|__O__|             |__|__|\n");
     printf("              |__|__|                                      |__|__|\n");
     printf("              |__|__|     - Press '1' to play 1P mode.     |__|__|\n");
     printf("              |__|__|                                      |__|__|\n");
     printf("              |__|__|     - Press '2' to play 2P mode.     |__|__|\n");
     printf("              |__|__|                                      |__|__|\n");
     printf("              |__|__|     - Press 'e' to exit.             |__|__|\n");
     printf("              |__|__|                                      |__|__|\n");
     printf("              |__|__|______________________________________|__|__|\n");
}
// choosing gameplay mode logic
void choice_mode (){
    enter_againe:
    switch(getch()){
       case '1':
        mode = 1;
        break;
       case '2':
        mode = 2;
        break;
       case 'e':
        mode = 3;
        break;
       default:
        goto enter_againe;
    }
}
// choosing symbole logic
void X_or_O(){
    printf("Press 'B' to back to menu. ");
    printf("\n\n\n\n\n\n\n\n\t\t\t   To choose X press 'x'.\n");
    printf("\t\t\t   To choo

           se O press 'o'.\n");
    enter_againe:
    switch(getch())
    {
      case 'x':
          player = 'X';
          comp = 'O';
          break;
      case 'o':
          player = 'O';
          comp = 'X';
          break;
      case 'b':
          main();
      default:
          goto enter_againe;
    }
    system("cls");
}
void oneP_drawing(){
          //drawing one player mode interface
    printf("- The player is '%c'.\t\t\t       Notice : Enter the chosen number\n",player);
    printf("- The computer is '%c'.\t\t\t                to place 'X' or 'O'\n\n",comp);
    printf("\t\t\t\t\t\t\t    1 , 2 , 3\n\t\t\t\t\t\t\t    4 , 5 , 6\n\t\t\t\t\t\t\t    7 , 8  ,9\n");
   x = 0;
  for(int i = 1 ; i <= 13; i++)
   {
       for(int j = 1 ; j <= 3; j++)
       {
        if(j == 1)
         printf("\t\t\t      |");
        if(i == 5 || i == 9 || i == 3 || i == 7 || i == 11 || i == 13 || i == 1)
         continue;
        else
         printf("    |");
       }
       for(int j = 1 ; j <= 1 ; j++)
       {
          if(i == 5 || i == 9 || i == 13 || i == 1)
            printf("--------------|");
       }
       for(int j = 1 ; j <= 3 ; j++)
       {
          if(i == 3 || i == 7 || i == 11)
          {
            printf("  %c |",T[x]);
            x++;
          }
       }
     printf("\n");
   }
   // reset logic values in draw case
   // and choosing to restart game or back to menu inputs logic
   if(draw == 1)
   {
    player_turn = 1;
    draw = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t          DRAW !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    switch(getch())
    {
      case 'r':
          system("cls");
          oneP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
   }
   // reset logic values in player win case
   // and choosing to restart game or back to menu inputs logic
   else if(winner == 1)
   {
    player_turn = 1;
    winner = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t       Player win !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    enter_againe:
    switch(getch())
    {
      case 'r':
          system("cls");
          oneP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
    }
    // reset logic values in computer win case
   // and choosing to restart game or back to menu inputs logic
   else if(winner == 2)
   {
    player_turn = 1;
    winner = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t       computer win !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    switch(getch())
    {
      case 'r':
          system("cls");
          oneP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
    }
    // keep printing enter the number while draw != 1 or winner != 1 or 2
   else
   {
     printf("\n\t\t\tEnter the number : ");
   }
}
//player inputs logic
void player_input_logic(){
        place_full_1:
    scanf("%d",&p1_turn); //take value from player
    if(T[p1_turn - 1] == 'X' || T[p1_turn - 1] == 'O'|| p1_turn <= 0 || p1_turn > 10) //checking if choosen place is full
        goto place_full_1;
    else
    {
     T[p1_turn - 1] = player; //filling place with player choosen symbole
     turn++;
    }
}
void comp_input_logic(){
       place_full_2:
    srand(time(NULL));
    comp_turn = (rand() % (max - min + 1)) + min; //generate a randome number
    if(T[comp_turn - 1] == 'X' || T[comp_turn - 1] == 'O'|| comp_turn <= 0 || comp_turn > 10) //checking if choosen place is full
        goto place_full_2;
    else
    {
     T[comp_turn - 1] = comp;//filling place with computer choosen symbole
     turn++;
    }
    sleep(1);
}
void checking_if_PLAYERwinner(){
          //checking for player win by comparing rows and columns and diagonals if they have the same player choosen symbole
    if((T[0] == T[1] && T[0] == T[2]) || (T[3] == T[4] && T[3] == T[5]) || (T[6] == T[7] && T[6] == T[8])&& (T[0] == player || T[3] == player || T[6] == player))
    {
      winner = 1;
    }
    else if((T[0] == T[3] && T[0] == T[6]) || (T[1] == T[4] && T[1] == T[7]) || (T[2] == T[5] && T[2] == T[8])&& (T[0] == player || T[1] == player || T[2] == player))
    {
      winner = 1;
    }
    else if((T[0] == T[4] && T[0] == T[8]) || (T[2] == T[4] && T[2] == T[6]) && (T[0] == player || T[2] == player))
    {
      winner = 1;
    }
}
void checking_if_COMPwinner(){
          //checking for player win by comparing rows and columns and diagonals if they have the same comp choosen symbole
    if((T[0] == T[1] && T[0] == T[2]) || (T[3] == T[4] && T[3] == T[5]) || (T[6] == T[7] && T[6] == T[8]) && (T[0] == comp || T[3] == comp || T[6] == comp))
    {
      winner = 2;
    }
    else if((T[0] == T[3] && T[0] == T[6]) || (T[1] == T[4] && T[1] == T[7]) || (T[2] == T[5] && T[2] == T[8]) && (T[0] == comp || T[1] == comp || T[2] == comp))
    {
      winner = 2;
      p2_score++;
    }
    else if((T[0] == T[4] && T[0] == T[8]) || (T[2] == T[4] && T[2] == T[6]) && (T[0] == comp || T[2] == comp))
    {
      winner = 2;
    }
}
//the main one player mode function
void oneP_mode (){
  X_or_O();
  play_againe:
  //always X begin first
  if(player == 'X')
  {
    if(player_turn == 1)
    {
     system("cls");
     oneP_drawing();
     player_input_logic();
     player_turn = 2;
     checking_if_PLAYERwinner();
      if(winner != 1)
     checking_for_draw();
    }
    else
    {
     system("cls");
     oneP_drawing();
     comp_input_logic();
     player_turn = 1;
     checking_if_COMPwinner();
      if(winner != 2)
     checking_for_draw();
    }
  }
  else
  {
   if(player_turn == 1)
    {
     system("cls");
     oneP_drawing();
     comp_input_logic();
     player_turn = 2;
     checking_if_COMPwinner();
      if(winner != 2)
     checking_for_draw();
    }
    else
    {
     system("cls");
     oneP_drawing();
     player_input_logic();
     player_turn = 1;
     checking_if_PLAYERwinner();
      if(winner != 1)
     checking_for_draw();
    }
  }
  goto play_againe;
}
void twoP_drawing(){
          //drawing two player mode interface
  printf("- The player 1 is 'X'.\t\t\t       Notice : Enter the chosen number\n");
  printf("- The player 2 is 'O'.\t\t\t                to place 'X' or 'O'\n\n");
  printf("     +P2 score : %d\t\t\t\t\t    1 , 2 , 3\n\t\t\t\t\t\t\t    4 , 5 , 6\n\t\t\t\t\t\t\t    7 , 8  ,9",p2_score);
  printf("\t\t     +P1 score : %d\n",p1_score);

   x = 0;
  for(int i = 1 ; i <= 13; i++)
   {
       for(int j = 1 ; j <= 3; j++)
       {
        if(j == 1)
         printf("\t\t\t      |");
        if(i == 5 || i == 9 || i == 3 || i == 7 || i == 11 || i == 13 || i == 1)
         continue;
        else
         printf("    |");
       }
       for(int j = 1 ; j <= 1 ; j++)
       {
          if(i == 5 || i == 9 || i == 13 || i == 1)
            printf("--------------|");
       }
       for(int j = 1 ; j <= 3 ; j++)
       {
          if(i == 3 || i == 7 || i == 11)
          {
            printf("  %c |",T[x]);
            x++;
          }
       }
     printf("\n");
   }
   //same code of one player mode
   if(draw == 1)
   {
    player_turn = 1;
    draw = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t          DRAW !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    switch(getch())
    {
      case 'r':
          twoP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
   }
   else if(winner == 1)
   {
    player_turn = 1;
    winner = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t       Player 1 win !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    enter_againe:
    switch(getch())
    {
      case 'r':
          twoP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
    }
   else if(winner == 2)
   {
    player_turn = 1;
    winner = 0;
    turn = 0;
    for(int i = 0 ; i < 9; i++)
     T[i] = Tres[i];
    printf("\n\t\t\t       Player 2 win !!\n");
    printf("Press 'R' to restart the game.\n");
    printf("Press 'B' to back to menu.");
    switch(getch())
    {
      case 'r':
          twoP_mode ();
          break;
      case 'b':
          main();
          break;
      default:
          goto enter_againe;
    }
    }
   else
   {
    if (player_turn == 1)
    {
     printf("\n\t\t\tP1 turn.\n");
     printf("\n\t\t\tEnter the number : ");
    }
    else
    {
     printf("\n\t\t\tP2 turn.\n");
     printf("\n\t\t\tEnter the number : ");
    }
   }
}
//player 1 inputs logic
void P1_input_logic(){
        place_full_1:
    scanf("%d",&p1_turn);
    if(T[p1_turn - 1] == 'X' || T[p1_turn - 1] == 'O'|| p1_turn <= 0 || p1_turn > 10) //checking if choosen place is full
        goto place_full_1;
    else
    {
     T[p1_turn - 1] = 'X'; //filling place with player 1 symbole
     player_turn = 2;
     turn++;
    }
}
//player 2 inputs logic
void P2_input_logic(){
        place_full_2:
    scanf("%d",&p2_turn);
    if(T[p2_turn - 1] == 'X' || T[p2_turn - 1] == 'O'|| p2_turn <= 0 || p2_turn > 10) //checking if choosen place is full
        goto place_full_2;
    else
    {
     T[p2_turn - 1] = 'O'; //filling place with player 2 symbole
     player_turn = 1;
     turn++;
    }
}
void checking_if_P1winner(){
               //checking for player win by comparing rows and columns and diagonals if they have the same player 1 symbole
    if((T[0] == T[1] && T[0] == T[2]) || (T[3] == T[4] && T[3] == T[5]) || (T[6] == T[7] && T[6] == T[8])&& (T[0] == 'X' || T[3] == 'X' || T[6] == 'X'))
    {
      winner = 1;
      p1_score++;
    }
    else if((T[0] == T[3] && T[0] == T[6]) || (T[1] == T[4] && T[1] == T[7]) || (T[2] == T[5] && T[2] == T[8])&& (T[0] == 'X' || T[1] == 'X' || T[2] == 'X'))
    {
      winner = 1;
      p1_score++;
    }
    else if((T[0] == T[4] && T[0] == T[8]) || (T[2] == T[4] && T[2] == T[6]) && (T[0] == 'X' || T[2] == 'X'))
    {
      winner = 1;
      p1_score++;
    }
}
void checking_if_P2winner(){
               //checking for player win by comparing rows and columns and diagonals if they have the same player 2 symbole
    if((T[0] == T[1] && T[0] == T[2]) || (T[3] == T[4] && T[3] == T[5]) || (T[6] == T[7] && T[6] == T[8]) && (T[0] == 'O' || T[3] == 'O' || T[6] == 'O'))
    {
      winner = 2;
      p2_score++;
    }
    else if((T[0] == T[3] && T[0] == T[6]) || (T[1] == T[4] && T[1] == T[7]) || (T[2] == T[5] && T[2] == T[8]) && (T[0] == 'O' || T[1] == 'O' || T[2] == 'O'))
    {
      winner = 2;
      p2_score++;
    }
    else if((T[0] == T[4] && T[0] == T[8]) || (T[2] == T[4] && T[2] == T[6]) && (T[0] == 'O' || T[2] == 'O'))
    {
      winner = 2;
      p2_score++;
    }
}
void checking_for_draw(){
       //if all places are full without validing win set game state to draw
    if(turn == 9 )
      draw = 1;
}
// the main fuction of two player mode
void twoP_mode (){
   play_again:
    if(player_turn == 1)
    {
     system("cls");
     twoP_drawing();
     P1_input_logic();
     checking_if_P1winner();
     if(winner != 1)
     checking_for_draw();
    }
    else
    {
     system("cls");
     twoP_drawing();
     P2_input_logic();
     checking_if_P2winner();
     if(winner != 2)
     checking_for_draw();
    }
    goto play_again;

}
//the main function of project
int main()
{
    system("COLOR 17"); //changing console background color to blue and font color to white
    system("cls");
    menu_draw();
    choice_mode();
    if(mode == 1) //if choosen mode equale to 1 launch one player mode
    {
      system("cls");
      oneP_mode();
    }
    else if (mode == 2) //if choosen mode equale to 2 launch two player mode
    {
      system("cls");
      twoP_mode();
    }
    else
    {
      system("cls"); // exite game
      exit(0);
    }
    return 0;
}
