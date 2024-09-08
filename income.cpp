#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct user{
	char name[20], email[30];
	int age;
	long int income;
	float tax;
}; int enroll_no = 1000;
struct user taxpayer;
void new_record(){
	FILE *fp = fopen("user_data.txt", "a");
	if(fp == NULL){
		puts("ERROR!!\n");
		exit(1);
	}
	float tax;
	printf("Add new record\n");
	printf("Enter name: ");
	gets(taxpayer.name);
	printf("Enter email: ");
	gets(taxpayer.email);
	printf("Enter age: ");
	scanf("%d", &taxpayer.age);
	printf("Enter income: ");
	scanf("%d", &taxpayer.income);
	if(taxpayer.income<=250000){
		printf("NO TAX");
	}
	else if(250000<taxpayer.income<=500000){
		tax = taxpayer.income*0.05;
	}
	else if(500000<taxpayer.income<=100000){
		tax = taxpayer.income*0.20;
	}
	else{
		tax = taxpayer.income*0.30;
	}
	fprintf(fp,"%s\n %s\n %d\n %d\n %d", taxpayer.name, taxpayer.email, taxpayer.age, taxpayer.income, taxpayer.tax);
	printf("Your tax is %.2f\n", tax);
	printf("Congratulation your enrollment no is: %d", enroll_no+1);
	enroll_no++;
	fclose(fp);
}
void list()
{
	struct user {
		char name[50];
		char email[50];
		int age;
		long int income;
	} taxpayer;

	FILE *fp = fopen("user_data.txt","rb");
	if(fp == NULL){
		printf("ERROR!!\n");
		exit(1);
	}
	
	while(fscanf(fp,"%s %s %d %ld",taxpayer.name,taxpayer.email,&taxpayer.age, &taxpayer.income)!=EOF){
		printf("%s\n %s\n %d\n %ld\n", taxpayer.name, taxpayer.email, taxpayer.age, taxpayer.income);
	}
	
	fclose(fp);
}

void search(){
	FILE *fp = fopen("user_data.txt","r");
	if(fp == NULL){
		puts("ERROR!!\n");
		exit(1);
	}
	int enroll_num;
	char name[50], email[50];
	int age;
	long int income;
	float tax;
	printf("Enter enroll no want to search: ");
	scanf("%d",&enroll_num);
	while(fscanf(fp,"%s %s %d %ld %f", name, email, &age, &income, &tax)!=EOF){
		if(enroll_num == enroll_no){
			printf("Name: %s\n", name);
			printf("Email: %s\n", email);
			printf("Age: %d\n", age);
			printf("Income: %ld\n", income);
			printf("Tax: %f\n", tax);
			return;
		}
	}
	printf("No record found for the entered enroll no.\n");
	fclose(fp);
}





int main() {
  int choice;
 

  while (1) {
    printf("\n                                     ==== Income Tax Calculator ====             \n");
    printf("1. Add New Record\n");
    printf("2. List Of All Tax Payer\n");
    printf("3. Search Record\n");
    printf("4. Edit Record\n");
    printf("5. Delete Record\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    getchar(); 

    switch (choice) {
      case 1:
        new_record();
        break;
      case 2:
      	list();
      case 3:
	  	search();	
      	break;
    	case 4:
        printf("Thank you for using our income tax calculator. Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}
