#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>
#include<vector>
#include"myDrawLib.h"
#include<conio.h>
#include<cmath>
#include<fstream>
#include<vector>
#include <sstream>
//#define _WIN32_WINNT  0x0500
using namespace std;
vector<string> id_List;

/***
	tempeployee
	
***/
#define MANAGER_FILE_PATH "D://fileTest//Manager.txt"
#define EMPLOYEE_ACCOUNTS_FILE_PATH "D://fileTest//EmployeeAcounts.txt"
#define EMPLOYEE_INFO_FILE_PATH "D://fileTest//EmployeeInfo.txt"
#define TEMP_EMPLOYEE_INFO_FILE_PATH "D://fileTest//TempEmployeeInfo.txt"
#define DEFAULT_TEXT_COLOR 91
#define FILE_PATH "D://fileTest//QuanLiCuaHang.txt"
// ngay thang nam
typedef struct Date {
//	private:
		int dd;
		int mm;
		int yyyy;
//	public:
		Date();
		Date(int dd, int mm, int yyyy);
		void setDate(const Date &a);
		~Date();
		void setDay(int dd);
		int getDay();
		void setMonth(int mm);
		int getMonth();
		void setYear(int yyyy);
		int getYear();
		bool checkDate();
		void inputDate();
		void inputPerson();
		void outputDate();
		bool checkExpiryDate();
		friend class Goods;
} Date;

//Lop hang hoa
class Goods {
	private:
		string name;		//ten hang hoa
		string code;		//ma hang hoa
		string category;	//danh muc
		string status;		//tinh trang
		float discount;		//chiet khau
		float price;		//gia goc
		float priceAfter;	//gia sau khi tru chiet khau
		int number;			//so luong
		Date date;			//ngay san xuat
		int valid;			//han su dung
		Date expiryDate;	//ngay het han
		
	public:
		//friend classes and functions
		friend class ListGoods;
		//Constructor
		Goods();
		Goods(string name, string code, int number, Date date, int valid, string status);
		//getter and setter
		string getName();
		void setName(string name);
		string getCategory();
		void setCategory(string category);
		string getCode();
		void setCode(string code);
		float getDiscount();
		void setDiscount(float discount);
		float getPrice();
		void setPrice(float price);
		float getPriceAfter();
		void setPriceAfter(float priceAfter);
		int getNumber();
		void setNumber(int number);
		int getvalid();
		void setvalid(int valid);
		string getStatus();
		void setStatus();
		void setStatusWithData(string status);
		Date getDate();
		void setDate(Date _data);
		Date getExpiryDate();
		void setExpiryDate(Date _data);
		//phuong thuc
		Date updateExpiryDate();
		void input();
		void output(int series);
		friend void outputTitle();
		
		friend void changeString(char a[], string b);
		~Goods();
		int Replace(vector<string> &id_List);
};
//Node hang hoa
class Node {
	public:
	Goods data;
	Node *next;
	//Node();
};
// Danh sach hang hoa
class ListGoods {
	private: 
		int size;
		Node *head;
		Node *tail;
	public:
		ListGoods();
		int getSize();
		Node *makeNode();
		Node *makeNode(Goods data);
		bool isEmpty();
		void output();
		void outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign);
		void insertLast();
		void insertLast(Goods data);
		bool checkCode(string code);
		~ListGoods();
		void Find_2();
		Node* Find_1();
		friend void writeDataToFile(ListGoods list);
		friend void readDataFromFile(ListGoods &list);
		void Change(vector<string> id_List);
		void addCode(vector<string> &id_List);
};

class Person {
	protected:
		string username;
		string password;
	public:
		Person();
		~Person();
		string getUserName();
		string getPassWord();
		void setUserName(string username);
		void setPassword(string password);
		void calculation(ListGoods list);
};
//class tempemployee
class TempEmployee {
	protected:
		string name;
		string gender;
		int age;
		Date birth;
		Date startWork;
		string phoneNumber;
		int month;
	public:
		TempEmployee();
		TempEmployee(const TempEmployee& data);
		~TempEmployee();
		string getName();
		string getGender();
		string getPhoneNumber();
		int getAge();
		Date getBirth();
		Date getStartWork();
		int getMonth();
		void setName(string name);
		void setGender(string gender);
		void setAge();
		void setPhoneNumber(string phoneNumber);
		void setBirth(Date birth);
		void setStartWork(Date startWork);
		void setMonth();
		void salary();
		void input();
		void output();
		friend class Manager;
};

//clas employee
class Employee: public Person, public TempEmployee {
	private:
		static int id;
		float wage;
	public:
		Employee();
		~Employee();
		Employee(const Employee& data);
		float getWage();
		void setWage();
		void setWage(float wage);
		void input();
		void output();
		void salary();
		friend class Manager;
};
int Employee::id = 0;
//hamcheck
bool validateNumber(string &toCheck) {
	bool correct = false;
	fflush(stdin);
	getline(cin, toCheck);
	for (int i = 0; i<toCheck.length(); i++) {
		if ((toCheck[i] >= 65 && toCheck[i] <= 90) || (toCheck[i] >= 97 && toCheck[i] <= 122) || toCheck[i] == 32 ) {
			return false;
		}else if (toCheck[i] >=48 && toCheck[i]<= 57) {
			correct = true;
		}else {
			return false;
		}
	}
	return correct;
}

bool validateString(string toCheck) {

	bool correct = false;
		
	for (int i = 0; i<toCheck.length(); i++) {
		
		if ((toCheck[i] >= 65 && toCheck[i] <= 90) || (toCheck[i] >= 97 && toCheck[i] <= 122) || toCheck[i] == 32 || toCheck[i] >=48 && toCheck[i]<= 57) {
		    correct = true;
		}
		else {
		    return false;
		}
	}
	return correct;
}
//in hoa chuoi
string upperCase(string a){
	for(int i=0; i<a.length(); ++i){
		if(a[i]>='a'&&a[i]<='z')
		a[i]-=32;
	}
	return a;
}
void changeString(char a[], string b){
			for(int i=0;i<b.length();++i){
				a[i] = b[i];
			}
		}
//Node nhan vien
struct Node_1{
	TempEmployee data_1;
	Node_1 *next;
};
struct Node_2 {
	Employee data_2;
	Node_2 *next;
};
//class manager
class Manager: public Person {
	private:
		int size_1;
		int size_2;
		//TempEmployee
		Node_1 *head_1;
		Node_1 *tail_1;
		//Employee
		Node_2 *head_2;
		Node_2 *tail_2;
	public:
		Manager();
		~Manager();
		Node_1 *makeNode_1();
		Node_2 *makeNode_2();
		bool isEmpty_1();
		bool isEmpty_2();
		void insertLast_1();
		void insertLast_2();
		void output_1();
		void output_2();
		void userList();
		Node_1 *makeNode_1(const TempEmployee& data);
		Node_2 *makeNode_2(const Employee& data);
		void insertLast_1(const TempEmployee& data);
		void insertLast_2(const Employee& data);
		Employee getEmployeeByUserName(string username);
		friend void writeManagerDataToFile(Manager list);
		friend void readManagerDataFromFile(Manager &list);
		void FindEmployee();
		void FindTempEmployee();
		Node_1* FindTelephone_1();
		Node_2* FindTelephone_2();
		void ChangeTempEmployee();
		void ChangeEmployee();
		void ReplaceTempEmployee();
		void ReplaceEmployee();
		void RemoveTempEmployee();
		void RemoveEmployee();
};

//class menu
class Menu {
	protected:
		int x, y;
		string title;
	public:
		Menu(int x, int y, string title);
		~Menu();
};

class ListMenu: public Menu{
	private:
		vector<string> menuContent;
		int numberOfMenuItem;
		int padding;
		int targetLength;
	public:
		ListMenu(int x, int y, vector<string> _menuContent, string title);
		~ListMenu(){};
		void printMenu(const string& title, const string& textAlign, int padding);
		void setPadding(int padding);
		void setTargetLength(int length);
		int GetItemAmount();
		void clearMenuScreen();
		void start(ListGoods &list, string role, Manager &managerList, string info);
};

class LoginMenu: public Menu{
	private:
		string username;
		string role;
	public:
		LoginMenu(int x, int y, string title);
		~LoginMenu();
		string getRole();
		void setRole(string role);
		string getUsername();
		void printLoginMenu();
		bool startLoginMenu();
};

int main() {
	ListGoods list;
	Manager managerList;
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);  // mo man hinh console dang fullscreen
	LoginMenu loginMenu(90, 2, "DANG NHAP");
	  	
	if(loginMenu.startLoginMenu()){
		system("cls");
		readDataFromFile(list);
		readManagerDataFromFile(managerList);
		list.addCode(id_List);
		
		if(loginMenu.getRole() == "manager"){
			vector<string> menuContent{
								"Nhap hang hoa",
								"Xuat hang hoa",
								"Tim kiem",
								"Cap nhat hang hoa",
								"Xuat thong tin vao file",
								"Cap nhap nhan vien",
								"Thoat"
								};
			ListMenu ListMenu(90, 2, menuContent, "MENU QUAN LY");
			ListMenu.start(list, loginMenu.getRole(), managerList, loginMenu.getUsername());
		}else if(loginMenu.getRole() == "employee"){
			
			vector<string> menuContent{
							"Nhap hang hoa",
							"Xuat hang hoa",
							"Tim kiem",
							"Cap nhat hang hoa",
							"Xuat thong tin vao file",
							"Chuc nang nhan vien",
							"Thoat"
							};
							
			ListMenu ListMenu(90, 2, menuContent, "MENU NHAN VIEN");
			ListMenu.start(list, loginMenu.getRole(), managerList, loginMenu.getUsername());
		}
	}

	return 0;
}

//menu
Menu::Menu(int x, int y, string title){
	this->x = x;
	this->y = y;
	this->title = title;
}

Menu::~Menu(){
}

LoginMenu::LoginMenu(int x, int y, string title): Menu(x, y, title){
	this->role = "employee";
}

LoginMenu::~LoginMenu(){
}

string LoginMenu::getRole(){
	return this->role;
}

void LoginMenu::setRole(string role){
	this->role = role;
}

string LoginMenu::getUsername(){
	return this->username;
}

void LoginMenu::printLoginMenu() {
	short xPos = this->Menu::x;
	short yPos = this->Menu::y;
	string title = this->Menu::title;
	
	drawBox(xPos, yPos, 34, 2, 9, 15, title, "center");
	drawBox(xPos, yPos + 3, 34, 9, 260, 15, "", "left");
}

