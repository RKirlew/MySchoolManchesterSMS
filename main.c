#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <time.h>
#include <string.h>
#define MAX 10000
#define ALT 18
#define ENTER 13
#define TAB 9
#define TRUE 1
#define FALSE 0
#define BKSP 8

struct User{
	char name[50];
	char sID[50];
	char pass;
}stud;
char adminPass[10];
char user[15];
int srAllowed=0;


void gotoxy(short col,short row){
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={col,row};
	SetConsoleCursorPosition(h,position);
}

void mkRep();
void modifyUser();
void changeAdmin();
void delUser();
void createNewUser();
void userLogin();
void changePass();
void load();
void addStud();
void generalInfo();
void searchStud();
void viewStud();
int verifyStud(char * name, char * lName);
void addGrad();
void viewGrad();
void gradByName();
void gradByForm();
void gradByID();
void viewRep();
void editRep();
void searchByForm();
void searchByID();
void showOptionsID();
void callAll();
void adminSettings();
void controlPanel(){
	char option;
	system("COLOR 3");
	printf("\n WELCOME %s!\n",user);
	sleep(2);
	system("cls");
	
    gotoxy(40,3);
	printf("                 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2                \n         ");
	gotoxy(40,5);
	printf("-------------------*CONTROL PANEL*------------------\n");
	gotoxy(40,7);
	printf("Options: 1)Add Student to Database  2)View All Students   3)Add Grades");
	gotoxy(48,8);
	printf("4)Make Report Card 5)View Report Card  6)Settings 7)Delete Student ");
	gotoxy(50,10);
	printf("8) View Student Grades      9)Exit MySchoolManchester \n");
	
	printf("->");
	scanf("%d",&option);
	switch(option){
		case 1:
			addStud();
			break;
	    case 2:
			viewStud();
			break;
		case 3:
			addGrad();
			break;
		case 4:
			mkRep();
			break;
		case 5:
			viewRep();
			break;
		case 6:
			adminSettings();
			break;	
		case 7:
			delUser();
			break;
		case 8:
			viewGrad();	
		case 9:
			printf("Thanks for using MYSCHOOLMANCHESTER Report Card System.");
			sleep(1);
			exit(1);
			break;		
		default:
			printf("Invalid option selected!");
			controlPanel();						
			
		
	}
}
int main(){
	FILE *fp;
	FILE *ad;
	ad=fopen("password.txt","r");
	fscanf(ad,"%s",adminPass);
	fclose(ad);
    fp=fopen("username.txt","r");
	fscanf(fp,"%s",user);
	fclose(fp);
	system("COLOR a");
	printf("Sic Luceat Lux");
	sleep(1);
	system("cls");
	HWND hWnd=GetConsoleWindow();
	ShowWindow(hWnd,SW_MAXIMIZE);
	system("test.exe");
	int isAdmin=0;
	int i;
	int x,y;
	char srA[10];
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
	system("COLOR 3");
	char password[10];
	wcscpy(cfi.FaceName, L"Lucida Caligraphy");
	x=40;
	y=3;
	gotoxy(x,y);
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MYSCHOOLMANCHESTER REPORT CARD SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	gotoxy(45,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,7);
	printf("\nSpeech Synthesis? (Y\\N):");
	scanf("%s",&srA);
	if(strcmp(srA,"y")==0){
		srAllowed=1;
	}
	else{
		srAllowed=0;
	}
	if(srAllowed==1){
		FILE *sr;
		sr=fopen("voice.vbs","w");
		fprintf(sr,"Dim message, sapi \n set sapi=CreateObject(\"sapi.spvoice\")\n sapi.Speak \"Welcome to MySchoolManchester Report Card System,Please enter your password\"");
		fclose(sr);
		system("voice.vbs");
	}
	int opt;
	HANDLE  hConsole;
    int k=249;

  	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	//gotoxy(40,5);
	//printf("1)User or 2)Admin:");
	//scanf("%d",&opt);
//	if(opt==1){
	//	userLogin();
//	}
	
	printf("Enter admin password:");
	char pass[50];
	char ch;
	while(1){
		ch=getch(); //gets keycode
		if(ch==ENTER || ch==TAB){ //checks the keycode
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}
			else{
				pass[i++]=ch;
				printf("* \b");
			}
		}
	//scanf("%s",&password);
	if(strcmp(adminPass,pass)==0){
		isAdmin=1;
		system("cls");
		system("COLOR a");
		printf("ACCESS GRANTED \n");
		printf("Loading admin panel");
		printf("[");
		for(i=0;i<5;i++){
			printf("::");
			sleep(1);
	}
		printf(">");
		controlPanel();
	}else{
		system("CLS");
		system("COLOR 04");
		printf("Password incorrect!\n");
		main();
	}
}
void addStud(){
	char fName[50];
	char lName[50];
	char form[5];
	int uid;
	char id[7];
	FILE *fp;
	FILE *rn;
	FILE *regNum;
	FILE *reg;
	rn=fopen("prevID.txt","r");
	fscanf(rn,"%d",&uid);
	fclose(rn);
	fp=fopen("students.txt","a+");

	printf("\nEnter student full name:");
	scanf("%s %s",fName,lName);
	printf("Enter student form:");
	scanf("%s",form);
	uid=uid+1;
	reg=fopen("prevID.txt","w");
	fprintf(reg,"%d",uid);
	fclose(reg);
	regNum=fopen("registeredIDs.txt","a");
	fprintf(regNum,"\n %d",uid);
	fclose(regNum);
	fprintf(fp,"\n %s              %s    %s                 %d",form,fName,lName,uid);
	printf("Student %s %s of form class %s added to database",fName,lName,form);
	fclose(fp);
	sleep(2);
	controlPanel();
}
void viewStud(){
	FILE *sr;
	sr=fopen("voice.vbs","w");
	fprintf(sr,"Dim message, sapi \n set sapi=CreateObject(\"sapi.spvoice\")\n sapi.Speak \"Accessing students in the database, Please choose an option from below\"");
	fclose(sr);
	system("voice.vbs");
	int searchVal;
	int id;
	int opt;
	system("cls");
	printf("Options:1) View All Students   2)Search For Specific Student   3) Search By Form 4) Search By ID\n");
	printf("->");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			callAll();
			break;
		case 2:
			searchStud();
			break;	
		case 3:
			searchByForm();
			break;	
		case 4:
			searchByID();
			break;			
		 
			
	}
	
}
void searchStud(){
	char names[135][125];
	int i=0;
	int freq=0;
	int j=0;
	char str;
	char query[50];
		FILE *fp;
		fp=fopen("students.txt","r");
		for(i=0;i<=MAX;i++){
			
		
		fscanf(fp,"%s", names[i]);
  }
	fclose(fp);
			
		printf("Enter first name to search:");
		getchar();
		gets(query);
	    for(i=0;i<=MAX;i++){
			
		if(strstr(names[i],query)){
			if(strcmp(names[i],query)==0){
				
				freq++;
				printf("\n%d record(s) found for %s",freq,query);
				printf("\n %s %s %s %s",names[i-1],names[i],names[i+1],names[i+2]);
				
			}
		}
		if(i>200){
			break;
		}
	}
	int option;
	printf("\n1) Return To Control Panel     2) Exit Program :");
	scanf("%d",&option);
	switch(option){
		case 1:
			controlPanel();
			break;
		case 2:
			exit(1);
		default:
			printf("Invalid option selected!\n");
			load();
			
			controlPanel();		
	}
}
void callAll(){
	    FILE *fp;
	    int opt;
		char str[MAXCHAR];
		fp=fopen("students.txt","r");
		FILE *sr;
		sr=fopen("voice.vbs","w");
		fprintf(sr,"Dim message, sapi \n set sapi=CreateObject(\"sapi.spvoice\")\n sapi.Speak \"Here are the registered students\"");
		fclose(sr);
		system("voice.vbs");
			printf("[*]Registered Students: \n");
			while (fgets(str, MAXCHAR, fp) != NULL)
		        printf("%s", str);
		    fclose(fp); 
		printf("\nOptions:1)Return to Control Panel 2)Exit Program");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				controlPanel();
				break;
			case 2:
				exit(1);
				break;
					
		}    
		    
}
void searchByID(){
	int opt;
	char names[255][255];
	int i=0;
	int freq=0;
	int j=0;
	char str;
	char query[100];
		FILE *fp;
		fp=fopen("students.txt","r");
		for(i=0;i<=MAX;i++){
			
		
		fscanf(fp,"%s", names[i]);
		
  }
	
			
		printf("Enter ID to search:");
		getchar();
		gets(query);
		
	    for(i=0;i<=MAX;i++){
		
		if(strstr(names[i],query)){
		
			
			if(strcmp(names[i],query)==0){
				
			
				freq++;
				printf("\n%d record(s) found for ID#: %s",freq,query);
			
				printf("\n  %s %s %s",names[i-1],names[i-2],names[i-3]);
			
			}
		}
		else if(strstr(names[i],query)!=0){
			printf("No record found for student ID#%s",query);
			break;
			fclose(fp);
		}
		
		if(i>200){
			break;
		}
		
	}
	sleep(1);
	showOptionsID();
	fclose(fp);
}
void adminSettings(){
	int opt;
	system("cls");
	system("COLOR 3");
	gotoxy(40,3);
	printf("------------ EDIT ADMINISTRATOR SETTINGS -------------\n");
	gotoxy(40,5);
	printf("Current Settings:Username:%s  Current Password:%s \n",user,adminPass);
	gotoxy(40,7);
	printf("Options:1)Change Username   2)Change Password  3)Return To Control Panel\n");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			changeAdmin();
			break;
		case 2:
			changePass();
			break;
		case 3:
			controlPanel();
			break;
		default:
			printf("Invalid option selected!");
			sleep(2);
			adminSettings();
			break;		
	}
	
	
}
void searchByForm(){
	char names[135][125];
	int i=0;
	int freq=0;
	int j=0;
	char str;
	char query[50];
		FILE *fp;
		fp=fopen("students.txt","r");
		for(i=0;i<=MAX;i++){
			
		
		fscanf(fp,"%s", names[i]);
  }
	fclose(fp);
			
		printf("Enter form to search:");
		getchar();
		gets(query);
	    for(i=0;i<=MAX;i++){
			
		if(strstr(names[i],query)){
			if(strcmp(names[i],query)==0){
				
				freq++;
				printf("\n%d record(s) found for %s",freq,query);
				printf("\n %s %s %s %s",names[i],names[i+1],names[i+2],names[i+3]);
				
			}
		}
		if(i>200){
			break;
		}
	}
	int option;
	printf("\n 1) Return To Control Panel     2) Exit Program:");
	scanf("%d",&option);
	switch(option){
		case 1:
			controlPanel();
			break;
		case 2:
			exit(1);
		default:
			printf("Invalid option selected!\n");
			load();
			
			controlPanel();		
	}
}
	
