	
							// Zhuo Wei En  178002002  D...

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <functional>
#include <ctime>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <stdlib.h>  
#include <windows.h>
#include <conio.h>

using namespace std;

//Declaration
unsigned int seconds = 5;

//Declaring  a Class
class employee
{
	private :

		//Declaration : Variables for employee details & Interaction with User
        char name[99][35];
        char id[99][8];
        char designation[99][25];
        char age[99][3];
		char salary[99][12];
		char experience[99][3];
		char gender[99][2];
		char checkName[35];
		char checkId[8];
		char checkDesignation[25];
		char checkAge[3];
		char checkSalary[12];
		char checkExp[3];
		int n;
		int i;
		int userChoice;
		int isRemoved;
		int isRenamed;


        // Utility functions
        void waitForEnter(void)
		{
			cout << endl;
            cout << " \n \n \n Press enter to go back \n \n ";
            cin.get();
            cin.get();
        }


		//1st Function to Create records in the file
		void initial(void)		
		{
		system("cls");
				cout << endl;
		cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "----------------------------------------------Creating Data Base---------------------------------------------" << endl;
		Sleep(300);
		cout<<"Enter the total number of the DMA employees " << endl;
			//Assignement
			cin >> n ;				// n is the size of the number of employees 
			//Conditional Testing
				//If Statement
				if ( (n>99) || (n<1) )	//To make sure user inputs a correct number
				{	
					Sleep(300);
					cout << endl
						 << "You entered a wrong number : n cannot be greater than 99 nor less than 1" << endl;
					Sleep(500);
					cout << " \t \t System will restart automatically" << endl;
					Sleep(1500);
					initial(); 
				}	
			cout<< endl << "Enter the data of the employees ";
				
				//Loop Structure to save the employees data in the variables	
			for (i=0; i<n; i++)
			{
							cout << endl;
				cin.ignore();
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Name of Employee " << i+1 << " : ";
						cin.getline(name[i],35);
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " ID [max 4 digits] : ";
						cin.getline(id[i],8);
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " Designation: ";
						cin.getline(designation[i],25);
				cout <<" \n-------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " Age: ";
						cin.getline(age[i],3);
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " Salary: ";
						cin.getline(salary[i],12);
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " Experience's years: ";
						cin.getline(experience[i],3);
				cout << " \n------------------------------------------------------------";
					cout << " \n Enter Employee " << i+1 << " Gender [M or F]: ";
						cin.getline(gender[i],2);
			}
				Sleep(300);
				char ch;
				cout << endl << " \n \t Enter 'yes' to save above information \n";
					cin >> ch;

				if((ch=='yes') || (ch=='Yes') || (ch=='YES') || (ch=='y') || (ch=='Y'))
				{
					//Loop Structure to transfer the employees data to the file 
					for (i=0; i<n; i++)
					{
						FILE  *file;
						file= fopen("data.txt","a");
						fprintf(file, "%s %s %s %s %s %s %s \n", name[i], id[i], designation[i], age[i], salary[i], experience[i], gender[i] );
						fclose(file);
					}
						Sleep(500);
						cout << endl << " \n \t Employees have been added to database";
						Sleep(500);
						waitForEnter();
				}
				else
				{
					cout << " \n You must Enter 'yes' to save above information \n" << endl;
					Sleep(500);
					cout << " \t \t \t System will restart automatically" << endl;
					Sleep(1500);
					initial();
				}
			}

