#include <z/core/string.hpp>
#include <z/system/console.hpp>

int main(int argc, char** argv)
{
	z::system::console console;

	const zstring english = "abcdefghijklmnopqrstuvwxyz ";
	const zstring ogham   = L"ᚐᚁᚉᚇᚓᚃᚌᚆᚔᚌᚊᚂᚋᚅᚑᚚᚊᚏᚄᚈᚒᚃᚒᚎᚔᚎ ";

	zstring args;
	if (argc > 1)
	{
		for (int i=1; i<argc; i++)
		{
			if (i > 1) args += ' ';
			args += zpath(argv[i]);
		}

		if (args.contains({'A', 'z'}))
			(L'᚛'_u32 + args.lower().cipher(english, ogham) + L'᚜'_u32).writeln(console);
		else
			args.replace(L'᚛',"").replace(L'᚜',"").cipher(ogham, english).writeln(console);
	}
	else
	{
		while(!console.empty())
		{
			args.readln(console);
			if (args.contains({'A', 'z'}))
				(L'᚛'_u32 + args.lower().cipher(english, ogham) + L'᚜'_u32).writeln(console);
			else
				args.replace(L'᚛',"").replace(L'᚜',"").cipher(ogham, english).writeln(console);
		}
	}

	return 0;
}
