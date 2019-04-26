/*

Autor: Thales Costa com base nos algoritmos apresentados no livro-base (Estruturas da  Dados e Algoritmos em C++, de Adam Drozdek)
Disciplina: ED2
Professor: Irineu
Agosto/2017

*/

#include "lib.hpp"

/*template<class T>
void Heap<T>::clear(HeapNode<T> *p) {//Observer chamada recursiva para deleção de nós terminais (folhas) para raiz 
    if (p != 0) {
         clear(p->left); //recursão para nó à esquerda
         clear(p->right); //recursão para nó à direita
         delete p; //desaloca objeto nó-dado
     }
}

template<class T>
Vector<HeapNode<T> > Heap<T>::vetCopy(vector<int> vet){
	vector<HeapNode<T> > vetheap;
	HeapNode<T> root = new HeapNode<T>(vet[0], new HeapNode<T>(vet[1]), new HeapNode<T>(vet[2]));
	vetheap[0] = root;
	
	for(int i=1; i<vet.size(); i++){
		if(2*i+1<vet.size())
			vetheap[i]->left = new HeapNode<T>(vet[2*i+1]);
		if(2*i+2<vet.size())
			vetheap[i]->right = new HeapNode<T>(vet[2*i+2]);
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


/*template<class T>
void Heap<T>::heap(vector<int> vet) {
	root = new HeapNode<T>(vet[0]);
	HeapNode<T>* p = root;
	
	for(int i=0; i<vet.size()-1; i++){
		p->left = new HeapNode<T>(vet[2*i+1]);
		p->right = new HeapNode<T>(vet[2*i+2]);
		
		
		
		
		
		
		
		if(2*i+1 <= vet.size()){
			insert(pai, 2*i+1, vet);
			insert(pai, 2*i+2, vet);
			pai = vet[i+1];
		}
	}
}
 
 */

 
 
 
/*template<class T>
void Heap<T>::insert(const T pai, const T filho, vector<int> vet) {   
    HeapNode<T> *p = root;
    HeapNode<T> *ant = 0;
    while(p->left != 0){
    	ant = p;
    	p = p->left;
	}
    while (p != 0) {  // find a place for inserting new node;
        if (p->left != 0 && filho%2 == 0){
        	 p->left = new BSTNode<T>(vet[filho]);
		}else if(p->right != 0 && filho%2 == 1){
			// TODO: Terminar o metodo de inserção
		}
             p = p->left;
        else p = p->right;
    }
    if (root == 0)    // tree is empty; //ou poderia ser testado "prev"
         root = new BSTNode<T>(el);
    else if (el < prev->el)
         prev->left  = new BSTNode<T>(el);
    else prev->right = new BSTNode<T>(el);
}
*/

/*template<class T>
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
}*/






