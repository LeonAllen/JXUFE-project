#include"stdio.h"
#include"process.h"
#include"string.h"
#include"windows.h"
#define N 1000//职工人数
struct staff_list
{
	char staff_number[10];//职工编号
	char staff_name[10];//姓名
	char staff_sex[10];//性别
	char staff_marriage[10];//婚姻状况
	char staff_degree[10];//学历
	char staff_apartment[10];//所属部门
	char staff_pay[10];//工资
	char staff_year[10];//工龄
}person[1000];

void fun(int m) {
	int i;
	FILE *tp;
	if ((tp = fopen("f2", "w")) == NULL)
	{
		printf("cannot?open?file");
		exit(0);
	}
	for (i = 0; i < m; i++)
		if (fwrite(&person[i], sizeof(struct staff_list), 1, tp) != 1)
			printf("file write error");
	fclose(tp);
}


void add()//增加职工信息
{
	char c5[999] = "______________________________________________________________\n";
	char c6[108] = "|                          职工信息表                        |\n";
	char c7[108] = "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n";
	char c8[208] = "|  编号  |姓名 |性别|婚姻状况|学历| 所属部门 | 工资|工龄（年)|\n";
	strcat(c5, c6); strcat(c5, c7); strcat(c5, c8);
	int i, m, a;

	printf("请输入需要创建的职工人数（1~1000）：");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("请输入第%d名职工编号：（例如：0154097）", i + 1);
		scanf("%s", &person[i].staff_number);
		printf("请输入第%d名职工姓名：（例如：张三）", i + 1);
		scanf("%s", &person[i].staff_name);
		printf("请输入第%d名职工性别：（例如：男）", i + 1);
		scanf("%s", &person[i].staff_sex);
		printf("请输入第%d名职工婚姻状况：（例如：未婚）", i + 1);
		scanf("%s", &person[i].staff_marriage);
		printf("请输入第%d名职工学历：（例如：小学）", i + 1);
		scanf("%s", &person[i].staff_degree);
		printf("请输入第%d名职工所属部门：（例如：技术部）", i + 1);
		scanf("%s", &person[i].staff_apartment);
		printf("请输入第%d名职工工资：（例如：1000）", i + 1);
		scanf("%s", &person[i].staff_pay);
		printf("请输入第%d名职工工龄：（例如：1）", i + 1);
		scanf("%s", &person[i].staff_year);
	}


	printf("\t--------------------信息录入成功----------------------------\n");
	fun(m);
	printf("\t         是否继续输入，是请按1，不是请按0: ");
	scanf("%d", &a);

	i++;


}

