#include <stdbool.h>
#include <windows.h>
#include <hard_assert.h>

#define LIBRARY_NAME "PEH"

bool peh_check_privileges(void)
{	HANDLE process_access_token;
	ha_assert(OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &process_access_token), LIBRARY_NAME, "process handle obtention failure");
	TOKEN_ELEVATION elevation_status;
	DWORD size = sizeof(TOKEN_ELEVATION);
	ha_assert(GetTokenInformation(process_access_token, TokenElevation, &elevation_status, size, &size), LIBRARY_NAME, "process token information obtention failure");
	ha_assert(CloseHandle(process_access_token), LIBRARY_NAME, "process handle cleanup failure");
	return elevation_status.TokenIsElevated;
}

void peh_elevated_restart(void)
{	char path[MAX_PATH + 1];
	DWORD size = MAX_PATH;
	ha_assert(QueryFullProcessImageNameA(GetCurrentProcess(), 0, path, &size), LIBRARY_NAME, "process image path obtention failure");
	ha_assert((INT_PTR)ShellExecuteA(NULL, "runas", path, "", NULL, SW_SHOWNORMAL) > 32, LIBRARY_NAME, "shell execution failure");
	exit(EXIT_SUCCESS);
}
