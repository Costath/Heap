/*

Autor: Thales Costa
Disciplina: ED2
Professor: Irineu
Agosto/2017

*/

#include <iostream>
#include <vector>
#include <stack>
#include <locale.h>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

using namespace std;

template<class T>
class Vector : public vector <T> {
public:
    void push_back(const T& el) {//Implementa a fun��o push_back de um vector para o tipo gen�rico T 
        push_back(el);
    }
};

template<class T> //T - s�mbolo aqui associado a qq tipo gen�rico 
class Stack : public stack <T> {//Implementa a fun��o pop de uma pilha para o tipo gen�rico T
public:
    T pop() {
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};

template<class T>
class HeapNode {//Classe gen�rica que define o n�-dado para a heap
public:
	//Construtor: caso sem passagem de par�metros
    HeapNode() { 
        left = right = 0; 
    }
    //Construtor: caso com passagem de par�metros
    HeapNode(const T& e, HeapNode<T> *l = 0, HeapNode<T> *r = 0) {
        el = e; //dado gen�rico a ser guardado no n�
		left = l; //ponteiro que encadeia filho � esquerda, podendo ser NULL caso n�o seja passado
		right = r;//ponteiro que encadeia filho � direita, podendo ser NULL caso n�o seja passado 
    }
    //Atributos p�blicos do n�-dado
    T el;
    HeapNode<T> *left, *right;
};

template<class T>
class Heap { //Aqui temos a implementa��o de m�todos e atributos da classe que definir� a �rvore bin�ria
public:
    Heap() { //construtor
        root = 0; //root � o atributo de controle da ED, ponteiro de in�cio, inicia em NULL
    }
    ~Heap() { //destrutor
        clear();
    }
    void clear() {//chamada para desalocar tudo que tiver sendo apontado pelo root...
        clear(root);//sobrecarga de m�todo mais abaixo, que aceitar� par�metro (ponteiro) para ir desalocando todos os n�s... 
        root = 0; //ap�s anterior, atribui NULL ao controle root
    }
    void insert(const T&);
    Vector<HeapNode<T> > vetCopy(vector<int> vet);
    void displayTree();
protected:
    HeapNode<T>* root;
    void clear(HeapNode<T>*);
};

template<class T>
void Heap<T>::clear(HeapNode<T> *p) {//Observer chamada recursiva para dele��o de n�s terminais (folhas) para raiz 
    if (p != 0) {
         clear(p->left); //recurs�o para n� � esquerda
         clear(p->right); //recurs�o para n� � direita
         delete p; //desaloca objeto n�-dado
     }
}

template<class T>
Vector<HeapNode<T> > Heap<T>::vetCopy(vector<int> vet){
	Vector<HeapNode<T> > vetheap;
	root = new HeapNode<T>(vet[0], new HeapNode<T>(vet[1]), new HeapNode<T>(vet[2]));
	vetheap[0] = *root;
	
	for(int i=1; i<vet.size(); i++){
		if(2*i+1<vet.size())
			vetheap[i].left = new HeapNode<T>(vet[2*i+1]);
		if(2*i+2<vet.size())
			vetheap[i].right = new HeapNode<T>(vet[2*i+2]);
	}
	
	return vetheap;
	
	
	
	/*for(int i=1; i<vet.size(); i++){
		
		vetheap[i]->el = vet[i];
	}*/
	/*for(int i=0; i<vet.size(); i++){
		if(2*i+1<vet.size())
			vetheap[i]->left = new HeapNode<T>(vet[2*i+1]);
		if(2*i+2<vet.size())
			vetheap[i]->right = new HeapNode<T>(vet[2*i+2]);
	}
	return vetheap;*/
}

template<class T>
void Heap<T>::displayTree(){
    Stack<HeapNode<T>*> pilhaGlobal;
    pilhaGlobal.push(root);
    int nEspacos = 32;
    bool isLinhaVazia = false;
    cout << "......................................................\n";
    
    while(isLinhaVazia==false){
        Stack<HeapNode<T>*> pilhaLocal;
        isLinhaVazia = true;
        for (int i=0; i<nEspacos; i++)
            cout << " ";
        while(pilhaGlobal.empty()==false){
            HeapNode<T> *tmp = pilhaGlobal.pop();
            if(tmp!=0){
                cout << tmp->el;
                pilhaLocal.push(tmp->left);
                pilhaLocal.push(tmp->right);
                if (tmp->left != 0 || tmp->right != 0)
                    isLinhaVazia = false;
            } else {
                cout << "--";
                pilhaLocal.push(0); //coloca NULL na pilhaLocal
                pilhaLocal.push(0); //coloca NULL na pilhaLocal
            }
            for(int j=0; j<nEspacos*2-2; j++){
                cout << " ";
            }
        }
        cout << endl;
        nEspacos /= 2;
        while(pilhaLocal.empty()==false){
            pilhaGlobal.push(pilhaLocal.pop());
        }
    }
    cout << "......................................................\n\n";
}

#endif