void load(){
	system("COLOR 3");
	printf("Loading");
	int j;
	for(j=0;j<5;j++){
		printf(":");
		sleep(1);
	}
	printf(">\n");
}	
void showOptionsID(){
	int opt;
	printf("\n Options:1)Return To Control Panel 2) Exit Program:");
	scanf("%d",&opt);
	
	switch(opt){
		case 1:
			controlPanel();
			break;
		case 2:
			gotoxy(40,3);
			printf("Thanks for using MYSCHOOLMANCHESTER Report Card System");
			sleep(1);
			exit(1);	
	}
}
void changeAdmin(){
	char newUser[20];
	FILE *fp;
	fp=fopen("username.txt","w");
	printf("Enter new admin username:");
	scanf("%s",newUser);
	fprintf(fp,"%s",newUser);
	fclose(fp);
	printf("Username changed to %s. Restart the program to see the changes.",newUser);
	sleep(1);
	controlPanel();
}
void addGrad(){
	system("cls");
	int verStatus;
	int i;
	int num;
	char subjects[150];
	char sName[100];
	char sID[10];
	
	float avg;
	char form[10];
	char fName[100];
	char lName[100];
	int sum=0;
	int grade;
	char str[1000];
	int choice;
	gotoxy(40,1);
	printf("MYSCHOOLMANCHESTER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD STUDENT GRADES ");
	gotoxy(40,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Enter Student\'s First and Last Name:");
	gotoxy(40,5);
	scanf("%s %s",&fName,&lName);
	//printf("%s %s",fName,lName);


	verStatus=verifyStud(fName,lName);
	//printf("%d",verStatus);
	if(verStatus==0){
		system("COLOR 3");
		Beep(1300,1000);
		printf("[!]Student not registered ");
		printf("Register Now(1) | Return To Control Panel(2):");
		scanf("%d",&choice);
		if(choice==1){
		
		printf("[*]Fetching registration form");
		sleep(2);
		addStud();}
		else if(choice==2){
			controlPanel();
		}else{
			printf("Invalid option selected! Returning to control panel");
			controlPanel();
		}
	}else if(verStatus!=0){
		FILE *fp;
		fp=fopen("grades.txt","a");
		gotoxy(40,5);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Amount of Subjects Done:");
		scanf("%d",&num);
		gotoxy(40,7);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student ID#:");
		gotoxy(40,9);
		//fflush(stdin);
		scanf("%s",&sID);
		//verifyID();
		gotoxy(40,11);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student Form Class:");
		gotoxy(40,12);
		scanf("%s",&form);
		gotoxy(40,14);
		//printf("%s",&fName);
		//printf("%s",&lName);
		
		//printf("%s",&sID);

		fprintf(fp,"\n\n [*] %s  %s           %s   %s",&fName,&lName,&form,&sID);

		printf("Enter the subject done, press enter, then enter the grade associated with the subject above:\n");
		printf("       NOTE: IF SUBJECT HAS TWO NAMES USE AN UNDERSCORE OR HYPHEN INSTEAD OF A SPACE.");
		gotoxy(40,18);
		for(i=0;i<num;i++){
		scanf("%s",&subjects);
		scanf("%d",&grade);
		sum+=grade;
	
		fprintf(fp,"\n %s  %d",&subjects,grade);
		
		}
		avg=(sum/num);
	
		fprintf(fp,"\n %s %s\'s Average: %.2f ",&fName,&lName,avg);
		fclose(fp);
	
		printf("Student grades added to database sucessfully!");
		sleep(2);
		controlPanel();
	}
}
void viewGrad(){
	COORD coordinates;
    coordinates.X = 1000;
    coordinates.Y = 1000;

    if (0 == SetConsoleScreenBufferSize(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coordinates
    ));
	system("cls");
	gotoxy(40,1);
	printf("MYSCHOOLMANCHESTER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW STUDENT GRADES \n");
	if(srAllowed==1){
	FILE *sr;
	sr=fopen("voice.vbs","w");
	fprintf(sr,"Dim message, sapi \n set sapi=CreateObject(\"sapi.spvoice\")\n sapi.Speak \"Now viewing student grades\"");
	fclose(sr);
	system("voice.vbs");
}
	int opt;
	char str[MAX];
	FILE *fp;
	fp=fopen("grades.txt","r");
	while (fgets(str, MAX, fp) != NULL)
        printf("%s", str);
    fclose(fp); 
    //gotoxy(40,3);
    //printf("\n\n\n");
    printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Options:1)Return to Control Panel 2) Search By Name  3) Search By ID 4)Exit Program:");
    scanf("%d",&opt);
    switch(opt){
    	case 1:
    		controlPanel();
    		break;
    	case 2:
			gradByName();
			break;
		case 3:
			gradByID();
			break;
					
		case 4:
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Thanks for using MYSCHOOLMANCHESTER!");
			sleep(1);
			exit(1);
			break;
		default:
			printf("Invalid option selected.");
			viewGrad();
		}
				
}
void gradByName(){
	char name[100];
	system("cls");
	gotoxy(40,1);
	printf("MYSCHOOLMANCHESTER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW STUDENT GRADES BY NAME \n");
	gotoxy(40,3);
	printf("Enter Student First  Name to Search:");
	getchar();
	gets(name);
	char grades[235][225];
	int i=0;
	int freq=0;
	int j=0;
	char str;
	FILE *fp;
	fp=fopen("grades.txt","r");
	for(i=0;i<=MAX;i++){
		fscanf(fp,"%s", grades[i]);
  }
	fclose(fp);
	int option;
	for(i=0;i<=MAX;i++){
			
		if(strstr(grades[i],name)){
			if(strcmp(grades[i],name)==0){
				int j;
				freq++;
				printf("\n%d record(s) found for %s",freq,name);
				//printf("\n %s %s %s %s %s %s %s %s %s %s",grades[i],grades[i+1],grades[i+2],grades[i+3],grades[i+4],grades[i+5],grades[i+6],grades[i+7],grades[i+8],grades[i+9],grades[i+10]);
				for(j=0;j<10;j++){
					
						if(grades[i+j]!='/0'){
						
						printf("\n %s",grades[i+j]);
					}
					
			}
			}
		}
		if(i>200){
			break;
		}
	}
	sleep(5);
	printf("1) Control Panel 2) Exit Program:");
	scanf("%d",&option);
	switch(option){
		case 1:
			load();
			controlPanel();
		break;
		case 2:
			exit(1);
		default:
			printf("Invalid Option Selected!");
			controlPanel();	
	}
	
	
	
}
void gradByID(){
	
	char grades[225][225];
	int i=0;
	int freq=0;
	int j=0;
	char str;
	char id[50];
		FILE *fp;
		fp=fopen("grades.txt","r");
		for(i=0;i<=MAX;i++){
			
		
		fscanf(fp,"%s", grades[i]);
  }
	fclose(fp);
			
		printf("Enter ID to search:");
		getchar();
		gets(id);
	    for(i=0;i<=MAX;i++){
			
		if(strstr(grades[i],id)){
			if(strcmp(grades[i],id)==0){
				int j;
				freq++;
				printf("\n%d record(s) found for ID#: %s",freq,id);
				//printf("\n %s %s %s %s %s %s %s",grades[i],grades[i-2],grades[i-1],grades[i+1],grades[i+2],grades[i+3],grades[i+4],grades[i+5]);
					for(j=0;j<12;j++){
					
						if(grades[i+j]!='/0' || grades[i+j]!='\n'|| grades[i+j]!='[*]'){
						
						printf("\n%s",grades[i+j]);
					}
					
			}
			}
		}
	
		if(i>200){
			break;
			}
		}
			int option;
			printf("\n 1) Control Panel 2)Exit Program:");
			scanf("%d",&option);
			
			switch(option){
				case 1:
					controlPanel();
					break;
				case 2:
					exit(1);
					break;
				default:
					printf("Invalid Option Selected!");
					controlPanel();
							
	}
	
}
void userLogin(){
	int i;
	char sID[10];
	char pass[50];
	char ch;
	printf("Enter your Student ID#:");
	scanf("%s",stud.sID);
	printf("Enter your password:");
	while(1){
		ch=getch(); //gets keycode
		if(ch==ENTER || ch==TAB){ //checks the keycode
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}
			else{
				pass[i++]=ch;
				printf("* \b");
			}
		}
}
int verifyStud(char studName[],char lName[]){
	//return 1;
	char names[135][125];
	int i=0;
	int found;
	int freq=0;
	int j=0;
	char str;
	char query[50];
	FILE *fp;
	//printf("%s",studName);
	fp=fopen("students.txt","r");
	for(i=0;i<=MAX;i++){
		fscanf(fp,"%s", names[i]);
		
  }
	fclose(fp);
			
for(i=0;i<=MAX;i++){
		if(strstr(names[i],studName)){
			if(strstr(names[i+1],lName)){
			
			//printf("Found!");
			if(strcmp(names[i],studName)==0){
				if(strstr(names[i+1],lName)==0)
					found=1;
					//printf("Found!");	
					return found;
			}else if(strcmp(names[i],studName)!=0){
				if(strstr(names[i+1],lName)!=0){
					found=0;
					return found;
				}
			}
		}
	}
	
}	
	
}
void delUser(){
	int del_line_no;
	int line_no;
	 
	char ch;
	int line;
	line=0;
	//char perToDelfirst;
	//char perToDelsec;
	char str[100];
	FILE *fp;
	fp=fopen("students.txt","r");
	printf("Students before modification: \n");
	while((ch=fgetc(fp))!=EOF){
		
		
		printf("%c",ch);
		if(ch=='\n'){
			line++;
			printf("Line:%d ",line);
		}
		
	}
	printf("Enter line number to delete:");
	scanf("%d",&del_line_no);
	//printf("Enter surname of person to delete:");
	//scanf("%s",perToDelsec);
	
	rewind(fp);

	FILE *fp1;
	fp1=fopen("duplicate.txt","w");
	while(fgets(str,1000,fp)!=NULL){
		line_no++;
		if(line_no!=del_line_no){
			fputs(str,fp1);
		}	
	}
	
	
fclose(fp1);
fclose(fp);
remove("students.txt");
rename("duplicate.txt","students.txt");	
	
	
}

