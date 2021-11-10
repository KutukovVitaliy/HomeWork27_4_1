//
// Created by kvitadmin on 10.11.2021.
//

#ifndef HOMEWORK27_4_1_BIGBRANCH_H
#define HOMEWORK27_4_1_BIGBRANCH_H


#include <utility>
#include <ctime>
#include "middlebranch.h"


class BigBranch{
    class Tree* tree;
    int countMiddleBranch;
    MiddleBranch** pMiddleBranch = nullptr;
    std::string elfName;
public:
    BigBranch(class Tree* inTree, std::string inName): tree(inTree), elfName(std::move(inName)){
        assert(inTree != nullptr);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        countMiddleBranch = (std::rand() % 2) + 2;
        pMiddleBranch = new MiddleBranch*[countMiddleBranch];
        for(int i = 0; i < countMiddleBranch; ++i){
            pMiddleBranch[i] = new MiddleBranch(this, "none");
        }
    }
    std::string GetElfName(){
        return this->elfName;
    }
    void SetElfName(std::string& name){
        this->elfName = std::move(name);
    }
    MiddleBranch* GetMiddleBranchPtr(int index){
        if(index >= 0 && index < countMiddleBranch) {
            return pMiddleBranch[index];
        }
        return nullptr;
    }
    int GetMiddleBranchCount(){
        return countMiddleBranch;
    }
    int GetElfNeighbors(std::string nameToSearch){
        int count = 0;
        bool searched = false;
        if(this->elfName == nameToSearch) {
            searched = true;
        }
            if(this->elfName != "None")count++;

        for(int i = 0; i < countMiddleBranch; ++i){
            if(pMiddleBranch[i]->GetElfName() == nameToSearch) searched = true;
            if(pMiddleBranch[i]->GetElfName() != "none") count++;
        }
        if(searched) return (count - 1);
        else return  -1;
    }
};


#endif //HOMEWORK27_4_1_BIGBRANCH_H
