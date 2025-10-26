#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void main(){

FILE *source,*intermediate,*optab,*symtab,*length;

source=fopen("source.txt","r");
intermediate=fopen("intermediate.txt","w");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","w+");
length=fopen("length.txt","w");

char  label[100],opcode[100],operand[100],symtad_data[50],optab_data[50],opcode_name[20],opcode_code[30];
int locctr,starting_address,pgm_length;
bool symbol_found,opcode_found;

fscanf(source,"%s%s%s",label,opcode,operand);
if(strcmp(opcode,"START")==0){
starting_address=(int)strtol(operand,NULL,16);
locctr=starting_address;
fprintf(intermediate,"0000\t%s\t%s\t%s\n",label,opcode,operand);
}
else{
locctr=0;
}

fscanf(source,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"END")!=0){

fprintf(intermediate,"%04X\t%s\t%s\t%s\n",locctr,label,opcode,operand);

if(strcmp(label,"**")!=0){
 fprintf(symtab,"%s\t%04x\n",label,locctr);
 }
 
 //opcode
 rewind(optab);
 opcode_found=false;
 while(fscanf(optab,"%s%s",opcode_name,opcode_code)!=	EOF){
 if(strcmp(opcode,opcode_name)==0){
 opcode_found=true;
 break;
 }
 }
 if(opcode_found==true){
 locctr+=3;
}
else if(strcmp(opcode,"WORD")==0){
locctr+=3;
}
else if(strcmp(opcode,"RESW")==0){
locctr+=3*atoi(operand);
}
else if(strcmp(opcode,"RESB")==0){
locctr+=atoi(operand);
}
else if(strcmp(opcode,"BYTE")==0){
locctr+=strlen(operand)-3;
}
else {
printf("Invalid");}

fscanf(source,"%s%s%s",label,opcode,operand);
}
fprintf(intermediate,"%04X\t%s\t%s\t%s",locctr,label,opcode,operand);
pgm_length=locctr-starting_address;
fprintf(length,"%d",pgm_length);

fclose(source);
fclose(intermediate);
fclose(optab);
fclose(symtab);
fclose(length);

    printf("Pass 1 completed successfully!\n");
    printf("Program length = %X\n", pgm_length);
 
 
 
 
 
 
}
