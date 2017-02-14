To ensure proper performance of the program, only input integers. There's
nothing performing typechecking, so putting in not-integers will cause a
program crash.
As for the input file, data.txt, the first line should be a prime and all
others are the input values, e.g.

[FILE START]
table_size
input
input
input
input
...
input
[FILE END]
(Also: avoid empty lines, I'm not sure if the program will handle those
either. Crashes would probably occur.
