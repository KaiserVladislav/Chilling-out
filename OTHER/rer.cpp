#include <iostream>
#include <string>
#include <iomanip>

#define SUCCESS 0
#define INCORRECT_TEST -1

#define N 1001
#define SIZE_OF_ANSWERS 3
#define SIZE_OF_QUESTINS 100

using namespace std;

typedef struct topic_t
{
	int q_number;    // ���� 1-10
	string q_text;   // �������� 24 �����
	int user_answer; // ������� 1-3
	string q_answers[SIZE_OF_ANSWERS];
	int right_answer; // ������� 1-3
}topic_t;

typedef struct table_t
{
	size_t size_now;
	size_t size_max;
	topic_t q_arr[SIZE_OF_QUESTINS];
}table_t;

int input_int();
void clear_c();
void init_table(table_t* table);
void show_table(table_t table);
topic_t input_topic(topic_t topic);
void add_table(topic_t topic, table_t* table);
void delete_table(table_t* table, int number);
int check_test(table_t table);
void make_test(table_t table);

int main()
{

	setlocale(LC_ALL, "ru");

	table_t table;
	topic_t topic;

	int flag = 0;

	init_table(&table);
	/*
	table.q_arr[0].q_number = 1;
	table.q_arr[0].q_text = "sdffffffffffffffsfsdsdfs";
	table.q_arr[0].user_answer = 2;
	table.q_arr[0].q_answers[0] = "sdffffffffffffffsfsdsdfs";
	table.q_arr[0].q_answers[1] = "sdffffffffffffffsfsdsdfs";
	table.q_arr[0].q_answers[2] = "sdffffffffffffffsfsdsdfs";
	table.q_arr[0].right_answer = 1;
	table.size_now = 1;
	*/
    bool repeat = true;
    int command;

    while (repeat)
    {
		cout << "---------------------------------\n\n"
			"1 - ������� ������� �������\n"
			"2 - ��������� ���� ������\n"
			"3 - �������� ������ � �������\n"
			"4 - ������������ ���� (�� 2 ������� �� ����)\n"
			"5 - ������� ������ ������ ����\n"
			"0 - �����\n\n"
			"---------------------------------\n\n";
        command = input_int();
        switch (command)
        {
            case 1:
            {
				show_table(table);
                break;
            }
            case 2:
            {
				topic  = input_topic(topic);
				flag = 1;
                break;
            }
            case 3:
            {
				if (table.size_now != 100)
				{
					if (flag == 1)
					{
						add_table(topic, &table);
						table.size_now += 1;
						flag = 0;
						cout << "\n������ ������� ���������.\n";
					}
					else
					{
						cout << "\n���� ������ ��� �������.\n";
					}
				}
				else
				{
					cout << "\n������� ��������� ������������ ����������� �������.\n";
				}
                break;
            }
			case 4:
			{
				if (check_test(table) == SUCCESS)
				{
					make_test(table);
				}
				else
				{
					cout << "\n������������ �������� ��� ������������ �������.\n";
				}
				break;
			}
			case 5:
			{
				if (table.size_now != 0)
				{
					int number;
					cout << "������� ���� ������� ��� �������� (�� 1 �� 10): ";
					number = input_int();

					while (number < 1 || number > 10)
					{
						cout << "������: ������������ ����.\n";
						cout << "������� ���� ������� ��� �������� (�� 1 �� 10): ";
						number = input_int();
					}
					delete_table(&table, number);
				}
				else
				{
					cout << "\n������� �����.\n";
				}
				break;
			}
            case 0:
            {
                return 0;
                break;
            }
            default:
            {
				cout << "\n�������� �������\n";
                break;
            }
        }
    }

	return SUCCESS;
}