void seek()
{

	int i; char n[1000];
	printf("请输入您需要查找的职工编号:");

	scanf("%s", n);
	for (i = 0; i < N; i++)
		if (strcmp(person[i].staff_number, n) == 0)
		{
			printf("该职工信息如下：\n");
			printf("______________________________________________________________\n");
			printf("|                          职工信息表                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| 编号 | 姓名 | 性别| 婚姻状况|学历| 所属部门 | 工资|   工龄 |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);

		}
	if (i == 1001)
		printf("\t*****************查无此人************************");
}
int read()
{
	FILE *tp;
	int i = 0;
	if (!(tp = fopen("f2", "r")))
	{
		printf("无法打开该文件\n");
		exit(0);
	}
	else
	{
		do {
			fread(&person[i], sizeof(struct staff_list), 1, tp);
			i++;
		} while (feof(tp) == 0);
	}
	fclose(tp);
	return(i - 1);

}
void show()
{
	char c5[999] = "______________________________________________________________\n";
	char c6[108] = "|                          职工信息表                        |\n";
	char c7[108] = "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n";
	char c8[208] = "| 编号 | 姓名 | 性别| 婚姻状况|学历| 所属部门 | 工资|   工龄 |\n";
	strcat(c5, c6); strcat(c5, c7); strcat(c5, c8);
	printf("显示所有职工信息：\n");
	printf("%s", c5);

	int i;
	int m = read();

	for (i = 0; i < m; i++)
	{
		printf("  %s    %s     %s     %s    %s     %s      %s    %s\n", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);
	}
}
void delete_()// 定义函数用来删除员工信息
{
	int  i, n, j, flag, m = read(), t;
	char z[1000];
	printf("欢迎进入删除员工信息界面：\n");
	printf("请输入您要删除的职工编号：\n");
	scanf("%s", z);
	for (i = 0; i < m; i++)
	{
		if (!strcmp(person[i].staff_number, z))
		{
			printf("职工信息已经找到，显示结果如下：\n");
			printf("______________________________________________________________\n");
			printf("|                          职工信息表                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| 编号 | 姓名 | 性别| 婚姻状况|学历| 所属部门 | 工资|   工龄 |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);

			printf("\n");

			printf("请认真思考是否真的要删除该员工信息？ 确认删除请输入1，取消请输入2\n");
			scanf("%d", &n);
		}
		else
			printf("------查无此人!-----\n");
		if (n == 1)
		{
			for (j = i; j < m - 1; j++)
			{
				strcpy(person[j].staff_apartment, person[j + 1].staff_apartment);
				strcpy(person[j].staff_name, person[j + 1].staff_name);
				strcpy(person[j].staff_pay, person[j + 1].staff_pay);
				strcpy(person[j].staff_year, person[j + 1].staff_year);
				strcpy(person[j].staff_sex, person[j + 1].staff_sex);
				strcpy(person[j].staff_marriage, person[j + 1].staff_marriage);
				strcpy(person[j].staff_marriage, person[j + 1].staff_marriage);

				strcpy(person[j].staff_degree, person[j + 1].staff_degree);
				strcpy(person[j].staff_number, person[j + 1].staff_number);
			}
			m--;
			fun(m);
			printf("\t***********成功删除************\n");
			break;
		}
		if (n == 2)
			break;
	}

	printf("继续删除请按1，不继续删除请按0;");
	scanf("%d", &t);
	switch (t)
	{
	case 1:delete_();
	case 0:break;
	default:
		break;
	}


}
void big_add()//追加职工信息
{
	FILE *tp;
	int n, i, c = 0, m = read();
	printf("原来的职工信息为：");
	show();
	printf("\n");
	tp = fopen("f2.txt", "a");
	printf("请输入需要追加的职工人数：");
	scanf("%d", &n);
	for (i = m; i < (m + n); i++)
	{
		printf("请输入职工编号：");
		scanf("%s", &person[i].staff_number);
		printf("请输入职工姓名：");
		scanf("%s", &person[i].staff_name);
		printf("请输入职工性别：");
		scanf("%s", &person[i].staff_sex);
		printf("请输入职工婚姻状况：");
		scanf("%s", &person[i].staff_marriage);
		printf("请输入职工学历：");
		scanf("%s", &person[i].staff_degree);
		printf("请输入职工所属部门：");
		scanf("%s", &person[i].staff_apartment);
		printf("请输入职工工资：");
		scanf("%s", &person[i].staff_pay);
		printf("请输入职工工龄：");
		scanf("%s", &person[i].staff_year);
		c = c + 1;
	}
	m += c;
	printf("追加完毕后全体职工人数已达：%d人", c + m - 1);
	printf("追加完毕后全体职工信息如下:");
	fun(m);
	show();
	fclose(tp);


}
void change()
{
	char number[10];//职工编号
	char name[10];//姓名
	char sex[10];//性别
	char marriage[10];//婚姻状况
	char degree[10];//学历
	char apartment[10];//所属部门
	char pay[10];//工资
	char year[10];//工龄
	int m = read(), i, n, a, t, b, f = 1;
	printf("原有信息如下：");
	show();
	printf("请输入需要修改的职工姓名：");
	scanf("%s", name);
	for (i = 0; i < m; i++)
	{
		if (strcmp(person[i].staff_name, name) == 0)
		{
			printf("已找到此人******该人信息如下：\n");
			printf("______________________________________________________________\n");
			printf("|                          职工信息表                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| 编号 | 姓名 | 性别| 婚姻状况|学历| 所属部门 | 工资|   工龄 |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);
			printf("请确认是否修改该职工信息？确认-》》1******取消-》》2\n");
			scanf("%d", &n);

			if (n == 1)
			{
				printf("请输入您需要修改该职工的信息选项：\n");
				printf("1->>职工编号\t2->>职工姓名\t3->>职工性别\t4->>婚姻状况\n");
				printf("5->>职工学历\t6->>所属部门\t7->>职工工资\t8->>职工工龄\n");
				scanf("%d", &a);
			}
		}f = 0;
	}
	if (f == 1)
	{
		printf("------查无此人!-----\n");
	}

	do {
		switch (a)
		{
		case 1:printf("职工编号改为："); scanf("%s", &number); strcpy(person[i - 1].staff_number, number); break;
		case 2:printf("职工姓名改为："); scanf("%s", &name); strcpy(person[i - 1].staff_name, name); break;
		case 3:printf("职工性别改为："); scanf("%s", &sex); strcpy(person[i - 1].staff_sex, sex); break;
		case 4:printf("婚姻状况改为："); scanf("%s", &marriage); strcpy(person[i - 1].staff_marriage, marriage); break;
		case 5:printf("职工学历改为："); scanf("%s", &degree); strcpy(person[i - 1].staff_degree, degree); break;
		case 6:printf("所属部门改为："); scanf("%s", &apartment); strcpy(person[i - 1].staff_apartment, apartment); break;
		case 7:printf("职工工资改为："); scanf("%s", &pay); strcpy(person[i - 1].staff_pay, pay); break;
		case 8:printf("职工工龄改为："); scanf("%s", &year); strcpy(person[i - 1].staff_year, year); break;
		default:
			break;
		}
		printf("请确认是否修改该职工信息？确认-》》1******重新修改-》》2\n");
		scanf("%d", &b);
	} while (b == 2);
	fun(m);
	show();
	if (n == 2)
		exit(0);
	printf("继续修改请按1，不继续请按0\n");
	scanf("%d", &t);
	switch (t)
	{
	case 1:change(); break;
	case 0:break;
	default:
		break;
	}



}

int exit()
{
	return 0;
}



int main()
{
	int k;
	do
	{

		printf("\n");
		printf("\t▄︻┻┳═一 \t\t┗( T﹏T )┛\t\t一┳═┻︻▄");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t      ╭━━━━━━━━━━━━━━╮ \n");
		printf("\t\t      ┃欢迎进入公司职工信息管理系统┃\n");
		printf("\t\t      ┃     ①    添加职工信息     ┃\n");
		printf("\t\t      ┃     ②    查找职工信息     ┃\n");
		printf("\t\t      ┃     ③    显示职工信息     ┃\n");
		printf("\t\t      ┃     ④    删除职工信息     ┃\n");
		printf("\t\t      ┃     ⑤    追加职工信息     ┃\n");
		printf("\t\t      ┃     ⑥    修改职工信息     ┃\n");
		printf("\t\t      ┃     ⑦    退出系统         ┃\n");
		printf("\t\t      ╰━━━━━━━━━━━━━━╯\n");
		printf("\t\t           请输入需要选择的编号:  ");

		scanf("%d", &k);
		switch (k)
		{
		case 1: system("cls"); add(); 	system("pause>nul");
			system("cls"); break;
		case 2: system("cls"); seek();	system("pause>nul");
			system("cls"); break;
		case 3:system("cls"); show();	system("pause>nul");
			system("cls"); break;
		case 4:system("cls"); delete_();	system("pause>nul");
			system("cls"); break;
		case 5: system("cls"); big_add();	system("pause>nul");
			system("cls"); break;
		case 6: system("cls"); change();	system("pause>nul");
			system("cls"); break;
		case 7:return 0; break;
		default:
			break;
		}
	} while (k);
}
