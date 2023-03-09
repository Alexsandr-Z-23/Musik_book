#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>   
#include <filesystem> 
#include <stdio.h>
#include<Windows.h>

const int MAXSIZE = 1000;
using namespace std;


struct MusicCard
{
	char MusicName[100]{ '0' };
	char AuthorName[100]{ '0' };
	char DATE[12]{ '0' };
	char TextMusic[1000]{ '0' };
};
int main();
int get_line_size(char str[], int max)// высчитвание длену строки
{
	int cymbol;
	int lenght;
	for (lenght = 0; (cymbol = getchar()) != EOF && cymbol != '\n' && lenght < max - 1; lenght++)
	{
		str[lenght] = cymbol;
	}
	str[lenght] = '\n';
	return lenght;
}
int ListMusic(MusicCard* List)
{
	//get_line_size(Buf_Str2, MAXSIZE);
	//M= (struct MusicCard*)realloc(M, (100) * sizeof(struct MusicCard));
	//if (M == nullptr)	exit(EXIT_SUCCESS);
	FILE* f;
	if ((f = fopen("text1.txt", "r")) == NULL)
	{
		printf("!!!Файл небыл открыт!!! \n");
	}

	//char Buf_Str[MAXSIZE];
	char Buf_Str2[MAXSIZE];//массив куда считываеться файл
	int lengt;// размер длены строки

	char Name[] = "Название песни : ";//масивы на первое вхождение в буфере для указателя 
	char Autor[] = "Автор : ";
	char Year[] = "Год издания : ";
	int ch1 = '*';
	char* name, * autor, * year;// указатели буфера для определениея поля структуры

	int counter_list = 0;// счетчик структуры  list

	int Index = -1;// индекс полей структуры структуры list
	int line = 0, any = 0;
	int nm = 0, at = 0, dt = 0, tt = 0; //счетчики

	if (f != NULL)
	{

		fgets(Buf_Str2, sizeof(Buf_Str2), f);//считывание файла в массив
		lengt = strlen(Buf_Str2);// оприделение длены строки массива



		/*do// цыкл на посимвольное считывание строки и при равенстве перехода строки выполняеться счетчик строк до окончания файла
		{
			any = fgetc(f);
			if (any == '\n')
			{
				line++;
				cout << "строка " << line << endl;
			}
		} while (any != EOF);*/
		do
		{
			name = strstr(Buf_Str2, Name);// оприделение входит ли строка массива инициализированого нами для структуры в буферном масиве если да возвращает указатель
			autor = strstr(Buf_Str2, Autor);
			year = strstr(Buf_Str2, Year);
			line++;
			cout << "строка " << line << endl;
			for (int i = 0; i < strlen(Buf_Str2); i++)
			{
				if (Buf_Str2[strlen(Buf_Str2) - 1] == '\n') //если буфер равен переходу на новую строку то присваиваем конец строки
				{
					Buf_Str2[strlen(Buf_Str2) - 1] = '\0';
					break;
				}

			}
			/*for (int i = 0; i < line; i++)
			{
				if (Buf_Str2[i] == '\n') если буфер равен переходу на новую строку то присваиваем конец строки
				{
					Buf_Str2[i] = '\0';
				}
				if (Buf_Str2[i] == '*')//проверка на разделитель файла
				{
					counter_list++;
					cout << counter_list << endl;
					continue;
				}
				if (Post != NULL)
				{

					continue;
				}
			}*/
			if (strchr(Buf_Str2, ch1) != NULL)
			{
				counter_list++;
				Index = 0;
				nm = 0;
				at = 0;
				dt = 0;
				tt = 0;


				cout << counter_list << endl;
			}
			else { Index++; }

			//for (int i = 0; i < line; i++)


			if (Index == 0)
			{
				List[counter_list].MusicName[nm] = '\0';
			}
			if (Index == 1) {
				List[counter_list].AuthorName[at] = '\0';
			}
			if (Index == 2) {
				List[counter_list].DATE[dt] = '\0';
			}

			if (Index >= 3) {
				List[counter_list].TextMusic[tt] = '\0';
			}



			if (name != NULL)
			{
				for (int i = 0; i < strlen(Buf_Str2); i++)
				{
					List[counter_list].MusicName[nm] = Buf_Str2[i];
					nm++;
				}
				//strncpy(&List[counter_list].MusicName[nm], Buf_Str2, lengt);

			}
			if (autor != NULL)
			{
				//List[counter_list].AuthorName[at] = Buf_Str2[i];

				for (int i = 0; i < strlen(Buf_Str2); i++)
				{
					List[counter_list].AuthorName[at], Buf_Str2[i];
					at++;
				}
				/*strncpy(&List[counter_list].AuthorName[at], Buf_Str2, lengt);
				at++;*/
			}
			if (year != NULL)
			{
				for (int i = 0; i < strlen(Buf_Str2); i++)
				{
					List[counter_list].DATE[dt], Buf_Str2[i];
					dt++;
				}
				//List[counter_list].DATE[dt] = Buf_Str2[i];
				/*strncpy(&List[counter_list].DATE[dt], Buf_Str2, lengt);
				dt++;*/
			}
			if (Index >= 4)
			{
				for (int i = 0; i < strlen(Buf_Str2); i++)
				{
					List[counter_list].TextMusic[dt], Buf_Str2[i];
					tt++;
				}
				//List[counter_list].TextMusic[tt] = Buf_Str2[i];
				/*strncpy(&List[counter_list].TextMusic[tt], Buf_Str2, strlen(Buf_Str2));
				tt++;*/
			}


			//delete[] Buf_Str2;
			//for (int i = 0; i <= /*counter_list*/ (sizeof(List->MusicName) != NULL); i++)
			//	{
			//		cout << List[counter_list].MusicName[nm] << endl;
			//		cout << List[counter_list].AuthorName[at] << endl;
			//		cout << List[counter_list].DATE[dt] << endl;
			//		cout << List[counter_list].TextMusic[tt] << endl;
			//		cout << "_____________________________________________________________________";
			//	}
		} while (fgets(Buf_Str2, sizeof(Buf_Str2), f));
		fclose(f);
	}
	_getwch();
	return counter_list;
}
//int Index = 0;
//do
//{
//	if (Index == 0)
//	{
//		fgets(Buf_Str2, MAXSIZE, f);
//		strncpy((List[Index].MusicName), Buf_Str2, strlen(Buf_Str2));
//		for (int i = 0; i < strlen(Buf_Str2); i++)
//			cout << List[i].MusicName;N++;
//	}
//	if (Index == 1)
//	{
//		fgets(Buf_Str2, MAXSIZE, f);
//		strncpy(List[Index].AuthorName, Buf_Str2, strlen(Buf_Str2));
//		for (int i = 0; i < strlen(Buf_Str2); i++)
//			cout << List[i].AuthorName;
//	}
//	if (Index == 2)
//	{
//		fgets(Buf_Str2, MAXSIZE, f);
//		strncpy(List[Index].DATE, Buf_Str2, strlen(Buf_Str2));
//		for (int i = 0; i < strlen(Buf_Str2); i++)
//			cout << List[i].DATE;
//	}
//	//if (Index >= 3)
//	//{
//	//	//char str= "*************";
//	//	if(strcmp(Buf_Str2,Buf_Str ) && f!=NULL)
//	//	{
//	//		for (int i = 0; i < strlen(Buf_Str2); i++)
//	//		{
//	//			fgets(Buf_Str2, MAXSIZE, f);
//	//			strncpy(List->FileName, Buf_Str2, strlen(Buf_Str2));

