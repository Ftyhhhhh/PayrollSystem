#include <stdio.h>//库
#include <stdlib.h>
#include <string.h>
#include "Enum.h"

/// <summary>
/// 用户结构体
/// </summary>
struct Users_sys
{
	permission permission;//身份权限
	char name[20];
	char account[20];//账号
	char password[20];//密码
	float wage;//工资
	state state;//账号状态
};

Users_sys* users;//存放所有用户信息
int elementSum;//用户结构体数组有效长度


void main() {
	permission p01 = admin;
	void Set(char* fileName);
	void Get(char* fileName);
	int zhuce(struct Users_sys zh[], int m);//注册模块
	void denglu(struct Users_sys zh[], int m);//登录模块
	void menu(void);//菜单
	void again(struct Users_sys zh[], char l[]);//检测模块
	char fileName[] = "data.txt";
	system("cls");//控制台清屏
	Get(fileName);
#pragma region 显示













#pragma endregion
	Set(fileName);
	int m = 0;
	int k;
	struct Users_sys zh[100];
	while (1)
	{
		menu();
		printf("请选择服务：");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			zhuce(zh, m);
			m++;
			printf("%d\n\n", m);
			break;
		case 2:
			denglu(zh, m);
			break;
		case 3:
			printf("谢谢使用!!!\n");
			exit(0);

		default:
			printf("不存在该服务！！！");
			break;
		}
	}





}
#pragma region 显示时所用函数












#pragma endregion
#pragma region 修改结构体函数
//注册与登入
int zhuce(struct Users_sys zh[], int m);//注册模块
void denglu(struct Users_sys zh[], int m);//登录模块
void menu(void);//菜单
void again(struct Users_sys zh[], char l[]);//检测模块
void menu(void)//菜单
{
	printf("---------------------------------------\n");
	printf("        1  --- 创建新账户\n");
	printf("        2  --- 登录\n");
	printf("        3 --- 退出系统\n");
	printf("---------------------------------------\n");
}
int zhuce(struct Users_sys zh[], int m)//注册模块
{
	char d[20], e[20], l[20];
	printf("用户名：");
	scanf("%s", &l);
	again(zh, l);
	printf("账号：");
	scanf("%s", &d);
	printf("\n");
	printf("密码");
	scanf("%s", &e);
	printf("\n");
	strcpy(zh[m].name, l);
	strcpy(zh[m].account, d);
	strcpy(zh[m].password, e);
	printf("创建成功！\n");
	printf("%s\n%s\n", zh[m].password, zh[m].account);
	m++;
	return m;
}
void denglu(struct Users_sys zh[], int m)//登录模块
{
	int g, f, i;
	char d[20], e[20], n[20];
	printf("用户名：");
	scanf("%s", &n);
	printf("账号：");
	scanf("%s", &d);
	printf("\n");
	printf("密码");
	scanf("%s", &e);
	printf("\n");
	for (i = 0; i < 99; i++)
	{
		if (strcmp(zh[i].name, n) == 0)
		{
			g = strcmp(zh[i].account, d);
			f = strcmp(zh[i].password, e);
			if ((g == 0) && (f == 0))
			{
				printf("%s,欢迎回来！！！\n\n", zh[i].name);

			}
			else
			{
				printf("账号或密码错误！！！！\n\n");
			}
		}
	}
}

