
/* A Mini Project By Harshvardhan Pardeshi*/

/* Copyright (C) 2021 Harshvardhan Pardeshi - All Rights Reserved
 * 
 * Project Description :This project is aimed at helping out doctors in preparing diagnosis
 *	and screening out corona patients from the patients having some other health problems
 * 
 * Date last modified :March 28th 2021
 */

#include<iostream>
#include<stdlib.h>
#include<ios>																		
#include<string>
#include<iomanip>																	

using namespace std;

//Primary Base Class

class patient {																	

protected:

	string name, address, email_id;												
	long long int mob_no;
	int mob_no_check;
	int age;


public:

	patient() {																	// patient class constructor
		name = "UNKNOWN";
		address = "UNKNOWN";
		email_id = "UNKNOWN";
		mob_no = 0;
		mob_no_check = 0;
		age = 0;
	}

	void getdata();                   //class methods prototypes								
};

void patient::getdata() {

	cin.ignore(numeric_limits<streamsize>::max(), '\n');         //clearing input buffer
	
	int q1;
	do {
		q1 = 0;
		cout << "Enter the name of the patient : \n ->";													
		getline(cin, name);
		
		if (name.size() < 3) {											//to check correct name input				
			q1 += 1;
			cout << "Please Enter a Valid Name!!" << endl << endl;
		}
	} while (q1 != 0);

	cout << endl << "Enter the address of the patient :\n -> ";
	getline(cin, address);

	cout << endl << "Enter the Email ID of the patient :\n -> ";
	getline(cin, email_id);

	int q2;
	do {
		q2 = 0;
		cout << endl << "Enter the Mobile Number of the patient :\n -> ";		//to check correct mobile number input
		cin >> mob_no;

		mob_no_check = mob_no / 1000000000;


		if (mob_no_check < 1 || mob_no_check>=10) {
			q2 += 1;
			cout << "Please enter a 10 digit valid mobile number!!" << endl;
		}
	} while (q2!=0);

	int q3;

	do {
		q3 = 0;
		cout << endl << "Enter the age of the patient :\n -> ";
		cin >> age;																		
																				
		if (age <= 0 || age >105) {										// to check correct age input
			q3 += 1;
			cout << "Please enter valid age!!" << endl;
		}
	} while (q3!=0);




	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl << "Data Entry Complete!!!" << endl;
	cout << endl << "Press Enter key to Continue....";
	cin.ignore();

	system("CLS");			//Clear Screen
}

class patient_details : public patient {					//derived class 1 (Base class = patient)

protected:

	//required set of variables

	bool dry_cough;		
	bool dyspnea;      //Problem in Breathing
	float fever;
	int SPO2_level;		//Blood oxygen level

	int c_info;	       //variable for checking how many cases true and display statements accordingly

	bool SPO2_severe;  // if severe then true, else false  //responsible case3
	bool fever_status; // if fever then true,else false		//responsible case4

public:

	patient_details() {                  //derived class constructor
		dry_cough = false;
		dyspnea = false;
		fever = 0.0;
		SPO2_level = 0;
		SPO2_severe = true;
		fever_status = false;
		c_info = 0;
	}

	void patient_examination();				//Method Prototypes
	void check_fever();
	void check_SPO2();
	void check_chances();
	void display_cinfo();  
};

void patient_details::patient_examination() {

	char response1;								//variables for checking Dry cough					
	int check1 = 0;												

	do {
		cout << "Dry cough ?? Y/N  -> ";					
		cin >> response1;
																		
		if (response1 == 'Y' || response1 == 'y') {			//Testing Dry Cough
			dry_cough = true;									
			check1 += 1;
		}
		else if (response1 == 'N' || response1 == 'n') {
			dry_cough = false;
			check1 += 1;
		}
		else cout << endl << "Wrong input!! Try again...";
	} while (check1 != 1);

	char response2;								//variables for checking dyspnea(Problem in Breathing)
	int check2 = 0;

	do {
		cout << "Dyspnea ?? Y/N  -> ";						//Testing Dyspnea(Problem in Breathing)
		cin >> response2;

		if (response2 == 'Y' || response2 == 'y') {
			dyspnea = true;
			check2 += 1;
		}
		else if (response2 == 'N' || response2 == 'n') {
			dyspnea = false;
			check2 += 1;
		}
		else cout << "Wrong input!! Try again...";
	} while (check2 != 1);

	cout << "Enter Body Temperature Reading (in Fahrenheit) : ";
	cin >> fever;											

	check_fever();											//function call for fever check

	cout << "Enter SPO2 level reading (in %): ";
	cin >> SPO2_level;

	check_SPO2();											//Function call for SPO2 check
	check_chances();										//Function call for risk severity check

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "Entries Complete..." << endl;
	cout << "Press Enter key to continue...";
	cin.ignore();

	system("CLS");
}

void patient_details::check_fever() {
	if (fever > 98.4) {
		fever_status = true;
	}
	else fever_status = false;
}

void patient_details::check_SPO2() {
	if (SPO2_level >= 95) {
		SPO2_severe = false;
	}
	else SPO2_severe = true;
}

void patient_details::check_chances() {					// to check the responsible cases

	int result = 0;

	if (dry_cough == true) {
		result += 1;
	}

	if (dyspnea == true) {
		result += 1;
	}

	if (SPO2_severe == true) {
		result += 1;
	}

	if (fever_status == true) {
		result += 1;
	}

	c_info = result;

}