//	//		}
//	//		for (int i = 0; i < strlen(Buf_Str2); i++)
//	//			cout << i << List[i].FileName;
//	//	} 
//	//	//if ((Index = 4) == NULL)continue;
//	//		//else cout << "[" << Index - 3 << "] ";
//	//}
//	//Index++;
//	
//	/*return Index;*/
//} while (!feof(f));




void MusicText(MusicCard* List)
{
	system("cls");
	int a;
	int al = 1;/*sizeof(List->MusicName) / sizeof(List->MusicName);*/
	cout << "Выберите музыкальное произведение: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << al << "] ";
		printf("%s \n", List[i].MusicName);
		al++;
	}
	cin >> a;
	for (int i = 0; i < 5; i++)
	{

		if (a - 1 == i)
		{
			int count = 1;
			for (int i = 0; i < (sizeof(List[i].TextMusic) != NULL); i++) {
				cout << "[" << count << "] ";
				printf("%s \n", List[i].TextMusic);
				count++;
			}
		}
	}
	while ((a <= 0) || (a > al))
	{
		cout << "Неверное значение." << endl;
		if ((a <= 0) || (a > al)) { main(); }
	}
	
	_getwch();
};
void SaveMusic(MusicCard* List)
{};
void DeleteMusic(MusicCard* List)
{};
void FindAuthorMusic(MusicCard* List)
{};
void FindWordInMusic(MusicCard* List)
{};
void EditSong(MusicCard* List)
{};

