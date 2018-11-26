#include "mine_sweep.h"

/*---游戏开始菜单打印---*/
void game_menu()
{
	/*---随机种子---*/
	srand((unsigned)time(0));

	/*---开始菜单---*/
	printf("----------\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("----------\n");
}

/*---显示地图和地雷地图的初始化---*/
void map_init(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2])
{
	/*---显示地图的初始化---*/
	for (int i = 1; i <= MAX_ROW; i++)
	{
		for (int j = 1; j <= MAX_COL; j++)
		{
			show_map[i][j] = '*';
		}
	}
	/*---地雷地图的初始化---*/
	for (int i = 0; i < MAX_ROW + 2; i++)
	{
		for (int j = 0; j < MAX_COL + 2; j++)
		{
			mine_map[i][j] = '0';
		}
	}
	/*---随机产生MINE_COUNT个雷,放入地雷地图中---*/
	int mine_count = 0;
	while (mine_count < MINE_COUNT)
	{
		int row = 1 + rand() % (MAX_ROW - 1 + 1);
		int col = 1 + rand() % (MAX_COL - 1 + 1);
		if (mine_map[row][col] == '1')
		{
			continue;
		}
		mine_map[row][col] = '1';
		mine_count++;
	}
}

/*---地图打印---*/
void map_display(char map[MAX_ROW + 2][MAX_COL + 2])
{
	/*---打印第一行,横坐标---*/
	printf("   ");
	for (int i = 1; i <= MAX_ROW; i++)
	{
		printf("%02d ", i);
	}
	printf("\n");
	/*---按行打印具体的地图---*/
	for (int i = 1; i <= MAX_ROW; i++)
	{
		/*---打印纵坐标---*/
		printf("%02d|", i);
		for (int j = 1; j <= MAX_COL; j++)
		{
			printf("%-3c", map[i][j]);
		}
		printf("\n");
	}
}

/*---地图更新---*/
void map_update(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2],
	int row, int col)
{
	int mine_count = 0;
	/*---统计(row, col)周围八格中的地雷总数---*/
	mine_count = (mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = mine_count + '0';
	blank_count++;
	/*---(row, col)周围展开---*/
	if (show_map[row][col] == '0')
	{
		/*---当(row, col)为0时,遍历周围8个位置---*/
		for (int i = row - 1; i <= row + 1; i++)
		{
			/*---横坐标越界判断---*/
			if (i < 1 || i > MAX_ROW)
			{
				continue;
			}
			for (int j = col - 1; j <= col + 1; j++)
			{
				/*---纵坐标越界判断---*/
				if (j < 1 || j > MAX_COL)
				{
					continue;
				}
				/*---跳过(row, col)位置---*/
				else if (i == row && j == col)
				{
					continue;
				}
				else
				{
					/*---若该位置还未被翻开,则递归调用---*/
					if (show_map[i][j] == '*')
					{
						map_update(show_map, mine_map, i, j);
					}
				}
			}
		}
	}
}

/*---胜利判断---*/
int win_check(char show_map[MAX_ROW + 2][MAX_COL + 2])
{
	int count = 0;
	for (int i = 1; i <= MAX_ROW; i++)
	{
		for (int j = 1; j <= MAX_COL; j++)
		{
			if (show_map[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

/*---游戏运行---*/
void game_run()
{
	int row = 0;
	int col = 0;
	char show_map[MAX_ROW + 2][MAX_COL + 2];
	char mine_map[MAX_ROW + 2][MAX_COL + 2];
	map_init(show_map, mine_map);
	while (1)
	{
		int input_check = 0;
		int win_flag = 0;
		map_display(show_map);
		/*---胜利检查---*/
		win_flag = win_check(show_map);
		if (win_flag == MINE_COUNT)
		{
			printf("恭喜您扫雷成功!\n");
			map_display(mine_map);
			break;
		}
		printf("请输入坐标: \n");
		/*---清除输入缓冲区---*/
		fflush(stdin);
		input_check = scanf("%d %d", &row, &col);
		if (input_check != 2)
		{
			printf("输入不合法,请重新输入! \n");
			continue;
		}
		if (row < 1 || row > MAX_ROW ||
			col < 1 || col > MAX_COL)
		{
			printf("输入不合法,请重新输入! \n");
			continue;
		}
		if (mine_map[row][col] == '1')
		{
			printf("遗憾,您差一点就赢了!\n");
			map_display(mine_map);
			break;
		}
		map_update(show_map, mine_map, row, col);
	}
}