void make_test(table_t table)
{
	cout << "\n------------------------------------------------------------------------------------\n"
		"|                                        TEST                                      |\n"
		"------------------------------------------------------------------------------------\n"
		"| Question |                          |  user  |         answer           | right  |\n"
		"|  number  |         Question         | answer |         options          | answer |\n"
		"|          |                          |        |                          |        |\n"
		"------------------------------------------------------------------------------------\n";

	int count = 0;
	int number = table.q_arr[0].q_number;
	int pos_1;
	int pos_2;
	for (size_t i = 0; i < table.size_now; i++)
	{
		if (number == table.q_arr[i].q_number)
		{
			count += 1;
		}
		if (number != table.q_arr[i].q_number || i + 1 == table.size_now)
		{
			pos_1 = (i - (count - 1)) + rand() % count;
			pos_2 = (i - (count - 1)) + rand() % count;
			while (pos_1 == pos_2)
			{
				pos_2 = (i - (count - 1)) + rand() % count;

			}

			cout << "|          |                          |        | " << setw(24) << table.q_arr[pos_1].q_answers[0] << " |        |\n";
			cout << "|" << setw(5) << table.q_arr[pos_1].q_number << setw(6) << "|";
			cout << " " << setw(24) << table.q_arr[pos_1].q_text << " |";
			cout << setw(9) << "|";
			cout << " " << setw(24) << table.q_arr[pos_1].q_answers[1] << " |";
			cout << setw(10) << "|\n";
			cout << "|          |                          |        | " << setw(24) << table.q_arr[pos_1].q_answers[2] << " |        |\n";
			cout << "------------------------------------------------------------------------------------\n";

			cout << "|          |                          |        | " << setw(24) << table.q_arr[pos_2].q_answers[0] << " |        |\n";
			cout << "|" << setw(5) << table.q_arr[pos_2].q_number << setw(6) << "|";
			cout << " " << setw(24) << table.q_arr[pos_2].q_text << " |";
			cout << setw(9) << "|";
			cout << " " << setw(24) << table.q_arr[pos_2].q_answers[1] << " |";
			cout << setw(10) << "|\n";
			cout << "|          |                          |        | " << setw(24) << table.q_arr[pos_2].q_answers[2] << " |        |\n";
			cout << "------------------------------------------------------------------------------------\n";
		}
	}
}

int check_test(table_t table)
{
	int count = 0;
	int number = table.q_arr[0].q_number;
	for (size_t i = 0; i < table.size_now; i++)
	{
		if (number == table.q_arr[i].q_number)
		{
			count += 1;
		}
		if (number != table.q_arr[i].q_number || i + 1 == table.size_now)
		{
			if (count < 2)
			{
				return INCORRECT_TEST;
			}
			count = 1;
		}
		number = table.q_arr[i].q_number;
	}

	if (table.size_now == 0)
	{
		return INCORRECT_TEST;
	}

	return SUCCESS;
}

void delete_table(table_t* table, int number)
{
	int count = 0;
	size_t j = 0;
	for (size_t i = 0; i < table->size_now; i++)
	{
		if (table->q_arr[i].q_number == number)
		{
			count += 1;
			j = i;
		}
	}

	if (count != 0)
	{
		j -= (count - 1);
		for (size_t i = j; i < table->size_now - count; i++)
		{
			table->q_arr[i] = table->q_arr[i + count];
		}
		table->size_now -= count;
		cout << "\n������� " << count << " �������\n";
	}
	else
	{
		cout << "\n���� ������� ��� ��������\n";
	}
}

void add_table(topic_t topic, table_t* table)
{
	topic_t buff;
	size_t j = table->size_now;
	for (size_t i = 0; i < table->size_now; i++)
	{
		if (table->q_arr[i].q_number >= topic.q_number)
		{
			j = i;
			break;
		}
	}
	for (size_t i = j; i < table->size_now; i++)
	{
		buff = table->q_arr[i];
		table->q_arr[i] = topic;
		topic = buff;
	}
	table->q_arr[table->size_now] = topic;
}

