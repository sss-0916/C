/*
**	扫雷游戏
*/

#include "mine_sweep.h"

int main()
{
	/*---游戏开始标志---*/
	int game_start_flag = 0;

	/*---游戏开始菜单打印---*/
	game_menu();

	/*---游戏运行---*/
	while (1)
	{
		/*---输入合法性的判断---*/
		int input_check = 0;
		printf("请输入命令: \n");
		/*---清除输入缓冲---*/
		fflush(stdin);
		input_check = scanf("%d", &game_start_flag);
		/*---输入不合法,重新输入---*/
		if (input_check != 1)
		{
			printf("无效的命令,请重新输入!\n");
			continue;
		}
		/*---输入1游戏开始---*/
		else if (game_start_flag == 1)
		{
			game_run();
			break;
		}
		/*---输入0游戏结束---*/
		else if (game_start_flag == 0)
		{
			break;
		}
		/*---输入0和1以外的字符,无效---*/
		else
		{
			printf("无效的命令,请重新输入!\n");
			continue;
		}
	}
	system("pause");
	return 0;
}