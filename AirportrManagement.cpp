//for input & output
#include <iostream>
//for get character without enter
#include <conio.h>
//for manages sequences of characters
#include <string>
//for working with file
#include <fstream>
//use system function
#include <cstdlib>
//for format output
#include <iomanip>

using namespace std;
struct runwayInfo{
	int id;
	int status=0;
	string controllerName;	
};
void initilizeRunway(runwayInfo []);
void PauseScreen();
int getValidationInt(int ,int );
void getInfo(runwayInfo []);
void printInfo(runwayInfo []);
void emptyStatus(runwayInfo []);
void emptyNumber(runwayInfo []);
int assignRunway(runwayInfo []);
int releaseRunway(runwayInfo []);
void printFile(string );

int main(){
	const string AddressOfHelp="help.txt";
	runwayInfo runway[100];
	short choice;
	initilizeRunway(runway);
	while(true){
    // -----------------start main menu-----------------------
		cout<<"\n=============================================\n";
		cout<<"              RUNWAY MANAGEMENT                \n";
		cout<<"=============================================\n\n";
		cout<<"1)Operations Menu"<<endl
		    <<"2)Help"<<endl
		    <<"3)Help (persian mode)"<<endl
		    <<"4)About The Developer"<<endl
		    <<"0)Exit"<<endl;
	//	-----------------end main menu--------------------------
		cout<<"\nyour choice: "<<endl;
		choice=getValidationInt(0,4);
		system("cls");
		if(choice==1){
			short choiceRunway;
			do{
				//---------------start runway operation menu----------------
		        cout<<"\n========================================\n";
			    cout<<"          RUNWAY OPERATION MENU           \n";
			    cout<<"========================================\n\n";
			    cout<<"1) Input Runway Data"<<endl
			        <<"2) Display Runway Details"<<endl
			        <<"3) Show Number of Available Runways"<<endl
			        <<"4) Show Available Runway Number"<<endl
			        <<"5) Allocate Runway To Aircraft"<<endl
			        <<"6) Release Runway"<<endl
			        <<"0) Back To Main Menu"<<endl;
			    //---------------end runway operation menu----------------
			    cout<<"\nyour choice: ";
			    cin.clear();
			    choiceRunway=getValidationInt(0,6);
		        system("cls");
		        switch(choiceRunway){
		    	    case 1:
		                getInfo(runway);
		                PauseScreen();
		                system("cls");
		                break;
		            case 2:
		                printInfo(runway);
		                PauseScreen();
		                system("cls");
			            break;
 		            case 3:
			            emptyStatus(runway);
			            PauseScreen();
		                system("cls");
			            break;
		            case 4:
		                emptyNumber(runway); 
						PauseScreen();
		                system("cls");  
		        	    break;
		            case 5:
		                assignRunway(runway);
		                PauseScreen();
		                system("cls");
		                break;
		            case 6:
			            releaseRunway(runway);
			            PauseScreen();
		                system("cls");
			            break;
		            case 0:	    
		        	    break;
		            default:
			            cout<<"INVALID.please enter number between 0 to 6 ";
			            break;
				}
	        }while(choiceRunway!=0);
	    }
	    else if(choice==2){
	    	cout<<"\n----------------------------------------------\n";
			cout<<"                  USER GUID                   \n";
			cout<<"----------------------------------------------\n\n";
	    	printFile(AddressOfHelp);
	    	PauseScreen();
		    system("cls");
	    }
		else if(choice==3){
			cout<<"\n----------------------------------------------\n";
			cout<<"           USER GUID(persian mode)             \n";
			cout<<"----------------------------------------------\n\n";	
		    cout << "Wait for open file ....";
		    system("persian_help.pdf");
		    PauseScreen();
		    system("cls");
		}
		else if (choice==4){
			cout << "\n----------------------------------------\n";
            cout << "          About The Developer           \n";
            cout << "----------------------------------------\n\n";

            cout <<" Create by \" Bahar Aminimajd \" " << endl;
            cout <<" github address : "<<endl;
            cout <<" project description: "<<endl
                 <<" this project is developed as the final project for the"<<endl
                 <<" \"fundemental of progrraming\"course"<<endl;
            PauseScreen();
		    system("cls");
		}
		else if(choice==0){
			return 0;
		}
    }
	getch();
	return 0;
};