		//2nd Function to Output the data from the file
		void output(void)
        {
		system("cls");
		FILE *file;
				cout << endl;
		cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "---------------------------------------------------------Accessing Data Base-------------------------------------------------------------" << endl;
		Sleep(300);
		cout << " \n \t \t \t \t \t      List of Employees \n";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
			//Loop Structure to output the employees data from to the file
				file= fopen("data.txt", "r");
				while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!= EOF)
					{
						cout << " \n " << setw(11) << *name << " \t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
							 << "\t \t" << setw(5) << *age << " \t \t " << setw(7) << *salary << "\t" << setw(4) 
							 << *experience << "\t \t" << setw(5) << *gender << endl;
						Sleep(300);
					}
				fclose(file);
            waitForEnter();
        }

		//3rd Function to Search an employee's data from the database (file)
		void search(void)
		{ 
        system("cls");
		FILE *file;
				cout << endl;
		cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "-----------------------------------------------Search Operation-------------------------------------------------" << endl;
		Sleep(300);
			cout << " \n "
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   1:   To Search for an employee's Name"
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   2:   To Search for an employee's Id"
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   3:   To Search for an employee's Designation"
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   4:   To Search for an employee's Age"
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   5:   To Search for an employee's Salary"
					 << " \n \t \t \t ---------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   6:   To Search for an employee Experience's years"
					 << " \n \t \t \t ---------------------------------------------------------------" << endl;
			Sleep(200);
                cout << " \n \n \t \t \t   Please Enter Your Choice: ";
			//Assignement
			cin >> userChoice ;		// let the user decide what he wants to do
			Sleep(300);

			switch(userChoice)
			{
				case 1:					//Displays all details according to Employee's name
  					    system("cls");
						cout << " \n \n Enter Employee's Name: ";
							cin>>checkName;
						file= fopen("data.txt", "r");
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkName,name[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender << endl;
									goto conclusive1;
							}
						}
	
						if(strcmp(checkName,name[0])!=0)
							{
								cout << endl << "Search inconclusive, the Name does not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive1 : ;
						fclose(file);
						waitForEnter();
                        break;
                   case 2:				//Displays all details according to Employee's id
					    system("cls");
						cout << " \n \n Enter Employee's ID: ";
							cin>>checkId;
						file= fopen("data.txt", "r");
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkId,id[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender << endl;
									goto conclusive2;
							}
						}
	
						if(strcmp(checkId,id[0])!=0)
							{
								cout << endl << "Search inconclusive, the Id does not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive2 : ;
						fclose(file);
						waitForEnter();
                        break;
                   case 3:				//Displays all details according to Employee's designation
  					    system("cls");
						cout << " \n \n Enter Employee's Designation: ";
							cin>>checkDesignation;
						file= fopen("data.txt", "r");
						cout << " \n----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkDesignation,designation[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender << endl;
									goto conclusive3;
							}
						}
	
						if(strcmp(checkDesignation,designation[0])!=0)
							{
								cout << endl << "Search inconclusive, the Designation does not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive3 : ;
						fclose(file);
						waitForEnter();
						system("cls");
                        break;
                   case 4:				//Displays all details according to Employee's age
						system("cls");
						cout << " \n \n Enter Employee's Age: ";
							cin>>checkAge;
						file= fopen("data.txt", "r");
						cout << " \n----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkAge,age[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender << endl;
									goto conclusive4;
							}
						}
	
						if(strcmp(checkAge,age[0])!=0)
							{
								cout << endl << "Search inconclusive, the Age does not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive4 : ;
						fclose(file);
						waitForEnter();
						system("cls");								
                        break;
				   case 5:					//Displays all details according to Employee's salary
  					    system("cls");
						cout << " \n \n Enter Employee's Salary: ";
							cin>>checkSalary;
						file= fopen("data.txt", "r");
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkSalary,salary[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender<< endl;
									goto conclusive5;
							}
						}
	
						if(strcmp(checkSalary,salary[0])!=0)
							{
								cout << endl << "Search inconclusive, the Salary does not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive5 : ;
						fclose(file);
						waitForEnter();
						system("cls");								
                        break;
				   case 6:					//Displays all details according to Employee experience's years
  					    system("cls");
						cout << " \n \n Enter Employee Experience's years: ";
							cin>>checkExp;
						file= fopen("data.txt", "r");
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
						cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
						while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
						{
							if(strcmp(checkExp,experience[0])==0)
							{
									cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
										 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
										 << *experience << "\t \t" << setw(5) << *gender << endl;
									goto conclusive6;
							}
						}
	
						if(strcmp(checkExp,experience[0])!=0)
							{
								cout << endl << "Search inconclusive, the Years of Experience do not belong to the database." << endl << endl;
								Sleep(200);
							}
						conclusive6 : ;
						fclose(file);
						waitForEnter();
						system("cls");								
                        break;
                    default:
                        cout << " \n \t \t \t Sorry! I don't understand that! \n";
						Sleep(500);
						cout << " \t \t \t \t System will restart automatically" << endl;
						Sleep(1500);
                        break;

			}
        }

			// Function to Search an employee's name from the database for the Functions Modify and Delete
			void sModDelName(void)
			{ 
			system("cls");
			FILE *file;
					cout << endl;
			Sleep(300);
				cout << " \n \t \t \t --------------------------------------------------------------------------------------------" ; Sleep(300);
					cout << " \n \n Enter Employee's Name: ";
								cin>>checkName;
				Sleep(200);
					//Displays all details according to Employee's name
							file= fopen("data.txt", "r");
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
							{
								if(strcmp(checkName,name[0])==0)
								{
										cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
											 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
											 << *experience << "\t \t" << setw(5) << *gender << endl;
										goto conclusive1;
								}
							}
	
							if(strcmp(checkName,name[0])!=0)
								{
									cout << endl << "Search inconclusive, the Name does not belong to the database." << endl << endl;
									Sleep(200);
								}
							conclusive1 : ;
							fclose(file);
			}

			// Function to Search an employee's id from the database for the Functions Modify and Delete
			void sModDelId(void)
			{ 
			system("cls");
			FILE *file;
					cout << endl;
			Sleep(300);
				cout << " \n \t \t \t --------------------------------------------------------------------------------------------" ; Sleep(300);
					cout << " \n \n Enter Employee's ID: ";
								cin>>checkId;
				Sleep(200);
					//Displays all details according to Employee's id
							file= fopen("data.txt", "r");
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
							{
								if(strcmp(checkId,id[0])==0)
								{
										cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
											 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
											 << *experience << "\t \t" << setw(5) << *gender << endl;
										goto conclusive2;
								}
							}
	
							if(strcmp(checkId,id[0])!=0)
								{
									cout << endl << "Search inconclusive, the ID does not belong to the database." << endl << endl;
									Sleep(200);
								}
							conclusive2 : ;
							fclose(file);
			}

			// Function to Search an employee's designation from the database for the Functions Modify and Delete
			void sModDelDesignation(void)
			{ 
			system("cls");
			FILE *file;
					cout << endl;
			Sleep(300);
				cout << " \n \t \t \t --------------------------------------------------------------------------------------------" ; Sleep(300);
					cout << " \n \n Enter Employee's Designation: ";
								cin>>checkDesignation;
				Sleep(200);
					//Displays all details according to Employee's designation
							file= fopen("data.txt", "r");
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							cout << " \n       Name		      |    ID    |      Designation        |     Age      |    Salary   |    Experience   |      Gender  ";
							cout << " \n-----------------------------------------------------------------------------------------------------------------------------------";
							while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
							{
								if(strcmp(checkDesignation,designation[0])==0)
								{
										cout << "\n" << setw(11) << *name << "\t \t \t" << setw(7) << *id << "\t \t" << setw(11) << *designation 
											 << "\t \t" << setw(5) << *age << "\t \t" << setw(7) << *salary << "\t \t" << setw(5) 
											 << *experience << "\t \t" << setw(5) << *gender << endl;
										goto conclusive3;
								}
							}
	
							if(strcmp(checkDesignation,designation[0])!=0)
								{
									cout << endl << "Search inconclusive, the Designation does not belong to the database." << endl << endl;
									Sleep(200);
								}
							conclusive3 : ;
							fclose(file);
			}


		//4th Function to Modify an existing employee's data in the data base (file)
			//Modifying records according to Name
			void modifyName(void)
			{
            char ch;
			char newName[35];
			char newId[8];
			char newDesignation[25];
			char newAge[3];
			char newSalary[12];
			char newExperience[3];
			char newGender[2];
			bool checked1;
			Sleep(300);
				cout << endl
					 << " \n----------------------------------------------------Modify Operation--------------------------------------------" << endl
					 << " \n Enter Employee's Name again to Modify the records  "; 
				cin >> checkName;
			Sleep(300);	
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
				{
					if((strcmp(checkName, name[0]))==0)
					{
						checked1 = true;
						Sleep(300);		
						cout << endl;
							cin.ignore();
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Name of Employee : ";
								cin >> newName;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New ID of Employee [max 4 digits] : ";
								cin >> newId;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Designation of Employee : ";
								cin >> newDesignation;
						cout <<" \n-------------------------------------------------------------";
						cout << " \n Enter New Age of Employee : ";
								cin >> newAge;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Salary of Employee : ";
								cin >> newSalary;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter  New Experience's years of Employee : ";
								cin >> newExperience;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee's Gender [M or F]: ";
								cin >> newGender;
						cout << " \n------------------------------------------------------------";

						fprintf(tempfile, "%s %s %s %s %s %s %s \n", newName, newId, newDesignation, newAge, newSalary, newExperience, newGender);
					}
					else
					{
						fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
						checked1 = false;
					}
				}
			if(checked1==false) 
			{
						cout << endl << "Search inconclusive, the Name does not belong to the database." << endl << endl;
							Sleep(500);
			}
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            Sleep(500);
			}
			//Modifying records according to Id
			void modifyId(void)
			{
            char ch;
			char newName[35];
			char newId[8];
			char newDesignation[25];
			char newAge[3];
			char newSalary[12];
			char newExperience[3];
			char newGender[2];
			bool checked2;
			Sleep(300);
				cout << endl
					 << " \n----------------------------------------------------Modify Operation---------------------------------------------" << endl
					 << " \n Enter Employee's Id again to Modify the records  "; 
				cin >> checkId;
			Sleep(300);
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
				{
					if((strcmp(checkId, id[0]))==0)
					{
						checked2 = true;
						Sleep(300);
						cout << endl;
							cin.ignore();
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Name of Employee : ";
								cin >> newName;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New ID of Employee [max 4 digits] : ";
								cin >> newId;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Designation of Employee : ";
								cin >> newDesignation;
						cout <<" \n-------------------------------------------------------------";
						cout << " \n Enter New Age of Employee : ";
								cin >> newAge;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Salary of Employee : ";
								cin >> newSalary;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter  New Experience's years of Employee : ";
								cin >> newExperience;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee's Gender [M or F]: ";
								cin >> newGender;
						cout << " \n------------------------------------------------------------";
						
						fprintf(tempfile, "%s %s %s %s %s %s %s \n", newName, newId, newDesignation, newAge, newSalary, newExperience, newGender);
					}
					else
					{
						fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
						checked2 = false;
					}
				}
			if(checked2==false) 
			{
						cout << endl << "Search inconclusive, the Id does not belong to the database." << endl << endl;
							Sleep(500);
			}
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            Sleep(500);
			}
			//Modifying records according to Designation
			void modifyDesignation(void)
			{
            char ch;
			char newName[35];
			char newId[8];
			char newDesignation[25];
			char newAge[3];
			char newSalary[12];
			char newExperience[3];
			char newGender[2];
			bool checked3;
			Sleep(300);
				cout << endl
					 << " \n----------------------------------------------------Modify Operation---------------------------------------------" << endl
					 << " \n Enter Employee's Designation again to Modify the records  "; 
				cin >> checkDesignation;
			Sleep(300);
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
				{
					if((strcmp(checkDesignation, designation[0]))==0)
					{
						checked3 = true;
						Sleep(300);
						cout << endl;
							cin.ignore();
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Name of Employee : ";
								cin >> newName;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New ID of Employee [max 4 digits] : ";
								cin >> newId;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Designation of Employee : ";
								cin >> newDesignation;
						cout <<" \n-------------------------------------------------------------";
						cout << " \n Enter New Age of Employee : ";
								cin >> newAge;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter New Salary of Employee : ";
								cin >> newSalary;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter  New Experience's years of Employee : ";
								cin >> newExperience;
						cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee's Gender [M or F]: ";
								cin >> newGender;
						cout << " \n------------------------------------------------------------";

						fprintf(tempfile, "%s %s %s %s %s %s %s \n", newName, newId, newDesignation, newAge, newSalary, newExperience, newGender);
					}
					else
					{
						fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
						checked3 = false;
					}
				}
			if(checked3==false) 
			{
						cout << endl << "Search inconclusive, the Designation does not belong to the database." << endl << endl;
							Sleep(500);
			}

            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            Sleep(500);
			}

		//Modifying records (Main Function amongst Modify Functions)
		void modifyRecords(void)
		{
		system("cls");
			cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "--------------------------------------------------Modifying DataBase---------------------------------------------" << endl;
		Sleep(300);
			cout << " \n "
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   1:   To search for an employee's Name then Modify the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   2:   To Search for an employee's Id then Modify the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   3:   To Search for an employee's Designation then Modify the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" << endl;	
				Sleep(200);
                cout << " \n \n \t \t \t   Please Enter Your Choice: ";
			//Assignement
			cin >> userChoice ;		// let the user decide what he wants to do
			Sleep(300);

			switch(userChoice)
			{
				case 1:	
						system("cls");
						sModDelName();
						cout << endl;
						modifyName();
                        break;
						waitForEnter();
				case 2:
						system("cls");
						sModDelId();
						cout << endl;
						modifyId();
						break;
						waitForEnter();
				case 3:
						system("cls");
						sModDelDesignation();
						cout << endl;
						modifyDesignation();
						break;
						waitForEnter();
				default:
						cout << " \n \t \t \t Sorry! I don't understand that! \n";
						Sleep(500);
						cout << " \t \t \t \t System will restart automatically" << endl;
						Sleep(1500);
						break;
			}
		}


		//5th Function to Insert a new employee's records in the data base (file)
		void insert(void)				//adding records
		{
			system("cls");
				cout << endl;
		cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "--------------------------------------------------Inserting New Data--------------------------------------------" << endl;
		Sleep(300);
		cout<<"Enter the total number of the DMA employees you want to insert " << endl;
			//Assignement
			cin >> n ;				// n is the size of the number of employees 
			//Conditional Testing
				//If Statement
				if ( (n>99) || (n<1) )	//To make sure user inputs a correct number
				{	
					Sleep(300);
					cout << "You entered a wrong number : n cannot be greater than 99 nor less than 1" << endl;
					Sleep(500);
					cout << " \t \t System will restart automatically " << endl;
					Sleep(1500);
					insert(); 
				}	
			cout<< endl << "Enter the data of the employees ";
				
				//Loop Structure to save the employees data in the variables
				for (i=0; i<n; i++)
				{				cout << endl;
					cin.ignore();
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter Name of new Employee : ";
							cin.getline(name[i],35);
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter new Employee's ID [max 4 digits] : ";
							cin.getline(id[i],8);
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter new Employee's Designation: ";
							cin.getline(designation[i],25);
					cout <<" \n-------------------------------------------------------------";
						cout << " \n Enter new Employee's Age: ";
							cin.getline(age[i],3);
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee's Salary: ";
							cin.getline(salary[i],12);
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee Experience's years: ";
							cin.getline(experience[i],3);
					cout << " \n------------------------------------------------------------";
						cout << " \n Enter Employee's Gender [M or F]: ";
							cin.getline(gender[i],2);
				}
			Sleep(300);
            char ch;
            cout << endl << " \n \t Enter 'yes' to save above information \n";
				cin>>ch;
            if((ch=='yes') || (ch=='Yes') || (ch=='YES') || (ch=='y') || (ch=='Y'))
			{
					//Loop Structure to transfer the employees data to the file 
					for (i=0; i<n; i++)
					{
						FILE  *file;
						file= fopen("data.txt","a");
						fprintf(file, "%s %s %s %s %s %s %s \n", name[i], id[i], designation[i], age[i], salary[i], experience[i], gender[i] );
						fclose(file);
					}
						Sleep(500);
						cout << endl << " \n \t New Employees have been added to database \n";
						Sleep(500);
						waitForEnter();
				}
				else
				{
					cout << " \n You must Enter 'yes' to save above information \n" << endl;
					Sleep(500);
					cout << " \t \t \t System will restart automatically" << endl;
					Sleep(1500);
					insert();
				}
        }

		//6th Function to Remove an employee's records from the database (file)
			//Removing records according to Id
			void deleteId()
			{
				char ch;
				Sleep(300);
				cout << endl
					 << " \n---------------------------------------------------Delete Operation----------------------------------------------" << endl
					 << " \n Enter Employee's Id again to Remove the records : "; 
				cin >> checkId;
				Sleep(300);
				FILE *file, *tempfile;
				file= fopen("data.txt", "r");
				tempfile= fopen("temp.txt", "w");
				while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
				{
					if(strcmp(checkId, id[0])!=0)
					{
							fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
					}
				}
				fclose(file);
				fclose(tempfile);
				int isRemoved= remove("data.txt");
				int isRenamed= rename("temp.txt", "data.txt");
				cout << " \n Output the List to check if Employee's records has successfully been removed \n ";
				Sleep(300);
					waitForEnter();
			}
			//Removing records according to Name
			void deleteName()
			{
				char ch;
				Sleep(300);
				cout << endl
					 << " \n---------------------------------------------------Delete Operation----------------------------------------------" << endl
					 << " \n Enter Employee's Name again to Remove the records : "; 
				cin >> checkName;
				Sleep(300);
					FILE *file, *tempfile;
					file= fopen("data.txt", "r");
					tempfile= fopen("temp.txt", "w");
					while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
					{
						if(strcmp(checkName, name[0])!=0)
						{
								fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
						}
					}
				fclose(file);
				fclose(tempfile);
				int isRemoved= remove("data.txt");
				int isRenamed= rename("temp.txt", "data.txt");
				cout << " \n Output the List to check if Employee's records has successfully been removed \n ";
				Sleep(300);
					waitForEnter();
			}
			//Removing records according to Designation
			void deleteDesignation(void)
			{
				char ch;
				Sleep(300);
				cout << endl
					 << " \n---------------------------------------------------Delete Operation----------------------------------------------" << endl
					 << " \n Enter Employee's Designation again to Remove the records : "; 
				cin >> checkDesignation;
				Sleep(300);
					FILE *file, *tempfile;
					file= fopen("data.txt", "r");
					tempfile= fopen("temp.txt", "w");
					while(fscanf(file, "%s %s %s %s %s %s %s", &name[0], &id[0] , &designation[0], &age[0], &salary[0], &experience[0], &gender[0])!=EOF)
					{
						if(strcmp(checkDesignation, designation[0])!=0)
						{
								fprintf(tempfile, "%s %s %s %s %s %s %s \n", name, id, designation, age, salary, experience, gender);
						}
					}
				fclose(file);
				fclose(tempfile);
				int isRemoved= remove("data.txt");
				int isRenamed= rename("temp.txt", "data.txt");
				cout << " \n Output the List to check if Employee's records has successfully been removed \n ";
				Sleep(300);
					waitForEnter();
			}

		//Removing records (Main Function amongst Delete Function)
		void deleteRecords(void)
		{
		system("cls");
			cout << "\t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
			cout << "\n \t \t \t >>>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<" << endl << endl;
		Sleep(300);
		cout << "-------------------------------------------------Delete Operation--------------------------------------------------" << endl;
		Sleep(300);
			cout << " \n "
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   1:   To search for an employee's Name then Delete the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   2:   To Search for an employee's Id then Delete the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   3:   To Search for an employee's Designation then Delete the records"
					 << " \n \t \t \t -----------------------------------------------------------------------------------" << endl;	
				Sleep(200);
                cout << " \n \n \t \t \t   Please Enter Your Choice: ";
			//Assignement
			cin >> userChoice ;		// let the user decide what he wants to do
			Sleep(300);

			switch(userChoice)
			{
				case 1:	
						system("cls");
						sModDelName();
						cout << endl;
						deleteName();
                        break;
						waitForEnter();
				case 2:
						system("cls");
						sModDelId();
						cout << endl;
						deleteId();
						break;
						waitForEnter();
				case 3:
						system("cls");
						sModDelDesignation();
						cout << endl;
						deleteDesignation();
						break;
						waitForEnter();
				default:
						cout << " \n \t \t \t Sorry! I don't understand that! \n";
						Sleep(500);
						cout << " \t \t \t \t System will restart automatically" << endl;
						Sleep(1500);
						break;
			}
		}
		

	public:
        // Function to serve as end point
        void options(void)					//menu
		{
        int login();		//login declaration
                login();	//login screen
            while(true)
			{
                system("cls");
				Sleep(300);
                // Options to choose an action : menu
						cout << endl <<endl;
		cout << " \t" << "\t" << "\t" << "\t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
		Sleep(300);
			cout << " \n \t \t \t >>>>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<<<" << endl << endl;
		Sleep(300);
                cout << " \n "
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   1:   To Create List of Employees"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   2:   To View Employees Data"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   3:   To Search one specific Employee's Data"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   4:   To Modify Existing Employee Data"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   5:   To Insert New Employee Data"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   6:   To Remove an Employee Data"
					 << " \n \t \t \t ----------------------------------------------------------" ; Sleep(300);
				cout << " \n \t \t \t ENTER   0:   To Exit     "
					 << " \n \t \t \t ----------------------------------------------------------" << endl;
				Sleep(200);
                cout << " \n \n \t \t \t   Please Enter Your Choice: ";

                // Taking the action input
                int choice;
					//Assignement
					cin>>choice;			//let the user decide what to do
                // Conditional Testing
                switch (choice) 
				{
                   case 0:
                    	system("cls");
						Sleep(300);
						cout << endl << endl;
						Sleep(300);
                        cout << " \n \n \t \t \t Data Management Algorithms by D . . . \n \n ";
                        Sleep(1000);
                        return;
                   case 1:
					    system("cls");
                        initial();
                        break;
                   case 2:
						system("cls");
                        output();
                        break;
                   case 3:
						system("cls");
                        search();
                        break;
                    case 4:
						system("cls");
						modifyRecords();
                        break;
                    case 5:
						system("cls");
                        insert();
                        break;
					case 6:
						system("cls");
						deleteRecords();
						break;
                    default:
						Sleep(300);
                        cout << " \n \t \t \t Sorry! I don't understand that! \n";
						Sleep(500);
						cout << " \t \t \t \t System will restart automatically" << endl;
						Sleep(1500);
                        break;
                }

            }
        }

};

