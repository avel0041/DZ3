#include "Group.h"


Group::Group()
{

	Name_Group = nullptr;
	StudentsNum = Countof2 = Countof5 = 0;
	AverageBall = AverageBallMath = AverageBallPhys = 0;
}

Group::Group(string Name, vector<Student> stud)
{
	for (int i = 0; i < stud.size(); i++) {
		add(stud[i]);
	}
	Name_Group = Name;
	StudentsNum = 0;
}

Group::~Group()
{

}

void Group::set_NameGroup(string NameGr)
{
	Name_Group = NameGr;
}



string Group::get_NameGroup()
{
	return Name_Group;
}
int Group::get_StudentsNum()
{
	return Students.size();
}
double Group::get_AverageBall()
{
	return AverageBall;
}
double Group::get_AverageBallPhys()
{
	return AverageBallPhys;
}
double Group::get_AverageBallMath()
{
	return AverageBallMath;
}
int Group::get_Countof5()
{
	return Countof5;
}
int Group::get_Countof2()
{
	return Countof2;
}

void Group::update() {
	AverageBall = AverageBallMath = AverageBallPhys = 0;
	for (int i = 0; i < OzenkiPhys.size(); i++) {
		AverageBallPhys += OzenkiPhys[i];
		AverageBall += OzenkiPhys[i];
	}
	for (int i = 0; i < OzenkiMath.size(); i++) {
		AverageBallMath += OzenkiMath[i];
		AverageBall += OzenkiMath[i];
	}
	AverageBallPhys /= (1.*OzenkiPhys.size());
	AverageBallMath /= (1.*OzenkiMath.size());
	AverageBall /= (1.*(OzenkiMath.size() + OzenkiPhys.size()));
}


void Group::add(Student& stud)
{
	Students.push_back(stud);
	StudentsNum += 1;
	OzenkiMath.push_back(stud.get_MathOzenka());
	OzenkiPhys.push_back(stud.get_FizOzenka());
	if (stud.get_MathOzenka() == 5 && stud.get_FizOzenka() == 5) {
		Countof5 += 1;
	}
	if (stud.get_MathOzenka() == 2 && stud.get_FizOzenka() == 2) {
		Countof2 += 1;
	}
	update();
}

void Group::del()
{
	if (Students.empty()) {
		cout << "It's empty";
		return;
	}
	Students.pop_back();
	StudentsNum -= 1;
	OzenkiMath.pop_back();
	OzenkiPhys.pop_back();
	update();
}

void Group::print_Students()
{
	for (auto it = Students.begin(); it != Students.end(); it++) {
		cout << *it;
		cout << endl;
	}
}


void Group::print_5()
{
	for (int i = 0; i < Students.size(); i++) {
		if (Students[i].get_MathOzenka() == 5 && Students[i].get_FizOzenka() == 5) cout << Students[i];
	}
}

void Group::print_2()
{
	for (int i = 0; i < Students.size(); i++) {
		if (Students[i].get_MathOzenka() == 2 && Students[i].get_FizOzenka() == 2)cout << Students[i];
	}
}

Group Group::operator+(Student& stud)
{
	add(stud);
	return *this;
}

ostream& operator<<(ostream& out, Group& Gr)
{
	Gr.update();
	out << "Group:" <<
		"name = " << Gr.get_NameGroup() << ";" << endl <<
		"number of Students = " << Gr.get_StudentsNum() << ";" << endl <<
		"Average ball = " << Gr.get_AverageBall() << ";" << endl <<
		"Average ball (Phys) = " << Gr.get_AverageBallPhys() << ";" << endl <<
		"Average ball (Math) = " << Gr.get_AverageBallMath() << ";" << endl <<
		"Number of 5 = " << Gr.get_Countof5() << ";" << endl <<
		"Nice = " << endl;
	Gr.print_5();
	out << endl << "Number of 2 = " << Gr.get_Countof2() << ";" << endl
		<< "Bad = " << endl;
	Gr.print_2();
	out << endl;
	return out;
}

void Group::search(string name, int age, int MO, int FO)
{
	int i = 0;
	vector<Student>::iterator it = Students.begin();
	while (it != Students.end()) {
		string temp_name = name;
		int temp_age = age;
		int temp_MO = MO;
		int temp_FO = FO;
		Student S = *it;
		if (name == "null") temp_name = S.get_name();
		if (age == 0) temp_age = S.get_age();
		if (MO == 0) temp_MO = S.get_MathOzenka();
		if (FO == 0) temp_FO = S.get_FizOzenka();
		if ((S.get_age() == temp_age) && (S.get_name() == temp_name) &&
			(S.get_MathOzenka() == temp_MO) && (S.get_FizOzenka() == temp_FO)) {
			cout << S;
			i++;
		}
		it++;
	}
	if (i == 0) cout << "No matches found";
}

void Group::edit(string student_name, string new_student_name, int age, int PO, int MO) {
	vector<Student>::iterator it = Students.begin();
	while (it != Students.end()) {
		Student S = *it;
		if (S.get_name() == student_name) {
			S.set_age(age);
			S.set_name(new_student_name);
			S.set_FizOzenka(PO);
			S.set_MathOzenka(MO);
			*it = S;
			cout << "Done";
			return;
		}
		it++;
	}
	cout << "No matches found!" << endl;
}

void Group::delstudent(int ind)
{
	if (Students.empty()) {
		cout << "List is empty";
		return;
	}
	vector<Student>::iterator it = Students.begin();
	advance(it, ind - 1);
	Students.erase(it);
	update();
}

ofstream& operator<<(ofstream& outf, Group& Gr)
{
	for (vector<Student>::iterator it = Gr.Students.begin(); it != Gr.Students.end(); it++)
	{
		outf << it->get_name() << endl;
		outf << it->get_age() << endl;
		outf << it->get_FizOzenka() << endl;
		outf << it->get_MathOzenka() << endl;
	}
	return outf;
}

ifstream& operator>>(ifstream& inf, Group& Gr)
{
	string name = {};
	int age = 0, PO = 0, MO = 0;
	while (inf) {
		inf >> name;
		inf >> age;
		inf >> MO;
		inf >> PO;
		if (!inf) break;
		Student A(name, age, MO, PO);
		Gr + A;
	}
	return inf;
}

void Group::agesort() {
	sort(Students.begin(), Students.end(), [](Student& a, Student& b) { return a.get_age() < b.get_age(); });
}

void Group::namesort() {
	sort(Students.begin(), Students.end(), [](Student& a, Student& b) { return a.get_name() < b.get_name(); });
}