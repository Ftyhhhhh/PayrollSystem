enum permission {
	admin,//系统管理员
	manager,//资金管理员
	staff//普通员工
};
permission StrToPermission(char str[]);
char* PermissionToStr(permission permission);
enum state;
state StrToState(char str[]);
char* StateToStr(state state);