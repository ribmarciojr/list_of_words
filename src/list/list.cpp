#ifndef LIST_CPP
#define LIST_CPP
#include "./node.cpp"
#include <iostream>
#include <fstream>

class List {
    public: 
        Node* prim{nullptr};

        List(){};

        bool isEmpty() {
            if(!this->prim){
                return true;
            }
            return false;
        };

        void insere_palavra(Node* node, Node* Node::*next, bool doShow){           
            if(this->isEmpty()){
                this->prim = node;
                if(!doShow){
                    std::cout << "palavra inserida: " << node->getWord() << std::endl;
                }
                return;
            }
            Node* currentNode = this->prim;
            Node* previousNode{nullptr};

            while (currentNode)
            {
                if(node->getWord() == currentNode->getWord()){
                    if(!doShow){

                    std::cout << "palavra ja existente: " << node->getWord() << std::endl;
                    }
                    return;
                }

                if(node->getWord() < currentNode->getWord() && currentNode->getWord() == this->prim->getWord()){
                    node->*next = this->prim;
                    this->prim = node;
                    if(!doShow){

                    std::cout << "palavra inserida: " << node->getWord() << std::endl;
                    }
                    return;
                }

                if(node->getWord() < currentNode->getWord()){
                    previousNode->*next = node;
                    node->*next = currentNode;
                    if(!doShow){

                    std::cout << "palavra inserida: " << node->getWord() << std::endl;
                    }
                    return;
                }
                
                previousNode = currentNode;
                currentNode = currentNode->*next;
            }
            
            previousNode->*next = node;
            if(!doShow){
            std::cout << "palavra inserida: " << node->getWord() << std::endl;
            }
            return;
        };

        void lista_palavra_tamanho(int expected_length, Node* Node::*next){
            Node* temp = this->prim;
            int count = 0;

            while(temp){
                if(temp->getWord().length() == expected_length){
                    std::cout << temp->getWord() << std::endl;
                    count++;
                }
                temp = temp->*next;
            }

            if(!count) {
                std::cout << "lista vazia" << std::endl;
            }
        }

        void lista_palavras_entre(char const &first_letter, char const &second_letter, Node* Node::*next){
            Node* temp = this->prim;
            int count = 0;

            while(temp){
                if(temp->getWord()[0] >= first_letter && temp->getWord()[0] <= second_letter){
                    std::cout << temp->getWord() << std::endl;
                    count++;
                }
                temp = temp->*next;
            }
            
            if(!count){
                std::cout << "lista vazia" << std::endl;
            }
        }

        

        void remove_palavra(std::string const &word, Node* Node::*next, bool doShow){
            Node* currentNode = this->prim;
            Node* previousNode{nullptr};

            while (currentNode)
            {
                if(currentNode->getWord() == word && currentNode == this->prim){
                    this->prim = currentNode->*next;
                    if(doShow){
                        std::cout << "palavra removida: " << currentNode->getWord() << std::endl;
                    }
                    return;
                }

                if(currentNode->getWord() == word){
                    previousNode = currentNode->*next;
                    if(doShow){
                        std::cout << "palavra removida: " << currentNode->getWord() << std::endl;
                    }
                    return;
                }

                previousNode = currentNode;
                currentNode = currentNode->*next;
            }
            
            if(doShow){
                std::cout << "palavra inexistente: " << currentNode->getWord() << std::endl;
            }
        }

        void print(Node* Node::*next){
            if(this->isEmpty()){
                std::cout << "lista vazia" << std::endl;
                return;
            }
            Node* temp = this->prim;
            while(temp){
                std::cout << temp->getWord() << std::endl;
                temp = temp->*next;
            }
        }
};

#endif