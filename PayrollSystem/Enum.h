enum permission {
	admin,//ϵͳ����Ա
	manager,//�ʽ����Ա
	staff//��ͨԱ��
};
permission StrToPermission(char str[]);
char* PermissionToStr(permission permission);
enum state;
state StrToState(char str[]);
char* StateToStr(state state);