#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
/*
  Assignment 01, CSE 326 Compiler Construction
  Group:17
  Name:Ronald Tudu, Shaibal Saha ID: 1411517042, 1411305042
  Symbols:  [A-Za-Z], [0-9] ( ) { } [ ] . ; + - * / % : = + - \ ‘ “ \n \t \r \\
  Reserved words: if, else, for, int, char, real, void
*/
int main()
{

FILE *fp;
long lSize;
char *buffer;

fp = fopen ( "rt.txt" , "rb" );
if( !fp ) perror("rt.txt"),exit(1);

fseek( fp , 0L , SEEK_END);
lSize = ftell( fp );
rewind( fp );

/* allocate memory for entire content */
buffer = calloc( 1, lSize+1 );
if( !buffer ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

/* copy the file into the buffer */
if( 1!=fread( buffer , lSize, 1 , fp) )
  fclose(fp),free(buffer),fputs("entire read fails",stderr),exit(1);

/* do your work here, buffer is a string contains the whole text */

 // printf("%c", buffer[2]);














    bool b;

    char tempid[10];

    char id[10][14];
//strcpy(a[0], "blah");
//strcpy(a[1], "hmm");

bool keyword;

//printf("%c",buffer[5]);

for (int i=0; i<lSize;i++)

 {

     b=false;
    switch (buffer[i])
      {
            case '(':
            {
             printf("LPT\n");
             b=true;
            }
            break;

            case ')':
            {
             printf("RPT\n");
             b=true;
            }
            break;

            case '{':
            {
             printf("LCB\n");
             b=true;
            }
            break;

            case '}':
            {
             printf("RCB\n");
             b=true;
            }
            break;

            case '[':
            {
             printf("LSB\n");
             b=true;
            }
            break;

            case ']':
            {
             printf("RSB\n");
             b=true;
            }
            break;

            case '.':
            {
             printf("DOT\n");
             b=true;
            }
            break;

            case ';':
            {
             printf("SEMI\n");
             b=true;
            }
            break;

            case '*':
            {
             printf("PROD\n");
             b=true;
            }
            break;

            case '/':
            {
             printf("DIV\n");
             b=true;
            }
            break;

            case '%':
            {
             printf("REM\n");
             b=true;
            }
            break;



            default :
            {

            }



      }


       if (b==false)
        {           if(buffer[i]==' ')  //1
                    {
                     //puts("empty string\n");
                    }

                    else if(buffer[i]==NULL) //2
                    {
                      puts("end\n");
                    }
                    else if (isalpha(buffer[i]) ) //3
                    {


                           if (buffer[i]=='i'&& buffer[i+1]=='f' && (buffer[i+2]==' '|| buffer[i+2]=='\n'))
                               {

                                       printf("if \n");
                                       i=i+ 1;


                                    }
                            else if (buffer[i]=='i'&& buffer[i+1]=='n' && buffer[i+2]=='t' && (buffer[i+3]==' '|| buffer[i+3]=='\n'))
                                    {
                                     printf("int \n");
                                     i =i+2;
                                    }






                            else if(buffer[i]=='r' && buffer[i+1]=='e' && buffer[i+2]=='a' && buffer[i+3]=='l' && (buffer[i+4]==' '|| buffer[i+4]=='\n'))
                                         {

                                              printf("real\n");
                                              i=i+3;
                                            }
                                    else if(buffer[i]=='r' && buffer[i+1]=='e' && buffer[i+2]=='t' && buffer[i+3]=='u' && buffer[i+4]=='r' && buffer[i+5]=='n'&& (buffer[i+6]==' '|| buffer[i+6]=='\n'))
                                            {
                                              printf("return\n");
                                              i=i+5;
                                            }

                              }
        else if(buffer[i]=='f' & buffer[i+1]=='o'&& buffer[i+2]=='r' && (buffer[i+3]==' '|| buffer[i+3]=='\n'))
                {
                    printf("for\n");
                    i=i+2;
                }

        else if(buffer[i]=='e' & buffer[i+1]=='l'&& buffer[i+2]=='s' && buffer[i+3]=='e' && (buffer[i+4]==' '|| buffer[i+4]=='\n'))
                {
                    printf("else\n");
                    i=i+3;
                }
        else if(buffer[i]=='v' & buffer[i+1]=='o'&& buffer[i+2]=='i' && buffer[i+3]=='d' && (buffer[i+4]==' '|| buffer[i+4]=='\n'))
                {
                    printf("void\n");
                    i=i+3;
                }
        else if(buffer[i]=='c' & buffer[i+1]=='h'&& buffer[i+2]=='a' && buffer[i+3]=='r' && (buffer[i+4]==' '|| buffer[i+4]=='\n'))
                {
                    printf("char\n");
                      i=i+3;
                }








                              //printf("%d ",isKeyword(buffer,i));
              else {


               while(isalpha(buffer[i+1]) || isdigit(buffer[i+1])){



                                      i++;

                              }

                             printf("ID \n");
                             i=i+1;





              }
              }














                else if(isdigit(buffer[i]) )  //4
                    {
                      //printf("its a digit %c\n",buffer[i]);

                     // printf("%d %d",i,lSize);

                      if (buffer[i]=='0' && buffer[i+1]=='x')
                    {
                       i=i+2;

                      while(isxdigit(buffer[i]))
                      {

                        i++;
                        printf("%d \n", i);
                      }

                      printf("HEX %d\n",i);



                    }

                    else

                     i= isILIT(buffer,i,lSize);




                    }
                else if (buffer[i]=='\n')
                   {

                       printf("new line\n");
                    }


                else if (buffer[i]=='\\')
                    {
                       if(buffer[i+1]=='n')
                       {
                            printf("NL\n");
                            i=i+1;

                       }

                       else if (buffer[i+1]=='t')
                       {

                            printf("TAB\n");
                             i=i+1;
                       }

                        else if (buffer[i+1]=='r')
                       {

                            printf("CR\n");
                             i=i+1;
                       }

                        else if (buffer[i+1]=='\\')
                       {

                            printf("BKSL\n");
                             i=i+1;
                       }

                    }

                else if (buffer[i]=='"')

                    {
                        while (buffer[i+1]!='"')
                        {
                          i++;

                        }
                        i=i+1;
                       printf("SLIT %d\n",i);

                    }

                else if(buffer[i]=='+' || buffer[i]=='-' || buffer[i]=='*' || buffer[i]=='/' || buffer[i]==' ' || buffer[i]==':')
                   {

                       if (buffer[i]=='+')
                       {

                          if (buffer[i+1]=='+')
                          {
                             printf("INC\n");
                             i= i+2;
                          }

                         else{
                          printf("PLUS\n");
                             i= i+1;
                         }
                       }

                       if (buffer[i+1]=='-')
                       {

                          if (buffer[i+2]=='-')
                          {
                             printf("DEC\n");
                            i= i+2;
                          }

                        else{
                          printf("MINUS\n");
                          i= i+1;
                        }

                       }

                        if (buffer[i+1]=='=')
                       {

                          printf("ASSIG\n");
                          i=i+1;

                       }






                    }





                   else
                   printf("error!\n");







        }

 else // the other stuffs
 {

 }









}
//printf(" %c %d", buffer[0],lSize);




fclose(fp);
free(buffer);








    return 0;
}




    int isILIT(char *buffer,int i, int size)

            {



               while(isdigit(buffer[i+1]))
               {


                i++;
               }
               if( buffer[i+1]=='.'  && isdigit(buffer[i+2]))
               {

                     while(isdigit(buffer[i+2]))
                        {

                         // printf("%c  %d", buffer[i+2], i);
                          i++;
                          }
                     printf("RLIT \n");

                     return i+1;

               }


               else
               {
                  printf("ILIT \n");
                  return i+1;

               }




        }










