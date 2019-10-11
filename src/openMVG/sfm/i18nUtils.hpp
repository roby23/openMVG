#pragma once

#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;

typedef map<string, string> StringsMap;

static StringsMap strings;

static StringsMap it = {	
	{"Step 5 of 5: Images alignment", "Step 5 di 5: Allineamento immagini"},
	{"Step 4 of 5: Selecting initial pair", "Step 4 di 5: Selezione coppia iniziale di immagini"},
	{" of ", " di "}
};

static StringsMap en = {	
	{"Step 5 of 5: Images alignment", "Step 5 of 5: Images alignment"},
	{"Step 4 of 5: Selecting initial pair", "Step 4 of 5: Selecting initial pair"},
	{" of ", " of "}
};

static map<string, StringsMap> locales = {
	{"italian", it},
	{"english", en},
};

static void LoadStrings()
{
	strings = locales["english"];

	WCHAR strNameBuffer[LOCALE_NAME_MAX_LENGTH];
	DWORD error = ERROR_SUCCESS;
	LCID  lcid;

	// Get the name for locale
	if (LCIDToLocaleName(GetUserDefaultUILanguage(), strNameBuffer, LOCALE_NAME_MAX_LENGTH, 0) == 0)
	{
		// There was an error
		error = GetLastError();
	}
	else
	{
		// Success, display the locale name we found
		wprintf(L"Locale Name is %s\n", strNameBuffer);

		wstring currentLocale = strNameBuffer;

		if (currentLocale.find(L"it") != wstring::npos)
		{
			strings = locales["italian"];
		}
	}
}

static string GetString(string text)
{
	if (strings.size() == 0)
	{
		LoadStrings();
	}

	if (strings.count(text))
	{
		return strings[text];
	}

	return text;
}
