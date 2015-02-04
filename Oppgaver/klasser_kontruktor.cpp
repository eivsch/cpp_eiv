#include <iostream>
#include <string>

using namespace std;

class computer{
	float cpu_freq, mem_size, disk_size;
	string model;
	int usb_ports;
	char* manufacturer;
	//test av strukt
	struct two_longs{
		long value1,value2;
	}l;

public:
	string pre_string;
	string to_string();
	computer();
};

computer::computer(){
	//pre_string = to_string();
	l.value1=312;
	l.value2=4353;
	cpu_freq=3.2;
	mem_size=4096;
	disk_size=246;
	model="Lenovo31425";
	usb_ports=4;
	manufacturer="IBM/Lenovo";
}

string computer::to_string(){
	string s;
	s = "CPU Frequency: " + std::to_string (cpu_freq) + 
	" \nMemory: " + std::to_string (mem_size) + 
	" \nDisk: " + std::to_string (disk_size) + 
	" \nModelname: " + model + 
	" \nUSB Ports: " + std::to_string (usb_ports) +
	" \nManufacturer: " + manufacturer +
	" \nLongtest: " + std::to_string (l.value1);
	return s;
}

computer cmp_glob;

int main(){
	computer cmp1;
	computer cmp2;
	//cmp1
	string s = cmp1.to_string();
	cout << "cmp1\n" << s << endl;
	//cmp2
	s = cmp2.to_string();
	cout << "cmp2\n" << s << endl;
	//Global
	s = cmp_glob.to_string();
	cout << "cmp_glob\n" << s << endl;
	//s = cmp1.pre_string;
	//cout << s <<endl;
}