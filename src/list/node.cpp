#ifndef NODE_CPP
#define NODE_CPP
#include <string>

class Node{
    private:
    std::string word;

    public:
    Node* macro_prox{nullptr};
    Node* micro_prox{nullptr};

    Node(std::string word){
        this->word = word;
    };

    std::string getWord(){
        return this->word;
    };
};
#endif