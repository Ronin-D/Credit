#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute] // ��������� ���������� ������ ������ �� �������
int main(array<String^>^ args)
{
	setlocale(LC_ALL, "Russia");

	Application::SetCompatibleTextRenderingDefault(false); // ���������� ��������� ������
	Application::EnableVisualStyles(); // ����������� ��������� ���������� ������

	Credit::MainWindow MainWindow;

	Application::Run(% MainWindow);
}