#ifndef Group_H
#define Group_H

#include "Student.h"
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Group
{
	string Name_Group;
	int StudentsNum;
	double AverageBall;
	double AverageBallPhys;
	double AverageBallMath;
	int Countof5;
	int Countof2;
	vector<int> OzenkiPhys;
	vector<int> OzenkiMath;
	vector<Student> Students;
public:
	Group();
	Group(string Name, vector<Student> stud);
	~Group();
	string get_NameGroup();
	int get_StudentsNum();
	double get_AverageBall();
	double get_AverageBallPhys();
	double get_AverageBallMath();
	int get_Countof5();
	int get_Countof2();
	void print_5();
	void print_2();
	void set_NameGroup(string NameGr);
	void update();
	void add(Student& stud);
	void del();
	void print_Students();
	friend ostream& operator<<(ostream& out, Group& gr);
	Group operator+(Student& Stud);
	void search(string name, int age, int MO, int FO);
	void edit(string student_name, string new_student_name, int age, int PO, int MO);
	void delstudent(int ind);
	friend ofstream& operator<<(ofstream& outf, Group& Gr);
	friend ifstream& operator>>(ifstream& inf, Group& Gr);
	void agesort();
	void namesort();
};

#endif