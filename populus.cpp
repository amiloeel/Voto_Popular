#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>  
#include <string>
#include <algorithm>

using namespace std;

//verifica se o cpf é verdadeiro
bool validar(string CPF){
	bool pode = false;
	//guarda os valores dos onze dígitos do cpf
	if(CPF.length()==11){
		string um = CPF.substr(0,1);
		int umx; istringstream (um) >> umx; 
		string dois = CPF.substr(1,1);
		int doisx; istringstream (dois) >> doisx; 
		string tres = CPF.substr(2,1);
		int tresx; istringstream (tres) >> tresx; 
		string quatro = CPF.substr(3,1);
		int quatrox; istringstream (quatro) >> quatrox; 
		string cinco = CPF.substr(4,1);
		int cincox; istringstream (cinco) >> cincox; 
		string seis = CPF.substr(5,1);
		int seisx; istringstream (seis) >> seisx; 
		string sete = CPF.substr(6,1);
		int setex; istringstream (sete) >> setex; 
		string oito = CPF.substr(7,1);
		int oitox; istringstream (oito) >> oitox;
		string nove = CPF.substr(8,1);
		int novex; istringstream (nove) >> novex; 
		string dez = CPF.substr(9,1);
		int dezx; istringstream (dez) >> dezx; 
		string onze = CPF.substr(10,1);
		int onzex; istringstream (onze) >> onzex; 
		//operação de validação
		if((umx == doisx && doisx==tresx && tresx==quatrox && quatrox==cincox && cincox==seisx && seisx==setex && setex==oitox && oitox==novex && novex==dezx && dezx==onzex)==false){
			int soma1 = (umx*10) + (doisx*9) + (tresx*8) + (quatrox*7) + (cincox*6) + (seisx*5) + (setex*4) + (oitox*3) + (novex*2);
			int resto1 = (soma1*10) % 11;
			if(resto1==10){
				resto1=0;
			}
			int soma2 = (umx*11) + (doisx*10) + (tresx*9) + (quatrox*8) + (cincox*7) + (seisx*6) + (setex*5) + (oitox*4) + (novex*3) + (dezx*2);
			int resto2 = (soma2*10) % 11;
			if(resto2==10){
				resto2=0;	
			}
			if(resto1==dezx && resto2==onzex){
				pode = true;
			}
		}
	}
	return pode;
}

//verifica se o cpf já foi utilizado
bool jaVotou (string CPF){
	//recebe buffer de cpfs
	bool saida = false;
	ifstream indiceCPF("LISTAGEM DE CPFs.txt");
	ifstream listagemCPF("LISTAGEM DE CPFs.txt");
	string linhaCPF;
	string linha;
	string csvItemX;
	int indice = 0;
	//calcula quantidade de itens no arquivo
    while (getline(indiceCPF, linhaCPF))
	{
        indice++;
	}
	indiceCPF.close();
	int lin = indice;
	//testa o cpf fornecido com os que já existem
	if (listagemCPF.is_open()) {
        while (getline(listagemCPF,linha)) {
           do{
                istringstream mylineZ(linha);
                for(int www=0; www!=lin; www++){
                while(getline(listagemCPF, csvItemX, '\n')) {
                				stringstream geekX(csvItemX);
                					if(CPF == geekX.str()){
                						saida = true;
									}
                    	} 
						}
        }while(!listagemCPF.eof());
        }
	listagemCPF.close();
}
	return saida;
}

//inclui o cpf inserido no arquivo de cpfs
int insereCPF(string CPF){
	//recebe buffer de cpfs
	ifstream indiceCPF("LISTAGEM DE CPFs.txt");
	string csvItemX;
	string TEMP;
	//armazena itens existentes
	while (!indiceCPF.eof()){
		 while(getline(indiceCPF, csvItemX, '\n')){
		 	stringstream temp (csvItemX);
		 	TEMP = TEMP + temp.str() + "\n";
		 }
	}
	ofstream SAIDA;
	SAIDA.open("LISTAGEM DE CPFs.txt");
	//grava arquivos existentes e o cpf inserido
	SAIDA << TEMP << CPF;
	SAIDA.close();	
	return 0;
}

