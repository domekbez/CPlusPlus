#include "grading.h"

// uzupe³nij
grading::grading()
{
	nota=0;
	wsp_ceny=1;
	firma_gradingowe=NULL;
}
grading::grading(int nota, firma centrum)
{
	this->nota=nota;
	if(centrum==BRAK)
	{
		wsp_ceny=1;
	}
	else if(centrum==Gliwickie_Centrum_Numizmatyczne)
	{
		wsp_ceny=1.25;
	}
	else if(centrum==Polskie_Centrum_Gradingu)
	{
		wsp_ceny=1.25;
	}
	else 
		wsp_ceny=1.5;
	firma_gradingowe=new (nothrow) firma;
	if(!firma_gradingowe)
		return;
	*(firma_gradingowe)=centrum;
}

grading::grading(const grading& gr)
{
	nota=gr.nota;
	wsp_ceny=gr.wsp_ceny;
	firma_gradingowe=new (nothrow) firma;
	if(!firma_gradingowe)
		return;
	*(firma_gradingowe)=*(gr.firma_gradingowe);
}
 grading::~grading()
 {
	 delete firma_gradingowe;
 }
 grading& grading::operator = (const grading& gr)
 {
	 if(this==&gr)
	 {
		 return *this;
	 }
	 delete firma_gradingowe;
	 nota=gr.nota;
	wsp_ceny=gr.wsp_ceny;
	firma_gradingowe=new (nothrow) firma;
	if(!firma_gradingowe)
		return *this;
	*(firma_gradingowe)=*(gr.firma_gradingowe);
	return *this;
 }
 ostream& operator<<(ostream& out, const grading& gr)
 {
	 if(!(gr.firma_gradingowe))
		out << "";
	 else if(*(gr.firma_gradingowe)==Gliwickie_Centrum_Numizmatyczne)
		 out << "GCN ";
	 else if(*(gr.firma_gradingowe)==Polskie_Centrum_Gradingu)
		 out << "PCG ";
	 else if(*(gr.firma_gradingowe)==Numismatic_Guaranty_Corporation)
		 out << "NGC ";
	 else if(*(gr.firma_gradingowe)==Professional_Coin_Grading_Service)
		 out << "PCGS ";

	 if(gr.nota<45)
		 out << "Stan obiegowy: ";
	 else if(gr.nota<60)
		out<< "stan okolomenniczy: ";
	 else if(gr.nota<70)
		 out << "stan menniczy: ";
	 else if(gr.nota==70)
		 out << "stan UNC: ";
	 
	 
	 out << gr.nota << endl;
	return out;
 
}