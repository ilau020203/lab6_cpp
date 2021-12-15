
#include <iostream>
#include <fstream>
#include <filesystem>
#include <clocale>
#include <string>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "Rus");
    using namespace filesystem;
    string path_name, A, B, C;
    cin >> path_name;
	cin >> A >> B >> C;
	try
	{
		for (auto& p : directory_iterator(path_name))
		{
			uint32_t max_size = 512000;
			// если текущий элемент - каталог
			if (p.is_directory())
			{
				// перебор всего содержимого в p
				for (auto& q : recursive_directory_iterator(p))
				{
					// получение размера текущего элемента
					auto qsize = q.file_size();
					size_t foundA = path(q).parent_path().generic_string().find(A);
					size_t foundB = path(q).stem().generic_string().find(B);

					// если q – обычный файл и его размер больше максимума
					if ((q.is_regular_file() && qsize > max_size) && ((foundA != std::string::npos) && (foundB != std::string::npos))) {
						rename(q, q.path().string().replace(q.path().string().size() - q.path().filename().string().size(), path(q).stem().generic_string().size(), C));
					}

				}

			}
		}
	}
	catch (const std::exception& er)
	{
		cout << er.what() << endl;
	}

	


   
}
/*
C:\Users\ilau020203\Downloads\
H
asdfasdf
a
*/