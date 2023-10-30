#include <iostream>
#include "../list/list.cpp"
#include "../controllers/HandleWords.cpp"
#include "../list/node.cpp"

int main(){
    List* all_words = new List();
    List* short_words = new List();
    List* medium_words = new List();
    List* large_words = new List();

    while(true){
        std::string command;
        std::cin >> command;

        if(command == "i"){
            std::string word;
            std::cin >> word;

            Node* node = new Node(word);

            handle_insertion(short_words, medium_words, large_words, all_words, node);
        };

        if(command == "l"){
            int list_number;
            std::cin >> list_number;

            handle_print(short_words, medium_words, large_words, all_words, list_number);
        }

        if(command == "x"){
            int length;
            std::cin >> length;

            handle_print_by_length(short_words, medium_words, large_words, all_words, length);
        }

        if(command == "o"){
            char firstLetter;
            char lastLetter;

            std::cin >> firstLetter >> lastLetter;

            all_words->lista_palavras_entre(firstLetter, lastLetter, & Node::macro_prox);
        }

        if(command == "r"){
            std::string word;

            std::cin >> word;

            handle_remove(short_words, medium_words, large_words, all_words, word);
        }

        if(command == "e"){
            break;
        }
    }
    return 0;
}