//void main_menu() {
//	
//	system("cls"); 
//	int index = -1;
//	int a = 1;
//	MusicCard* List = new MusicCard[100];
//	ListMusic(List);
//
//	while (a != 0) {
//		system("cls");
//		cout << "Каталог текстов песен" << endl;
//		cout << "---------------------" << endl;
//		cout << "Выберите действие: " << endl;
//		cout << "[1] - Вывести текст песни." << endl;
//		cout << "[2] - Сохранить текст песни в файл." << endl;
//		cout << "[3] - Удалить песню из каталога." << endl;
//		cout << "[4] - Поиск песен одного автора." << endl;
//		cout << "[5] - Поиск слова в песнях." << endl;
//		cout << "[6] - Изменение текста песни." << endl;
//		cout << "[0] - Выход из программы." << endl;
//		cin >> a;
//		while ((a < 0) || (a > 6)) {
//			cout << "Неверное значение." << endl;
//			cin >> a;
//		}
//		//cin.get();
//		if (a == 1) MusicText(List, index);
//		else if (a == 2) SaveMusic(List);
//		else if (a == 3) DeleteMusic(List);
//		else if (a == 4) FindAuthorMusic(List);
//		else if (a == 5) FindWordInMusic(List);
//		else if (a == 6) EditSong(List);
//		else if (a == 0) break;
//	}
//	
//}



int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "1251");
	printf("Чтобы начать работу нажмите клавишу [ENTER]!!!\n");
	_getwch();


	MusicCard* List = new MusicCard[100];
	ListMusic(List);

	system("cls");
	//main_menu();
	while (true) {
		system("cls");
		printf("Каталог текстов песен\n");
		printf("---------------------\n");
		printf("Выберите действие: \n");
		printf("[1] - Вывести текст песни.\n");
		printf("[2] - Сохранить текст песни в файл.\n");
		printf("[3] - Удалить песню из каталога.\n");
		printf("[4] - Поиск песен одного автора.\n");
		printf("[5] - Поиск слова в песнях.\n");
		printf("[6] - Изменение текста песни.\n");
		printf("[0] - Выход из программы.\n");

		int choice;
		cin >> choice;

		switch (choice) {
			//ListMusic(List);
		case 1:  MusicText(List); break;
		case 2:  SaveMusic(List); break;
		case 3:  DeleteMusic(List); break;
		case 4:  FindAuthorMusic(List); break;
		case 5:  FindWordInMusic(List); break;
		case 6:  EditSong(List); break;
		case 0: exit(EXIT_SUCCESS); break;
		default: printf("Ошибка\n");
		}
		system("pause");
	}

	return 0;


}

