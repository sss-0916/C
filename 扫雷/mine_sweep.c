#include "mine_sweep.h"

/*---��Ϸ��ʼ�˵���ӡ---*/
void game_menu()
{
	/*---�������---*/
	srand((unsigned)time(0));

	/*---��ʼ�˵�---*/
	printf("----------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("----------\n");
}

/*---��ʾ��ͼ�͵��׵�ͼ�ĳ�ʼ��---*/
void map_init(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2])
{
	/*---��ʾ��ͼ�ĳ�ʼ��---*/
	for (int i = 1; i <= MAX_ROW; i++)
	{
		for (int j = 1; j <= MAX_COL; j++)
		{
			show_map[i][j] = '*';
		}
	}
	/*---���׵�ͼ�ĳ�ʼ��---*/
	for (int i = 0; i < MAX_ROW + 2; i++)
	{
		for (int j = 0; j < MAX_COL + 2; j++)
		{
			mine_map[i][j] = '0';
		}
	}
	/*---�������MINE_COUNT����,������׵�ͼ��---*/
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

/*---��ͼ��ӡ---*/
void map_display(char map[MAX_ROW + 2][MAX_COL + 2])
{
	/*---��ӡ��һ��,������---*/
	printf("   ");
	for (int i = 1; i <= MAX_ROW; i++)
	{
		printf("%02d ", i);
	}
	printf("\n");
	/*---���д�ӡ����ĵ�ͼ---*/
	for (int i = 1; i <= MAX_ROW; i++)
	{
		/*---��ӡ������---*/
		printf("%02d|", i);
		for (int j = 1; j <= MAX_COL; j++)
		{
			printf("%-3c", map[i][j]);
		}
		printf("\n");
	}
}

/*---��ͼ����---*/
void map_update(char show_map[MAX_ROW + 2][MAX_COL + 2],
	char mine_map[MAX_ROW + 2][MAX_COL + 2],
	int row, int col)
{
	int mine_count = 0;
	/*---ͳ��(row, col)��Χ�˸��еĵ�������---*/
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
	/*---(row, col)��Χչ��---*/
	if (show_map[row][col] == '0')
	{
		/*---��(row, col)Ϊ0ʱ,������Χ8��λ��---*/
		for (int i = row - 1; i <= row + 1; i++)
		{
			/*---������Խ���ж�---*/
			if (i < 1 || i > MAX_ROW)
			{
				continue;
			}
			for (int j = col - 1; j <= col + 1; j++)
			{
				/*---������Խ���ж�---*/
				if (j < 1 || j > MAX_COL)
				{
					continue;
				}
				/*---����(row, col)λ��---*/
				else if (i == row && j == col)
				{
					continue;
				}
				else
				{
					/*---����λ�û�δ������,��ݹ����---*/
					if (show_map[i][j] == '*')
					{
						map_update(show_map, mine_map, i, j);
					}
				}
			}
		}
	}
}

/*---ʤ���ж�---*/
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

/*---��Ϸ����---*/
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
		/*---ʤ�����---*/
		win_flag = win_check(show_map);
		if (win_flag == MINE_COUNT)
		{
			printf("��ϲ��ɨ�׳ɹ�!\n");
			map_display(mine_map);
			break;
		}
		printf("����������: \n");
		/*---������뻺����---*/
		fflush(stdin);
		input_check = scanf("%d %d", &row, &col);
		if (input_check != 2)
		{
			printf("���벻�Ϸ�,����������! \n");
			continue;
		}
		if (row < 1 || row > MAX_ROW ||
			col < 1 || col > MAX_COL)
		{
			printf("���벻�Ϸ�,����������! \n");
			continue;
		}
		if (mine_map[row][col] == '1')
		{
			printf("�ź�,����һ���Ӯ��!\n");
			map_display(mine_map);
			break;
		}
		map_update(show_map, mine_map, row, col);
	}
}