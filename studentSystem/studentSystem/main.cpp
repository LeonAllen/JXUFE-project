#include"stdio.h"
#include"process.h"
#include"string.h"
#include"windows.h"
#define N 1000//ְ������
struct staff_list
{
	char staff_number[10];//ְ�����
	char staff_name[10];//����
	char staff_sex[10];//�Ա�
	char staff_marriage[10];//����״��
	char staff_degree[10];//ѧ��
	char staff_apartment[10];//��������
	char staff_pay[10];//����
	char staff_year[10];//����
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


void add()//����ְ����Ϣ
{
	char c5[999] = "______________________________________________________________\n";
	char c6[108] = "|                          ְ����Ϣ��                        |\n";
	char c7[108] = "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n";
	char c8[208] = "|  ���  |���� |�Ա�|����״��|ѧ��| �������� | ����|���䣨��)|\n";
	strcat(c5, c6); strcat(c5, c7); strcat(c5, c8);
	int i, m, a;

	printf("��������Ҫ������ְ��������1~1000����");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		printf("�������%d��ְ����ţ������磺0154097��", i + 1);
		scanf("%s", &person[i].staff_number);
		printf("�������%d��ְ�������������磺������", i + 1);
		scanf("%s", &person[i].staff_name);
		printf("�������%d��ְ���Ա𣺣����磺�У�", i + 1);
		scanf("%s", &person[i].staff_sex);
		printf("�������%d��ְ������״���������磺δ�飩", i + 1);
		scanf("%s", &person[i].staff_marriage);
		printf("�������%d��ְ��ѧ���������磺Сѧ��", i + 1);
		scanf("%s", &person[i].staff_degree);
		printf("�������%d��ְ���������ţ������磺��������", i + 1);
		scanf("%s", &person[i].staff_apartment);
		printf("�������%d��ְ�����ʣ������磺1000��", i + 1);
		scanf("%s", &person[i].staff_pay);
		printf("�������%d��ְ�����䣺�����磺1��", i + 1);
		scanf("%s", &person[i].staff_year);
	}


	printf("\t--------------------��Ϣ¼��ɹ�----------------------------\n");
	fun(m);
	printf("\t         �Ƿ�������룬���밴1�������밴0: ");
	scanf("%d", &a);

	i++;


}