bool LoginMenu::startLoginMenu(){
	short xPos = this->Menu::x;
	short yPos = this->Menu::y;
	string enteredUsername, enteredPassword;
	string Mpassword, Musername, Epassword, Eusername;
	short labelCol = 190;
	short textCol = 15;
	bool isCorrect = false;
	bool isManager = false;
	
	do{
		this->printLoginMenu();

		gotoXY(xPos+2, yPos+ 4);
		SetColor(labelCol);
		cout << "Nhap ten dang nhap:";
		SetColor(260);
		cout << "-------------" << endl;
		gotoXY(xPos+1, yPos+ 6);
		cout << "---------------------------------" << endl;
		
		gotoXY(xPos+2, yPos+ 8);
		SetColor(labelCol);
		fflush(stdin);
		cout << "Nhap mat khau:";
		SetColor(260);
		cout << "------------------" << endl;
		gotoXY(xPos+1, yPos+ 10);
		cout << "---------------------------------" << endl;
		
		gotoXY(xPos+2, yPos+ 5);
		SetColor(textCol);
		fflush(stdin);
		getline(cin, enteredUsername);
		
		gotoXY(xPos+2, yPos+ 9);
		SetColor(textCol);
		getline(cin, enteredPassword);
		
		ifstream accInput(MANAGER_FILE_PATH);
		while(accInput >> Musername){
			accInput.ignore();
			accInput >> Mpassword;
			if(enteredUsername.compare(Musername) == 0 && enteredPassword.compare(Mpassword) == 0){
				isCorrect = true;
				gotoXY(xPos - 4, yPos+ 13);
				SetColor(290);
				cout << "Dang nhap thanh cong voi tu cach la manager!!" << endl;
				this->role = "manager";
				sleepFunc(1);
				accInput.close();
				break;
			}
		}
		
		ifstream emAccInput(EMPLOYEE_ACCOUNTS_FILE_PATH);
		while(emAccInput >> Eusername){
			emAccInput.ignore();
			emAccInput >> Epassword;
			
			if(enteredUsername.compare(Eusername) == 0 && enteredPassword.compare(Epassword) == 0){
				isCorrect = true;
				gotoXY(xPos - 4, yPos+ 13);
				SetColor(290);
				cout << "Dang nhap thanh cong voi tu cach la nhan vien!!" << endl;
				this->role = "employee";
				this->username = Eusername;
				sleepFunc(1);
				emAccInput.close();
				break;
			}
		}
		
		if(!isCorrect){
			gotoXY(xPos - 8, yPos+ 13);
			SetColor(260);
			cout << "Sai ten dang nhap hoac mat khau!! (Nhan Enter de tiep tuc)" << endl;
			_getch();
			accInput.close();
			emAccInput.close();
			system("cls");
		}
	}while(!isCorrect);
	
	ShowCur(0);
	return isCorrect;
}

ListMenu::ListMenu(int x, int y, vector<string> _menuContent, string title): Menu(x, y, title){
	this->menuContent = _menuContent;
	this->numberOfMenuItem = _menuContent.size();
}

int ListMenu::GetItemAmount(){
	return this->numberOfMenuItem;
}

void ListMenu::setPadding(int padding) {
	this->padding = padding;
}

void ListMenu::setTargetLength(int length) {
	this->targetLength = length;
}

void ListMenu::printMenu(const string& title, const string& textAlign, int padding) {
	int yPos = this->y;
	int xPos = this->x;
	vector<string> _menuContent = this->menuContent;
	this->setPadding(padding);
	int size = this->GetItemAmount();
	short titleLength = title.length() + 10;
	short contentMaxLength;
	
	//find the longest ListMenu content string
	contentMaxLength = _menuContent[0].length();
	
	for(short i = 0; i < size; i++){
		if(_menuContent[i].length() > contentMaxLength){
			contentMaxLength = _menuContent[i].length();
		}
	}
	short contentXPos = (xPos + round(titleLength / 2)) - round(contentMaxLength / 2) - (padding * 1.0 / 2);
	this->setTargetLength(contentMaxLength);
	//draw the title of ListMenu
	drawBox(xPos, yPos, titleLength, 2, 9, 15, title, "center");
	
	//draw the ListMenu item
	for(short i = 0; i < size; i++){
		drawBox(contentXPos, 
				yPos+=3, 
				contentMaxLength + padding,
				2, 
				260, 
				15, 
				_menuContent[i], 
				textAlign);
	}
}

void ListMenu::clearMenuScreen() {
		cout << "\n\nNhan phim bat ki de tiep tuc..." << endl;
		_getch();
		system("cls");
		ShowCur(0);
}

void ListMenu::start(ListGoods &list, string role, Manager &managerList, string info) {
	ShowCur(0);
	int soLuong;
	string title = this->title;
	int contentYPos = this->y + 3;
	int lastPosY = this->y + 3;
	int currentIndex = 0;
	bool isUp = false;

	startPoint: ;
	
	this->printMenu(title, "center", 5);
	bool isPressed = true;
	while(true){
		if(isPressed){
			if(currentIndex > 0 && !isUp){
				// Set the target element position x
				currentTarget((this->x + round((title.length() + 10) / 2))
								 - round(this->targetLength / 2) 
								 - round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
							  lastPosY, 
						  	  this->targetLength + this->padding, 
						  	  2, 
						  	  0, 
						  	  15, 
						  	  this->menuContent[currentIndex - 1], 
						  	  "center");
			}else if(isUp){
				currentTarget((this->x + round((title.length() + 10) / 2))
							    - round(this->targetLength / 2) 
								- round(this->padding * 1.0 / 2), // set the target X postion to fit with the content box
							  lastPosY, 
						  	  this->targetLength + this->padding, 
						  	  2, 
						  	  0, 
						  	  15, 
						  	  this->menuContent[currentIndex + 1], 
						  	  "center");
			}
	
			lastPosY = contentYPos;
			currentTarget((this->x + round((title.length() + 10) / 2))
							 - round(this->targetLength / 2) 
							 - round(this->padding * 1.0 / 2) // set the target X postion to fit with the content box
							 , 
						  contentYPos, 
						  this->targetLength + this->padding, 
						  2, 
						  200, 
						  15, 
						  this->menuContent[currentIndex], 
						  "center");
			isPressed = false;
			textColor(0);
			ShowCur(0);
		}
		
		if(_kbhit()){
			char c = _getch();
			if(c == -32){ // check if arrow key is pressed
				c = _getch();
				if(c == 72){
					if(contentYPos != this->y + 3){
						lastPosY = contentYPos;
						isUp = true;
						currentIndex--;
						contentYPos-=3;	
					}
					isPressed = true;
				}else if(c == 80){
					if(contentYPos != this->y + 3 + (3 * (this->GetItemAmount() - 1))){
						lastPosY = contentYPos;
						isUp = false;
						currentIndex++;
						contentYPos+=3;		
					}
					isPressed = true;
				}
			}
			if(c == 13){
				ShowCur(1);
				int pointerX = 0;
				int pointerY = this->y + 3 + 3 * this->GetItemAmount() + 2;
				gotoXY(pointerX, pointerY);
				textColor(0);
				SetColor(DEFAULT_TEXT_COLOR);

				switch(currentIndex){
					case 0:
						do {
							string checkNumber;
							stringstream ss;
							bool tempCheck;
							do {
								cout<<"Nhap so luong mat hang: ";
								tempCheck = validateNumber(checkNumber);
								if(tempCheck == false) {
									cout<<"Nhap sai dinh dang"<<endl;
								}
							}while(tempCheck == false);
							ss.clear();
							ss<<checkNumber;
							ss>>soLuong;
							if(soLuong < 0) {
								cout<<"Nhap sai so luong. Vui long nhap lai!"<<endl;
							}else if(soLuong == 0) {
								cout<<"Da thoat khoi chuc nang!"<<endl;
							}
							}while(soLuong < 0);
							for(int i = 0; i<soLuong; i++) {
								Goods a;
								do{
									a.input();
									id_List.push_back(a.getCode());
									if(!list.checkCode(a.getCode()))
									cout<<"\nMA ID "<<a.getCode()<<" DA TON TAI! VUI LONG NHAP LAI."<<endl;
								}while(!list.checkCode(a.getCode()));
								list.insertLast(a);
							}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 1:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							list.outputAsTable(0, pointerY, 21, 10, list.getSize(), 196, 1, "left");
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 2:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							list.Find_2();
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 3:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
                        	list.Change(id_List);
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 4:
						if(list.isEmpty()){
							cout << "\nDanh sach trong..." << endl;
						}else{
							writeDataToFile(list);
							loadingAnimation(68, pointerY+2, "Dang xuat du lieu ra file...", "->Xuat thanh cong");
						}
						this->clearMenuScreen();
						goto startPoint;
					case 5:
						if(role.compare("manager") == 0){
							short choice;
							cout << "1) Them nhan vien" << endl;
							cout << "2) Xuat nhan vien" << endl;
							cout << "3) Cap nhat thong tin nhan vien" << endl;
							cout << "4) Tim kiem" << endl;
							cout << "0) Thoat" << endl;
							cout << "Nhap lua chon: ";
							cin >> choice;
							switch(choice){
								case 1:
									short amount, type;
									cout << "\nNhap so luong nhan vien muon them: ";
									cin >> amount;
									startChossing: ;
									cout << "Chon loai nhan vien: " << endl;
									cout << "1) Nhan vien chinh thuc" << endl;
									cout << "2) Thu viec" << endl;
									cout << "Nhap lua chon: ";
									cin >> type;
									if(type == 1){
										for(short i = 0;i < amount;i++){
											managerList.insertLast_2();
										}
									}else if(type == 2){
										for(short i = 0;i < amount;i++){
											managerList.insertLast_1();
										}
									}else{
										cout << "Khong co lua chon nay!" << endl;
										goto startChossing;
									}
									writeManagerDataToFile(managerList);
									cout << "Da them thanh cong" << endl;
									break;
								case 2:
									short outType;
									startOutChossing: ;
									cout << "Chon loai nhan vien: " << endl;
									cout << "1) Nhan vien chinh thuc" << endl;
									cout << "2) Thu viec" << endl;
									cout << "Nhap lua chon: ";
									cin >> outType;
									if(outType == 1){
										managerList.output_2();
									}else if(outType == 2){
										managerList.output_1();
									}else{
										cout << "Khong co lua chon nay!" << endl;
										goto startOutChossing;
									}
									break;
								case 3:
									short n;
									do{
										cout<<"Chon 1 de thay doi thong tin nhan vien thu viec\n";
										cout<<"Chon 2 de thay doi thong tin nhan vien\n ";
										cout<<"Chon 0 de thoat\n";
										cout<<"Nhap lua chon:";
										cin>>n;
										if(n<0||n>2)
											cout<<"Khong co lua chon nay\n";
									}while(n<0||n>2);
									switch(n){
										case 0:
											break;
										case 1:
											managerList.ChangeTempEmployee();
											break;
										case 2:
											managerList.ChangeEmployee();
											break;
									}
									writeManagerDataToFile(managerList);
									break;
								case 4:
									short x;
									do{
										cout<<"Nhap 1 de tim nhan vien thu viec\n";
										cout<<"Nhap 2 de tim kiem nhan vien\n";
										cout<<"Nhap 0 de thoat\n";
										cout<<"Nhap lua chon:";
										cin>>x;
										if(x<0||x>2)
											cout<<"Khong co lua chon nay\n";
									}while(x<0||x>2);
									switch(x){
										case 0:
											break;
										case 1:
											managerList.FindTempEmployee();
											break;
										case 2:
											managerList.FindEmployee();
											break;
									}
									break;
								case 0:
									break;
								default:
									cout << "Lua chon khong hop le" << endl;
							}
						}else{
							Employee a = managerList.getEmployeeByUserName(info);
							short choice;
							cout << "1) Thong tin nhan vien" << endl;
							cout << "2) Xuat hoa don" << endl;
							cout << "0) Thoat" << endl;
							cout << "Nhap lua chon: ";
							cin >> choice;
							switch(choice){
								case 1:
									a.output();
									break;
								case 2:
									a.calculation(list);
									break;
								case 0:
									break;
								default:
									cout << "Lua chon khong hop le!" << endl;
							}
						}
						this->clearMenuScreen();
						goto startPoint;
						break;
					case 6:
						cout << "Ban da chon thoat chuong trinh!!" << endl;
						exit(0);
						break;
					default:
						cout << "Khong co chuc nang nay, vui long them chuc nang vao case!!!" << endl;
						break;
				}
			}
		}
	};
}

