#include <iostream>
#include "../list/list.cpp"
#include "../list/node.cpp"

void handle_insertion(List* short_words, List* medium_words, List* large_words, List* all_words, Node* node){
    if(node->getWord().length() <= 5){
        short_words->insere_palavra(node, & Node::micro_prox, true);
        
    } 
    else if (node->getWord().length() >= 6 && node->getWord().length() <= 10){
        medium_words->insere_palavra(node, & Node::micro_prox, true);
        
    } else if (node->getWord().length() > 10) {
        large_words->insere_palavra(node, & Node::micro_prox, true);
        
    }
    all_words->insere_palavra(node, &Node::macro_prox, false);
}

void handle_print(List* short_words, List* medium_words, List* large_words, List* all_words, int list_number){
    if(list_number == 1){
        short_words->print(& Node::micro_prox);
    } else if(list_number == 2){
        medium_words->print(& Node::micro_prox);
    } else if(list_number == 3){
        large_words->print(& Node::micro_prox);
    } else {
        all_words->print(& Node::macro_prox);
    }
}

void handle_print_by_length(List* short_words, List* medium_words, List* large_words, List* all_words, int length){
    if(length <= 5){
        short_words->lista_palavra_tamanho(length, & Node::micro_prox);
    } else if (length >= 6 && length <= 10){
        medium_words->lista_palavra_tamanho(length, & Node::micro_prox);
    } else {
        large_words->lista_palavra_tamanho(length, & Node::micro_prox);
    }
}

void handle_remove(List* short_words, List* medium_words,List* large_words, List* all_words, std::string &word){
    int const length = word.length();

    if (length <= 5){
        short_words->remove_palavra(word, & Node::micro_prox, true);
    } else if (length >= 6 && length <= 10){
        medium_words->remove_palavra(word, & Node::micro_prox, true);
    } else {
        large_words->remove_palavra(word, & Node::micro_prox, true);
    }

    all_words->remove_palavra(word, & Node::macro_prox, false);
}