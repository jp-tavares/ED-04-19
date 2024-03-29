#include <iostream>
#include <string>
using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;

public:
	Data(int dia, int mes, int ano)
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}

	Data()
	{
		this->dia = 28;
		this->mes = 9;
		this->ano = 1962;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}

	void setMes(int mes)
	{
		this->mes = mes;
	}

	void setAno(int ano)
	{
		this->ano = ano;
	}

	int getDia()
	{
		return this->dia;
	}

	int getMes()
	{
		return this->mes;
	}

	int getAno()
	{
		return this->ano;
	}

	string getData()
	{
		return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
	}

	Data* dia_seguinte()
	{
		Data *ds;
		int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		ds = new Data(this->dia, this->mes, this->ano);

		if (ds->ano % 4 == 0)
		{
			diasNoMes[1]++;
		}

		ds->dia++;
		if (ds->dia > diasNoMes[ds->mes - 1])
		{
			ds->dia = 1;
			ds->mes++;
			if(ds->mes > 12)
			{
				ds->mes = 1;
				ds->ano++;
			}
		}

		return ds;
	}

};

class Contato
{
private:
	string email;
	string nome;
	int telefone;
	Data* dtnasc;
	

public:
	Contato(string email, string nome, int telefone, Data* dtnasc)
	{
		this->email = email;
		this->nome = nome;
		this->telefone = telefone;
		this->dtnasc = dtnasc;
	}

	Contato()
	{
		this->email = "";
		this->nome = "";
		this->telefone = 0;
		this->dtnasc = new Data();
	}

	void setEmail(string email)
	{
		this->email = email;
	}
	
	void setNome(string nome)
	{
		this->nome = nome;
	}
	
	void setTelefone(int telefone)
	{
		this->telefone = telefone;
	}
	
	void setDtnasc(Data* data)
	{
		this->dtnasc = data;
	}
	
	string getEmail(string email)
	{
		return this-> email;
	}
	
	string getNome(string nome)
	{
		return this-> nome;
	}
	
	int getTelefone(int telefone)
	{
		return this-> telefone;
	}
	
	int getIdade(int idade)
	{
		return this-> calcIdade();
	}
	
	Data* getDtnasc(Data* data)
	{
		return this-> dtnasc;
	}

	
	string getContato()
	{
		return "Email: " + this->email + "\n" +
			   "Nome: " + this->nome + "\n" +
			   "Telefone: " + to_string(this->telefone) + "\n" +
			   "Data de Nascimento: " + this->dtnasc->getData() + "\n" +
			   "Idade: " + to_string(this->calcIdade());
	}

	int calcIdade()
	{
		return 2022 - this->dtnasc->getAno();
	}

};

int main(int argc, char** argv)
{
	Contato *contatos[5];
	
	string email;
	string nome;
	int telefone;
	int dia;
	int mes;
	int ano;
	
	for(int i=0; i<5; i++)
	{
		cout<<"Digite o email do " + to_string(i+1) + "° contato: ";
		cin>>email;
		cout<<"Digite o nome do " + to_string(i+1) + "° contato: ";
		cin>>nome;
		cout<<"Digite o telefone do " + to_string(i+1) + "° contato: ";
		cin>>telefone;
		cout<<"Digite o dia de nacimento do " + to_string(i+1) + "° contato: ";
		cin>>dia;
		cout<<"Digite o mes de nacimento do " + to_string(i+1) + "° contato: ";
		cin>>mes;
		cout<<"Digite o ano de nacimento do " + to_string(i+1) + "° contato: ";
		cin>>ano;
		
		Data *dataNascimento = new Data();
		dataNascimento->setDia(dia);
		dataNascimento->setMes(mes);
		dataNascimento->setAno(ano);
		
        	contatos[i]= new Contato();
		contatos[i]->setEmail(email);
		contatos[i]->setNome(nome);
		contatos[i]->setTelefone(telefone);
		contatos[i]->setDtnasc(dataNascimento);
	}
	
	for(int i=0; i<5; i++){
	    cout << contatos[i]->getContato() << endl;
	}
	
	
	Data *dataNascimento = new Data(27, 5, 2003);
	cout << dataNascimento->getData() << endl;

	Contato *contato = new Contato("jpcovinhas0@gmail.com", "Joao", 984613215, dataNascimento);
	cout << contato->getContato() << endl;

	return 0;
}
