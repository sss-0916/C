/*
**	ɨ����Ϸ
*/

#include "mine_sweep.h"

int main()
{
	/*---��Ϸ��ʼ��־---*/
	int game_start_flag = 0;

	/*---��Ϸ��ʼ�˵���ӡ---*/
	game_menu();

	/*---��Ϸ����---*/
	while (1)
	{
		/*---����Ϸ��Ե��ж�---*/
		int input_check = 0;
		printf("����������: \n");
		/*---������뻺��---*/
		fflush(stdin);
		input_check = scanf("%d", &game_start_flag);
		/*---���벻�Ϸ�,��������---*/
		if (input_check != 1)
		{
			printf("��Ч������,����������!\n");
			continue;
		}
		/*---����1��Ϸ��ʼ---*/
		else if (game_start_flag == 1)
		{
			game_run();
			break;
		}
		/*---����0��Ϸ����---*/
		else if (game_start_flag == 0)
		{
			break;
		}
		/*---����0��1������ַ�,��Ч---*/
		else
		{
			printf("��Ч������,����������!\n");
			continue;
		}
	}
	system("pause");
	return 0;
}