First run the .l file 
    flex file_name.l  OR  
    lex file_name.l

Compile the lex.yy.c file
    gcc lex.yy.c -o lexer

Finally run the executable 
    ./lexer
