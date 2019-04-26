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
    void push_back(const T& el) {//Implementa a função push_back de um vector para o tipo genérico T 
        push_back(el);
    }
};

template<class T> //T - símbolo aqui associado a qq tipo genérico 
class Stack : public stack <T> {//Implementa a função pop de uma pilha para o tipo genérico T
public:
    T pop() {
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};

template<class T>
class HeapNode {//Classe genérica que define o nó-dado para a heap
public:
	//Construtor: caso sem passagem de parâmetros
    HeapNode() { 
        left = right = 0; 
    }
    //Construtor: caso com passagem de parâmetros
    HeapNode(const T& e, HeapNode<T> *l = 0, HeapNode<T> *r = 0) {
        el = e; //dado genérico a ser guardado no nó
		left = l; //ponteiro que encadeia filho à esquerda, podendo ser NULL caso não seja passado
		right = r;//ponteiro que encadeia filho à direita, podendo ser NULL caso não seja passado 
    }
    //Atributos públicos do nó-dado
    T el;
    HeapNode<T> *left, *right;
};

template<class T>
class Heap { //Aqui temos a implementação de métodos e atributos da classe que definirá a árvore binária
public:
    Heap() { //construtor
        root = 0; //root é o atributo de controle da ED, ponteiro de início, inicia em NULL
    }
    ~Heap() { //destrutor
        clear();
    }
    void clear() {//chamada para desalocar tudo que tiver sendo apontado pelo root...
        clear(root);//sobrecarga de método mais abaixo, que aceitará parâmetro (ponteiro) para ir desalocando todos os nós... 
        root = 0; //após anterior, atribui NULL ao controle root
    }
    void insert(const T&);
    Vector<HeapNode<T> > vetCopy(vector<int> vet);
    void displayTree();
protected:
    HeapNode<T>* root;
    void clear(HeapNode<T>*);
};

template<class T>
void Heap<T>::clear(HeapNode<T> *p) {//Observer chamada recursiva para deleção de nós terminais (folhas) para raiz 
    if (p != 0) {
         clear(p->left); //recursão para nó à esquerda
         clear(p->right); //recursão para nó à direita
         delete p; //desaloca objeto nó-dado
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
