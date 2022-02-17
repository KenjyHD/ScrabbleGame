#include <stdio.h>
#include "util/print_board.h"
#include <stdlib.h>
#include "util/scrabble.h"
#include <string.h>

void task0(char board[15][15])
{
   print_board(board);
}

void task1(char board[15][15])
{
   char n_char[4], line[30], word[30];
   int x, y, d, n_int;
   fgets(n_char, 4, stdin);
   n_int = strtol(n_char, NULL, 10);
   for (int i=0; i < n_int; i++)
   {
      fgets(line, 30, stdin);
      sscanf(line,"%d %d %d %s",&y, &x, &d, word);
  
      for (int j = 0; word[j] != '\0'; j++)
      if (d == 0) board[y][x + j]=word[j];
      else board[y + j][x] = word[j];
   }
   print_board(board);
}

void task2()
{
        int pt[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 
        1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
        char n_char[4], line[20], word[20];
        int x, y, d, n_int, player1 = 0, player2 = 0;
        
        fgets(n_char, 4, stdin);
        n_int = strtol(n_char, NULL, 10);
        for (int i = 0; i < n_int; i++)
        {
        fgets(line,20,stdin);
        sscanf(line, "%d %d %d %s", &y, &x, &d, word);
        
        for (int j = 0; word[j] != '\0'; j++)
        if (i % 2 == 0) player1 = player1 + pt[(int)word[j] - 65];
        else player2 = player2 + pt[(int)word[j] - 65];
        }
        printf("Player 1: %d Points\n", player1);
        printf("Player 2: %d Points", player2);
}

void task3(int *player1, int *player2, int *n_int)
{
   int pt[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 
   1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
   char n_char[4], line[20], word[20], xx[4], yy[4];
   int x, y, d, wordpts = 0, bonus1 = 1, bonus2 = 1;
   
   fgets(xx, 3, stdin);
   getchar();
   fgets(yy, 3, stdin);
   getchar();
   fgets(n_char, 4, stdin);
   *n_int = strtol(n_char, NULL, 10);
   for (int i = 0; i < *n_int; i++)
   {
      fgets(line, 20, stdin);
      sscanf(line, "%d %d %d %s", &y, &x, &d, word);
        
      for (int j=0; word[j] != '\0'; j++)
      {
         wordpts = wordpts + pt[(int)word[j] - 65];
         
         if (((d == 0) && (bonus_board[y][x + j] == 1))
         || ((d == 1) && (bonus_board[y + j][x] == 1)))
            bonus1 = bonus1 * 2;
         if (((d == 0) && (bonus_board[y][x + j] == 2))
         || ((d == 1) && (bonus_board[y + j][x] == 2)))
            bonus2 = bonus2 * 3;   
      }
      if (strstr(word, xx) != NULL)
         wordpts = wordpts * bonus1;
      if ((word[strlen(word)-1] == yy[1]) && (word[strlen(word)-2] == yy[0]))
         wordpts = wordpts * bonus2;
      if (i % 2 == 0)
         *player1 = *player1 + wordpts;
      if (i % 2 == 1)
         *player2 = *player2 + wordpts;
      wordpts = 0;
      bonus1 = 1;
      bonus2 = 1;
   }
   
}

void task4(char board[15][15])
{
   char n_char[4], line[20], word[20][20], xx[4], yy[4];
   int x, y, d, n_int, compatible = 0, k, l, not_used = 0;;
   size_t k1, l1;
   
   fgets(xx, 3, stdin);
   getchar();
   fgets(yy, 3, stdin);
   getchar();
   fgets(n_char,4,stdin);
   n_int = strtol(n_char, NULL, 10);
   for (int i = 0; i < n_int; i++)
   {  
      fgets(line,20,stdin);
      sscanf(line,"%d %d %d %s", &y, &x, &d, word[i]);
        
      for (int j = 0; word[i][j] != '\0'; j++)
         if (d == 0) board[y][x + j] = word[i][j];
         else board[y + j][x] = word[i][j];
   }
   
   for (int i = 0; i<100; i++)
   {
      if (compatible)
         break;
      not_used = 1;
      for (int j = 0; j < n_int; j++)
         if (strcmp(words[i],word[j]) == 0)
            not_used = 0;
      if (not_used == 1)
         for (k = 0; k < 15; k++)
         {
               if (compatible)
                  break;
               for (l = 0; l < 15; l++)
                  if (words[i][0] == board[k][l])
                  {
                  
                     compatible = 1;
                     if ((strlen(words[i]) + k) > 15)
                        compatible = 0;
                     
                     for  (k1 = k+1; k1 < (k + strlen(words[i])); k1++)
                        if ((board[k1][l] != '.'))
                           compatible = 0;
                     if (compatible)
                     {
                       for  (k1 = 1; words[i][k1] != '\0'; k1++) 
                          board[k+k1][l] = words[i][k1];
                       break;
                     }
                     else
                     {
                        compatible = 1;
                        if ((strlen(words[i]) + l) > 15)
                           compatible = 0;
                        for  (l1 = l+1; l1 < (l + strlen(words[i])); l1++)
                           if ((board[k][l1] != '.'))
                              compatible = 0;
                        if (compatible)
                        {
                          for  (l1 = 1; words[i][l1] != '\0'; l1++) 
                             board[k][l+l1] = words[i][l1];
                        break;
                        }
                     }
                  }
         }   
         
   }
   print_board(board);
}

void count_word_pts(int *player1, int *player2, char word[20], 
char xx[4], char yy[4], int d, int x, int y, int i)
{
   int wordpts = 0, bonus1 = 1, bonus2 = 1;
   int pt[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 
   1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
   for (int j=0; word[j] != '\0'; j++)
      {
         wordpts = wordpts + pt[(int)word[j] - 65];
         
         if (((d == 0) && (bonus_board[y][x+j] == 1))
         || ((d == 1) && (bonus_board[y+j][x] == 1)))
            bonus1 = bonus1 * 2;
         if (((d == 0) && (bonus_board[y][x+j] == 2))
         || ((d == 1) && (bonus_board[y+j][x] == 2)))
            bonus2 = bonus2 * 3;   
      }
      
      if (strstr(word, xx) != NULL)
         wordpts = wordpts * bonus1;
      if ((word[strlen(word) - 1] == yy[1]) && (word[strlen(word) - 2] == yy[0]))
         wordpts = wordpts * bonus2;
      if (i % 2 == 0)
         *player1 = *player1 + wordpts;
      if (i % 2 == 1)
         *player2 = *player2 + wordpts;
      wordpts = 0;
      bonus1 = 1;
      bonus2 = 1;
}

void task5(char board[15][15])
{
   char n_char[4], line[20], word[20][20], xx[4], yy[4], 
   compatible_words[200][200];
   int q = 0, n_int, x, y, d, compatible = 0, k, l, not_used = 0, 
   *player1 = malloc(4), *player2 = malloc(4), 
   compatible_words_y[200], compatible_words_x[200], 
   compatible_words_orizontal[200], compatible_words_vertical[200], 
   compat_aux = 0, player2_pre, pts = 0, pts_max = 0, index = -1;
   size_t k1, l1;
   
   memset(compatible_words_orizontal, 0, 200*sizeof(int));
   memset(compatible_words_vertical, 0, 200*sizeof(int));
   
   fgets(xx, 3, stdin);
   getchar();
   fgets(yy, 3, stdin);
   getchar();
   fgets(n_char,4,stdin);
   n_int = strtol(n_char, NULL, 10);
   for (int i = 0; i < n_int; i++)
   {
      fgets(line,20,stdin);
      sscanf(line,"%d %d %d %s", &y, &x, &d, word[i]);
      
      count_word_pts(player1, player2, word[i], xx, yy, d, x, y, i);
      for (int j=0; word[i][j] != '\0'; j++)
      {
         if (d == 0) board[y][x + j] = word[i][j];
         else board[y + j][x] = word[i][j];
      }
   }
   
   for (int i = 0; i<100; i++)
   {
      compatible = 0;
      
      not_used = 1;
      for (int j = 0; j < n_int; j++)
         if (strcmp(words[i], word[j]) == 0)
            not_used = 0;
      if (not_used == 1)
         for (k = 0; k < 15; k++)
         {
            for (l = 0; l < 15; l++)
               if (words[i][0] == board[k][l])
               {
                  compat_aux = 0;
                  compatible = 1;
                  if ((strlen(words[i]) + k) > 15)
                     compatible = 0;
                     
                  for  (k1 = k + 1; k1 < (k + strlen(words[i])); k1++)
                     if ((board[k1][l] != '.'))
                        compatible = 0;
                  if (compatible)
                     {
                        compat_aux = 1;
                        compatible_words_y[q] = k;
                        compatible_words_x[q] = l;
                        compatible_words_vertical[q] = 1;
                        strcpy(compatible_words[q], words[i]);
                     }
                  compatible = 1;
                  if ((strlen(words[i]) + l) > 15)
                     compatible = 0;
                     
                  for  (l1 = l + 1; l1 < (l + strlen(words[i])); l1++)
                     if ((board[k][l1] != '.'))
                        compatible = 0;
                  if (compatible)
                  {
                     compat_aux = 1;
                     compatible_words_y[q] = k;
                     compatible_words_x[q] = l;
                     compatible_words_orizontal[q] = 1;
                     strcpy(compatible_words[q], words[i]);
                  }
                  if (compat_aux) q++;
               }
         }
   }
   for (int i = 0; i < q; i++)
   {
      player2_pre = *player2;

      if (compatible_words_vertical[i])
      count_word_pts(player1, player2, compatible_words[i], xx, yy, 1, 
      compatible_words_x[i], compatible_words_y[i], 1);
      pts = *player2 - player2_pre; 
      if (pts_max < pts)
      {
         pts_max = pts;
         index = i;
         d = 1;
      }
      else if (pts == pts_max && index >= 0)
      {
         if (compatible_words_y[i] < compatible_words_y[index])
         {
            pts_max = pts;
            index = i;
            d = 1;
         }
         if (compatible_words_y[i] == compatible_words_y[index])
            if (compatible_words_x[i] <= compatible_words_x[index])
            {
               pts_max = pts;
               index = i;
               d = 1;
            }
      }
      
      *player2 = player2_pre;
      if (compatible_words_orizontal[i])
      count_word_pts(player1, player2, compatible_words[i], xx, yy, 0, 
      compatible_words_x[i], compatible_words_y[i], 1);
      pts = *player2 - player2_pre;
      if (pts_max < pts)
      {
         pts_max = pts;
         index = i;
         d = 0;
      }
      else if (pts == pts_max && index >= 0)
      {
         if (compatible_words_y[i] < compatible_words_y[index])
         {
            pts_max = pts;
            index = i;
            d = 0;
         }
         if (compatible_words_y[i] == compatible_words_y[index])
            if (compatible_words_x[i] <= compatible_words_x[index])
            {
                  pts_max = pts;
                  index = i;
                  d = 0;
            }
      }
      *player2 = player2_pre;
   }
   for (int j=0; compatible_words[index][j] != '\0'; j++)
      {
         if (d == 0) 
            board[compatible_words_y[index]][compatible_words_x[index] + j] = 
            compatible_words[index][j];
         else 
            board[compatible_words_y[index] + j][compatible_words_x[index]] = 
            compatible_words[index][j];
      }
   if ((*player2 + pts_max) >= *player1) print_board(board);
   else printf("Fail!");   
}


void task6(char board[15][15])
{
   char n_char[4], line[30], word[20][20], xx[4], yy[4], 
   compatible_words[200][200];
   int q = 0, n_int, x, y, d, compatible = 0, k, l, not_used = 0, 
   *player1 = malloc(4), *player2 = malloc(4), 
   compatible_words_y[200], compatible_words_x[200], 
   compatible_words_orizontal[200], compatible_words_vertical[200], 
   compat_aux = 0, player2_pre, pts = 0, pts_max = 0, index = -1;
   size_t k1, l1;
   
   
   
   fgets(xx, 3, stdin);
   getchar();
   fgets(yy, 3, stdin);
   getchar();
   fgets(n_char,4,stdin);
   n_int = strtol(n_char, NULL, 10);
   for (int o = 0; o < n_int; o++)
   {
      memset(compatible_words_orizontal, 0, 200*sizeof(int));
      memset(compatible_words_vertical, 0, 200*sizeof(int));
      q = 0;
      pts = 0;
      pts_max = 0;
      fgets(line, 30, stdin);
      sscanf(line,"%d %d %d %s", &y, &x, &d, word[2 * o]);
      
      count_word_pts(player1, player2, word[2 * o], xx, yy, d, x, y, 0);
      for (int j=0; word[2 * o][j] != '\0'; j++)
      {
         if (d == 0) board[y][x + j] = word[2 * o][j];
         else board[y + j][x] = word[2 * o][j];
      }
   
   for (int i = 0; i<100; i++)
   {
      compatible = 0;
      
      not_used = 1;
      for (int j = 0; j < ((2 * o) + 1); j++)
         if (strcmp(words[i], word[j]) == 0)
            not_used = 0;
      if (not_used == 1)
         for (k = 0; k < 15; k++)
         {
            for (l = 0; l < 15; l++)
               if (words[i][0] == board[k][l])
               {
                  compat_aux = 0;
                  compatible = 1;
                  if ((strlen(words[i]) + k) > 15)
                     compatible = 0;
                     
                  for  (k1 = k+1; k1 < (k + strlen(words[i])); k1++)
                     if ((board[k1][l] != '.'))
                        compatible = 0;
                  if (compatible)
                     {
                        compat_aux = 1;
                        compatible_words_y[q] = k;
                        compatible_words_x[q] = l;
                        compatible_words_vertical[q] = 1;
                        strcpy(compatible_words[q], words[i]);
                     }
                  compatible = 1;
                  if ((strlen(words[i]) + l) > 15)
                     compatible = 0;
                     
                  for  (l1 = l+1; l1 < (l + strlen(words[i])); l1++)
                     if ((board[k][l1] != '.'))
                        compatible = 0;
                  if (compatible)
                  {
                     compat_aux = 1;
                     compatible_words_y[q] = k;
                     compatible_words_x[q] = l;
                     compatible_words_orizontal[q] = 1;
                     strcpy(compatible_words[q], words[i]);
                  }
                  if (compat_aux) q++;
               }
         }   
   }
   for (int i = 0; i < q; i++)
   {

      player2_pre = *player2;

      if (compatible_words_vertical[i])
      count_word_pts(player1, player2, compatible_words[i], xx, yy, 1, 
      compatible_words_x[i], compatible_words_y[i], 1);
      pts = *player2 - player2_pre;
      
      if (pts_max < pts)
      {
         pts_max = pts;
         index = i;
         d = 1;
      }
      else if (pts == pts_max && index >= 0)
      {
         if (compatible_words_y[i] < compatible_words_y[index])
         {
            pts_max = pts;
            index = i;
            d = 1;
         }
         if (compatible_words_y[i] == compatible_words_y[index])
         {
            if (compatible_words_x[i] < compatible_words_x[index])
            {
               pts_max = pts;
               index = i;
               d = 1;
            }
         }
      }
      
      *player2 = player2_pre;
      if (compatible_words_orizontal[i])
      count_word_pts(player1, player2, compatible_words[i], xx, yy, 0, 
      compatible_words_x[i], compatible_words_y[i], 1);
      pts = *player2 - player2_pre;
      if (pts_max < pts)
      {
         pts_max = pts;
         index = i;
         d = 0;
      }
      else if (pts == pts_max && index >= 0)
      {
         if (compatible_words_y[i] < compatible_words_y[index])
         {
            pts_max = pts;
            index = i;
            d = 0;
         }
         if (compatible_words_y[i] == compatible_words_y[index])
         {
            if (compatible_words_x[i] < compatible_words_x[index])
            {
               pts_max = pts;
               index = i;
               d = 0;
            }
         }
      }
      *player2 = player2_pre;
   }
   for (int j=0; compatible_words[index][j] != '\0'; j++)
      {
         if (d == 0) 
            board[compatible_words_y[index]][compatible_words_x[index] + j] = 
            compatible_words[index][j];
         else 
            board[compatible_words_y[index] + j][compatible_words_x[index]] = 
            compatible_words[index][j];
      }
   strcpy(word[(2 * o) + 1],compatible_words[index]);
   *player2 = *player2 + pts_max;   
   }
   print_board(board);
   if (*player1 > *player2)
      printf("Player 1 Won!\n");
   else
      printf("Player 2 Won!\n");
}

int main()
{
   char board[15][15] = {
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
   {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}};
   char task = fgetc(stdin);
   getchar();
   int *player1 = malloc(4), *player2 = malloc(4), *n_int = malloc(4);
        
   if (task == '0')
      task0(board);
        
   if (task == '1')
      task1(board);
           
   if (task == '2')
      task2();
           
   if (task == '3')
   {
      task3(player1, player2, n_int);
      printf("Player 1: %d Points\n", *player1);
      printf("Player 2: %d Points", *player2);
   }  
   if (task == '4')
      task4(board);
   
   if (task == '5')
      task5(board);
      
   if (task == '6')
      task6(board);
   
   
}
