#include <iostream>
#include <string>

#define SIZE_OF_ANSWERS 3
#define SIZE_OF_QUESTINS 100

using namespace std;

typedef struct topic_t
{
	int q_number;
	string q_text;
	int r_answer;
	string q_answers[SIZE_OF_ANSWERS];
	int answer_number;
}
topic_t;

typedef struct table_t
{
	int size_now;
	int size_max;
	topic_t q_arr[SIZE_OF_QUESTINS];
}
table_t;

void init_table(table_t table)
{
	table.size_now = 0;
	table.size_max = SIZE_OF_QUESTINS;
}

int main()
{
	setlocale(LC_ALL, "ru");

	table_t table;

	init_table(table);
	cout << table.size_max " RER";
	int m;


	return 0;
}