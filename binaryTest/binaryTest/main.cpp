#include <iostream>

char* convertBintoInt(const char* binaryNum)
{
	char *binRes = new char[250];

	return binRes;
}

bool checkBin(char* binary)
{
	bool accept = true;
	for (int i = 0; i < strlen(binary); i++)
	{
		if (binary[i] == '0' || binary[i] == '1')
		{
			continue;
		}
		else
		{
			std::cout << "Please enter a binary number please" << std::endl;
			accept = false;
			break;
		}
	}

	return accept;
}

char getInputBin(char *binNum)
{
	bool accept = false;
	while (accept == false)
	{
		std::cout << "Please enter a binary number to convert to decimal: ";
		binNum = new char[250];
		std::cin.getline(binNum, 250);
		std::cout << "\nYou entered: " << binNum << std::endl;
		accept = checkBin(binNum);
		if (accept == false)
		{
			delete[] binNum;
			*binNum = NULL;
		}
	}

	return *binNum;
}
int main()
{
	char *binaryStart;
	char binaryStart = getInputBin(binaryStart);

	
	system("PAUSE");
	return 0;
}