//Some Other Utility Functions
void fail()		//Function Fail when the user input a wrong password
{ 
    // system call to clear the screen 
    system("cls"); 
	cout << endl << endl;
	cout << "\n \n \t \t \t Access Aborted ... You entered a wrong password \n";
			cout << " \n \t \t \t \t System will automatically restart in  "
				 << setfill('0') << setw(2) << seconds << " sec " << endl; 
} 
void timerFail() 
{
//Conditional Testing
	//Loop
    while (seconds>=0)		// infinte loop because timer will keep counting down
	{ 
          
        // display the timer 
        fail(); 
  
        // sleep system call to sleep   
        Sleep(700); 
  
        // decrement seconds 
        seconds--; 
		//If Statement
		if (seconds==0)			//LoopHole to exist the loop, stop the ietration when the timer reaches 0
		{
			seconds =5;
			goto down;			//Using Conditional Branching to Exit the loop
		}
    }
	down : ;
} 

//Main Function
int main ()
{
//Declaration
	//Using Class type
	employee e;

//Calling Function
 e.options();

	return 0;
}
//Sub-Function
int login()				//login procedure
{
   string pass ="";
   char ch;
   cout << endl << endl;
	cout << " \n \n \t \t \t \t" << "Welcome to Data Management Algorithms by D..." << endl << endl;
	cout << " \n \t \t \t >>>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<<< " << endl << endl;
		cout << " \n \n \n \t \t \t \t \t Enter Your Password :";
   ch = _getch();
   while(ch != 13)		//character 13 taken as enter
   {
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "1234")																				
   {
   		cout << " \n \n \n \t \t \t \t \t LOADING \n \t \t \t \t \t ";
   		for(int a=0;a<8;a++) 
		{
			Sleep(500);
			cout << "...";
		}
		  cout << " \n \n \n \t \t \t \t \t \t Access Granted!! \n \n \n " << endl;
		  Sleep(1000);
		  system("cls");
   }
   else
   {	
		timerFail();
		Sleep(500);
		system("cls");
		login();
   }
   return 0;
}

