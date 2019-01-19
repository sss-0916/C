#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

/*---用户信息---*/
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];
} PersonInfo;

/*---通讯录---*/
typedef struct AddressBook 
{
	PersonInfo* infos;
	int capacity;
	int size;
} AddressBook;

/*---通讯录---*/
AddressBook g_address_book;

/*---通讯录初始化---*/
void Init(AddressBook* addr_book);

/*---扩容---*/
void capacityEnlargement(AddressBook* addr_book);

/*---索引---*/
int menu();

/*---增加用户---*/
void addPersonInfo(AddressBook* addr_book);

/*---删除用户---*/
void delPersonInfo(AddressBook* addr_book);

/*---修改用户---*/
void modifyPersonInfo(AddressBook* addr_book);

/*---查找用户---*/
void findPersonInfo(AddressBook* addr_book);

/*---显示所有用户---*/
void displayAllPersonInfo(AddressBook* addr_book);

/*---清除所有用户---*/
void clearAllPersonInfo(AddressBook* addr_book);