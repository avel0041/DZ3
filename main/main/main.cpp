// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Student.h"
#include "Group.h"


int main(int argc, char *argv[])
{
	//Режимы работы:
	//Ввод нового объекта и добавление его в массив (addstudent <Name> <Age> <Phys> <Math>)
	//Поиск объекта в массиве по значениям полей (find <Name>/<Age>/<Phys>/<Math>)
	//Редактирование объекта (edit <Name> <Age> <Phys> <Math> with Name/Age/Phys/Math = <Name>/<Age>/<Phys>/<Math>)
	//Удаление объекта из массива (del <Name> <Age> <Phys> <Math>)
	//Cохранение массива объектов в файле (save)
	//Чтение списка(массива) объектов из файла (read)
	//Сортировка списка(массива) объектов как минимум одному из 2 - х полей (sort)
	//	выбор поля осуществляется через командную строку (Name/Age)
	//Печать списка объектов (print)
	cout << "Enter name of group" << endl;
	string group_name;
	cin >> group_name;
	Group Gr(group_name, {});
	string a{ "start" };
	cout << "Avaliable commands:" << endl
		<< "add;" << endl
		<< "find;" << endl
		<< "edit;" << endl
		<< "del;" << endl
		<< "save;" << endl
		<< "read;" << endl
		<< "sort;" << endl
		<< "print;" << endl
		<< "stop." << endl;
	while (a != "stop") {
		cout << "Enter command" << endl;
		cin >> a;
		if (a == "add") {
			cout << "enter student (<Name> <Age> <PhysGrade> <MathGrade>)" << endl;
			string Name;
			int Age, Phys, Math;
			cin >> Name >> Age >> Phys >> Math;
			Student St(Name, Age, Math, Phys);
			Gr + St;
			cout << "Done" << endl;
		}
		if (a == "find") {
			cout << "Enter student name (if you dont have information, enter null)" << endl;
			string student_name;
			cin >> student_name;
			cout << "Enter student age (if you dont have information, enter 0)" << endl;
			int age;
			cin >> age;
			cout << "Enter student Math grade (if you dont have information, enter 0)" << endl;
			int MO;
			cin >> MO;
			cout << "Enter student Phys grade (if you dont have information, enter 0)" << endl;
			int PO;
			cin >> PO;
			Gr.search(student_name, age, MO, PO);
		}
		if (a == "edit") {
			cout << "Enter student name" << endl;
			string student_name;
			cin >> student_name;
			cout << "Enter new information:" << endl
				<< "Enter new name:" << endl;
			string new_student_name;
			cin >> new_student_name;
			cout << "Enter new age:" << endl;
			int age;
			cin >> age;
			cout << "Enter new Phys Grade:" << endl;
			int PO;
			cin >> PO;
			cout << "Enter new Math Grade:" << endl;
			int MO;
			cin >> MO;
			Gr.edit(student_name, new_student_name, age, PO, MO);
		}
		if (a == "print") {
			Gr.print_Students();
		}
		if (a == "del") {
			Gr.print_Students();
			cout << "chose position of student to delete" << endl;
			int position;
			cin >> position;
			Gr.delstudent(position);
			cout << "Done" << endl;
		}
		if (a == "save") {
			ofstream outf("Group.txt");
			outf << Gr;
			outf.close();
		}
		if (a == "read") {
			ifstream inf("Group.txt");
			inf >> Gr;
			inf.close();
		}
		if (a == "sort") {
			cout << "Press 1 to sort by name" << endl
				<< "or press 2 to sort by age" << endl;
			int ch;
			cin >> ch;
			if (ch == 2) Gr.agesort();
			if (ch == 1) Gr.namesort();
			cout << "Done";
		}
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
