#include "MyClasses.h"
using namespace std;
//Это основной файл, в котором создаются эобъекты классов и вызывается метод Type
int main(){
	string path = "out.txt"; //Выходной файл с чатом
	fstream fs; //Создаем объект класса fstream для работы с файлами
	
	fs.open(path, fstream::out | fstream::trunc); //Производим очистку файла
		if(!fs.is_open()){
			cout << "File opening error!" <<endl;	//Проверка существования файла out.txt и возможности его открыть
		}
	fs.close();
	
	
	fs.open("in.txt", fstream::in); //Открываем файл in.txt для чтения входных данных
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	
	string line; //Переменная, в которую записывается строка читаемого файла
	string nickname, role; //nickname это переменная хранящая имя пользователя, например, User_1
	//role переменная хранящая роль пользователя в чате, например, junior
	while (std::getline(fs, line)) {

       	istringstream iss(line); //Выбираем первые два слова в строке
        iss >> nickname >> role;
		//Выбираем какой пользователь будет писать в чат
        if (role == "User") {
        	User user;
        	user.Type(path, nickname);
        }
        if (role == "Junior") {
        	Junior junior;
        	junior.Type(path, nickname);
        }
        if (role == "Middle") {
        	Middle middle;
        	middle.Type(path, nickname);
        }
        if (role == "Senior") {
        	Senior senior;
        	senior.Type(path, nickname);
        }
        if (role == "TeamLead") {
        	TeamLead teamlead;
        	teamlead.Type(path, nickname);
        }
        if (role == "ProductManager") {
        	ProductManager productmanager;
        	productmanager.Type(path, nickname);
        }
    }
    fs.close();
    //Информация для пользователя, что программа отработала корректно
    cout << "The program worked successfully!" << endl;
    cout << "The conversation took place!" << endl;
    cout << "Check the file out.txt!";
    
}