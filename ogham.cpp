#include <z/core.h>
#include <z/system.h>

using namespace z;

#define s core::string<utf32>

s translate(const s arg);

int main(int argc, char** argv)
{
	system::console console;

	core::string<utf8> args;
	for (int i=1; i<argc; i++)
	{
		if (i > 1) args += ' ';
		args += argv[i];
	}

	args = args.lower();

	if (argc > 1)
	{
		translate(args).writeln(console);
	}
	else
	{
		while(true)
		{
			args.readln(console);
			translate(args.lower()).writeln(console);
			console.flush();
		}
	}
}

s translate(const s arg)
{
	const s english = "abcdefghijklmnopqrstuvwxyz ";
	const s ogham   = L"ᚐᚁᚉᚇᚓᚃᚌᚆᚔᚌᚊᚂᚋᚅᚑᚚᚊᚏᚄᚈᚒᚃᚒᚎᚔᚎ ";

	bool toOgham = false;
	bool isOgham = false;
	uint32_t ogOpen = L'᚛', ogClose = L'᚜';
	s result;
	for (size_t i=0; i<arg.length(); i++)
	{
		int index;
		if ((index = ogham.find(arg[i])) >= 0)
		{
			isOgham = true;
			result += english[index];
		}
		else if (!isOgham && ((index = english.find(arg[i])) >= 0))
		{
			toOgham = true;
			result += ogham[index];
		}
		else
		{
			if ((arg[i] != ogOpen) && (arg[i] != ogClose))
				result += arg[i];
			else
				isOgham = true;
		}
	}

	if (toOgham)
	{
		result = s(ogOpen) + result + s(ogClose);
	}
	return result;
}
