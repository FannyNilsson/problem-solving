#include <iostream>
#include <string>
using namespace std;

int Policy1(string inpArr);
int Policy2(string inpArr);
int Policy3(string inpArr);

int main()
{
	string input;
	while (cin >> input)
	{
		int result1 = Policy1(input);
		int result2 = Policy2(input);
		int result3 = Policy3(input);
		cout << result1 << endl;
		cout << result2 << endl;
		cout << result3 << endl;
	}
	return 0;
}

int Policy1(string inpArr)
{
	int seatAdjCount = 0;
	int inpLen = inpArr.length();

	if (inpArr[0] == 'D')
	{
		//we want to skip the first char since that only tells us how the seat is in the beginning
		//if the toilet seat starts down we want to skip the first person aswell since it will always need ONE adjustment from either D or U
		for (int i = 2; i < inpLen; i++)
		{
			//nothing needs to be done
			if (inpArr[i] == 'U')
			{
				seatAdjCount = seatAdjCount;
			}
			//all 'D's have to adjust the seat twice (once down before the visit and once up before leaving)
			if (inpArr[i] == 'D')
			{
				seatAdjCount = seatAdjCount + 2;
			}

		}

		seatAdjCount = seatAdjCount + 1;
	}
	else
	{
		//we want to skip the first char since that only tells us how the seat is in the beginning
		for (int i = 1; i < inpLen; i++)
		{
			//nothing needs to be done
			if (inpArr[i] == 'U')
			{
				seatAdjCount = seatAdjCount;
			}
			//all 'D's have to adjust the seat twice (once down before the visit and once up before leaving)
			if (inpArr[i] == 'D')
			{
				seatAdjCount = seatAdjCount + 2;
			}
		}
	}

	return seatAdjCount;
}

int Policy2(string inpArr)
{
	int seatAdjCount = 0;
	int inpLen = inpArr.length();

	if (inpArr[0] == 'U')
	{
		//we want to skip the first char since that only tells us how the seat is in the beginning
		//if the toilet seat starts down we want to skip the first person aswell since it will always need ONE adjustment from either D or U
		for (int i = 2; i < inpLen; i++)
		{
			//nothing needs to be done
			if (inpArr[i] == 'D')
			{
				seatAdjCount = seatAdjCount;
			}
			//all 'D's have to adjust the seat twice (once down before the visit and once up before leaving)
			if (inpArr[i] == 'U')
			{
				seatAdjCount = seatAdjCount + 2;
			}

		}

		seatAdjCount = seatAdjCount + 1;
	}
	else
	{
		//we want to skip the first char since that only tells us how the seat is in the beginning
		for (int i = 1; i < inpLen; i++)
		{
			//nothing needs to be done
			if (inpArr[i] == 'D')
			{
				seatAdjCount = seatAdjCount;
			}
			//all 'D's have to adjust the seat twice (once down before the visit and once up before leaving)
			if (inpArr[i] == 'U')
			{
				seatAdjCount = seatAdjCount + 2;
			}
		}
	}

	return seatAdjCount;
}

int Policy3(string inpArr)
{
	int seatAdjCount = 0;
	int inpLen = inpArr.length();

	//we want to skip the first char since that only tells us how the seat is in the beginning
	for (int i = 1; i < inpLen; i++)
	{
		if (inpArr[i] == 'U')
		{
			//if the one before is unlike the current person, one adjustment needs to be done
			if (inpArr[i - 1] == 'D')
			{
				seatAdjCount = seatAdjCount + 1;
			}
			// else nothing needs to be done
			else if(inpArr[i-1] == 'U')
			{
				seatAdjCount = seatAdjCount;
			}
			
		}
		//all 'D's have to adjust the seat twice (once down before the visit and once up before leaving)
		if (inpArr[i] == 'D')
		{
			//if the one before is unlike the current person, one adjustment needs to be done
			if (inpArr[i - 1] == 'U')
			{
				seatAdjCount = seatAdjCount + 1;
			}
			// else nothing needs to be done
			else if (inpArr[i - 1] == 'D')
			{
				seatAdjCount = seatAdjCount;
			}
		}
	}
	return seatAdjCount;
}