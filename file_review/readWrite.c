 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 void readTextWriteBin(char *inputFile, char *outputFile){
		FILE *ifp=fopen(inputFile,"r");
		FILE *ofp=fopen(outputFile,"w");
		char line[512];
		while(fgets(line,sizeof(line),ifp)){
			char name[512];
			int age;
			int len;
			sscanf(line,"%s %d\n",name,&age);
			len=strlen(name);
			fwrite(&len,sizeof(int),1,ofp);
			fwrite(name,strlen(name),1,ofp);
			fwrite(&age,sizeof(int),1,ofp);
		}	
		fclose(ifp);
		fclose(ofp);
	}
 void readBinWriteText(char *inputFile, char *outputFile){
		FILE *ifp=fopen(inputFile,"r");
		FILE *ofp=fopen(outputFile,"w");
		int len,age;
		char name[512];
		while(fread(&len,sizeof(int),1,ifp)){
		 fread(name,len,1,ifp);
		 name[len]='\0';
			fread(&age,sizeof(int),1,ifp);
			fprintf(ofp,"%s %d\n",name,age);
		}	
		fclose(ifp);
		fclose(ofp);
	}
 
 int main(int argc, char *argv[]){
  char *inputFile,*outputFile,text2Bin=1;
  int i=1;
  while(i <argc){
			if(strcmp(argv[i],"-i") ==0){
				inputFile=argv[++i];
			}	
			else if(strcmp(argv[i],"-o") ==0){
				outputFile=argv[++i];
			}
			else if(strcmp(argv[i],"-b") ==0){
				text2Bin=0;
			}
			else{
				fprintf(stderr,"readWriteFiles -i <inputFile> -o <outputFile> -b (optional)\n");
				exit(EXIT_FAILURE);
			}			
			i++;
		}
  fprintf(stderr,"inputFile %s outputFile %s text2Bin %d\n",inputFile,outputFile, text2Bin);
  if(text2Bin)readTextWriteBin(inputFile,outputFile);
  else readBinWriteText(inputFile,outputFile);
  
  //parse the command line for flags -i -o and an optional -b falg
  //i.e.
  //readWriteFiles -i <inputFile> -o <outputFile> -b (optional) in any order
  //if the -b flag appears set the text2Bin to 0
  
  //if text2Bin is 1 you will call readTextWriteBin on inputFile and outputFile
  //otherwise you will call readBinWriteText on inputFile and outputFile
  
  
  //write two functions readTextWriteBin and readBinWriteText
  
  //the text format is two fields on each line, one a name and the other an age (integer) separated by a space
  //the binary format is a series of 3 repeating fields <nameLength><name><age> i.e. an integer, a series of characters, and a 
  
  //to read the text format use fgets and sscanf and write using 3 fwrites
  //to read the binary format use a while loop and 3 freads (one can be in the loop) and write the text using fprintf
  
  //two sample files are given to you sample.txt sample.bin
  
  //assume no line is greater than 500 characters in length

  
  return 1;
	}  

 
