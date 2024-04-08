#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct tovar
{
	string stuff;
	string articul;
	int amount;
	int price_4_one;
};

struct order
{
	string number;
	string date;
	string last_name;
	string phone_num;
	vector <string> articuls;
};

 tovar t_1 = { "pear", "001", 300, 30 };
 tovar t_2 = { "apple", "002", 300, 20 };
 tovar t_3 = { "peach", "003", 300, 40 };

 vector <tovar> goods = {t_1, t_2, t_3};

 order o_1 = { "01", "01.01.2001", "Ivanov", "89059081699", {"001", "001", "001"}};
 order o_2 = { "02", "01.02.2005", "Petrov", "89069847175", {"001", "001", "003"}};
 order o_3 = { "03", "05.05.2023", "Sidorov", "89069214878", {"002", "002", "003"}};
 
 vector <order> orders = {o_1, o_2, o_3};

 void ovr_bill(vector <order> orders, vector <tovar> goods) {
	 string number;
	 int bill = 0;
	 cout << "ENTER THE NUMBER OF ORDER: ";
	 cin >> number;
	 for (auto& element : orders) {
		 if (number == element.number) {
			 for (int j = 0; j < element.articuls.size(); j++) {
				 for (auto& k : goods) {
					 if (element.articuls[j] == k.articul) {
						 bill += k.price_4_one;
					 }
				 }
			 }
			 cout << "THE OVERALL BILL IS " << bill << endl;
			 break;
		 }
		 else {
			 cout << "THERE'S NO SUCH A NUMBER!!!\n";
			 break;
		 }
	 }
 }

 void add_tovar(vector <order> orders) {
	 string number;
	 cout << "ENTER THE NUMBER OF ORDER: ";
	 cin >> number;
	 for (auto& element : orders) {
		 if (number == element.number) {
			 string temp;
			 cout << "ENTER THE GOODS: ";
			 cin >> temp;
			 element.articuls.push_back(temp);
			 cout << "COMPLETED! IT'S CURRENT LIST OF GOODS: ";
			 for (int i = 0; i < element.articuls.size(); i++) {
				 cout << element.articuls[i] << " ";
			 }
			 cout << endl;
			 break;
		 }
		 else {
			 cout << "THERE'S NO SUCH A NUMBER!!!!\n";
			 break;
		 }

	 }
 }

 void add_order(vector <order> orders) {
	string number_1;
	string date_1;
	string last_name_1;
	string phone_num_1;
	vector <string> articuls_1;
	cout << "ENTER THE NUMBER OF ORDER: ";
	cin >> number_1;
	cout << "ENTER THE DATE OF ORDER: ";
	cin >> date_1;
	cout << "ENTER THE LAST NAME: ";
	cin >> last_name_1;
	cout << "ENTER THE PHONE NUMBER: ";
	cin >> phone_num_1;
	cout << "ENTER THE LIST OF GOODS(3 ITEMS): ";
	for (int i = 0; i < 3; i++) {
		string temp;
		cin >> temp;
		articuls_1.push_back(temp);
	}
	order o_4 = { number_1, date_1, last_name_1, phone_num_1, articuls_1 };
	orders.push_back(o_4);
	cout << "COMPLETED!\n";
 }

 void delete_order(vector <order> orders) {
	 string number;
	 cout << "ENTER THE NUMBER OF ORDER: ";
	 cin >> number;
	 auto begin = orders.begin();
	 for (int i = 0; i < orders.size(); i++) {
		 if (number == orders[i].number) {
			 orders.erase(begin + i);
		 }
	 }
	 cout << "COMPLETED!\n";
 }

int main() {
	order o;
	tovar t;
	int solution;
	cout << "ENTER THE NUMBER\n" << "1. Define overall bill for order\n" << "2. Enter a new stuff to an order\n" << "3. Enter a new order to orders list\n" << "4. Delete an order with certain number from orders list\n" << "5.Stop the programm\n" << "ANSWER: ";
	cin >> solution;
	while (solution != 5) {
		if (solution == 1) {
			ovr_bill(orders, goods);
		}
		if (solution == 2) {
			add_tovar(orders);
		}
		if (solution == 3) {
			add_order(orders);
		}
		if (solution == 4) {
			delete_order(orders);
		} 
		cout << "ENTER THE NUMBER\n" << "1. Define overall bill for order\n" << "2. Enter a new stuff to an order\n" << "3. Enter a new order to orders list\n" << "4. Delete an order with certain number from orders list\n" << "5.Stop the programm\n" << "ANSWER: ";
		cin >> solution;
	}
	return 0;
}