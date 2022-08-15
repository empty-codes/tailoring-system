
/*	 This program stores customer records of any registered Fashion designer.
     The fashion designer first creates an account and has a password and username which is stored in a text file to be used on subsequent logins.
     Then the designer has the option of creating a new record or viewing already created ones.
     The record of each customer is stored in a text file which is created on the data entry and is read from anytime, the record is needed to be viewed	*/
 
 
#include <iostream>
#include <fstream> // header allows to read and write to and from a file
#include <string>
#include <windows.h> // needed for sleep ()
#include <stdlib.h>   // needed for system("CLS");


using namespace std;

/*
	The below function compares the inputted username and password with the one stored in the text file.
	If they match, it returns true, else it returns false.
*/
bool login() 
{
	
	string username, password, un, pw;
	
	cout << "\n\n.......................Loading Login Page....................\n\n\n";
	sleep(2); // suspends program execution for 2 seconds
	system("CLS"); // clears the console
	cout << "\n\t\tLOGIN PAGE\n\n";
	cout << "ENTER YOUR LOG-IN DETAILS BELOW \n\n";
	cout << "USERNAME: \n";
	cin >> username;
	cout << "\n\nPASSWORD: \n";
	cin >> password;
	
	ifstream read(username + ".txt"); // opens the username text file in read mode
	getline(read, un); // reads each line of code and stores it in variables "un" and "pw" respectively
	getline(read, pw);
	
	if (un == username && pw == password) // compares the username and password gotten from the user to that gotten from the text file
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main () 
{

int choice, rchoice;
double s_cost, vat, total;
string name, email, phone, username, password, c_name, c_phone, descrip, measure, transaction, delivery, designer;
	
	
	cout << "**********************************************" << endl;
	cout << "WELCOME TO GOLDEN TAILORING MANAGEMENT SYSTEM :) PLEASE CHOOSE FROM THE CHOICES BELOW: " << endl;
	cout << "[1] REGISTER\n";
	cout << "[2] LOG-IN\n";
	cout << "**********************************************\n";
	cout << "Enter your choice here: ";
	cin >> choice;
	
	if (choice == 1) 
	{
	
		cout << "\n\n.......................Loading Registration Page....................\n\n\n";
		sleep(2);
		system("CLS");
		cout << "\n\t\tREGISTRATION PAGE\n";
		cout << "\nFashion designer name: \n";
		cin.ignore();
		getline(cin, name);
		cout << "\nFashion designer email address: \n";
		cin >> email;
		cout << "\nFashion designer phone number: \n";
		cin >> phone;        
		sleep(2);
		
		cout << "\n\nYour company has successfully been registered in our database. \n";
		cout << "Please choose a username and password to be used for access.\n\n";
		
		cout << "ENTER A USERNAME :\n";
		cin >> username;
		cout << "\n\nENTER A PASSWORD: \n";
		cin >> password;
		
	
		ofstream file; // opens the username text file in write mode
		file.open(username + ".txt");
		file << username << endl << password; // writes the inputted data into the file
		file.close(); // closes the file
	
	system("CLS");	// clears the console before displaying next line of code
	cout << "\n\nCONGRATULATIONS! YOU ARE NOW REGISTERED.\n\n";
	cout << " TO AUTHENTICATE YOUR ACCOUNT, YOU WILL BE REDIRECTED TO THE HOMEPAGE TO LOGIN" << endl;
	sleep(2);
		
	main(); // returns program to the starting point; the int main() function
	}
	
	else if (choice == 2) 
	{
		bool status = login(); // calls the login() function defined earlier
		
		if (!status) // if the function returns false, status becomes false
		{
			cout << "\nFalse Login!" << endl;
			sleep(2);
			system("CLS");
			main ();
		}
		else 
		{
		    system("CLS");
			cout << "\n\nWelcome! \n";
            cout << "You have been logged in successfully! \n";
           
        
		    jump: // label for goto statement
		    cout << endl;
	
            cout << "Select [1] to Add a New Record. \n";
	 	    cout << "Select [2] to View Records. \n";
		    cout << "Select [3] to Quit. \n\n\n";
		    cin >> rchoice;
		    
		    switch(rchoice) {
		    	
    	case 1 : {
	
    		cout << "\nCustomer name: \n";
    		cin >> c_name;
    		cout << "\nCustomer phone number: \n";
    		cin >> c_phone;
    		cout << "\nTransaction Date (DD-MM-YY): \n";
    		cin >> transaction;
    		cout << "\nDelivery Date (DD-MM-YY): \n";
    		cin >> delivery;
    		cout << "\nCloth Measurements: \n";
    		cin.ignore();  // ignores characters from the input buffer preventing an empty string
    		getline(cin, measure);  // allows multiple word/line input by extracting characters from the input stream and appending it to the string
    		cout << "\nCloth description: \n";
    		cin.ignore();
    		getline(cin, descrip);
    		cout << "\nService Cost: \n";
    		cin >> s_cost;
    		cout << "\nVAT: \n";
    		cin >>  vat;
    		cout << "\nTotal Cost: \n";
    		cin >> total;
    		cout << "\nDesigner name: \n";
    		cin.ignore();
    		getline(cin, designer);

    	
          	 ofstream file;  // opens a text file for the customer in write mode
		     file.open(c_name + ".txt"); // writes the data stored in the variables into the file on separate lines
		     file << c_name << endl << c_phone << endl << transaction << endl << delivery << endl << measure << endl << descrip  << endl;
		     file << s_cost << endl << vat << endl << total << endl << designer << endl;   
		     file.close();   // closes the text file
		    
	
	         goto jump;   // goto statement jumps to the specified label which in this case is "jump"
		    }  break; // terminates the switch, i.e ends execution of statements inside the case

		       
		case 2 : {
			
			cout << "\nEnter customer name: \n";
			cin >> c_name;
			cout << "\n\n\n";
			cout << c_name << "'s Records \n";
			cout << "*************************************\n";
			
			
			ifstream text;     // opens the text file for the customer in read mode
            text.open(c_name + ".txt");   

            /* reads each line of data stored in the text file and stores it in each variable
			   getline can only be used for string variables, using a getline  to read an int/double variable would result in an error    */
			   
            getline(text, c_name);   
            cout << "\nCustomer name: " << c_name << endl;  
            getline(text, c_phone);
            cout << "\nCustomer phone number: " << c_phone << endl;
            getline(text, transaction);
            cout << "\nTransaction Date (DD-MM-YY): " << transaction << endl;
            getline(text, delivery);
            cout << "\nDelivery Date (DD-MM-YY): " << delivery << endl;
            getline(text, measure);
            cout << "\nCloth Measurements: " << measure << endl;
            getline(text, descrip);
            cout << "\nCloth description: " << descrip << endl;
            text >> s_cost;  
            cout << "\nService Cost: " << s_cost << endl;
            text >> vat;
            cout << "\nVAT: " << vat << endl;
            text >> total;
            cout << "\nTotal Cost: " << total << endl;
            text >> designer;
            cout << "\nDesigner name: " << designer << endl;
            
            text.close();   // closes the text file
            cout << endl << endl;
            
            goto jump; // goes to the jump label
    
   }
		break;	

		case 3 : {

		    return 0; // ends the program execution
		    } break;
		    
		default :   
			cout << "Error! Please re-login and select a valid option \n\n\n";
			
	     	main ();   // returns program to the starting point; the int main() function
			break;
      }
    
    }
    			
	}
	
	else {
		cout << "\n\nError!! Please choose between option 1 and 2" << endl;
		system("CLS"); // clears the console
		main (); // returns program to the starting point; the int main() function
	}
	return 0;
	
	}
	
	
	