#include<LinkedList.h> 
#include <iostream>
#include <time.h>
using namespace List;
using namespace std;

int number_of_list(LinkedList<int> num1)
{
	int number1 = 0;
	int rank = 0;
	for (int i = num1.size() - 1; i >= 0; --i)
	{
		number1 += num1[i] * pow(10, rank);
		rank++;
	}
	return number1;
}
LinkedList<int> list_of_number(int num1)
{
	LinkedList<int> result;
	int rank = 2;
	int res = -1;
	while (res)
	{
		res = num1 % 10;
		result.push_head(res);
		num1 = num1/ 10;
		res = num1;
	}
	return result;
}
LinkedList<int> sum(LinkedList<int> num1, LinkedList<int> num2)
{	
	int number1 = number_of_list(num1);
	int number2 = number_of_list(num2);
	
	int sum = number1 + number2;
	LinkedList<int> result = list_of_number(sum);
	return result;
}


LinkedList<int> mult(LinkedList<int> num1, LinkedList<int> num2)
{
	int number1 = number_of_list(num1);
	int number2 = number_of_list(num2);

	int sum = number1 * number2;
	LinkedList<int> result = list_of_number(sum);
	return result;
}
int main()
{
	srand(time(NULL));
	LinkedList<int> num1(1);
	LinkedList<int> num2(1);
	cout <<"Number 1: " << num1 << endl;
	cout <<"Number 2: " << num2 << endl;
	cout << num1 << " + " << num2 << " = " << sum(num1, num2) << endl;
	cout << num1 << " * " << num2 << " = " << mult(num1, num2) << endl;
	return 0;
}