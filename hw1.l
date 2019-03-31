%{
#include "stdio.h"
#include "string.h"

//OPERATOR
#define ADD			3
#define SUB			4
#define MUL			5
#define DIV			6
#define EQL			7
#define GTR			8
#define GEQ			9
#define LSS			10
#define LEQ			11
#define EQT			12
#define NEQ			13

//KEYWORDS
#define INT			20
#define DOUBLE		21
#define STR			22
#define IF			23
#define WHILE		24
#define RETURN		25
#define PRINT		26
#define ELSE		27
#define FLOAT		28

//SPECIFIC
#define QUOTATION		30	//쌍따옴표
#define COMMA			31
#define LPAREN			32
#define RPAREN			33
#define SEMICOLON		34
#define LCURLY_BRACK	35	//중괄호
#define RCURLY_BRACK	36	//중괄호
#define SINGLE_QUOTE	37	//홑따옴표
#define LSQUARE_BRACK	38	//대괄호
#define RSQUARE_BRACK	39	//대괄호

//INTEGER
#define R_INTEGER		100
//DOUBLE
#define R_DOUBLE		101
//STRING
#define STRING			102
//IDENTIFIERS(ID)
#define IDENTIFIERS		103
//COMMENTS
#define COMMENTS		104
#define SCOMMENTS		105

//WS
#define WHITESPACE		106

%}
ADD 		"+"
SUB 		"-"
MUL 		"*"
DIV 		"/"
EQL 		"="
GTR 		">"
GEQ 		">="
LSS 		"<"
LEQ		"<="
EQT		"=="
NEQ		"!="

INT		"int"
DOUBLE		"double"
STR		"str"
IF		"if"
WHILE		"while"
RETURN		"return"
PRINT		"print"
ELSE		"else"
FLOAT		"float"


QUOTATION 	"\""
COMMA 		"\,"
LPAREN		"("
RPAREN		")"
SEMICOLON	";"
LCURLY_BRACK	"{"
RCURLY_BRACK	"}"
SINGLE_QUOTE	"\'"
LSQUARE_BRACK	"["
RSQUARE_BRACK	"]"

R_INTEGER 	-?([1-9][0-9]*|[0])

R_DOUBLE	-?[0-9]+\.[0-9]+

STRING		\"([^"\n]|\\(.|\n))*\"

IDENTIFIERS	([_]+[a-zA-Z0-9]|[a-zA-Z])[a-zA-Z0-9_]*

COMMENTS	\/\*([^*]|\*+[^*/])*\*+\/
SCOMMENTS	\/\/[^\n]*\n

WHITESPACE	[ \t\n\r]
%%
{ADD}		{return ADD;}
{SUB}		{return SUB;}
{MUL}		{return MUL;}
{DIV}		{return DIV;}
{EQL}		{return EQL;}
{GTR} 		{return GTR;}
{GEQ} 		{return GEQ;}
{LSS} 		{return LSS;}
{LEQ} 		{return LEQ;}
{EQT} 		{return EQT;}
{NEQ} 		{return NEQ;}

{INT}		{return INT;}
{DOUBLE}	{return DOUBLE;}
{STR}		{return STR;}
{IF}		{return IF;}
{WHILE}		{return WHILE;}
{RETURN}	{return RETURN;}
{PRINT}		{return PRINT;}
{ELSE}		{return ELSE;}
{FLOAT}		{return FLOAT;}

{QUOTATION}		{return QUOTATION;}
{COMMA}			{return COMMA;}
{LPAREN}		{return LPAREN;}
{RPAREN}		{return RPAREN;}
{SEMICOLON}		{return SEMICOLON;}
{LCURLY_BRACK}		{return LCURLY_BRACK;}
{RCURLY_BRACK}		{return RCURLY_BRACK;}
{SINGLE_QUOTE}		{return SINGLE_QUOTE;}
{LSQUARE_BRACK}		{return LSQUARE_BRACK;}
{RSQUARE_BRACK}		{return RSQUARE_BRACK;}

{R_INTEGER}		{return R_INTEGER;}

{R_DOUBLE}		{return R_DOUBLE;}

{STRING}		{return STRING;}

{IDENTIFIERS}		{return IDENTIFIERS;}

{COMMENTS}		{return COMMENTS;}
{SCOMMENTS}		{return SCOMMENTS;}

{WHITESPACE}		{return WHITESPACE;}
%%

