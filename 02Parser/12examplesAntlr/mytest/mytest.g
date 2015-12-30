grammar mytest;

options {
  language=C;
}

@header {
}


@members {
/** Map variable name to Integer object holding value */
}

prog:   HELLO WORLD ;

HELLO: 'hello' | 'Hello' {printf("juhu");};
WORLD: 'World' ;

    ID  :   ('a'..'z'|'A'..'Z')+ ;
    INT :   '0'..'9'+ ;
    NEWLINE:'\r'? '\n' ;
    WS  :   (' '|'\t')+ {} ;
