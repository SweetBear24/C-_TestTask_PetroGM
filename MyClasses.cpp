#include "MyClasses.h"

void User :: Type(string path, string username){	
	fstream fs;
	fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
		
	if(!fs.is_open()){
		cout << "File opening error!" <<endl; //Проверка существования файла out.txt и возможности его открыть	
	}
	else{
		//Выводим сообщение от пользователя User в общий чат
		message = username + " : Hey!\n";
		fs << message; 
	}
	fs.close();
}

void Junior :: Type(string path, string username){	
	fstream fs;
	fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
	
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	else{
		//Выводим сообщения от пользователя Junior в общий чат
		message = username + " : Hey!\n";
		fs << message; 
		message = username + " : I want a merge. Will somebody review it for me?\n";
		fs << message;
	}
	fs.close();
}  

void Middle :: Type(string path, string username){	
	fstream fs;
		
	fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	else{
		//Выводим сообщения от пользователя Middle в общий чат
		message = username + " : Hey!\n";
		fs << message; 
		message = username + " : I want a merge. Will somebody review it for me?\n";
		fs << message;
		fs.close();
			
	    fs.open(path, fstream::in); //Открываем файл для чтения
		fs.seekg(0, ios::beg); //Переводим курсор на первую строку в файле
		bool foundTL = false;  // Флаг для отслеживания наличия "TeamLead" или "TL"
        while (getline(fs, message)) {
        	//Условие налиячия слов "TeamLead" или "TL"
            if (message.find("Team Lead") != std::string::npos || message.find("TL") != std::string::npos) {
	            foundTL = true; //Поднимаем флаг
            }
        }
        fs.close();
            
		fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
        if (foundTL) {
        	//Если флаг foundTL поднят, то выводим соответствующие сообщения
			message = username + " : AAAAaaa! No! No TL code review, please!\n";
            fs << message;
        }
		fs.close();
	}
} 

void Senior :: Type(string path, string username){	
	fstream fs;
		
	fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	else{
		//Выводим сообщение от пользователя Senior в общий чат
		message = username + " : Hey!\n";
		fs << message; 
		fs.close();
			
	    fs.open(path, fstream::in); //Открываем файл для чтения
		fs.seekg(0, ios::beg);
		bool SeniorReply = false;  // Флаг для отслеживания наличия "I want a merge"
        while (getline(fs, message)) {
        	//Условие налиячия фразы "I want a merge"
            if (message.find("I want a merge") != string::npos) {
                SeniorReply = true; //Поднимаем флаг
            }
        }
        fs.close();
            
		fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
        if (SeniorReply) {
        	//Если флаг SeniorReply поднят, то выводим соответствующие сообщения
            message = username + " : You are such a jnr! Are you afraid of the Team Lead?\n";
            fs << message;
        }
		fs.close();
	}
} 

void TeamLead :: Type(string path, string username){	
	fstream fs;
		
	fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	else{
		//Выводим сообщения от пользователя TeamLead в общий чат
		message = username + " : Hey!\n";
		fs << message; 
		message = username + " : I have a non-fallen prod\n";
		fs << message;
		fs.close();
			
	    fs.open(path, fstream::in); //Открываем файл для чтения
		fs.seekg(0, ios::beg);
		bool TeamLeadReply = false;  // Флаг для отслеживания наличия "I want a merge. Will somebody review it for me?"
		string nickname = ""; //Переменая хранящая имя пользователя, кому адресовано сообщение "Of course, baby. Be ready to suffer"
		while (getline(fs, message)) {
			//Условие налиячия фразы "I want a merge. Will somebody review it for me?"
    		if (message.find("I want a merge. Will somebody review it for me?") != string::npos) {
           		TeamLeadReply = true; //Поднимаем флаг
           		istringstream iss(message); //Выбираем имя пользователя
           		iss >> nickname;					            		
       		}        		
    	}
		fs.close();
			
		fs.open(path,fstream::out | fstream::app); //Открываем файл для записи
		if (TeamLeadReply) {
			//Если флаг TeamLeadReply поднят, то выводим соответствующие сообщения
			message = username + " : Of course, baby. Be ready to suffer " + nickname + "\n";
			fs << message;
		}
		fs.close();
	}		
}
//Данный класс был необязателен по ТЗ, но я решил добавить чтобы команда была в сборе
void ProductManager :: Type(string path, string username){	
	fstream fs;
		
	fs.open(path, fstream::out | fstream::app);  //Открываем файл для записи
	if(!fs.is_open()){
		cout << "File opening error!" <<endl;	
	}
	else{
		//Выводи сообщения от пользователя ProductManager в общий чат
		message = username + " : Hey!\n";
		fs << message; 
		message = username + " : Deadline is coming soon!\n";
		fs << message;
		fs.close();
		
	    fs.open(path, fstream::in); //Открываем файл для чтения
		fs.seekg(0, ios::beg);
		bool ProductManagerReply = false;  // Флаг для отслеживания наличия "I have a non-fallen prod"
        while (getline(fs, message)) {
        	//Условие налиячия фразы "I have a non-fallen prod"
            if (message.find("I have a non-fallen prod") != string::npos) {
                ProductManagerReply = true; //Поднимаем флаг
            }
        }
        fs.close();
            
		fs.open(path, fstream::out | fstream::app); //Открываем файл для записи
		if (ProductManagerReply) {
			//Если флаг ProductManagerReply поднят, то выводим соответствующие сообщения
			message = username + " : When to expect release?";
			fs << message;
		}
		fs.close();
	}
} 