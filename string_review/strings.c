#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *chop1(char *a);
void  chop2(char *a);

char *chop1(char *a){
 char *b=malloc(strlen(a)+1);
 strcpy(b,a+1);
 strncat(b,a,1);
 return(b);
}	
void chop2(char *a){
 char b[strlen(a)+1]; //c99 only
 strcpy(b,a+1);
 strncat(b,a,1);
 strcpy(a,b);
}		
int main(){
	char b[]="GoodBye Hello Goodbye";
	char c[]= "A World Apart";
 char d[100],e[100],f[100],g[100];
 char str1[]="chopped";
 char *str2;

 
 //if necessary in the next 5 exercises you can also '\0' where necessary 
 
 //Use strncat	and strings b and c to put "Hello World" in d; print out d
 //Use sprintf and strings b and c to put Hello World in e; print out e
 //use fwrite(s) and b and c to write to the screen Hello World
 //Use strcpy and strings b and c to put "Hello World" in f; print out f 
 //Use memcpy and strings b and c to put Hello World in g; print out g 

 //write a function chop1 that takes as a parameter the a string and returns a new string with the first character at the end i.e. str2=chop(str1) should result in str2 containing "hoppedc" - test it using str2 and str1 and print out str1 in the main function
  
 //write a function chop2 that does the same thing but replaces the parameter with the new string i.e. after applying chop2 to str1, str1 should contain "hoppedc". Test on str1 and print out the result in the main function.
 
 d[0]='\0';
 
 strncat(d,b+8,6);
 strncat(d,c+2,5);
 fprintf (stdout,"%s\n",d);
 
 sprintf(e,"%.6s%.5s",b+8,c+2);
 fprintf (stdout,"%s\n",e);
 
 fwrite(b+8,6,1,stdout);
 fwrite(c+2,5,1,stdout);
 fwrite("\n",1,1,stdout);
 
 strcpy(f,b+8);
 strcpy(f+6,c+2);
 f[11]='\0'; 
 fprintf (stdout,"%s\n",f);

 memcpy(g,b+8,6);
 memcpy(g+6,c+2,5);
 g[11]='\0'; 
 fprintf (stdout,"%s\n",g);

 str2=chop1(str1);
 fprintf (stdout,"%s\n",str2);
 chop2(str1);
 fprintf (stdout,"%s\n",str1);
  return 1;
} 
 