//getter setter
Person::Person() {
}
Person::~Person() {
}
string Person::getUserName() {
	return this->username;
}
string Person::getPassWord() {
	return this->password;
}
void Person::setUserName(string username) {
	this->username = username;
}
void Person::setPassword(string password) {
	this->password = password;
}
void Person::calculation(ListGoods list) { 
	Node *a = new Node;
	int totalPrice = 0;
	vector<Goods> invoice;
	vector<int> quantity;
	vector<float> endPrice;
	int select;
	
	do {
		cout<<"1.Them san pham"<<endl;
		cout<<"2.Xuat hoa don"<<endl;
		cout<<"3.Chinh hoa don"<<endl;
		cout<<"4.Thoat"<<endl;
		cout<<"Nhap lua chon: ";
		cin>>select;
		switch(select) {
			case 1: {
				a = list.Find_1();
				bool check = true;
				if(a != NULL) {
					for(int i = 0; i < invoice.size(); ++i){
					if(a->data.getCode() == invoice[i].getCode()){
						cout<<"San pham nay da co trong danh sach thanh toan."<<endl;
						check = false;
						break;
					}
				}
				if(check){
					if(a->data.getStatus() == "HET HAN"){
					cout<<"San pham hien tai da het han! Khong the thuc hien thanh toan."<<endl;
				}else{
					cout<<"Nhap so luong san pham: ";
					int number;
					cin>>number;
					if(number < 1 || number > a->data.getNumber()) {
						cout<<"Them san pham that bai!"<<endl;
					}else {
						a->data.setNumber(a->data.getNumber() - number);
						invoice.push_back(a->data);
						quantity.push_back(number);
						endPrice.push_back(number * a->data.getPriceAfter());
						cout<<"San pham da duoc them vao gio hang"<<endl;
					}
				}
			}
	
				}else {
					cout<<"Vui long nhap chinh xac ma san pham!"<<endl;
				}
				break;
			}
				
			case 2:{
				float endOfPrice = 0;
				cout <<endl<<setw(30)<<"Ten san pham"
					 <<setw(4)<<right<<"SL"
					 <<setw(9)<<right<<"Gia ban"
					 <<setw(6)<<right<<"CK"
					 <<setw(11)<<right<<"Thanh tien"<<endl;
				for(int i = 0; i < 60; ++i)
					cout<<"_";
				cout<<endl;	
				for(int i = 0; i < invoice.size(); i++) {
					cout 	<<setw(30)<<left<<invoice[i].getName()
					 		<<setw(4)<<right<<quantity[i]
							<<setw(9)<<right<<invoice[i].getPrice()
							<<setw(5)<<right<<invoice[i].getDiscount()<<"%"
							<<setw(11)<<right<<endPrice[i]<<endl;
				}
				for(int i = 0; i < 60; ++i)
					cout<<"_";
				cout<<endl;				
				for(int i = 0; i < endPrice.size(); i++) {
					endOfPrice += endPrice[i];
				}
				cout<<setw(48)<<left<<"\nTong hoa don: "<<setw(13)<<right<<endOfPrice<<endl<<endl;
				break;
			}
			case 3:
				int num;
				bool check = false;
				a = list.Find_1();
				for(int i = 0; i < invoice.size(); ++i){
					if(a->data.getCode() == invoice[i].getCode()){
						cout<<"So luong moi: ";
						cin>>num;
						if(a->data.getNumber() + quantity[i] - num < 0){
							cout<<"So luong can thay doi qua lon! Khong the sua"<<endl;
						}
						else{
							endPrice[i] = num * a->data.getPriceAfter();
							a->data.setNumber(a->data.getNumber() + quantity[i] - num);
							quantity[i] = num;
							cout<<"Da cap nhat hoa don."<<endl;
						}
						check = true;
						break;
					}
				}
				if(!check)
				cout<<"San pham nay hien khong co trong danh sach thanh toan."<<endl;
				
		}
	}while(select != 4);
}
//tempemployee
TempEmployee::TempEmployee() {
}
TempEmployee::~TempEmployee() {
}

TempEmployee::TempEmployee(const TempEmployee& data){
	this->name = data.name;
	this->age = data.age;
	this->gender = data.gender;
	this->birth.dd = data.birth.dd;
	this->birth.mm = data.birth.mm;
	this->birth.yyyy = data.birth.yyyy;
	this->startWork.dd = data.startWork.dd;
	this->startWork.mm = data.startWork.mm;
	this->startWork.yyyy = data.startWork.yyyy;
	this->phoneNumber = data.phoneNumber;
	this->setMonth();
}

Employee::Employee(const Employee& data){
	this->name = data.name;
	this->age = data.age;
	this->gender = data.gender;
	this->birth.dd = data.birth.dd;
	this->birth.mm = data.birth.mm;
	this->birth.yyyy = data.birth.yyyy;
	this->startWork.dd = data.startWork.dd;
	this->startWork.mm = data.startWork.mm;
	this->startWork.yyyy = data.startWork.yyyy;
	this->phoneNumber = data.phoneNumber;
	this->password = data.password;
	this->username = data.username;
	this->wage = data.wage;
	this->setMonth();
}

Node_1 *Manager::makeNode_1(const TempEmployee& data){
	Node_1 *newNode = new Node_1;
	newNode->data_1 = data;
	newNode->next = NULL;
	return newNode;
}

void Manager::insertLast_1(const TempEmployee& data){
	Node_1 *newNode = makeNode_1(data);
	if (isEmpty_1() == true) {
		head_1 = tail_1 = newNode;
		this->size_1++;
	}else {
		tail_1->next = newNode;
		tail_1 = newNode;
		this->size_1++;
	}
}

void Manager::insertLast_2(const Employee& data){
	Node_2 *newNode = makeNode_2(data);
	if (isEmpty_2() == true) {
		head_2 = tail_2 = newNode;
		this->size_2++;
	}else {
		tail_2->next = newNode;
		tail_2 = newNode;
		this->size_2++;
	}
}

Node_2 *Manager::makeNode_2(const Employee& data){
	Node_2 *newNode = new Node_2;
	newNode->data_2 = data;
	newNode->next = NULL;
	return newNode;
}