int main(void){
  int tok;
  char sym_tab[101][1001]={0};
  char str_tab[101][1001]={0};

  int sym_num=0;
  int str_num=0;
  int same_idx=-1;
  int check =1;

  while((tok=yylex())!=0){

    if(check){
	printf("TOKEN \t\tLEXEME\n");
	check=0;
    }
    
    if(tok == ADD)
	printf("<ADD,>\t\t%s\n",yytext);
    else if(tok == SUB)
	printf("<SUB,>\t\t%s\n",yytext);
    else if(tok == MUL)
	printf("<MUL,>\t\t%s\n",yytext);
    else if(tok == DIV)
	printf("<DIV.>\t\t%s\n",yytext);
    else if(tok == EQL)
	printf("<EQL,>\t\t%s\n",yytext);
    else if(tok == GTR)
	printf("<GTR,>\t\t%s\n",yytext);
    else if(tok == GEQ)
	printf("<GEQ,>\t\t%s\n",yytext);
    else if(tok == LSS)
	printf("<LSS,>\t\t%s\n",yytext);
    else if(tok == LEQ)
	printf("<LEQ,>\t\t%s\n",yytext);
    else if(tok == EQT)
	printf("<EQT,>\t\t%s\n",yytext);
    else if(tok == NEQ)
	printf("<NEQ,>\t\t%s\n",yytext);
    else if(tok == INT)
	printf("<INT,>\t\t%s\n",yytext);
    else if(tok == DOUBLE)
	printf("<DOUBLE,>\t%s\n",yytext);
    else if(tok == STR)
	printf("<STR,>\t\t%s\n",yytext);
    else if(tok == IF)
	printf("<IF,>\t\t%s\n",yytext);
    else if(tok == WHILE)
	printf("<WHILE,>\t%s\n",yytext);
    else if(tok == RETURN)
	printf("<RETURN,>\t%s\n",yytext);
    else if(tok == PRINT)
	printf("<PRINT,>\t%s\n",yytext);
    else if(tok == ELSE)
	printf("<ELSE,>\t%s\n",yytext);
    else if(tok == FLOAT)
	printf("FLOAT,>\t%s\n",yytext);
    else if(tok == QUOTATION)
	printf("<QUOTATION,>\t%s\n",yytext);
    else if(tok == COMMA)
	printf("<COMMA,>\t%s\n",yytext);
    else if(tok == LPAREN)
	printf("<LPAREN,>\t%s\n",yytext);
    else if(tok == RPAREN)
	printf("<RPAREN,>\t%s\n",yytext);
    else if(tok == SEMICOLON)
	printf("<SEMICOLON,>\t%s\n",yytext);
    else if(tok == LCURLY_BRACK)
	printf("<LCURLY_BRACK,>\t%s\n",yytext);
    else if(tok == RCURLY_BRACK)
	printf("<RCURLY_BRACK,>\t%s\n",yytext);
    else if(tok == SINGLE_QUOTE)
	printf("<SINGLE_QUOTE,>\t%s\n",yytext);
    else if(tok == LSQUARE_BRACK)
	printf("<LSQUARE_BRACK,>\t%s\n",yytext);
    else if(tok == RSQUARE_BRACK)
	printf("<RSQUARE_BRACK,>\t%s\n",yytext);
    else if(tok == R_INTEGER){
        yytext[10]='\0';
	printf("<INTEGER , \t%s>\n",yytext);
    }
    else if(tok == R_DOUBLE){
	printf("<DOUBLE , \t%s>\n",yytext);
    }
    else if(tok == STRING){
	same_idx=-1;
	for(int i=0;i<str_num;i++){
		if(!strcmp(yytext,str_tab[i])){
			same_idx = i;
			printf("<STRING, %d>\t%s\n",same_idx+1,yytext);
			break;
		}
	}
	if(same_idx==-1){
		strcpy(str_tab[str_num],yytext);
		str_num++;
		printf("<STRING, %d>\t%s\n",str_num,yytext);
	}
    }
    else if(tok == IDENTIFIERS){
	same_idx=-1;
	for(int i=0;i<sym_num;i++){
		if(!strcmp(yytext,sym_tab[i])){
			same_idx = i;
			printf("<ID, %d>\t\t%s\n",same_idx+1,yytext);
			break;
		}
	}
	if(same_idx==-1){
		strcpy(sym_tab[sym_num],yytext);
		sym_num++;
		printf("<ID, %d>\t\t%s\n",sym_num,yytext);
	}

    }
    else if(tok == COMMENTS)
	printf("<COMMENTS,>\t%s\n",yytext);
    else if(tok == SCOMMENTS)
	printf("<SCOMMENTS,>\t%s\n",yytext);
    else if(tok ==WHITESPACE)
    	continue;
    }
	printf("----------------------------------------------------------\n");
    printf("Index\t\tSymbols\n");
    for(int i=0;i<sym_num;i++){
		printf("%d\t\t\"%s\"\n",i+1,sym_tab[i]);
	}
	printf("----------------------------------------------------------\n");
	printf("\n\n");
	printf("----------------------------------------------------------\n");
    printf("Index\t\tString\n");
    for(int i=0;i<str_num;i++){
		printf("%d\t\t%s\n",i+1,str_tab[i]);
	}
	printf("----------------------------------------------------------\n");
    return 0;
}