//initilizerunaway
void initilizeRunway(runwayInfo runways[]){
	for(int i=0;i<100;i++){
		runways[i].id = 0;
		runways[i].status = 0;
		runways[i].controllerName = "";
	}
}
//pause screan
void PauseScreen()
{
    cout << "\n\n";
    system("pause");
}
//validation int
int getValidationInt(int min,int max){
	int value;
	while(true){
		cin>>value;
		if(!cin.fail()&&value>=min&&value<=max){
			    return value;
		}
		cout<<"Invalid,"
		    <<"Enter number between ("<<min<<","<<max<<")"<<endl;
		    cin.clear();
		    cin.ignore(1000,'\n');	
	}
};

//get_info
void getInfo(runwayInfo runways[]){
	int count=0;
	cout<<"\n---------------------------------------------\n";
	cout<<"           Runway Information Entry            \n";
	cout<<"---------------------------------------------\n\n";
	cout<<"Airport runway count(1,100)-->";
	count = getValidationInt(1,100);
	cin.ignore();
	for(int i=0;i<count;i++){
		int id,status;
		string name;
		cout<<"ID(1,100): ";
		id=getValidationInt(1,100);
		cout<<"controllername: ";
		cin.ignore();
		getline(cin,name);
		int index = id-1;
		runways[index].id = id;
		runways[index].status = 1;
		runways[index].controllerName = name;
		cout<<"runaway "<<id<<" saved successsfully."<<endl;
		cout<<"--------------------------------------"<<endl;
	}
	cout<<"Data entry completed successsfully."<<endl;
}

//print_info
void printInfo(runwayInfo runways[]){
	int id;
	cout<<"============================================="<<endl;
	cout<<"            Show Runway Information          "<<endl;
	cout<<"============================================="<<endl;
	cout<<"please enter the runway id: "<<endl;
	id=getValidationInt(1,100);
	int index = id-1;	
	cout<<"--------------Runway #"<<id<<" details---------"<<endl;
	cout<<"id: "<<runways[index].id<<endl;                   
	cout<<"status: "<<runways[index].status<<endl;
	cout<<"controllerName: "<<runways[index].controllerName<<endl;
}
//empty status		
void emptyStatus(runwayInfo runways[]){
    int count=0;
    for(int i=0;i<100;i++){
    	if(runways[i].status==0){
    		count++;
		}
	}
	cout<<"Total available runways = "<<count<<" from 100";
}
//empty_number
void emptyNumber(runwayInfo runways[]){
    int ids[100];
    int count = 0;
    
    for (int i = 0; i < 100; i++) {
        if (runways[i].status == 0) {
            ids[count++] = i+1;
        }
    }
    
    if (count == 0) {
        cout << "\nNo available runways found!\n";
        return;
    }
    
    int cols = 10;
    int rows = (count + cols - 1) / cols;
    
    cout << "\nAvailable Runways:\n";
    cout << "----------------------------------------\n";
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = col * rows + row;
            if (index < count) {
                cout << setw(6) <<"id"<<ids[index];
            } else {
                cout << setw(6) << " ";
            }
        }
        cout << endl;
    }
    
    cout << "----------------------------------------\n\n";
}
//assign_runway
int assignRunway(runwayInfo runways[]){
    cout << "\n----------------------------------------\n";
    cout << "          Allocate Runways              \n";
    cout << "----------------------------------------\n\n";
	int id;
	cout<<"ID: ";
	id=getValidationInt(1,100);
	int index = id-1;
	if(runways[index].status==0){
		string name;
	    cout<<"controllerName: ";
	    cin.ignore();
		getline(cin,name);
		runways[index].id = id;
		runways[index].controllerName=name;	
		runways[index].status=1;
		cout<<"runaway "<<id<<" saved successsfully."<<endl;
		cout<<"--------------------------------------"<<endl;
		return 0;
	}
	cout<<"this runway is already reserved."<<endl;
	return 0;
}

//release_runaway
int releaseRunway(runwayInfo runways[]){
	cout << "\n----------------------------------------\n";
    cout << "           release Runways              \n";
    cout << "----------------------------------------\n\n";
	int id;
	cout<<"ID: ";
	id=getValidationInt(1,100);
	int index = id-1;
	if(runways[index].status==1){
		string name;
	    cout<<"controllerName: ";
	    cin.ignore();
	    getline(cin,name);
	    runways[index].id =0;
		runways[index].controllerName="";	
		runways[index].status=0;
		cout<<"free successfully"<<endl;
		return 0;
	}
	cout<<"this runway is already empty."<<endl;
	return 0;
}

//userGuid
void printFile(string address){
    fstream h;
    string str;
    h.open(address, ios::in);
    while (!h.eof())
    {
        getline(h, str);
        cout << str << endl;
    }
    h.close();
}
