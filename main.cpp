#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

class kolejka{
	ifstream plik1;
	ofstream plik2;
	std::queue <int> kolejeczka;
	public:
		kolejka();
		~kolejka();
		
		void load();
		void save();
};

kolejka::kolejka(){
	plik1.open("c:\\od.txt");
	plik2.open("c:\\do.json");
}

void kolejka::load(){
	int number;
	while(!plik1.eof()){
		plik1>>number;
		kolejeczka.push(number);
	}
}

void kolejka::save(){
	bool first = true;
	plik2<<"["<<endl;
	while(!kolejeczka.empty()){
		if(first){
			plik2<<"{\"liczba\":"<<kolejeczka.front()<<"}",
			kolejeczka.pop();
			first = false;
		} else {
			plik2<<","<<endl;
			plik2<<"{\"liczba\":"<<kolejeczka.front()<<"}",
			kolejeczka.pop();
		}	
	}
	plik2<<endl<<"]";
}
kolejka::~kolejka(){
	plik1.close();
	plik2.close();
}

int main(int argc, char** argv) {
	kolejka q1;
	q1.load();
	q1.save();
	return 0;
}