void changePass(){
	system("cls");
	char newPass[100];
	char oldPass[100];
	printf("\nEnter new password:");
	scanf("%s",&newPass);
	
	FILE *fp;
	fp=fopen("password.txt","r");
	fscanf(fp,"%s",oldPass);
	fclose(fp);
	if(strcmp(oldPass,newPass)==0){
		system("COLOR 4");
		Beep(1000,2);
		printf("[!]Error New password cant be the same as old password.");
		sleep(2);
		changePass();
	}else{
		fp=fopen("password.txt","w");
		fprintf(fp,"%s",newPass);
		fclose(fp);
		printf("Password successfully changed! Restart program to see change\n");
		sleep(1);
		showOptionsID();
		
		
	}
	
	
}

void viewRep(){
	FILE *fp;
	int option;
	char str[MAX];
	printf("ENTER TERM IN WHICH EXAM WAS SAT\n 1)SPRING 2)EASTER 3)SUMMER 4)WINTER:");
	scanf("%d",&option);
	switch(option){
		case 1:
			
			fp=fopen("spring.txt","r");
			if(fp==NULL){
				printf("Error opening SPRING semester file!");
				sleep(2);
				controlPanel();
			}else{
				while (fgets(str, MAXCHAR, fp) != NULL)
		        	printf("%s", str);
		    	fclose(fp); 	
			}
			showOptionsID();
			break;
		case 2:
			
			fp=fopen("easter.txt","r");
			if(fp==NULL){
				printf("Error opening EASTER semester file!");
				sleep(2);
				controlPanel();
			}else{
				while (fgets(str, MAXCHAR, fp) != NULL)
		        	printf("EASTER SEMESTER\n%s", str);
		    	fclose(fp); 
				showOptionsID();	
			}
			break;
		case 3:
			fp=fopen("summer.txt","r");
			if(fp==NULL){
				printf("Error opening SUMMER semester file!");
				sleep(2);
				controlPanel();
			}else{
				while (fgets(str, MAXCHAR, fp) != NULL)
		        	printf("SUMMER SEMESTER\n%s", str);
		    	fclose(fp); 	
			}
			showOptionsID();
			break;	
			
		case 4:
			
				fp=fopen("winter.txt","r");
				if(fp==NULL){
					printf("Error opening CHRISTMAS semester file!");
					sleep(2);
					controlPanel();
				}else{
					while (fgets(str, MAXCHAR, fp) != NULL)
			        	printf("CHRISTMAS SEMESTER \n %s", str);
			    	fclose(fp); 	
				}
				showOptionsID();
				break;	
	}
	
}

