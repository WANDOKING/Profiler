#include <iostream>
#include <Windows.h>

#include "Profiler.h"

long long GetFibonacciRecursive(int n)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}
	return GetFibonacciRecursive(n - 2) + GetFibonacciRecursive(n - 1);
}

int main(void)
{
	for (int i = 0; i < 30; ++i)
	{
		PROFILE_BEGIN(L"fibonacci");
		long long ret = GetFibonacciRecursive(i);
		PROFILE_END(L"fibonacci");

		printf("%lld\n", ret);
	}

	for (int i = 0; i < 30; ++i)
	{
		PROFILE_BEGIN(L"Sleep100");
		Sleep(100);
		PROFILE_END(L"Sleep100");
	}

	for (int i = 0; i < 100; ++i)
	{
		PROFILE_BEGIN(L"HelloWorld");
		printf("Hello World!");
		PROFILE_END(L"HelloWorld");
	}

	PROFILE_SAVE(L"profile_test.txt");
}