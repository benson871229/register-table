#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<winreg.h>
int main(int argc, char* argv)
{
	HKEY hKey = NULL;

	if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
	{
		printf("Error. %d\n", GetLastError());
		return -1;
	}
	//list
	int i = 0;
	DWORD dwType = 0;
	DWORD dwBufferSize = MAXBYTE;
	DWORD dwKeySize = MAXBYTE;
	char szValueName[MAXBYTE];
	char szValueKey[MAXBYTE];

	while (true)
	{
		if (RegEnumValueA(hKey, i, szValueName, &dwBufferSize, NULL, &dwType, (LPBYTE)szValueKey, &dwKeySize) == ERROR_NO_MORE_ITEMS)
		{
			break;

		}
		printf("%d:%s %s \n", i, szValueName, szValueKey);
		//same function
		memset(szValueKey, 0, sizeof(szValueKey));
		ZeroMemory(szValueName, MAXBYTE);

		dwBufferSize = MAXBYTE;
		dwKeySize = MAXBYTE;
		i++;
	}
	RegCloseKey(hKey);
	system("pause");
}
