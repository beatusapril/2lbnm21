/*21.����������� ����� Cursor. ������ �������� ���������� ������� �� ����������� �
��������� � ����� ������������� �����, ��� ������� � �������������� ���
������������, ������ ������� - ����� �� 1 �� 15. ����������� ������ ��������� ����
�������, ��������� ������� �������, ����� ������� � �������������� �������. ������� �.�.*/
//#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
using namespace std;

enum Cursor_Type		// ��� �������
{
	CursorType_Vert,
	CursorType_Horz,
};

class Cursor
{
private:
		unsigned int m_X; // ���������� ������� �� �����������
		unsigned int m_Y; // ���������� ������� �� ���������
		Cursor_Type m_Type; // ��� �������
		short m_Size;      // ������ ������� 1-15

		friend bool operator==(const Cursor& a, const Cursor& b)
		{
			return (a.m_Size == b.m_Size && a.m_Type == b.m_Type);
		}


public:
		Cursor(void) throw() :
			m_X(0), m_Y(0), m_Type(CursorType_Vert), m_Size(1)
		{
		}

		void SetPos(unsigned int x, unsigned int y) throw() // ��������� ������� �������
		{
			m_X = x;
			m_Y = y;
		}

		void SetType(Cursor_Type t) throw()		// ��������� ���� �������
		{
			m_Type = t;
		}

		void SetSize(short s) throw()	// ��������� ������� �������
		{
			m_Size = s;
		}



		void Init(unsigned int x, unsigned int y, Cursor_Type m_Tp, short msz) // ������������� �������
		{
			SetPos(x, y);
			SetType(m_Tp);
			SetSize(msz);
		}

		void Display()							// ����� ������� �� ������
		{
			cout << "[x] = " << m_X << endl;
			cout << "[y] = " << m_Y << endl;
			cout << "��� ������� - ";
			switch (m_Type)
			{
			case CursorType_Vert:
				cout << "������������" << endl;
				break;
			case CursorType_Horz:
				cout << "��������������" << endl;
				break;
			}
			cout << "������ ������� - " << m_Size << endl;
		}

		void Read()								// ���� ������ � �������
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
				cout << "\n�������� ��� �������: 1 - �������������� 2 - ������������\n";
				cin >> k;
			} while (k != 1 && k != 2);

			do{
				cout << "\n������� ������ �������\n";
				cin >> size;
			} while (size<0 || size >15);
			Init(x, y, static_cast<Cursor_Type>(k), size);
		}

		string StringToInt(unsigned int x)   // ��������������� � ������
		{
			std::ostringstream oss;
			oss << x;
			return oss.str();
		}

		string StringToShort(short sz)		// ��������������� � ������
		{
			std::ostringstream oss;
			oss << sz;
			return oss.str();
		}

		void ChangePos()            // ��������� ������� �������
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

		void ChangeTypeCursor()			// ��������� ���� �������
		{
			int k;
			do{
				cout << "\n�������� ��� �������: 1 - �������������� 2 - ������������\n";
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

		void ChangeSize()					// ��������� ������� �������
		{
			short size;
			do{
				cout << "\n������� ������ �������\n";
				cin >> size;
			} while (size<0 || size >15);
			SetSize(size);
		}

		void DampingCursor()	// ������� �������
		{
			while (m_Size >= 0){
				m_Size--;
			}
		}

		void RecoveryCursor()	//������������� ������
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
		cout << " ����  " << endl;
		cout << "1 - ���� ������" << endl;
		cout << "2 - ����� ������" << endl;
		cout << "3 - ��������� ��������� �������" << endl;
		cout << "4 - ��������� ���� �������" << endl;
		cout << "5 - ��������� ������� �������" << endl;
		cout << "6 - ��������� �������" << endl;
		cout << "7 - �������������� �������" << endl;
		cout << "8 - ����� " << endl << endl;
		cout << "������� ��� ������� " << endl;
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
			cout << "����� " << endl; exit(1);
			break;
		default:
			cout << "����������� ���� " << endl;
			break;
		}
		getchar();

	}
	return 0;
}