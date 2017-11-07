/*21.Реализовать класс Cursor. Полями являются координаты курсора по горизонтали и
вертикали – целые положительные числа, вид курсора – горизонтальный или
вертикальный, размер курсора - целое от 1 до 15. Реализовать методы изменения вида
курсора, изменения размера курсора, метод гашения и восстановления курсора. Воищева З.Ю.*/
//#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;

enum Cursor_Type		// тип курсора
{
	CursorType_Vert,
	CursorType_Horz,
};

class Cursor
{
private:
		unsigned int m_X; // координата курсора по горизонтали
		unsigned int m_Y; // координата курсора по вертикали
		Cursor_Type m_Type; // тип курсора
		short m_Size;      // размер курсора 1-15

		friend bool operator==(const Cursor& a, const Cursor& b)
		{
			return (a.m_Size == b.m_Size && a.m_Type == b.m_Type);
		}


public:
		Cursor(void) throw() :
			m_X(0), m_Y(0), m_Type(CursorType_Vert), m_Size(1)
		{
		}

		void SetPos(unsigned int x, unsigned int y) throw() // изменение позиции курсора
		{
			m_X = x;
			m_Y = y;
		}

		void SetType(Cursor_Type t) throw()		// изменение типа курсора
		{
			m_Type = t;
		}

		void SetSize(short s) throw()	// изменение размера курсора
		{
			m_Size = s;
		}



		void Init(unsigned int x, unsigned int y, Cursor_Type m_Tp, short msz) // инициализация курсора
		{
			SetPos(x, y);
			SetType(m_Tp);
			SetSize(msz);
		}

		void Display()							// вывод курсора на экране
		{
			cout << "[x] = " << m_X << endl;
			cout << "[y] = " << m_Y << endl;
			cout << "Вид курсора - ";
			switch (m_Type)
			{
			case CursorType_Vert:
				cout << "вертикальный" << endl;
				break;
			case CursorType_Horz:
				cout << "горизонтадьный" << endl;
				break;
			}
			cout << "Размер курсора - " << m_Size << endl;
		}

		void Read()								// ввод данных о курсоре
		{
			unsigned int x, y;
			short size;
			short k;

			do{
				cout << "[x]=";
				cin >> x;
			} while (x < 0);

			do{
				cout << endl << "[y]=";
				cin >> y;
			} while (y < 0);

			do{
				cout << "\nВыберите вид курсора: 1 - горизонтальный 2 - вертикальный\n";
				cin >> k;
			} while (k != 1 && k != 2);

			do{
				cout << "\nВведите размер курсора\n";
				cin >> size;
			} while (size<0 || size >15);
			Init(x, y, static_cast<Cursor_Type>(k), size);
		}

		string StringToInt(unsigned int x)   // конвертирование в строку
		{
			std::ostringstream oss;
			oss << x;
			return oss.str();
		}

		string StringToShort(short sz)		// конвертирование в строку
		{
			std::ostringstream oss;
			oss << sz;
			return oss.str();
		}

		void ChangePos()            // изменение позиции курсора
		{
			int x, y;
			do{
				cout << "[x]=";
				cin >> x;
			} while (x < 0);

			do{
				cout << endl << "[y]=";
				cin >> y;
			} while (y < 0);
			SetPos(x, y);
		}

		void ChangeTypeCursor()			// изменение типа курсора
		{
			int k;
			do{
				cout << "\nВыберите вид курсора: 1 - горизонтальный 2 - вертикальный\n";
				cin >> k;
			} while (k != 1 && k != 2);

			switch (k)
			{
			case 1:
				SetType(CursorType_Horz);
				break;
			case 2:
				SetType(CursorType_Vert);
				break;
			}
		}

		void ChangeSize()					// изменение размера курсора
		{
			short size;
			do{
				cout << "\nВведите размер курсора\n";
				cin >> size;
			} while (size<0 || size >15);
			SetSize(size);
		}

		void DampingCursor()	// гашение курсора
		{
			while (m_Size >= 0){
				m_Size--;
			}
		}

		void RecoveryCursor()	//восстновление курсоа
		{
			while (m_Size < 0){
				m_Size++;
			}
		}



};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Cursor cr;
	int number;

	for (;;)
	{
		cout << " Меню  " << endl;
		cout << "1 - Ввод данных" << endl;
		cout << "2 - Вывод данных" << endl;
		cout << "3 - Изменение положения курсора" << endl;
		cout << "4 - Изменение типа курсора" << endl;
		cout << "5 - Изменение размера курсора" << endl;
		cout << "6 - Погашение курсора" << endl;
		cout << "7 - Восстановление курсора" << endl;
		cout << "8 - Выход " << endl << endl;
		cout << "Введите ваш вариант " << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			cr.Read(); break;
		case 2:
			cr.Display(); break;
		case 3:
			cr.ChangePos(); break;
		case 4:
			cr.ChangeTypeCursor(); break;
		case 5:
			cr.ChangeSize(); break;
		case 6:
			cr.DampingCursor(); break;
		case 7:
			cr.RecoveryCursor(); break;
		case 8:
			cout << "Выход " << endl; exit(1);
			break;
		default:
			cout << "Некорретный ввод " << endl;
			break;
		}
		getchar();

	}
	return 0;
}