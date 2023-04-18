#include<iostream>
#include<fstream>
#include<string>

bool statistic(std::string str);
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::string path = "file.txt";   //"file.txt\\folder  вот такая штука не окроется.  // путь к файлу, который необходимо открыть.

	// Класс ofstream для записи в файл.
	/*std::ofstream out;//(path);     // можно сделать один раз.  // объект класса ofstream, позволяющий открывать файлы для добавления текста.\
	если открываемого файла нет, то он будет создан.
	out.open(path,std::ios::app);  // в любой момент.   // открытие файла по указанному пути в указанном режиме\
	пока файл открыт, сторонние приложения и объекты не могут с ним работать.
	if (out.is_open()) {        // проверка на открытие файла.
		std::cout << "Файл открыт для записи.\n";
		std::cout << "Введите строку : ";
		std::string str;
		std::getline(std::cin, str);
		out << str << '\n';          // добавление текста в файл.
		std::cout << "Запись добавлена в файл.\n";
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	out.close();         // закрытие файла и очистка объекта out.

	// Возможные причины ошибки открытия файла.
	// 1. Файл открыт другим приложением или объектом.
	// 2. Неправильный синтаксис указания пути к файлу.
	// 3. Нет доступа к файлу.*/

	// Класс ifstream для чтения из файла.
	/*std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "Файл открыт для считывания.\n";
		std::string file;
		// Посимвольное считывание.
		//char sym;
		//while (in.get(sym))  // если удалось считать- возвращает символ, если нет - то нет.
			//std::cout << sym;   
			//file += sym;
			//std::cout << file;
		

		// Пословное считывание.      // если надо записать кучу слов.
		//while (!in.eof()) {        // end of file
		//std::string str;
		//	in >> str;
		//	file += str + '\n';
		//}
		//std::cout << file;

		// Построчное считывание.     
		std::string str;
		while (std::getline(in, str))
			file += str+'\n';
		std::cout << file;
	}
	else
		std::cout << "Ошибка открытия файла.\n";

	in.close();
	// Возможные причины ошибки открытия файла :
	// 1. Файл открыт другим приложением или объектом.
	// 2. Неправильный синтаксис указания пути к файлу.
	// 3. Нет доступа к файлу.
	// 4. Файл не существует.*/

	// Удаление файлов .
	/*if (remove(path.c_str()) == 0)         // превращает в массив типа char.
		std::cout << "Файл \"" << path << "\" удалён.\n";
	else
		std::cout << "Ошибка удаления файла.\n";

	// Возможные причины ошибки удаления файла :
	// 1. Файл открыт другим приложением или объектом.
	// 2. Неправильный синтаксис указания пути к файлу.
	// 3. Нет доступа к файлу.
	// 4. Файл не существует.*/

	// Задача 1.
	std::cout << "Задача 1.\nВведите слово : ";
	std::string word;
	std::getline(std::cin, word);
	if (statistic(word))
		std::cout << "Слово записано в файл.\n";
	else
		std::cout << "Ошибка выполнения функции.\n";


	return 0;
}

bool statistic(std::string str) {
	const std::string path = "words.txt";
	std::ofstream out;	
	out.open(path,std::ios::app);

	if (out.is_open()) {
		out << str << ' ' << str.length() << '\n';
		out.close();
		return true;
	}
	out.close();
	return false;
}
