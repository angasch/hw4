#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void read(int N, string originaldata, double* d);

void filter(int N, double* d);

void write(int N, string filtered, double* d);

int main(){
	int N;
	double* d;
	string originaldata;
	string filtered = "filtered";
	cout << "Welche Datei?" << endl;
	cin >> originaldata;
	cout << "Eintraege der Datei: N = " ; 
	cin >> N;
	
	read(N, originaldata, d);
	filter(N, d);
	write(N, filtered, d);
	
	 
	delete[] d;

	return 0;
}



void read(int N, string originaldata, double* d){
	d = new double[N];
	ifstream in(originaldata.c_str());
	for(int i=0;i<N;i++){
		in >> d[i];
	}
	in.close();
}

void filter(int N, double* d){
	d[0]= (d[N] + d[0] + d[1])/3;
	for(int i=1; i<(N-1); i++){
		d[i] = (d[i-1] + d[i] + d[i+1])/3;
	}
	d[N]= (d[N-1] + d[N] + d[0])/3;
}


void write(int N, string filtered, double* d){
	ofstream out(filtered.c_str());
	for(int i=0;i<N;i++){
		out << d[i]<<endl;
	}
	out.close();
}
