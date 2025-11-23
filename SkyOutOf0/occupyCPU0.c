#include <windows.h>
#include <stdio.h>
#include <math.h>

int main()
{
  HANDLE hProcess = OpenProcess(
      PROCESS_ALL_ACCESS,
      FALSE,
      GetCurrentProcessId());

  SetProcessAffinityMask(hProcess, 0x1);

  volatile double result = 0.0;

  while (1)
  {
    for (long long i = 0; i < 10000000LL; i++)
    {
      result += sin(i * 0.1) * cos(i * 0.1);
    }
    printf(".\r");
  }

  return 0;
}