# ogham

This is a simple program that transliterates English text to [Ogham](https://en.wikipedia.org/wiki/Ogham) and vice versa.

Note that it only converts A-Z (case insensitive) and space, and some English letters will convert to the same character in Ogham, as a few do not have an equivalent to English ("x" for example).

---

This project requires make, g++ (C++11), and [libzed](https://www.github.com/ZacharyWesterman/libzed).
To compile, just run make.

Note that while this does *compile and run* on Windows, the default command prompt does not support UTF-8 text, so any Ogham output will be a garbled mess. If you can make it work, power to you. I honestly just can't be bothered.

---

To use the resulting binary, you can run it with any text as command-line arguments. They will be read as if separated by a single space.

Alternately, you can run with no arguments for an interactive prompt (ctrl-D to exit).
