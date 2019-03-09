/*
**	主函数
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include "adress_book.h"

int main()
{
	Init(&g_address_book);
	typedef void(pfunc_t)(AddressBook*);
	pfunc_t* table[] = {
		addPersonInfo,
		delPersonInfo,
		modifyPersonInfo,
		findPersonInfo,
		displayAllPersonInfo,
		clearAllPersonInfo
	};
	while (1)
	{
		int choice = menu();
		if (choice < 0 ||
			choice >(int)(sizeof(table) / sizeof(table[0])))
		{
			printf("输入有误!\n");
			continue;
		}
		if (choice == 0)
		{
			printf("感谢使用!\n");
			saveAllPersonInfo(&g_address_book);
			break;
		}
		table[choice - 1](&g_address_book);
	}
	system("pause");
	return 0;
}