/*

Autor: Thales Costa
Disciplina: ED2
Professor: Irineu
Outubro/2017

*/

#include "lib.hpp"

int main() {
	setlocale(LC_ALL, "");

	bool sair = false;
	int menu, element;
	Vector<int> vet;
	Vector<HeapNode<int> > vetheap;
	Heap<int> arvheap;
	
	while (!sair){
		
		cout<<"1 - Inserir elemento no final\n";
		cout<<"2 - Remover elemento do final\n";
		cout<<"3 - Mostrar heap\n";
		cout<<"4 - sair\n\n";
		
		cin>>menu;
		
		switch(menu){
			case 1:		//Inserir
				cout<<"\n\nElemento a ser inserido: ";
				cin>>element;
				vet.push_back(element);
				
				system("cls");
				
			break;
			case 2:		//Remover
				/*if(!isEmpty()){
					cout<<"\n\nO elemento \""<<vet.pop_back<<"\" foi removido\n\n";
				}else{
					cout<<"\n\nERRO - A fila está vazia.\n\n";
				}
				
				system("pause");
				system("cls");*/
				
			break;
			case 3:
				vetheap = arvheap.vetCopy(vet);
				arvheap.displayTree();
				
				system("pause");
				system("cls");
				
			break;
			case 4:		//Sair
				sair = true;
				cout<<"\nObrigado!\n";
				
			break;
			
		}
		
	}
	
	return 0;
}