void seek()
{

	int i; char n[1000];
	printf("����������Ҫ���ҵ�ְ�����:");

	scanf("%s", n);
	for (i = 0; i < N; i++)
		if (strcmp(person[i].staff_number, n) == 0)
		{
			printf("��ְ����Ϣ���£�\n");
			printf("______________________________________________________________\n");
			printf("|                          ְ����Ϣ��                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| ��� | ���� | �Ա�| ����״��|ѧ��| �������� | ����|   ���� |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);

		}
	if (i == 1001)
		printf("\t*****************���޴���************************");
}
int read()
{
	FILE *tp;
	int i = 0;
	if (!(tp = fopen("f2", "r")))
	{
		printf("�޷��򿪸��ļ�\n");
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
	char c6[108] = "|                          ְ����Ϣ��                        |\n";
	char c7[108] = "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n";
	char c8[208] = "| ��� | ���� | �Ա�| ����״��|ѧ��| �������� | ����|   ���� |\n";
	strcat(c5, c6); strcat(c5, c7); strcat(c5, c8);
	printf("��ʾ����ְ����Ϣ��\n");
	printf("%s", c5);

	int i;
	int m = read();

	for (i = 0; i < m; i++)
	{
		printf("  %s    %s     %s     %s    %s     %s      %s    %s\n", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);
	}
}
void delete_()// ���庯������ɾ��Ա����Ϣ
{
	int  i, n, j, flag, m = read(), t;
	char z[1000];
	printf("��ӭ����ɾ��Ա����Ϣ���棺\n");
	printf("��������Ҫɾ����ְ����ţ�\n");
	scanf("%s", z);
	for (i = 0; i < m; i++)
	{
		if (!strcmp(person[i].staff_number, z))
		{
			printf("ְ����Ϣ�Ѿ��ҵ�����ʾ������£�\n");
			printf("______________________________________________________________\n");
			printf("|                          ְ����Ϣ��                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| ��� | ���� | �Ա�| ����״��|ѧ��| �������� | ����|   ���� |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);

			printf("\n");

			printf("������˼���Ƿ����Ҫɾ����Ա����Ϣ�� ȷ��ɾ��������1��ȡ��������2\n");
			scanf("%d", &n);
		}
		else
			printf("------���޴���!-----\n");
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
			printf("\t***********�ɹ�ɾ��************\n");
			break;
		}
		if (n == 2)
			break;
	}

	printf("����ɾ���밴1��������ɾ���밴0;");
	scanf("%d", &t);
	switch (t)
	{
	case 1:delete_();
	case 0:break;
	default:
		break;
	}


}
void big_add()//׷��ְ����Ϣ
{
	FILE *tp;
	int n, i, c = 0, m = read();
	printf("ԭ����ְ����ϢΪ��");
	show();
	printf("\n");
	tp = fopen("f2.txt", "a");
	printf("��������Ҫ׷�ӵ�ְ��������");
	scanf("%d", &n);
	for (i = m; i < (m + n); i++)
	{
		printf("������ְ����ţ�");
		scanf("%s", &person[i].staff_number);
		printf("������ְ��������");
		scanf("%s", &person[i].staff_name);
		printf("������ְ���Ա�");
		scanf("%s", &person[i].staff_sex);
		printf("������ְ������״����");
		scanf("%s", &person[i].staff_marriage);
		printf("������ְ��ѧ����");
		scanf("%s", &person[i].staff_degree);
		printf("������ְ���������ţ�");
		scanf("%s", &person[i].staff_apartment);
		printf("������ְ�����ʣ�");
		scanf("%s", &person[i].staff_pay);
		printf("������ְ�����䣺");
		scanf("%s", &person[i].staff_year);
		c = c + 1;
	}
	m += c;
	printf("׷����Ϻ�ȫ��ְ�������Ѵ%d��", c + m - 1);
	printf("׷����Ϻ�ȫ��ְ����Ϣ����:");
	fun(m);
	show();
	fclose(tp);


}
void change()
{
	char number[10];//ְ�����
	char name[10];//����
	char sex[10];//�Ա�
	char marriage[10];//����״��
	char degree[10];//ѧ��
	char apartment[10];//��������
	char pay[10];//����
	char year[10];//����
	int m = read(), i, n, a, t, b, f = 1;
	printf("ԭ����Ϣ���£�");
	show();
	printf("��������Ҫ�޸ĵ�ְ��������");
	scanf("%s", name);
	for (i = 0; i < m; i++)
	{
		if (strcmp(person[i].staff_name, name) == 0)
		{
			printf("���ҵ�����******������Ϣ���£�\n");
			printf("______________________________________________________________\n");
			printf("|                          ְ����Ϣ��                        |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\n");
			printf("| ��� | ���� | �Ա�| ����״��|ѧ��| �������� | ����|   ���� |\n");
			printf("  %s    %s     %s     %s    %s     %s      %s    %s", person[i].staff_number, person[i].staff_name, person[i].staff_sex, person[i].staff_marriage, person[i].staff_degree, person[i].staff_apartment, person[i].staff_pay, person[i].staff_year);
			printf("��ȷ���Ƿ��޸ĸ�ְ����Ϣ��ȷ��-����1******ȡ��-����2\n");
			scanf("%d", &n);

			if (n == 1)
			{
				printf("����������Ҫ�޸ĸ�ְ������Ϣѡ�\n");
				printf("1->>ְ�����\t2->>ְ������\t3->>ְ���Ա�\t4->>����״��\n");
				printf("5->>ְ��ѧ��\t6->>��������\t7->>ְ������\t8->>ְ������\n");
				scanf("%d", &a);
			}
		}f = 0;
	}
	if (f == 1)
	{
		printf("------���޴���!-----\n");
	}

	do {
		switch (a)
		{
		case 1:printf("ְ����Ÿ�Ϊ��"); scanf("%s", &number); strcpy(person[i - 1].staff_number, number); break;
		case 2:printf("ְ��������Ϊ��"); scanf("%s", &name); strcpy(person[i - 1].staff_name, name); break;
		case 3:printf("ְ���Ա��Ϊ��"); scanf("%s", &sex); strcpy(person[i - 1].staff_sex, sex); break;
		case 4:printf("����״����Ϊ��"); scanf("%s", &marriage); strcpy(person[i - 1].staff_marriage, marriage); break;
		case 5:printf("ְ��ѧ����Ϊ��"); scanf("%s", &degree); strcpy(person[i - 1].staff_degree, degree); break;
		case 6:printf("�������Ÿ�Ϊ��"); scanf("%s", &apartment); strcpy(person[i - 1].staff_apartment, apartment); break;
		case 7:printf("ְ�����ʸ�Ϊ��"); scanf("%s", &pay); strcpy(person[i - 1].staff_pay, pay); break;
		case 8:printf("ְ�������Ϊ��"); scanf("%s", &year); strcpy(person[i - 1].staff_year, year); break;
		default:
			break;
		}
		printf("��ȷ���Ƿ��޸ĸ�ְ����Ϣ��ȷ��-����1******�����޸�-����2\n");
		scanf("%d", &b);
	} while (b == 2);
	fun(m);
	show();
	if (n == 2)
		exit(0);
	printf("�����޸��밴1���������밴0\n");
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
		printf("\t�{��ߩרTһ \t\t��( T�nT )��\t\tһ�רT�ߦ�{");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t      �q�����������������������������r \n");
		printf("\t\t      ����ӭ���빫˾ְ����Ϣ����ϵͳ��\n");
		printf("\t\t      ��     ��    ���ְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    ����ְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    ��ʾְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    ɾ��ְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    ׷��ְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    �޸�ְ����Ϣ     ��\n");
		printf("\t\t      ��     ��    �˳�ϵͳ         ��\n");
		printf("\t\t      �t�����������������������������s\n");
		printf("\t\t           ��������Ҫѡ��ı��:  ");

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