topic_t input_topic(topic_t topic)
{
	cout << "������� ���� ������� (�� 1 �� 10): ";
	topic.q_number = input_int();

	while (topic.q_number < 1 || topic.q_number > 10)
	{
		cout << "������: ������������ ����.\n";
		cout << "������� ���� ������� (�� 1 �� 10): ";
		topic.q_number = input_int();
	}

	cout << "������� ������ (������ �� 24-� ��������): ";
	cin >> topic.q_text;
	while (topic.q_text.size() < 1 || topic.q_text.size() > 24)
	{
		cout << "������: ������������ ������.\n";
		cout << "������� ������ (������ �� 24-� ��������): ";
		cin >> topic.q_text;
	}

	clear_c();
	cout << "������� ����� ������ ������������ (�� 1 �� 3): ";
	topic.user_answer = input_int();

	while (topic.user_answer < 1 || topic.user_answer > 3)
	{
		cout << "������: ������������ ����� ������.\n";
		cout << "������� ����� ������ ������������ (�� 1 �� 3): ";
		topic.user_answer = input_int();
	}

	for (size_t i = 0; i < SIZE_OF_ANSWERS; i++)
	{
		cout << "������� " << i << " ������� ������ (������ �� 24 - � ��������): ";
		cin >> topic.q_answers[i];
		while (topic.q_answers[i].size() < 1 || topic.q_answers[i].size() > 24)
		{
			cout << "������: ������������ ������� ������.\n";
			cout << "������� " << i << " ������� ������ (������ �� 24 - � ��������): ";
			cin >> topic.q_answers[i];
		}
	}
	clear_c();
	cout << "������� ����� ����������� ������ (�� 1 �� 3): ";
	topic.right_answer = input_int();

	while (topic.right_answer < 1 || topic.right_answer > 3)
	{
		cout << "������: ������������ ����� ������.\n";
		cout << "������� ����� ����������� ������ (�� 1 �� 3): ";
		topic.right_answer = input_int();
	}

	return topic;
}

void show_table(table_t table)
{
	if (table.size_now != 0)
	{
		cout << "\n------------------------------------------------------------------------------------\n"
			    "| Question |                          |  user  |         answer           | right  |\n"
			    "|  number  |         Question         | answer |         options          | answer |\n"
				"|          |                          |        |                          |        |\n"
				"------------------------------------------------------------------------------------\n";
		for (size_t i = 0; i < table.size_now; i++)
		{
			cout << "|          |                          |        | " << setw(24) << table.q_arr[i].q_answers[0] << " |        |\n";
			cout << "|" << setw(5) << table.q_arr[i].q_number << setw(6) << "|";
			cout << " " << setw(24) << table.q_arr[i].q_text << " |";
			cout << setw(5) << table.q_arr[i].user_answer << setw(4) << "|";
			cout << " " << setw(24) << table.q_arr[i].q_answers[1] << " |";
			cout << setw(5) << table.q_arr[i].right_answer << setw(5) << "|\n";
			cout << "|          |                          |        | " << setw(24) << table.q_arr[i].q_answers[2] << " |        |\n";
			cout << "------------------------------------------------------------------------------------\n";
		}
	}
	else
	{
		cout << "\n����������� ������\n";
	}
}

void init_table(table_t* table)
{
	table->size_now = 0;
	table->size_max = SIZE_OF_QUESTINS;
}

void clear_c()
{
	char symbol;		
	cin.get(symbol);	
	while (symbol != '\n')	
	{
		cin.get(symbol);	
	}
}

int input_int()			
{
	char symbol;		
	char str[N];		
	size_t i = 0;		
	cin.get(symbol);	
	str[i] = symbol;	

	while (symbol != '\n')	
	{
		i++;
		cin.get(symbol);	
		str[i] = symbol;	
		if (i >= 1000)		
		{
			cin.clear();	
			return -1;
		}
	}

	if (i == 0)				
	{
		return -1;
	}

	for (size_t j = 0; j < i; j++)	
	{
		if (str[j] < '0' || str[j] > '9')
		{
			return -1;
		}
	}

	int count = atoi(str);	

	return count;
}