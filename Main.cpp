#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute] // Выделение отдельного потока данных на функцию
int main(array<String^>^ args)
{
	setlocale(LC_ALL, "Russia");

	Application::SetCompatibleTextRenderingDefault(false); // Корректная обработка текста
	Application::EnableVisualStyles(); // Подключение различных визуальных стилей

	Credit::MainWindow MainWindow;

	Application::Run(% MainWindow);
}