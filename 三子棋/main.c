/*
** Èı×ÓÆåÓÎÏ·
*/

#include "stdio.h"
#include "stdlib.h"
#include "game_chess3.h"

int main()
{	
 	game_chess3_init();
	while (1)
	{
		print_board();
		player_move();
		winner = check_winner();
		if (winner == 'x' || 
			winner == 'o')
		{
			break;
		}
		computer_move();
		winner = check_winner();
		if (winner == 'x' ||
			winner == 'o')
		{
			break;
		}
	}
	print_board();
	print_result();
	system("pause");
	return 0;
}