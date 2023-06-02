#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>
#include<chrono>
#include<iomanip>

using namespace std;
class Patient {
private:
	int patientId;
	string fullName;

public:
	tm dayStart;
	string diseaseCode;
	float fee;
	
	// Initative by constructor with mulpti values
	Patient() {
		patientId = 0;
		fullName = "";
		
		// Get current time default is now
		auto now = chrono::system_clock::now();
		time_t dayToString = chrono::system_clock::to_time_t(now);
		dayStart = *localtime(&dayToString);
		
		diseaseCode = "";
		fee = 0.0;
	}
	
	// Initative by constructor with parameters
	Patient(int id, string name, tm day, string dCode, float f) {
		patientId = id;
		fullName = name;
		dayStart = day;
		diseaseCode = dCode;
		fee = f;
	}
	
	// Getter
	int getPatientId() {
		return patientId;
	}
	
	string getFullName() {
		return fullName;
	}
	
	// Setter
	void setPatientId(int p) {
		patientId = p;
	}
	
	void setFullName(string f) {
		fullName = f;
	}
};

int main() {
	Patient *myP = new Patient;
	
	int patientId = 20101951;
	string fullName = "Le Cong Vi";
	tm NgayNv = {}; // Inititative with default values
	string diseaseID = "HO";
	float f = 1000.0;
	
	// Establishing field of object
	myP->setPatientId(patientId);
	myP->setFullName(fullName);
	myP->dayStart = NgayNv;
	myP->diseaseCode = diseaseID;
	myP->fee = f;
	
	time_t now = time(nullptr);
	tm* currentTime = localtime(&now);
	// localtime() function get a pointer have type time_t is parameter 
	// And return a object pointer of struct tm
	// Value will been return by localtime() function is local time (gio cuc bo)
	// Struct: tm* localtime(const time_t* time_pretr)
	
	// Maybe in trash: myP->dayStart = currentTime;
	myP->dayStart = *currentTime;
	string formatedDate = "";
	char buffer[11]; // format date was been dd/mm/yyyy/0 in here 
	// /0 is null character 
	
	strftime(buffer, sizeof(buffer), "%d/%m/%Y", &myP->dayStart);
	// Struct of strftime(1,2,3,4)
	// 1: array accommodated format of date you want. Maybe is different
	// 2: Size of array
	// 3: Format of day. In case, example is %d/%m/%Y 
	// 3: %d is day [1 to 31], %m is month [1 to 12], %Y is year [example 2023]
	// 4: A pointer was selected
	formatedDate = buffer;
	
	cout << "Ma benh nhan: " << myP->getPatientId() << endl;
	cout << "Ten benh nhan: " << myP->getFullName() << endl;
	cout << "Ngay nhap vien: " << formatedDate << endl;
	cout << "Ma benh: " << myP->diseaseCode << endl;
	cout << setprecision(1);
	cout << fixed;
	cout << "Tien vien phi: " << fixed << myP->fee << endl;
}