string TempEmployee::getName() {
	return this->name;
}
string TempEmployee::getGender() {
	return this->gender;
}
string TempEmployee::getPhoneNumber(){
	return this->phoneNumber;
}
int TempEmployee::getAge(){
	return this->age;
}
Date TempEmployee::getBirth() {
	return this->birth;
}
void TempEmployee::setName(string name) {
	this->name = name;
}
void TempEmployee::setGender(string gender) {
	this->gender = gender;
}
void TempEmployee::setBirth(Date birth) {
	this->birth = birth;
}
void TempEmployee::setAge(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int yearNow = tm.tm_year + 1900;
	this->age = yearNow - this->birth.getYear();
}
void TempEmployee::setPhoneNumber(string phoneNumber){
	this->phoneNumber = phoneNumber;
}
void TempEmployee::setMonth() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	int month = 0;
	month = (yearNow - startWork.getYear()) * 12;
	month += monNow - startWork.getMonth();
	if(dayNow < startWork.getDay())
		month -= 1;
	this->month = month;	
}
void TempEmployee::salary() {
	if(month == 0) {
		cout<<"Nhan vien nay chua co luong"<<endl;
	}else {
		cout<<"Luong "<<month<<" thang: "<<3000000*month;
	}
}
void TempEmployee::input() {
	bool checkPhone;
	string choiceGender;
	do{
		cout<<"Ten nhan vien: ";
		fflush(stdin);
		getline(cin, name);
		name = upperCase(name);
		if(!validateString(name))
			cout<<"Ten sai dinh dang! Vui long nhap lai."<<endl;
	}while(!validateString(name));
	
	cout<<"Gioi tinh: "<<endl;
	cout<<"1.Nam"<<endl<<"2.Nu"<<endl;

	do{
		cout<<"Chon gioi tinh: ";
		fflush(stdin);
		getline(cin, choiceGender);
		if(choiceGender=="1")
			gender = "NAM";
		else if(choiceGender=="2")
			gender = "NU";
		else cout<<"sai"<<endl;
	}while(choiceGender!="1"&&choiceGender!="2");
	
	
	do {
		cout<<"So dien thoai: ";
		checkPhone = validateNumber(phoneNumber);
		if(!checkPhone)cout<<"So dien thoai khong hop le! Vui long nhap lai."<<endl;
		else{
			if(phoneNumber.length()!=10){
				cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
				checkPhone = false;
			}
			else if(phoneNumber[0] != '0'){
				cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
				checkPhone = false;
			}
		} 
	}while(!checkPhone);
	
	do{
		cout<<"Nhap ngay sinh: "<<endl;
		birth.inputPerson();
		setAge();
		if(age<18)
			cout<<"Nhan vien chua du tuoi lam viec! Vui long nhap lai."<<endl;
	}while(age<18);
	
	do{
		cout<<"Nhap ngay bat dau lam viec: "<<endl;
		startWork.inputPerson();
		if(startWork.getYear() - birth.getYear() < 18)
			cout<<"Nhan vien chua du tuoi lam viec! Vui long nhap lai."<<endl;
	}while(startWork.getYear() - birth.getYear() < 18);
	setMonth();
}
void TempEmployee::output() {
	cout<<"\nTen nhan vien: "<<name<<endl;
	cout<<"Gioi tinh: "<<gender<<endl;
	cout<<"So dien thoai: "<<phoneNumber<<endl;
	cout<<"Ngay sinh: ";
	birth.outputDate();
	cout<<"\nNgay bat dau lam viec: ";
	startWork.outputDate();
	cout<<"\nSo thang lam viec: "<<month<<endl;
	cout <<"So tuoi: "<< this->age << endl;
}
//class employee
Employee::Employee() {
}
Employee::~Employee() {
}
float Employee::getWage(){
	return this->wage;
}
void Employee::setWage(){
	int _month = this->month;
	float _wage = 1;
	while(_month > 5){
		_month -=6;
		_wage +=0.1;
	}
	this->wage = _wage;
}
void Employee::setWage(float wage){
	this->wage = wage;
}
void Employee::salary() {
	cout<<"Luong co ban: 9000000VND"<<endl;
	if(month == 0) {
		cout<<"Hien tai chua co luong!"<<endl;
	}else {
		float temp = 9000000*wage;
		cout<<"Luong thang: "<<(int)temp<<" VND"<<endl;
	}
}
void Employee::input() {
	//chinh thanh viet lien khong cho phep cach ra
	cout<<"Nhap ten tai khoan: ";
	fflush(stdin);
	getline(cin, username);
	// nhap binh thuong
	cout<<"Nhap mat khau: ";
	fflush(stdin);
	getline(cin, password);
	TempEmployee::input();
	setWage();
	output();
}
void Employee::output() {
	TempEmployee::output();
	cout<<"he so luong: "<<wage<<endl;
	salary();
}
// class manager

void TempEmployee::setStartWork(Date startWork){
	this->startWork.dd = startWork.dd;
	this->startWork.mm = startWork.mm;
	this->startWork.yyyy = startWork.yyyy;
}

Date TempEmployee::getStartWork(){
	return this->startWork;
}

Manager::Manager() {
	this->head_1 = NULL;
	this->tail_1 = NULL;
	this->size_1 = 0;
	this->head_2 = NULL;
	this->tail_2 = NULL;
	this->size_2 = 0;
}
Manager::~Manager() {
}
// nhap xuat tempemployee
bool Manager::isEmpty_1() {
	if(head_1 == NULL) {
		return true;
	}else {
		return false;
	}
}
Node_1 *Manager::makeNode_1() {
	Node_1 *temp = new Node_1();
	temp->data_1.input();
	temp->next = NULL;
	return temp;
}
void Manager::insertLast_1() {
	Node_1 *temp = makeNode_1();
	if (isEmpty_1() == true) {
		head_1 = tail_1 = temp;
		this->size_1++;
	}else {
		tail_1->next = temp;
		tail_1 = temp;
		this->size_1++;
	}

}
//nhap xuat employee
bool Manager::isEmpty_2() {
	if(head_2 == NULL) {
		return true;
	}else {
		return false;
	}
}
Node_2 *Manager::makeNode_2() {
	Node_2 *temp = new Node_2();
	temp->data_2.input();
	temp->next = NULL;
	return temp;
}
void Manager::insertLast_2() {
	Node_2 *temp = makeNode_2();
	if (isEmpty_2() == true) {
		head_2 = tail_2 = temp;
		this->size_2++;
	}else {
		tail_2->next = temp;
		tail_2 = temp;
		this->size_2++;
	}

}
void Manager::output_2() {
	for(Node_2 *i = head_2; i != NULL; i = i->next) {
		i->data_2.output();
	}
}

void Manager::output_1() {
	for(Node_1 *i = head_1; i != NULL; i = i->next) {
		i->data_1.output();
	}
}
//chuc nang manager 

Employee Manager::getEmployeeByUserName(string username){
	for(Node_2* i = this->head_2;i!=NULL;i=i->next){
		if(i->data_2.getUserName() == username){
			return i->data_2;
		}
	}
}
void readManagerDataFromFile(Manager &list){
	string name, gender, phoneNumber, username, password;
	string ename, egender, ephoneNumber;
	int age;
	float wage;
	Date birthDay;
	Date workStart;
	Date ebirthDay;
	Date eworkStart;
//	ifstream tempEmployeeIn();
	ifstream employeeIn(EMPLOYEE_INFO_FILE_PATH);
	if(!employeeIn.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeIn.close();
	}
	Employee temp;
	while(employeeIn >> wage){
		employeeIn >> username;
		employeeIn >> password;
		employeeIn.ignore();
		getline(employeeIn, name);
		employeeIn >> birthDay.dd;
		employeeIn >> birthDay.mm;
		employeeIn >> birthDay.yyyy;
		employeeIn >> workStart.dd;
		employeeIn >> workStart.mm;
		employeeIn >> workStart.yyyy;
		employeeIn >> phoneNumber;
		employeeIn.ignore();
		employeeIn >> gender;
			
		temp.setName(name);
		temp.setBirth(birthDay);
		temp.setStartWork(workStart);
		temp.setPhoneNumber(phoneNumber);
		temp.setWage(wage);
		temp.setPassword(password);
		temp.setUserName(username);
		temp.setGender(gender);
		temp.setAge();
		temp.setMonth();
		
		list.insertLast_2(temp);
	}
	employeeIn.close();
		
	ifstream tempEmplyoyeeIn(TEMP_EMPLOYEE_INFO_FILE_PATH);
	if(!tempEmplyoyeeIn.is_open()){
		cout << "File khong ton tai!" << endl;
		tempEmplyoyeeIn.close();
	}
	TempEmployee eTemp;
	while(tempEmplyoyeeIn >> ebirthDay.dd){
		tempEmplyoyeeIn >> ebirthDay.mm;
		tempEmplyoyeeIn >> ebirthDay.yyyy;
		tempEmplyoyeeIn >> eworkStart.dd;
		tempEmplyoyeeIn >> eworkStart.mm;
		tempEmplyoyeeIn >> eworkStart.yyyy;
		tempEmplyoyeeIn.ignore();
		getline(tempEmplyoyeeIn, ename);
		tempEmplyoyeeIn >> egender;
		tempEmplyoyeeIn.ignore();
		tempEmplyoyeeIn >> ephoneNumber;
		
		eTemp.setBirth(ebirthDay);
		eTemp.setStartWork(eworkStart);
		eTemp.setName(ename);
		eTemp.setGender(egender);
		eTemp.setPhoneNumber(ephoneNumber);
		eTemp.setMonth();
		eTemp.setAge();
		list.insertLast_1(eTemp);
	}
	
	tempEmplyoyeeIn.close();
}

void writeManagerDataToFile(Manager list){
	ofstream employeeOut(EMPLOYEE_INFO_FILE_PATH);
	if(!employeeOut.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeOut.close();
	}
	
	for(Node_2 *i = list.head_2; i!=NULL; i=i->next){
		employeeOut << i->data_2.getWage() << endl;
		employeeOut << i->data_2.getUserName() << endl;
		employeeOut << i->data_2.getPassWord() << endl;
		employeeOut << i->data_2.getName() << endl;
		employeeOut << i->data_2.getBirth().dd << endl;
		employeeOut << i->data_2.getBirth().mm << endl;
		employeeOut << i->data_2.getBirth().yyyy << endl;
		employeeOut << i->data_2.getStartWork().dd << endl;
		employeeOut << i->data_2.getStartWork().mm << endl;
		employeeOut << i->data_2.getStartWork().yyyy << endl;
		employeeOut << i->data_2.getPhoneNumber() << endl;
		employeeOut << i->data_2.getGender() << endl;
	}
	employeeOut.close();
	
	ofstream employeeAccountsOut(EMPLOYEE_ACCOUNTS_FILE_PATH);
	if(!employeeAccountsOut.is_open()){
		cout << "File khong ton tai!" << endl;
		employeeAccountsOut.close();
	}
	
	for(Node_2 *i = list.head_2; i!=NULL; i=i->next){
		employeeAccountsOut << i->data_2.getUserName() << endl;
		employeeAccountsOut << i->data_2.getPassWord() << endl;
	}
	
	employeeAccountsOut.close();
	
	ofstream tempEmployeeOut(TEMP_EMPLOYEE_INFO_FILE_PATH);
	if(!tempEmployeeOut.is_open()){
		cout << "File khong ton tai!" << endl;
		tempEmployeeOut.close();
	}
	
	for(Node_1 *i = list.head_1; i!=NULL; i=i->next){
		tempEmployeeOut << i->data_1.getBirth().dd << endl;
		tempEmployeeOut << i->data_1.getBirth().mm << endl;
		tempEmployeeOut << i->data_1.getBirth().yyyy << endl;
		tempEmployeeOut << i->data_1.getStartWork().dd << endl;
		tempEmployeeOut << i->data_1.getStartWork().mm << endl;
		tempEmployeeOut << i->data_1.getStartWork().yyyy << endl;
		tempEmployeeOut << i->data_1.getName() << endl; 
		tempEmployeeOut << i->data_1.getGender() << endl; 
		tempEmployeeOut << i->data_1.getPhoneNumber() << endl; 
	}
	
	tempEmployeeOut.close();
}