void again(struct Users_sys zh[], char l[])//检测模块
{
	int i;
	char z[20];
	strcpy(z, l);
	for (i = 0; i < 99; i++)
	{
		while (strcmp(zh[i].name, z) == 0)
		{
			printf("该用户名已被注册！！！\n");
			i = 0;
			printf("用户名：");
			scanf("%s", &z);
		}
	}
	strcpy(l, z);
}
#pragma endregion
#pragma region Set
/// <summary>
/// 从字符串结尾处拼接,s01=s01+s02
/// </summary>
void ConnectStrang(char s01[], char s02[]) {
	int s01Length = 0;
	for (int i = 0; s01[i] != '\0'; i++)s01Length++;
	for (int i = 0; s02[i] != '\0'; i++)s01[s01Length + i] = s02[i];
}
/// <summary>
///用户转str
/// </summary>
char* UsersToStr(Users_sys users) {
	static char str[70]{},
		lineFeed[] = "\n",
		suspend[] = "|",
		* permission,
		* account,
		* password,
		wage[10]{},
		* state;
	for (int i = 0;str[i] != '\0'; i++) str[i] = '\0';

	permission = PermissionToStr(users.permission);
	account = users.account;
	password = users.password;
	sprintf(wage, "%.2f", users.wage);//单浮点转字符串	
	state = StateToStr(users.state);

	ConnectStrang(str, permission);
	ConnectStrang(str, suspend);
	ConnectStrang(str, account);
	ConnectStrang(str, suspend);
	ConnectStrang(str, password);
	ConnectStrang(str, suspend);
	ConnectStrang(str, wage);
	ConnectStrang(str, suspend);
	ConnectStrang(str, state);
	ConnectStrang(str, lineFeed);

	return str;
}
/// <summary>
/// users有效数组长度
/// </summary>
int EffectiveLength(Users_sys* users) {
	elementSum = 0;
	while (users[elementSum].wage != 0.0)
		elementSum++;
	return elementSum;
}
/// <summary>
/// 将users覆盖fileName文件,如果fileName不存在,则新建一个
/// </summary>
void Set(char* fileName) {
	FILE* fp;


	char* str;
	fp = fopen(fileName, "w");
	int Length = EffectiveLength(users);
	for (int i = 0; i < Length; i++)
	{
		str = UsersToStr(users[i]);
		fprintf(fp, str);
	}


	fclose(fp);
}
#pragma endregion
#pragma region Get
/// <summary>
/// 字符串转换为结构体
/// </summary>
/// <param name="index">索引</param>
void StrToUsers(char str[], Users_sys* users, int index) {
	//大字符串拆为多个小字符串
	char permission[10], account[20], password[20], wage[10], state[10];
	for (int i = 0, r = 0, n = 0; ; i++)
	{
		if (str[i] == '\n' || str[i] == '\0') { state[n] = '\0'; break; };
		if (str[i] == '|') {
			switch (r)
			{
			case 0:permission[n] = '\0';break;
			case 1:account[n] = '\0';break;
			case 2:password[n] = '\0';break;
			case 3:wage[n] = '\0';break;
			} r++, i++, n = 0;
		}
		switch (r)
		{
		case 0:
			permission[n] = str[i];
			n++;break;
		case 1:
			account[n] = str[i];
			n++;break;
		case 2:
			password[n] = str[i];
			n++;break;
		case 3:
			wage[n] = str[i];
			n++;break;
		case 4:
			state[n] = str[i];
			n++;break;
		}
	}
	users[index].permission = StrToPermission(permission);
	users[index].state = StrToState(state);
	strcpy(users[index].account, account);
	strcpy(users[index].password, password);
	users[index].wage = atof(wage);
}
/// <summary>
/// 光标现在位置换n行
/// </summary>
void CursorLineFeed(int n, FILE* fp) {
	for (int i = 0; i < n; i++)
		while (fgetc(fp) != '\n');
}
/// <summary>
/// 计算行总数
/// </summary>
int LineSum(FILE* fp) {
	char c01 = fgetc(fp);
	int lineSum = 0;
	while (c01 != EOF)
	{
		if (c01 == '\n')lineSum++;
		c01 = fgetc(fp);
	}
	fseek(fp, SEEK_SET, 0);
	return lineSum;
}
/// <summary>
/// 读取
/// </summary>
void Get(char* fileName) {
	char str[70]{};
	int lineSum;//行总数	

	FILE* fp = fopen(fileName, "r");//打开	
	if (fp == NULL) {
		printf("找不到%s对应的文件", fileName);
		return;
	}
	lineSum = LineSum(fp);
	users = new Users_sys[lineSum];
	for (int i = 0; i < lineSum; i++)
	{
		fgets(str, 70, fp);//最大读取70个
		StrToUsers(str, users, i);
		for (int i = 0; i != '\0'; i++)str[i] = '\0';//重置缓冲区	
	}
	//char* c01 = strstr(buffer, "state");//寻找state	
	fclose(fp);//关闭
}
#pragma endregion