//encontra projeto a partir de seu índice fornecido
string procuraID(string ID){
	//recebe a lista de projetos
	string confere;
	ifstream PROJETOS("LISTAGEM DE PROJETOS.txt");
	ifstream PRO("LISTAGEM DE PROJETOS.txt");
	string linha;
	string linhaPRO;
	string csvItemX;
	int indice = 0;
    while (getline(PRO, linhaPRO))
	{
        indice++;
	}
	PRO.close();
	int lin = indice;
	//procura pelo índice fornecido no arquivo de projetos
	if (PROJETOS.is_open()) {
        while (getline(PROJETOS,linha)) {
           do{
                istringstream mylineZ(linha);
                for(int www=0; www!=lin; www++){
                while(getline(PROJETOS, csvItemX, '\n')) {
                				stringstream geekX(csvItemX);
                				string TEMP = geekX.str();
                				string temp = TEMP.substr(0,4);
                					if(ID == temp){
                						confere = TEMP;
									}
                    	} 
						}
        }while(!PRO.eof());
        }
	PRO.close();
}
	return confere;
}

//adiciona um voto no arquivo de votos 
int insereVoto(string ID){
	//recebe o arquivo de votos
	string guarda;
	string confere;
	ifstream PROJETOS("VOTOS.txt");
	ifstream PRO("VOTOS.txt");
	string linha;
	string linhaPRO;
	string csvItemX;
	int indice = 0;
    while (getline(PRO, linhaPRO))
	{
        indice++;
	}
	PRO.close();
	int lin = indice;
	//encontra o índice do projeto e adiciona um voto ao total 
	if (PROJETOS.is_open()) {
        while 
		(getline(PROJETOS,linha)) {
           do{
                istringstream mylineZ(linha);
                guarda = mylineZ.str() + "\n";
                for(int www=0; www!=lin; www++){
                while(getline(PROJETOS, csvItemX, '\n')) {
                				stringstream geekX(csvItemX);
                				string TEMP = geekX.str();
                				string temp = TEMP.substr(0,4);
                					if(ID == temp){
                						guarda = guarda + temp + " - ";
                						string b = TEMP.substr(7, '\n');
										int c ;
                						istringstream (b) >> c; 
										int cc = c+1;
										ostringstream ccc;
										ccc << cc;
										string cccc = ccc.str();		
										guarda = guarda + cccc + "\n";		
									}else{
										guarda = guarda + TEMP + "\n";
									}
                    	} 
						}
        }while(!PRO.eof());
        }
        PROJETOS.close();
		PRO.close();
		}
		ofstream SAIDA;
		SAIDA.open("VOTOS.txt");
		SAIDA << guarda;
		SAIDA.close();
		return 0;
		}
		
		
int main (int argc, const char * argv[]) {
	
	int x = 0;
	while(x==0){
	
	string entrada;
	
	cout << "\n\n\n\n\n                       VOTO POPULAR - CIENCIA JOVEM 2018\n\n\n\n";
	
	cout << "Insira o seu CPF:     \n";
	cin >> entrada;
	
	bool checagem = validar(entrada);
	
	if(checagem==true){
		bool sai = jaVotou(entrada);
	if(sai == true){
		cout << "\n\n\n\n                       !!! CPF UTILIZADO ANTERIORMENTE !!!\n";
	}else{
			
		string ID;
		cout << "\nInsira o codigo correspondente ao projeto no qual deseja votar:\n";
		cin >> ID;
		
		string certeza = procuraID(ID); 
		if(certeza.length()>7){
					char confirme;
					cout << "\nConfirmar voto para o projeto: \n" << certeza << "? (S/N)\n";
					cin >> confirme;
					if(confirme == 'S' || confirme == 's'){
							insereCPF(entrada);
							insereVoto(ID);
							cout << "\n\n\n\n                            !!! VOTO REGISTRADO !!!\n";
					}else{
						cout << "\n\n\n\n                            !!! VOTO DISPENSADO !!!\n";
					}
		} else{
			cout << "\n\n\n\n                           !!! CODIGO INEXISTENTE !!!\n";
		}
	}
	}else{
		cout << "\n\n\n\n                            !!! CPF INEXISTENTE !!!\n";
	}
}
	return 0;
}
