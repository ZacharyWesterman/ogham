#include <z/core/string.hpp>
#include <z/system/console.hpp>

zstring translate(const zstring& arg);

int main(int argc, char** argv)
{
	z::system::console console;

	zpath args;
	if (argc > 1)
	{
		for (int i=1; i<argc; i++)
		{
			if (i > 1) args += ' ';
			args += argv[i];
		}

		args.toLower();
		translate(args).writeln(console);
	}
	else
	{
		while(!console.empty())
		{
			args.readln(console);
			args.toLower();
			translate(args).writeln(console);
		}
	}

	return 0;
}

zstring translate(const zstring& arg)
{
	const zstring english = "abcdefghijklmnopqrstuvwxyz ";
	const zstring ogham   = L"ᚐᚁᚉᚇᚓᚃᚌᚆᚔᚌᚊᚂᚋᚅᚑᚚᚊᚏᚄᚈᚒᚃᚒᚎᚔᚎ ";

	bool toOgham = false;
	uint32_t ogOpen = L'᚛', ogClose = L'᚜';
	zstring result;

	for (auto ch : arg)
	{
		if ((ch == ogOpen) || (ch == ogClose)) continue;

		auto index = ogham.find(ch);
		if (index >= 0)
		{
			result += english[index];
			continue;
		}

		index = english.find(ch);
		if (index >= 0)
		{
			toOgham = true;
			result += ogham[index];
			continue;
		}

		result += ch;
	}

	if (toOgham) result = zstring(ogOpen) + zstring(result) + zstring(ogClose);
	return result;
}