void patient_details::display_cinfo() {							

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (c_info > 0) {
		cout << "Patient is at risk of corona. Proceed for risk factor check immediately!!!" << endl << endl;
	}
	else {
		cout << "Patient is having some other health problem but not corona." << endl;
		cout << "The Patient can collect his/her report!!";
	}

	cout << endl << endl << "Basic Diagnosis Complete!!" << endl << endl;

	cout << "Press Enter key to continue...";
	cin.ignore();
	system("CLS");
}

class corona_patient :public patient_details {				//Derived Class 2 (Base Class = patient_details)

protected:

	bool home_quarantine;
	bool ctest_requirement;				// if corona chances = true then true 
	bool covid_centre;
	int decision;						// Suggestions for treatment

public:

	corona_patient() {
		home_quarantine = false;
		ctest_requirement = false;
		covid_centre = false;
		decision = 0;
	}

	void decisions();					//function for decision making on home quarrantine and covid centre refer
	void display_report();

};

void corona_patient::decisions() {

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	decision = c_info;

	if (c_info == 0) {
		cout << "The patient has some other health problem." << endl << endl;
	}

	if (c_info > 0 && c_info <= 2) {

		cout << endl << "The patient is at a mild risk of corona." << endl;

		home_quarantine = true;
		ctest_requirement = true;
		covid_centre = false;
	}

	if (c_info > 2) {

		cout << endl << "The patient is at high risk of corona." << endl;

		home_quarantine = false;
		ctest_requirement = true;
		covid_centre = true;
	}

	cout << "Risk Factor Check Complete!! Proceed to Collect the Report.";
	cout << endl << "Press Enter key to continue..." << endl;
	cin.ignore();

	system("CLS");
}

void corona_patient::display_report() {

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << endl << "*********** THE PATIENT REPORTS ARE ***********" << endl << endl;

	cout << "GENERAL INFO :-" << endl << endl;								// General Info Output
	cout << "Name -> " << name << endl;
	cout << "Age -> " << age << " YEARS" << endl;
	cout << "Mobile Number -> " << mob_no << endl;					// Basic Details Output(From Base Class patient)
	cout << "Email ID -> " << email_id << endl;
	cout << "Address -> " << address << endl;

	cout << endl << "CHECK-UP DETAILS :-" << endl << endl;

	if (dry_cough == true) {
		cout << "Dry Cough -> YES" << endl;
	}
	else cout << "Dry Cough -> NO" << endl;
	// Check-up details output
	if (dyspnea == true) {
		cout << "Dyspnea -> YES" << endl;
	}
	else cout << "Dyspnea -> NO" << endl;
	// Bool variables output in yes or no
	cout << endl << "Body Temperature -> " << fever << endl;

	if (fever_status == true) {
		cout << "THE PATIENT HAS FEVER " << endl << endl;
	}
	else cout << "THE PATIENT DOES NOT HAVE FEVER " << endl << endl;

	cout << "SPO2 level -> " << SPO2_level << endl;

	if (SPO2_severe == true) {
		cout << "SPO2 LEVEL IS NOT NORMAL " << endl;
	}
	else cout << "SPO2 LEVEL NORMAL " << endl;

	cout << endl << endl << "MEDICAL ADVICES :- " << endl << endl;								// Medical Advices Output

	if (home_quarantine == true) {
		cout << "Home Quarrantine -> YES" << endl;
	}
	else cout << "Home Quarrantine -> NO" << endl;

	if (ctest_requirement == true) {
		cout << "Covid Test Required -> YES" << endl;
	}
	else cout << "Covid Test Required -> NO" << endl;

	if (covid_centre == true) {
		cout << "Refer to COVID centre -> YES" << endl;
	}
	else cout << "Refer to COVID centre -> NO" << endl;

	cout << endl << "Press Enter key to continue..." << endl;
	cin.ignore();

	system("CLS");

}


int main() {

	int ch = 0;

	corona_patient c1;

	cout << setfill('*') << setw(80) << "*" << endl;
	cout << setfill(' ') << setw(56) << "Welcome to Covid Patients Screening System" << endl;
	cout << setfill('*') << setw(80) << "*" << endl;

	do {
		cout << endl;
		cout << "Make a choice by entering the serial number of the choice... " << endl << endl;
		cout << "1.New Patient Data Entry" << endl;
		cout << "2.Patient Examination" << endl;
		cout << "3.Check Chances of Corona " << endl;
		cout << "4.Check Risk Factor " << endl;
		cout << "5.Display Patient Report " << endl;
		cout << "6.Exit " << endl << endl;

		cout << "Enter your choice : ";
		cin >> ch;
		switch (ch) {

		case 1:
			system("CLS");
			c1.getdata();
			break;

		case 2:
			system("CLS");
			c1.patient_examination();
			break;

		case 3:
			system("CLS");
			c1.display_cinfo();
			break;

		case 4:
			system("CLS");
			c1.decisions();
			break;

		case 5:
			system("CLS");
			c1.display_report();
			break;

		case 6:
			exit(0);

		default:
			cout << "Invalid Choice!! Try Again...";
		}
	} while (ch != 6);

	return 0;

}