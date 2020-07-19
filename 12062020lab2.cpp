/*
Задание 2
Создайте класс Worker.
Необходимо хранить данные:
ФИО, Должность, Год поступления на работу, Зарплата.
Name, Position, Year of employment, Salary.
Создать массив объектов.
Вывести:
■ список работников, стаж работы которых на данном предприятии превосходит заданное число лет;
■ список работников, зарплата которых превосходит заданную;
■ список работников, занимающих заданную должность.
■ a list of workers whose work experience at the enterprise exceeds a predetermined number of years;
■ a list of employees whose salary exceeds the given;
■ a list of employees holding a given position.
Используйте explicit конструктор и константные функции-члены (например, для отображения данных о работнике и т.д.)
*/
#include <iostream>
#include <windows.h>
using namespace std;
class Worker
{
	char* m_Name;
	char* m_Position;
	int m_YearOfEmployment;
	double m_Salary;
public:
	Worker(const char* nm, const char* pstn, int yrOfEmpl, double slr) :
		m_Name(_strdup(nm)), m_Position(_strdup(pstn)), m_YearOfEmployment(yrOfEmpl), m_Salary(slr) { };
	Worker();
	~Worker();
	int get_year() { return m_YearOfEmployment; }
	int get_salary() { return m_Salary; }
	const char* get_positin() { return m_Position; }
	const void show();
	void workersWhoseWorkExpMoreThan(Worker* A, const int count_workers, int moreThanYears);
	void workersWhoseSalaryMoreThan(Worker* A, const int count_workers, int salaryMoreThan);
	const void workersHoldingAGivenPosition(Worker* A, const int count_workers, const char* position);
};
Worker::Worker()
{
	m_Name = 0;
	m_Position = 0;
	m_YearOfEmployment = 0;
	m_Salary = 0.0;
}
Worker::~Worker()
{
	delete[] m_Name; //cout << "Деструктор для " << this << endl;
	delete[] m_Position;
}

const void Worker::show()
{
	cout << "ФИО: " << m_Name << endl;
	cout << "Должность: " << m_Position << endl;
	cout << "Год поступления на работу: " << m_YearOfEmployment << endl;
	cout << "Зарплата: " << m_Salary << endl;
	cout << "/****************************************************" << endl;
}

void Worker::workersWhoseWorkExpMoreThan(Worker* A, const int count_workers, int moreThanYears)
{
	int workersexpirience = 0;
	cout << "\tРаботники со стажем больше " << moreThanYears << " лет :" << endl;
	for (size_t i = 0; i < count_workers; i++)
	{
		workersexpirience = 2020 - A[i].get_year();
		if (workersexpirience > moreThanYears)
		{
			A[i].show();
		}
	}
}

void Worker::workersWhoseSalaryMoreThan(Worker* A, const int count_workers, int salaryMoreThan)
{
	cout << "\tРаботники с зарплатой больше " << salaryMoreThan << " :" << endl;
	for (size_t i = 0; i < count_workers; i++)
	{
		if (A[i].get_salary() > salaryMoreThan)
		{
			A[i].show();
		}
	}
}

const void Worker::workersHoldingAGivenPosition(Worker* A, const int count_workers, const char* position)
{
	cout << "\tРаботники занимающие должность - " << position << " :" << endl;
	for (size_t i = 0; i < count_workers; i++)
	{
		if (strcmp(A[i].get_positin(), position) == 0) A[i].show();
	}
}

int main()
{
	setlocale(LC_ALL, ""); //працює тільки з потоком виведення
	SetConsoleCP(1251); //встановлює потрібну кодову таблицю, на потік введення
	SetConsoleOutputCP(1251); //встановлює потрібну кодову таблицю, на потік виводу.
	const int count_workers = 5;
	Worker* A = new Worker[count_workers]{
		   {"Волков Владимир Константинович","Микробиолог",  1997, 15000.25},
		   {"Беспалов Павел Андреевич","Слесарь",  2001, 6000.95},
		   {"Иванов Александр Иванович","Водитель",  1989, 8000.00},
		   {"Коровкина Нина Ивановна","Уборщица",  2005, 7000.00},
		   {"Зайцева Вера Николаевна","Бухгалтер",  2008, 10000.00}
	};
	A->workersWhoseWorkExpMoreThan(A, count_workers, 25);
	A->workersWhoseSalaryMoreThan(A, count_workers, 9000);
	A->workersHoldingAGivenPosition(A, count_workers, "Водитель");
	delete[] A;
}
