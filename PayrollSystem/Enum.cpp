#include <string.h>
#include "Enum.h"
/// <summary>
/// ���Ȩ��
/// </summary>
enum permission ;
permission StrToPermission(char str[]) {//strcmp(str, "MON") == 0//�ַ���str��ֵΪ"MON",��������ת��ö��
	if (strcmp(str, "admin") == 0)return admin;
	if (strcmp(str, "manager") == 0)return manager;
	if (strcmp(str, "staff") == 0)return staff;
}
char* PermissionToStr(permission permission) {
	static char admin01[] = "admin";
	static char manager01[] = "manager";
	static char staff01[] = "staff";
	char* str;
	if (permission == admin) str = admin01;
	if (permission == manager)str = manager01;
	if (permission == staff)str = staff01;

	return str;
}


#include <string.h>
/// <summary>
/// �˺�״̬
/// </summary>
enum state {
	normal,
	ban,//�����
	deletes,//��ɾ��
};
state StrToState(char str[]) {
	if (strcmp(str, "normal") == 0)return normal;
	if (strcmp(str, "ban") == 0)return ban;
	if (strcmp(str, "deletes") == 0)return deletes;
}
char* StateToStr(state state) {
	static char normal01[] = "normal";
	static char ban01[] = "ban";
	static char deletes01[] = "deletes";
	char* str;
	if (state == normal)str = normal01;
	if (state == ban)str = ban01;
	if (state == deletes)str = deletes01;
	return str;
}