#ifndef MYCLASSES_H
#define MYCLASSES_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//Заголовочный файл, в котором объявляются классы и метод Type
//User класс является базовым. В нем инициализируется переменная message
//И вертуальный метод Type, который будет изменяться у наследников

class User{
protected:
	string message;
public:
//переменная path хранит путь к файлу out.txt, а переменная username хранит имя пользователя в чате
	virtual void Type(string path, string username);
};

class Junior : public User{
public:
	void Type(string path, string username) override;
};

class Middle : public User{
public:
	void Type(string path, string username) override;
};

class Senior : public User{
public:
	void Type(string path, string username) override; 
};

class TeamLead : public User{
public:
	void Type(string path, string username) override;
};

class ProductManager : public User{
public:
	void Type(string path, string username) override;
};
#endif // MYCLASSES_H