void mkRep(){
	FILE *sprRep;
	FILE *easRep;
	FILE *summRep;
	FILE *winRep;
	system("cls");
	int verStatus;
	int i;
	int num;
	char subjects[150];
	char sName[100];
	char sID[10];
	int termOpt;
	float avg;
	char form[10];
	char fName[100];
	char lName[100];
	int sum=0;
	int grade;
	char str[1000];
	int choice;
	gotoxy(40,1);
	printf("MYSCHOOLMANCHESTER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD STUDENT GRADES FOR SEMESTER ");
	gotoxy(40,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   Enter Student\'s First and Last Name:");
	gotoxy(40,5);
	scanf("%s %s",&fName,&lName);
	//printf("%s %s",fName,lName);


	verStatus=verifyStud(fName,lName);
	//printf("%d",verStatus);
	if(verStatus==0){
		system("COLOR 3");
		Beep(1300,1000);
		printf("[!]Student not registered ");
		printf("Register Now(1) | Return To Control Panel(2):");
		scanf("%d",&choice);
		if(choice==1){
		
		printf("[*]Fetching registration form");
		sleep(2);
		addStud();}
		else if(choice==2){
			controlPanel();
		}else{
			printf("Invalid option selected! Returning to control panel");
			controlPanel();
		}
	}else if(verStatus!=0){
		printf("Enter term in which exam was sat| SPRING (1) EASTER (2) SUMMER(3) WINTER(4):");
		scanf("%d",&termOpt);
		switch(termOpt){
			case 1:
				//char term[100]="Spring";
				sprRep=fopen("spring.txt","a");
				gotoxy(40,5);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Amount of Subjects Done:");
				scanf("%d",&num);
				gotoxy(40,7);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student ID#:");
				gotoxy(40,9);
				//fflush(stdin);
				scanf("%s",&sID);
				//verifyID(sID);
				gotoxy(40,11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student Form Class:");
				gotoxy(40,12);
				scanf("%s",&form);
				gotoxy(40,14);
				//printf("%s",&fName);
				//printf("%s",&lName);
				
				//printf("%s",&sID);
		
				fprintf(sprRep,"\n\n [*] %s  %s           %s   %s",&fName,&lName,&form,&sID);
		
				printf("Enter the subjects done for the selected term, press enter, then enter the grade associated with the subject above:\n");
				printf("       NOTE: IF SUBJECT HAS TWO NAMES USE AN UNDERSCORE OR HYPHEN INSTEAD OF A SPACE.");
				gotoxy(40,18);
				for(i=0;i<num;i++){
				scanf("%s",&subjects);
				scanf("%d",&grade);
				sum+=grade;
			
				fprintf(sprRep,"\n %s  %d %%",&subjects,grade);
				
				}
				avg=(sum/num);
			
				fprintf(sprRep,"\n %s %s\'s Average For Spring Term Is: %.2f %% ",&fName,&lName,avg);
				fclose(sprRep);
			
				printf("Student grades added to database sucessfully!");
				sleep(2);
				controlPanel();
				break;
			case 2:
				easRep=fopen("easter.txt","a");
				gotoxy(40,5);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Amount of Subjects Done:");
				scanf("%d",&num);
				gotoxy(40,7);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student ID#:");
				gotoxy(40,9);
				//fflush(stdin);
				scanf("%s",&sID);
				//verifyID(sID);
				gotoxy(40,11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student Form Class:");
				gotoxy(40,12);
				scanf("%s",&form);
				gotoxy(40,14);
				//printf("%s",&fName);
				//printf("%s",&lName);
				
				//printf("%s",&sID);
		
				fprintf(easRep,"\n\n [*] %s  %s           %s   %s",&fName,&lName,&form,&sID);
		
				printf("Enter the subjects done for the selected term, press enter, then enter the grade associated with the subject above:\n");
				printf("       NOTE: IF SUBJECT HAS TWO NAMES USE AN UNDERSCORE OR HYPHEN INSTEAD OF A SPACE.");
				gotoxy(40,18);
				for(i=0;i<num;i++){
				scanf("%s",&subjects);
				scanf("%d",&grade);
				sum+=grade;
			
				fprintf(easRep,"\n %s  %d %%",&subjects,grade);
				
				}
				avg=(sum/num);
			
				fprintf(easRep,"\n %s %s\'s Average For Easter Term Is: %.2f %% ",&fName,&lName,avg);
				fclose(easRep);
			
				printf("Student grades added to database sucessfully!");
				sleep(2);
				controlPanel();
				break;
			case 3:
				summRep=fopen("summer.txt","a");
				gotoxy(40,5);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Amount of Subjects Done:");
				scanf("%d",&num);
				gotoxy(40,7);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student ID#:");
				gotoxy(40,9);
				//fflush(stdin);
				scanf("%s",&sID);
				//verifyID(sID);
				gotoxy(40,11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student Form Class:");
				gotoxy(40,12);
				scanf("%s",&form);
				gotoxy(40,14);
				//printf("%s",&fName);
				//printf("%s",&lName);
				
				//printf("%s",&sID);
		
				fprintf(summRep,"\n\n [*] %s  %s           %s   %s",&fName,&lName,&form,&sID);
		
				printf("Enter the subjects done for the selected term, press enter, then enter the grade associated with the subject above:\n");
				printf("       NOTE: IF SUBJECT HAS TWO NAMES USE AN UNDERSCORE OR HYPHEN INSTEAD OF A SPACE.");
				gotoxy(40,18);
				for(i=0;i<num;i++){
				scanf("%s",&subjects);
				scanf("%d",&grade);
				sum+=grade;
			
				fprintf(summRep,"\n %s  %d %%",&subjects,grade);
				
				}
				avg=(sum/num);
			
				fprintf(summRep,"\n %s %s\'s Average For Summer Term Is: %.2f %% ",&fName,&lName,avg);
				fclose(summRep);
			
				printf("Student grades added to database sucessfully!");
				sleep(2);
				controlPanel();
				break;
			case 4:
				winRep=fopen("winter.txt","a");
				
				gotoxy(40,5);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Amount of Subjects Done:");
				scanf("%d",&num);
				gotoxy(40,7);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student ID#:");
				gotoxy(40,9);
				//fflush(stdin);
				scanf("%s",&sID);
				//verifyID(sID);
				gotoxy(40,11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    Enter Student Form Class:");
				gotoxy(40,12);
				scanf("%s",&form);
				gotoxy(40,14);
				//printf("%s",&fName);
				//printf("%s",&lName);
				
				//printf("%s",&sID);
		
				fprintf(winRep,"\n\n [*] %s  %s           %s   %s",&fName,&lName,&form,&sID);
		
				printf("Enter the subjects done for the selected term, press enter, then enter the grade associated with the subject above:\n");
				printf("       NOTE: IF SUBJECT HAS TWO NAMES USE AN UNDERSCORE OR HYPHEN INSTEAD OF A SPACE.");
				gotoxy(40,18);
				for(i=0;i<num;i++){
				scanf("%s",&subjects);
				scanf("%d",&grade);
				sum+=grade;
			
				fprintf(winRep,"\n %s  %d %%",&subjects,grade);
				
				}
				avg=(sum/num);
			
				fprintf(winRep,"\n %s %s\'s Average For Christmas Term Is: %.2f %% ",&fName,&lName,avg);
				fclose(winRep);
			
				printf("Student grades added to database sucessfully!");
				sleep(2);
				controlPanel();
				break;
			default:
				printf("Invalid Option Selected!\n");
				showOptionsID();				
		}
	}
}