void Manager::userList() {
	if(isEmpty_2()) {
		cout<<"Danh sach dang trong "<<endl;
	}else {
		cout<<"Danh sach tai khoan dang nhap: "<<endl;
		for(Node_2 *i = head_2; i != NULL; i =i->next) {
			cout<<"Ten tai khoan: "<<i->data_2.getUserName()<<endl;
			cout<<"Mat khau: "<<i->data_2.getPassWord()<<endl;
		}
	}
}

int ListGoods::getSize(){
	return size;
}

void ListGoods::outputAsTable(int x, int y, int w, int columns, int rows, int color, int titleColor, string contentAlign) {
	if(columns == 0 || rows == 0 || w == 0) return;
	int xStep = x;
	int _x = x;
	int _y = y;
	SetScreenBufferSize(500, 500);
	SetWindowSize(300, 300);
	vector<string> title{"ID", "Name", "Category", "Amount", "Price", "Discount", "Total", "NSX", "HSD", "Status"};
	vector<Goods> content;

	for(Node *i = this->head;i != NULL; i=i->next){
		content.push_back(i->data);
	}// copy the linked list into vector list
	
	for(short k = 0; k < title.size(); k++){
		drawBox(_x + (k*w), y, w, 2, titleColor, 11, title[k] ,"center");
		if(k > 0){
			SetColor(titleColor);
			gotoXY(x + (w * k), y + 2);
			cout << char(193);
			gotoXY(x + (w * k), y);
			cout << char(194);
		}
	}
	_y+=3;
	
	for(short i = 0; i < rows; i++){
			drawBox(xStep, _y, w, 2, color, 250, content[i].code, contentAlign);
			xStep+=w;	
			drawBox(xStep, _y, w, 2, color, 250, content[i].name, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].category, contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)content[i].number), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)content[i].price) + " vnd", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)round(content[i].discount)) + " %", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string((int)round(content[i].priceAfter)) + " vnd", contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].date.getDay()) + "/" + to_string(content[i].date.getMonth()) + "/" + to_string(content[i].date.getYear()), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, to_string(content[i].expiryDate.getDay()) + "/" + to_string(content[i].expiryDate.getMonth()) + "/" + to_string(content[i].expiryDate.getYear()), contentAlign);
			xStep+=w;
			drawBox(xStep, _y, w, 2, color, 250, content[i].status, contentAlign);
		for(short j = 0; j < title.size(); j++){
			if(i >= 1){
				SetColor(color);
				gotoXY(x, _y);
				cout << char(195);
				gotoXY(_x, _y);
				cout << char(197);
				gotoXY(x + w * (title.size()), _y);
				cout << char(180);
				if(j >= 1){
					gotoXY(_x,(y + 3) + 2 * rows);
					cout << char(193);
				}
			}else if(i < 1 && j >= 1){
				SetColor(color);
				gotoXY(_x, y + 3);
				cout << char(194);
			}
			_x+=w;
		}	
		_y+=2;
		_x = x;
		xStep = x;
	}
	gotoXY(0, (y+3) + 2 * rows + 2);
	SetColor(DEFAULT_TEXT_COLOR);
	ShowCur(0);
}

//Constructor va huy cua Date
Date::Date() {
	this->dd = 1;
	this->mm = 1;
	this->yyyy = 2001;
}
Date::Date(int dd, int mm, int yyyy) {
	this->dd = dd;
	this->mm = mm;
	this->yyyy = yyyy;
}
void Date::setDate(const Date &a){
	this->dd = a.dd;
	this->mm = a.mm;
	this->yyyy = a.yyyy;
}
Date::~Date() {
}
// Getter va setter cho Date
Date Goods::getDate(){
	return this->date;
}
void Goods::setDate(Date _data){
	this->date.setDate(_data);
}
Date Goods::getExpiryDate(){
	return this->expiryDate;
}
void Goods::setExpiryDate(Date _data){
	this->expiryDate.setDate(_data);
}

void Date::setDay(int dd) {
	this->dd = dd;
}
int Date::getDay() {
	return dd;
}
void Date::setMonth(int mm) {
	this->mm = mm;
}
int Date::getMonth() {
	return mm;
}
void Date::setYear(int yyyy) {
	this->yyyy = yyyy;
}
int Date::getYear() {
	return yyyy;
}
// Kiem tra ngay
bool Date::checkDate() {
	int maxDay;
	    if (yyyy<=0 || mm<=0 || mm> 12 || dd<=0 || dd> 31)
    {
        return false;
    }
    else
    {
        switch (mm)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((yyyy%4==0 && yyyy%100!=0) || (yyyy%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (dd<=maxDay)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// Nhap ngay
void Date::inputDate() {
	bool temp;
	bool tempCheck;
	string ddTemp,mmTemp,yyyyTemp;
	stringstream ss;
	do {
		cout<<"Ngay ";
		do {
			tempCheck = validateNumber(ddTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<ddTemp;
		ss>>dd;
		do {
			cout<<"Thang ";
			tempCheck = validateNumber(mmTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<mmTemp;
		ss>>mm;
		cout<<"Nam ";
		do {
			tempCheck = validateNumber(yyyyTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang!"<<endl;
			}
		}while(tempCheck == false );
		ss.clear();
		ss<<yyyyTemp;
		int yyyyTemp2;
		ss>>yyyyTemp2;
		if(yyyyTemp2 > 2000) {
			yyyy = yyyyTemp2;
			temp = checkDate();
			if(temp != true) {
				cout<<"Ngay san xuat phai dung dinh dang"<<endl;
			}
			else if(checkExpiryDate()){
			cout<<"Ngay  san xuat khong duoc lon hon ngay hien tai!"<<endl;
			}
		}else {
			cout<<"Nam san xuat phai lon hon 2000"<<endl;
		}
	}while(yyyy <= 2000 ||  temp == false || checkExpiryDate());
}
//Nhap ngay sinh cua nhan vien
void Date::inputPerson() {
	bool temp;
	bool tempCheck;
	string ddTemp,mmTemp,yyyyTemp;
	stringstream ss;
	do {
		cout<<"Ngay ";
		do {
			tempCheck = validateNumber(ddTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<ddTemp;
		ss>>dd;
		do {
			cout<<"Thang ";
			tempCheck = validateNumber(mmTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<mmTemp;
		ss>>mm;
		cout<<"Nam ";
		do {
			tempCheck = validateNumber(yyyyTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang!"<<endl;
			}
		}while(tempCheck == false );
		ss.clear();
		ss<<yyyyTemp;
		int yyyyTemp2;
		ss>>yyyyTemp2;
			yyyy = yyyyTemp2;
			temp = checkDate();
			if(temp != true) {
				cout<<"Ngay sinh phai dung dinh dang"<<endl;
			}
			else if(checkExpiryDate()){
				cout<<"Ngay sinh khong duoc lon hon ngay hien tai!"<<endl;
			}
	}while(temp == false || checkExpiryDate());
}
//Xuat ngay
void Date::outputDate() {
	bool temp = checkDate();
	if(temp == false) {
		cout<<"Sai dinh dang, se thiet lap thanh ngay mac dinh!"<<endl;
		this->dd = 1;
		this->mm = 1;
		this->yyyy = 2001;
	}
	if(dd >= 10) {
		cout<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	} else {
		cout<<"0"<<dd<<"/";
		if(mm >= 10) {
			cout<<mm<<"/"<<yyyy;
		} else {
			cout<<"0"<<mm<<"/"<<yyyy;
		}
	}
}
//mh7
//so sanh ngay vua nhap voi ngay hien tai
bool Date::checkExpiryDate(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int dayNow = tm.tm_mday;
	int monNow = tm.tm_mon + 1;
	int yearNow = tm.tm_year + 1900;
	if (yyyy < yearNow)
	{
		return false;
	}
	else if (yyyy == yearNow)
	{
		if (mm < monNow)
		{
			return false;
		}
		else if (mm == monNow)
		{
			if (dd < dayNow)
			{
				return false;
			}
		}
	}
	return true;
}

//getter and setter
string Goods::getName() {
	return name;
}
void Goods::setName(string name) {
	this->name = name;
}
string Goods::getCode() {
	return code;
}
void Goods::setCode(string code) {
	this->code = code;
}
int Goods::getNumber() {
	return number;
}
void Goods::setNumber(int number) {
	this->number = number;
}
string Goods::getCategory(){
	return category;
}
void Goods::setCategory(string category){
	this->category = category;
}
float Goods::getDiscount(){
	return discount;
}
void Goods::setDiscount(float discount){
	this->discount = discount;
}
float Goods::getPrice(){
	return price;
}
void Goods::setPrice(float price){
	this->price = price;
}
float Goods::getPriceAfter(){
	return priceAfter;
}
void Goods::setPriceAfter(float priceAfter){
	this->priceAfter = priceAfter;
}
int Goods::getvalid() {
	return valid;
}
void Goods::setvalid(int valid) {
	this->valid = valid;
}
string Goods::getStatus(){
	return status;
}
void Goods::setStatus(){
	if(expiryDate.checkExpiryDate()){
		this->status = "CON HAN";
	}
	else this->status = "HET HAN";
}
void Goods::setStatusWithData(string status){
	this->status = status;
}
//khoi tao
Goods::Goods() {
	this->name = "";
	this->code = "";
	this->number = 0;
	this->valid = 3;
}
Goods::Goods(string name, string code, int number, Date date, int valid, string status) {
	this->name = name;
	this->code = code;
	this->number = number;
	this->date = date;
	this->valid = valid;
	this->status = status;
}
//cap nhat ngay het han
Date Goods::updateExpiryDate(){
	Date update(date.getDay(), date.getMonth(),date.getYear());
	int copyValid = valid;
	int maxDay;
	update.setYear(update.getYear() + (copyValid / 12));
	update.setMonth(update.getMonth() + (copyValid % 12));
	while(update.checkDate() == false){
		if(update.getMonth() > 12){
		update.setYear(update.getYear() + 1);
		update.setMonth(update.getMonth()-12);
	}
	switch (update.getMonth())
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              maxDay=31;
              break;
            case 2:
                if ((update.getYear()%4==0 && update.getYear()%100!=0) || (update.getYear()%400==0))
                    maxDay=29;
                else 
                    maxDay=28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDay=30;
                break;
        }
        if (update.getDay()>maxDay)
        {
            update.setMonth(update.getMonth()  + 1);
            update.setDay(update.getDay() - maxDay);
        }
	}
	return update;
}

//Nhap thong tin hang hoa
void Goods::input(){
	bool tempCheck;
	string nameTemp, codeTemp, categoryTemp;
	stringstream ss;
	string priceTemp, discountTemp, numberTemp, validTemp;
	int numberTemp2,validTemp2;
	float priceTemp2, discountTemp2;
	cout<<"Nhap thong tin san pham"<<endl;
	cout<<"Nhap ID: ";
	do {
		fflush(stdin);
		getline(cin, codeTemp);
		
		if(validateString(codeTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(codeTemp) == false);
	codeTemp = upperCase(codeTemp);
	setCode(codeTemp);
	cout<<"Nhap ten: ";
	do {
		fflush(stdin);
		getline(cin, nameTemp);
		
		if(validateString(nameTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(nameTemp) == false);
	nameTemp = upperCase(nameTemp);
	setName(nameTemp);
	do {
		cout<<"Nhap danh muc: ";
		fflush(stdin);
		getline(cin, categoryTemp);
		
		if(validateString(categoryTemp) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(categoryTemp) == false);
	categoryTemp = upperCase(categoryTemp);
	setCategory(categoryTemp);
	do {
		cout<<"Nhap so luong: ";
		tempCheck = validateNumber(numberTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<numberTemp;
	ss>>numberTemp2;
	setNumber(numberTemp2);
	do {
		cout<<"Nhap gia: ";
		tempCheck = validateNumber(priceTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<priceTemp;
	ss>>priceTemp2;
	setPrice(priceTemp2);
	
	do {
		cout<<"Nhap chiet khau: ";
		tempCheck = validateNumber(discountTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<discountTemp;
	ss>>discountTemp2;
	setDiscount(discountTemp2);
	setPriceAfter(getPrice()*(100-getDiscount())/100);
	date.inputDate();
	do {
		cout<<"Nhap han su dung(tu 1 thang tro len): ";
		tempCheck = validateNumber(validTemp);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<validTemp;
	ss>>validTemp2;
	valid = validTemp2;
	expiryDate.setDate(updateExpiryDate());
	setStatus();
}
//xuat thong tin hang hoa
void Goods::output(int series){
	cout << "|" << 	setw(3) << left << series 		<< "|";
	cout << 		setw(4) << left << getCode() 		<< "|";
	cout <<			setw(15) << left << getName() 		<< "|";
	cout << 		setw(15) << left << getCategory() 	<< "|";
	cout << 		setw(6) << right << getNumber() 	<< "|";
	cout << 		setw(7) << right << getPrice() 		<< "|";
	cout << 		setw(8) << right << getDiscount() 	<< "|";
	cout << 		setw(7) << right << getPriceAfter() 		<< "|";
	date.outputDate();
	cout<<"|";
	expiryDate.outputDate();
	cout<<"|";
	cout << 		setw(7) << left << getStatus() 	<< "|"<<endl;;
}
void outputTitle(){
	cout << "|" << 	setw(3) << left << "STT" 		<< "|";
	cout << 		setw(4) << left << "ID" 		<< "|";
	cout <<			setw(15) << left << "Name" 		<< "|";
	cout << 		setw(15) << left << "Category" 	<< "|";
	cout << 		setw(6) << left << "Amount" 	<< "|";
	cout << 		setw(7) << left << "Price" 		<< "|";
	cout << 		setw(8) << left << "Discount" 	<< "|";
	cout << 		setw(7) << left << "Total" 		<< "|";
	cout << 		setw(10) << left << "NSX" 		<< "|";
	cout << 		setw(10) << left << "HSD" 		<< "|";
	cout << 		setw(7) << left << "Status" 	<< "|"<<endl;;
}

//ham huy
Goods::~Goods() {
}

//Constructor khoi tao gia tri 
ListGoods::ListGoods() {
	head = NULL;
	tail = NULL;
	this->size = 0;
}
//Ham huy
ListGoods::~ListGoods() {
}
//Tao ra Node moi
Node *ListGoods::makeNode() {
	Node *temp = new Node();
	temp->data.input();
	temp->next = NULL;
	return temp;
}
// Tao ra Node moi nhung co san gia tri
Node *ListGoods::makeNode(Goods data) {
	Node *temp = new Node();
	temp->data.setName(data.getName());
	temp->data.setCode(data.getCode());
	temp->data.setCategory(data.getCategory());
	temp->data.setNumber(data.getNumber());
	temp->data.setPrice(data.getPrice());
	temp->data.setDiscount(data.getDiscount());
	temp->data.setPriceAfter(data.getPriceAfter());
	Date tempDate(data.date.getDay(),data.date.getMonth(),data.date.getYear());
	temp->data.date = tempDate;
	temp->data.setvalid(data.getvalid());
	temp->data.expiryDate.setDate(data.updateExpiryDate());
	temp->data.setStatus();
	temp->next = NULL;
	return temp;
}

//Kiem tra danh sach rong
bool ListGoods::isEmpty() {
	if(head == NULL) {
		return true;
	}else {
		return false;
	}
}
//In ra danh sach hien tai
void ListGoods::output() {
	Node *temp = head;
	outputTitle();
	int series = 1;
	while(temp != NULL) {
		temp->data.output(series);
		series++;
		temp = temp->next;
	}
}
//Nhap them hang vao cuoi danh sach
void ListGoods::insertLast() {
	Node *temp = makeNode();
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//Nhap them hang vao cuoi danh sach nhung co data
void ListGoods::insertLast(Goods data) {
	Node *temp = makeNode(data);
	if (isEmpty() == true) {
		head = tail = temp;
		this->size++;
	}else {
		tail->next = temp;
		tail = temp;
		this->size++;
	}
}
//kiem tra trung id
bool ListGoods::checkCode(string code){
	for(Node *i = head; i != NULL; i = i->next){
		if(i->data.getCode() == code)
		return false;
	} 
	return true;
}	
// Chuc nang tim kiem
void ListGoods::Find_2(){
	int select,dem,check;
	string selectTemp;
	char temp_1[100],temp_2[100];
	string _temp_1, _temp_2;
	stringstream ss;
	bool tempCheck;
	do{
	cout<<"Lua chon thong tin tim kiem\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Danh muc\n";
	cout<<"3.Tinh trang\n";
	cout<<"0.Thoat\n";
		do {
			cout<<"Nhap lua chon: ";
			tempCheck = validateNumber(selectTemp);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<selectTemp;
		ss>>select;
		switch(select){
		case 0: {
			break;
		}
		case 1:
			{
				do {
					cout<<"Nhap ten: ";
					fflush(stdin);
					getline(cin,_temp_1);
					changeString(temp_1,upperCase(_temp_1));
					if(validateString(temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(_temp_1) == false);
				check=0;
				dem=0;
				for(Node* i=head;i!=NULL;i=i->next){
					if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
						check++;
					}
				}
				if(check!=0){
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){	
                    if( strstr( strupr(strcpy(temp_2, i->data.name.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				}
			    }
			    else{
			    	cout<<"Phan tu can tim ko co trong danh sach\n";
				}
				break;
			}       
		case 2:
				{
				do {
					cout<<"Nhap danh muc: ";
					fflush(stdin);
					getline(cin,_temp_1);
					changeString(temp_1,upperCase(_temp_1));
					if(validateString(_temp_1) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(_temp_1) == false);
				check=0;
				dem=0;
				for(Node* i=head;i!=NULL;i=i->next){
					if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
						check++;
					}
				}
				if(check!=0){
				outputTitle();
				for(Node* i=head;i!=NULL;i=i->next){
				    if( strstr( strupr(strcpy(temp_2, i->data.category.c_str())),strupr(temp_1) ) ){
				        dem++;
				        i->data.output(dem);
				    }
				    }
				}
				else{
			    	cout<<"Phan tu can tim ko co trong danh sach\n";
				}
				break;
				}
		case 3:
					{
                    int choice,dem_1=0;
                    char temp_1[100]="CON HAN";
                    char temp_2[100]="HET HAN";
                    //sua lai cai nayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
                    do{
                    cout<<"1.Con han su dung\n";
                    cout<<"2.Het han su dung\n";
                    cout<<"Nhap lua chon:";
                    cin>>choice;
                    }while(choice<1||choice>2);
                    switch(choice){
                    	case 1:
                    		check=0;
                    		dem=0;
                    		for(Node* i=head;i!=NULL;i=i->next){
                    			if(strcmp(temp_1,i->data.status.c_str())==0){
                    				check++;
                    			}
							}
							if(check!=0){
                    		outputTitle();
                    		for(Node* i=head;i!=NULL;i=i->next){
                    			dem++;
                    			if(strcmp(temp_1,i->data.status.c_str())==0){
                    				dem_1++;
                    				i->data.output(dem);
								}
						    }
							}
							else{
							cout<<"Phan tu can tim khong co trong danh sach\n";
						}
							break;
						case 2:
							check=0;
							dem=0;
							for(Node* i=head;i!=NULL;i=i->next){
								if(strcmp(temp_2,i->data.status.c_str())==0){
									check++;
								}
							}
							if(check!=0){
							outputTitle();
							for(Node* i=head;i!=NULL;i=i->next){
                    			dem++;
                    			if(strcmp(temp_2,i->data.status.c_str())==0){
                    				dem_1++;
                    				i->data.output(dem);
								}
							}
						}
						else{
							cout<<"Phan tu can tim khong co trong danh sach\n";
						}
							break;
				default:
					cout<<"Khong co lua chon nay\n";
					break;
					}
                    
				    break;
					}
		default: 
			cout<<"Lua chon khong ton tai!"<<endl;
			
	}
}while(select!=0);
	
}
//Chuc nang sua
Node* ListGoods:: Find_1(){
	string temp_1;
	int dem_1 =0,dem_2=0;
    do {
		cout<<"Nhap ma san pham: ";
		fflush(stdin);
		getline(cin,temp_1);
		temp_1 = upperCase(temp_1);
//		changeString(temp_1,upperCase(temp_1));
		if(validateString(temp_1) == false) {
			cout<<"Vui long nhap dung dinh dang!"<<endl;
		}
	}while(validateString(temp_1) == false);
		for(Node* i=head;i!=NULL;i=i->next){
			dem_1++;
            if(strcmp(temp_1.c_str(),i->data.code.c_str())==0){
			    dem_2++;
			    outputTitle();
			    i->data.output(dem_1);
			    return i;
			}	
		}
	if(dem_2==0){
		cout<<"Ma san pham khong co trong danh sach\n";
	    return NULL;
	}
}
void ListGoods::addCode(vector<string> &id_List){
	for(Node* i=head;i!=NULL;i=i->next){
		id_List.push_back(i->data.getCode());
	}
}
void ListGoods:: Change(vector<string> id_List){
	int option,check,dem;
	Node* i=new Node;
	string checkNumber;
	stringstream ss;
//	do{
	cout<<"\n\nVui long chon phuong thuc ma ban muon thay doi\n";
	cout<<"1.Sua lai thong tin san pham\n";
	cout<<"2.Xoa san pham\n";
	cout<<"0.Thoat\n";
	do{
		bool tempCheck;
		do {
			cout<<"Vui long nhap lua chon: ";
			tempCheck = validateNumber(checkNumber);
			if(tempCheck == false) {
				cout<<"Nhap sai dinh dang"<<endl;
			}
		}while(tempCheck == false);
		ss.clear();
		ss<<checkNumber;
		ss>>option;
		if(option<0||option>2)
		    cout<<"Nhap lai!\n";
	}while(option<0||option>2);
	switch(option){
		case 0:
			break;
		case 1:
			{
				dem=0;
				id_List.clear();
        		i=Find_1();
        		if(i!=NULL){
        		addCode(id_List);
        		check=i->data.Replace(id_List);
        		dem++;
        		if(check==1){
        		    cout<<"Da sua thanh cong\n";
        		break;
        	    }
        	}
		else{
			cout<<"Khong tim thay trong danh sach\n";
			break;
		}
	}
    case 2: {
    	dem=0;
		i=Find_1();
		if(i!=NULL){
		cout<<"Chon 1 de tiep tuc\n";
		cout<<"Chon 0 de thoat\n";
		do{
			bool tempCheck;
			do {
				cout<<"Vui long nhap lua chon:";
				tempCheck = validateNumber(checkNumber);
				if(tempCheck == false) {
					cout<<"Nhap sai dinh dang"<<endl;
				}
			}while(tempCheck == false);
			ss.clear();
			ss<<checkNumber;
			ss>>check;
					
		}while(check<0||check>1);
		if(check==0)
			break;
		else{
		    if(i==head){
	        	head=head->next;
	        	delete i;
	        	dem++;
	        	this->size--;
            	}
            else if(i==tail){
	        	Node* q=head;
		        while(q->next->next!=NULL){
			        q=q->next;
		        }
	        	tail=q;
		        q->next=NULL;
		        delete i;
		        dem++;
		        this->size--;
             	}
	            else{ 
                    Node* p=head;
                    while(p->next==i){
                    	p->next=p->next->next;
                    	i->next=NULL;
                    	delete i;
                    	dem++;
                    	this->size--;
					}	
	            }	
		        cout<<"Danh sach sau khi xoa la:\n";
		     	output ();
		    }
		    break;
	    }  
		else{
		    cout<<"Phan tu can xoa khong co trong danh sach\n";
		    break;
		} 
	    break;
   	}
	default:
		cout<<"Lua chon khong ton tai!"<<endl;  
   }
//}while(option!=0);
}
int Goods::Replace(vector<string> &id_List){
	int option;
	cout<<"\nVui long lua chon phan thong tin can sua\n";
	cout<<"1.Ten san pham\n";
	cout<<"2.Ma san pham\n";
	cout<<"3.Danh muc \n";
	cout<<"4.Gia chiet khau\n";
	cout<<"5.Gia goc \n";
	cout<<"6.So luong san pham\n";
	cout<<"7.Ngay san xuat \n";
	cout<<"8.Han su dung \n";
	string checkOption;
	stringstream ss;
	bool tempCheck;
	do {
		cout<<"Vui long nhap lua chon: ";
		tempCheck = validateNumber(checkOption);
		if(tempCheck == false) {
			cout<<"Nhap sai dinh dang"<<endl;
		}
	}while(tempCheck == false);
	ss.clear();
	ss<<checkOption;
	ss>>option;
		switch(option){
//			case 0:
//				return 0;
			case 1:
				{
				string temp;
				do {
					cout<<"Ten moi:";
					fflush(stdin);
					getline(cin, temp);
					temp = upperCase(temp);
					if(validateString(temp) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp) == false);
				name=temp;
				return 1;
			}
			case 2:
				{
				int dem;
				string temp;
				do{
				dem=0;
					do {
						cout<<"Ma moi:";
						fflush(stdin);
						getline(cin, temp);
						temp = upperCase(temp);
						if(validateString(temp) == false) {
							cout<<"Vui long nhap dung dinh dang!"<<endl;
						}
					}while(validateString(temp) == false);
				int n=temp.size();
				char temp_1[n+1];
				strcpy(temp_1,temp.c_str());
				for(int i=0;i<id_List.size();i++){
					if(strcmp(temp_1,id_List[i].c_str())==0){
					    cout<<"Nhap lai:\n";
						dem++;	
					}
				}
			}while(dem!=0);
                id_List.clear();
				code=temp;
				return 1;
			}
			case 3:
				{
				string temp;
				do {
					cout<<"Danh muc moi: ";
					fflush(stdin);
					getline(cin, temp);
					temp = upperCase(temp);
					if(validateString(temp) == false) {
						cout<<"Vui long nhap dung dinh dang!"<<endl;
					}
				}while(validateString(temp) == false);
				category=temp;
				return 1;
			}
			case 4:
				{
				float num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Chiet khau moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				discount=num;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 5:
				{
				float num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Gia goc moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				price=num;
				priceAfter=price*(100-discount)/100;
				return 1;
			}
			case 6:
				{
				int num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"So luong san pham moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				number=num;
				return 1;
			}
			case 7:
				{
				Date temp;
				cout<<"Vui long nhap lai ngay san xuat:"<<endl;
				temp.inputDate();
				date=temp;
				expiryDate.setDate(updateExpiryDate());
				setStatus();
				return 1;
			}
			case 8:
				{
				int num;
				string checkNumber;
				stringstream ss;
				bool tempCheck;
				do {
					cout<<"Han su dung moi: ";
					tempCheck = validateNumber(checkNumber);
					if(tempCheck == false) {
						cout<<"Nhap sai dinh dang"<<endl;
					}
				}while(tempCheck == false);
				ss.clear();
				ss<<checkNumber;
				ss>>num;
				valid=num;
				expiryDate.setDate(updateExpiryDate());
				setStatus();
				return 1;
			}
			default: 
				cout<<"Lua chon khong ton tai";
				return 0;
		}
}

void  Manager::FindEmployee(){
	char temp_1[100], temp_2[100];
	short dem=0;
	cout<<"Nhap ten cua nhan vien:";
	fflush(stdin);
	gets(temp_1);
	for(Node_2* i=head_2;i!=NULL;i=i->next){
		if(strstr (strupr (strcpy(temp_2,i->data_2.getName().c_str()) ),strupr(temp_1)) ){
		    dem++;
			i->data_2.output();
	    }
	}
	string result =dem==0?"Khong co thong tin trong danh sach":"";	
}
void  Manager::FindTempEmployee(){
	char temp_1[100], temp_2[100];
	short dem =0;
	cout<<"Nhap ten cua nhan vien thu viec:";
	fflush(stdin);
	gets(temp_1);
	for(Node_1* i=head_1;i!=NULL;i=i->next){
		if(strstr (strupr (strcpy(temp_2,i->data_1.getName().c_str())) ,strupr(temp_1)) ){
			i->data_1.output();
			dem++;
		}
	}
	string result =dem==0?"Khong co thong tin trong danh sach":"";
}

Node_1* Manager::FindTelephone_1(){
	string temp;
	short dem=0;
	cout<<"Nhap so dien thoai:";
	fflush(stdin);
	getline(cin,temp);
	for(Node_1* i=head_1;i!=NULL;i=i->next){
		if(strcmp(i->data_1.getPhoneNumber().c_str(),temp.c_str())==0){
			dem++;
			return i;
		}
	}
	if(dem==0){
		cout<<"Khong tim thay trong danh sach\n";
		return NULL;
	}	
}
Node_2* Manager::FindTelephone_2(){
	string temp;
	short dem=0;
	cout<<"Nhap so dien thoai:";
	fflush(stdin);
	getline(cin,temp);
	for(Node_2* i=head_2;i!=NULL;i=i->next){
		if(strcmp(i->data_2.getPhoneNumber().c_str(),temp.c_str())==0){
			dem++;
			return i;
		}
	}
	if(dem==0){
		cout<<"Khong tim thay trong danh sach\n";
		return NULL;
	}
}

void Manager::ChangeTempEmployee(){
	short choice;
	do{
		cout<<"Chon 1 de sua thong tin cua nhan vien thu viec\n";
		cout<<"Chon 2 de xoa thong tin nhan vien thu viec\n";
		cout<<"Nhap 0 de thoat\n";
		cout<<"Nhap lua chon:\n";
		cin>>choice;
	}while(choice<0&&choice>2);
	switch(choice){
		case 0:
			break;
		case 1:
		{
			ReplaceTempEmployee();
			break;		
		}
		case 2:
		{
			RemoveTempEmployee();
			break;
		}
	}
}
void Manager::ChangeEmployee(){
	short choice;
	do{
		cout<<"Chon 1 de sua thong tin cua nhan vien\n";
		cout<<"Chon 2 de xoa thong tin nhan vien\n";
		cout<<"Nhap 0 de thoat\n";
		cout<<"Nhap lua chon:\n";
		cin>>choice;
	}while(choice<0&&choice>2);
	switch(choice){
		case 0:
			break;
		case 1:
		{
			ReplaceEmployee();
			break;		
		}
		case 2:
		{
			RemoveEmployee();
			break;
		}
	}
}

void Manager::ReplaceTempEmployee(){
	short choice;
	Node_1* i=FindTelephone_1();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		do{
		cout<<"Chon 1 de sua thong tin ca nhan cua nhan vien thu viec\n";
		cout<<"Chon 0 de thoat\n";
		cout<<"Nhap lua chon:";
		cin>>choice;
		}while(choice<0&&choice>1);
		switch(choice){
			case 0:
				break;
			case 1:
			{
				short option;
				cout<<"Chon 1 de sua ten\n";
				cout<<"Chon 2 de sua gioi tinh\n";
//				cout<<"Chon 3 de sua tuoi\n";
				cout<<"Chon 3 de sua ngay sinh\n";
				cout<<"Chon 4 de sua so dien thoai\n";
				do{
					cout<<"Nhap lua chon\n";
					cin>>option;
				}while(option<1&&option>5);
				switch(option){
					case 1:
					{
						string temp;
						char temp_1;
						cout<<"Nhap ten:";
						fflush(stdin);
						getline(cin, temp);
						i->data_1.name=temp;
						break;
					}
					case 2:
					{
					    string temp;
						char temp_1;
						cout<<"Nhap gioi tinh:";
						fflush(stdin);
						getline(cin, temp);
						i->data_1.gender=temp;
						break;
					}
//					case 3:
//					{
//					    int temp;
//					    cout<<"Nhap tuoi";
//					    cin>>temp;
//					    i->data_1.age=temp;
//						break;
//					}
					case 3:
					{
						Date temp;
					    cout<<"Nhap lai ngay sinh\n";
					    temp.inputPerson();
					    i->data_1.setBirth(temp);
					    i->data_1.setAge();
						break;
					}
					case 4:
					{
					    string temp;
					    bool isDuplicated;
					    do{
					    	isDuplicated = false;
					    	cout<<"Nhap so dien thoai:";
					    	fflush(stdin);
					    	getline(cin, temp);
//					    	checkNum = validateNumber(temp);
					    	
								if(temp.length()!=10){
									cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
									isDuplicated = true;
								}else if(temp[0] != '0'){
								cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
								isDuplicated = true;
								}else{
								for(Node_1* i=head_1;i!=NULL;i=i->next){
					    			if(i->data_1.getPhoneNumber().compare(temp)==0){
					    				isDuplicated=true;
					    				cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
					    				break;
									}		
								}
								for(Node_2* i=head_2;i!=NULL;i=i->next){
					    			if(i->data_2.getPhoneNumber().compare(temp)==0){
					    				isDuplicated=true;
					    				cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
					    				break;
									}		
								}
							}
					    
						}while(isDuplicated);
					    i->data_1.phoneNumber=temp;
						break;
					}
				}
				break;
			}
		}
	}
}
void Manager::RemoveTempEmployee(){
	short dem=0;
	Node_1* i=FindTelephone_1();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		if(i==head_1){
	        head_1=head_1->next;
	        delete i;
	        dem++;
	        this->size_1--;
        }
        else if(i==tail_1){
	        Node_1* q=head_1;
		    while(q->next->next!=NULL){
			    q=q->next;
		    }
	        tail_1=q;
		    q->next=NULL;
		    delete i;
		    dem++;
		    this->size_1--;
        }
	    else{ 
            Node_1* p=head_1;
            while(p->next==i){
            	p->next=p->next->next;
                i->next=NULL;
                delete i;
                dem++;
                this->size_1--;
			}	
	    }
	}
	string temp = dem!=0?"Da sua thanh cong\n":"";
}
void Manager::ReplaceEmployee(){
	short choice;
	Node_2* i=FindTelephone_2();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		do{
			cout<<"Chon 1 de sua thong tin ca nhan cua nhan vien\n";
			cout<<"Chon 2 de sua thong tin tai khoan cua nhan vien\n";
			cout<<"Chon 0 de thoat\n";
			cout<<"Nhap lua chon:";
			cin>>choice;
		}while(choice<0&&choice>2);
		switch(choice){
			case 0:
				break;
			case 1:
			{
//				do{
//					cout<<"Chon 1 de sua thong tin ca nhan cua nhan vien thu viec\n";
//					cout<<"Chon 0 de thoat\n";
//					cout<<"Nhap lua chon:";
//					cin>>choice;
//				}while(choice<0&&choice>1);
//				switch(choice){
//					case 0:
//						break;
//					case 1:
//					{
						short option;
						cout<<"Chon 1 de sua ten\n";
						cout<<"Chon 2 de sua gioi tinh\n";
//						cout<<"Chon 3 de sua tuoi\n";
						cout<<"Chon 3 de sua ngay sinh\n";
						cout<<"Chon 4 de sua so dien thoai\n";
						cout<<"Chon 5 de sua luong\n";
						do{
							cout<<"Nhap lua chon\n";
							cin>>option;
						}while(option<1&&option>6);
						switch(option){
							case 1:
							{
								string temp;
								char temp_1;
								cout<<"Nhap ten:";
								fflush(stdin);
								getline(cin, temp);
								i->data_2.name=temp;
								break;
							}
							case 2:
							{
					   			string temp;
								char temp_1;
								cout<<"Nhap gioi tinh:";
								fflush(stdin);
								getline(cin, temp);
								i->data_2.gender=temp;
								break;
							}
//							case 3:
//							{
//					    		int temp;
//					    		cout<<"Nhap tuoi";
//					    		cin>>temp;
//					    		i->data_2.age=temp;
//								break;
//							}
							case 3:
							{
					    		Date temp;
					    		cout<<"Nhap lai ngay sinh\n";
					    		temp.inputPerson();
					    		i->data_2.setBirth(temp);
					    		i->data_2.setAge();
								break;
							}
							case 4:
							{
					    		string temp;
					    		bool isDuplicated;
					    		do{
					    			isDuplicated = false;
					    			cout<<"Nhap so dien thoai:";
					    			fflush(stdin);
					    			getline(cin, temp);
									if(temp.length()!=10){
										cout<<"So dien thoai phai du 10 chu so! Vui long nhap lai."<<endl;
										isDuplicated = true;
									}else if(temp[0] != '0'){
										cout<<"So dien thoai can bat dau bang so 0 (+84)! Vui long nhap lai."<<endl;
										isDuplicated = true;
									}else{
										for(Node_1* i=head_1;i!=NULL;i=i->next){
					    				if(i->data_1.getPhoneNumber().compare(temp)==0){
					    					isDuplicated=true;
					    					cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
					    					break;
										}		
									}
									for(Node_2* i=head_2;i!=NULL;i=i->next){
					    				if(i->data_2.getPhoneNumber().compare(temp)==0){
					    					isDuplicated=true;
					    					cout << "So dien thoai da ton tai, vui long nhap lai!" << endl;
					    					break;
										}		
									}
								}
					    
								}while(isDuplicated);
					    			i->data_2.phoneNumber=temp;
									break;
						   	}
							case 5:
							{
								float temp;
								cout<<"Nhap he so luong:";
								cin>>temp;
								i->data_2.setWage(temp);
								//wage
								break;
							}
						}
					}	break;
				

			break;
			case 2:
				string temp;
				cout<<"Nhap mat khau:";
				fflush(stdin);
				getline(cin,temp);
				i->data_2.password=temp;
				break;
		}
	}
}
void Manager::RemoveEmployee(){
	short dem=0;
	Node_2* i=FindTelephone_2();
	if(i==NULL){
		cout<<"Khong tim thay\n";
	}
	else{
		if(i==head_2){
	        head_2=head_2->next;
	        delete i;
	        dem++;
	        this->size_2--;
        }
        else if(i==tail_2){
	        Node_2* q=head_2;
		    while(q->next->next!=NULL){
			    q=q->next;
		    }
	        tail_2=q;
		    q->next=NULL;
		    delete i;
		    dem++;
		    this->size_2--;
        }
	    else{ 
            Node_2* p=head_2;
            while(p->next==i){
            	p->next=p->next->next;
                i->next=NULL;
                delete i;
                dem++;
                this->size_2--;
			}	
	    }
	}
	string temp = dem!=0?"Da sua thanh cong\n":"";
}

//Read and Write data to file
// Write and read file
void readDataFromFile(ListGoods &list){
	ifstream inputFile(FILE_PATH);
	string code, name, category, status;
	float discount, price, priceAfter;
	int number, valid;
	Date date, expiryDate;
	Goods temp;
		
	if(!inputFile.is_open()){
		cerr << "Khong the mo File - '" << FILE_PATH << "'" << endl;
		cout << "Nhan phim bat ki de tiep tuc" << endl;
		_getch();
		goto endPoint;
	}

	while(inputFile >> code){
		temp.setCode(code);
		inputFile.ignore();
		getline(inputFile, name);
		temp.setName(name);	
		getline(inputFile, category);
		temp.setCategory(category);		
		inputFile.ignore();
		getline(inputFile, status);
		temp.setStatusWithData(status);	
		inputFile >> discount;
		temp.setDiscount(discount);	
		inputFile >> price;
		temp.setPrice(price);	
		inputFile >> priceAfter;
		temp.setPriceAfter(priceAfter);		
		inputFile >> number;
		temp.setNumber(number);		
		inputFile >> valid;
		temp.setvalid(valid);		
		inputFile >> date.dd;
		inputFile >> date.mm;
		inputFile >> date.yyyy;
		temp.setDate(date);		
		inputFile >> expiryDate.dd;
		inputFile >> expiryDate.mm;
		inputFile >> expiryDate.yyyy;
		temp.setExpiryDate(expiryDate);
				
		list.insertLast(temp);
	}
	loadingAnimation(68, 2, "Dang doc file...", "Doc file thanh cong!!");
	endPoint:
	inputFile.close();
	system("cls");
}

void writeDataToFile(ListGoods list){
	ofstream outputFile(FILE_PATH);
		
	if(!outputFile.is_open()){
		cerr << "Khong the mo file- '" << FILE_PATH << "'" << endl;
		cout << "Nhan phim bat ki de tiep tuc" << endl;
		_getch();
		goto endPoint;
	}
		
	for(Node *i = list.head; i != NULL;i=i->next){
		outputFile << i->data.getCode() << "\n";
		outputFile << i->data.getName() << "\n";
		outputFile << i->data.getCategory() << "\n";
		outputFile << i->data.getStatus() << "\n";
		outputFile << i->data.getDiscount() << "\n";
		outputFile << i->data.getPrice() << "\n";
		outputFile << i->data.getPriceAfter() << "\n";
		outputFile << i->data.getNumber() << "\n";
		outputFile << i->data.getvalid() << "\n";		
		outputFile << i->data.getDate().getDay()<< "\n";
		outputFile << i->data.getDate().getMonth()<< "\n";
		outputFile << i->data.getDate().getYear()<< "\n";		
		outputFile << i->data.getExpiryDate().getDay()<< "\n";
		outputFile << i->data.getExpiryDate().getMonth()<< "\n";
		outputFile << i->data.getExpiryDate().getYear()<< "\n";
	}
	
	endPoint:
	outputFile.close();
}


